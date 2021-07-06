/* 
    this Contact Book Project is implementation of the linked List Where with the help of linked list you can perfrom add,

    edit,delete,display etc. operations on Contact Book. Here names are already stored in sotred order and can 

    find contact in O(n) time.
*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

struct node
{              //node which represent the deatils of a paticular user.
    string firstName;
    string lastName;
    string phoneNo;
    node* next;
 };

//class which will represent the contact book
class Contactbook
{
    private:
        node* head = NULL;

    public:
        bool does_exist(string);
        void add_contact(string,string,string);
        void search_contact(string);
        void edit_contact(string,int);
        void display_contact_list();
        void delete_contact(string);
        void self_exit();

}cb;

//Function will chech whether the contact already exist or not
bool Contactbook::does_exist(string userN)
{
    node* temp = head;

    while(temp->next != NULL)
    {
        if(temp->firstName == userN)
            return true;

        temp = temp->next;
    }

    if(temp->next == NULL && temp->firstName == userN )
        return true;
    
    return false;
}

//Function will add the new contact in the contact book.
void Contactbook::add_contact(string firstN, string lastN, string phno)
{
    if(head != NULL && does_exist(firstN))
    {
        cout << "\nContact Already Exist!..\n";
        return;
    }
    
    node* new_node = new node;              // ctreating new node and entring details in it.
    new_node->firstName = firstN;
    new_node->lastName = lastN;
    new_node->phoneNo = phno;
    new_node->next = NULL;


    if(head == NULL)                    // if first time contact is added.
    {
        head = new_node;
        cout << "\n\tContact Added!..";
        return;
    }

    if(head->firstName.compare(firstN) > 0)     //if entered user name is lexographically smaller than first
    {                                          //contact then swap the new_node with head node and                      
        new_node->next = head;                 //set new_node as head node.
        head = new_node;
        cout << "\n\tContact added!..";
        return;
        
    }

    node* temp = head;
    
    while(temp->next != NULL && temp->next->firstName.compare(firstN) < 0)      //traverse the list till the username reaches to its correct postion    
    {
        temp = temp->next;    
    }

    if(temp->next == NULL)
    {
        temp->next = new_node;
        cout << "\n\tContact Added!..";
        return;
    }

    new_node->next = temp->next;             //add the new_contact in its correct position.
    temp->next = new_node;
}

//function will search the desired contact in the contact list.
void Contactbook::search_contact(string userN)
{
    if(head == NULL)
    {
        cout << "Contact List is empty !.. " << endl;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        if(temp->firstName == userN)
        {
            cout << "Contact found !.. \n\n";
            cout << "\tDetails\n\n";
            cout << temp->firstName << endl << temp->lastName << endl << temp->phoneNo << endl << endl; 
            return;
        }
        temp = temp->next;
    }

    if(temp->next == NULL && head->firstName == userN)
    {                                                             //if only one exist then display its details.
            cout << "Contact found !.. \n\n";
            cout << "\tDetails\n";
            cout << head->firstName << endl << head->lastName << endl << head->phoneNo << endl << endl;
            return;   
    }
      
    else 
    {                                           //if entered contact is not found
         cout << "Contact Not found !...\n";
    }
}

//Function will modify the contact book according to the username entered by the user.
void Contactbook::edit_contact(string userN, int choice)
{
    if(head == NULL)                 // if there are no contacts in contactBook
    {
        cout << "Contact List is Empty !.." << endl;
        return;
    }

    if(head->next == NULL)
    {
        if(head->firstName == userN)
        {
            switch(choice)           // according to the choice of the user modification be made
            {
                case 1: 
                {
                    string name;
                    cout << endl << "Enter new name : ";
                    cin >> name;
                    head->firstName = name;
                    cout << "\n\tContact Updated !..\n";
                    break;
                }

                case 2:
                {
                    string lname;
                    cout << "Enter the last name: ";
                    cin >> lname;
                    head->lastName = lname;
                    cout << "\n\tContact Updated !..\n";
                    break;
                }

                case 3:
                {
                    string ph;
                    cout << "Enter new phone number: ";
                    cin >> ph;
                    head->phoneNo = ph;
                    cout << "\n\tContact Updated !..\n";
                    break;
                }

                default : cout << "\nInvalid input!..\n";
                break;
            }
        }
        else    //if contact does not exist.
        {
            cout << "Contact not found !.." << endl;
        }
        return;
    }

    node* temp = head;

    while(temp->next != NULL)
    {
        if(temp->firstName == userN)
        {
            switch(choice)
            {
                case 1: 
                {
                    string name;
                    cout << endl << "Enter new name : ";
                    cin>>name;
                    temp->firstName = name;
                    break;
                }

                case 2:
                {
                    string lname;
                    cout << "Enter the last name: ";
                    cin >> lname;
                    temp->lastName = lname;
                    break;
                }

                case 3:
                {
                    string ph;
                    cout << "Enter new phone number: ";
                    cin >> ph;
                    temp->phoneNo = ph;
                    break;
                }

                default : cout << "\nInvalid input!..\n";
                break;
            }

            return;
        }

        temp = temp->next;
    }

    if(temp->next == NULL)
        cout << "Contact not found !.." << endl;
    
}

// Function will display the complete contact list.
void Contactbook::display_contact_list()
{
    if(head == NULL)
    {
        cout << "Contact List is empty !.." << endl;
        return;
    }
    node* temp = head;                 //traversing the list and displaying contacts details

    while(temp->next != NULL)
    {
        cout << endl << temp->firstName << endl << temp->lastName << endl << temp->phoneNo << endl;

        temp = temp->next;
    }
    //executes to display the last node
    cout << endl << temp->firstName << endl << temp->lastName << endl << temp->phoneNo << endl;
}

//function which will delete the contact from contact list 
void Contactbook::delete_contact(string userN)
{
    if(head == NULL)
    {
        cout << "Contact list is Empty !.." << endl;
        return;
    }

    if(head->firstName == userN)      //checking weather head contain desired username
    {
        node* temp = head;
        head = head->next;
        delete temp;
        cout << "\n\tContact Deleted...";
        return;
    }

    node* curr = head;     
    while(curr->next != NULL  && curr->next->firstName != userN)       //traversing to the node precedes the desired node
        curr = curr->next;

    if(curr->next == NULL)
    {
        cout << "\n\tContact Not found !..";
        return;
    }

    node* temp = curr->next;         //deleting the node
    curr->next = temp->next;
    delete temp;

    cout << "\n\tContact Deleted...";
}

//Function will exit from the program
void Contactbook::self_exit()
{
    cout << "\n\n\tThank you for using Contact Book\n\n\t\tSee you Soon Again !..\n\n";
    exit(1);
}
//Driver program
main()
{
    int choice;
    //Contactbook cb;
    system("cls");
    system("color 0A");

    while (1) 
    {
        cout << "\n\n\n\t\t\tCONTACT BOOK";
        cout << "\n\n\t1. Add Contact(lowercase letter allowed)\n\t2. Search Contact"
                "\n\t3. Edit Contact\n\t4. Display Contact\n\t"
                "5. Delete Contact\n\t6. Exit\n\t>";
        cin >> choice;
  
        //Switch case
        switch (choice) 
        {
            case 1:
            {
                string fnm,lnm,ph;
                cout << "\n\tEnter first Name : ";
                cin >> fnm;
                cout << "\n\tEnter last Name : ";
                cin >> lnm;
                cout << "\n\tEnter the phone Number : ";
                cin >> ph;
                cb.add_contact(fnm,lnm,ph);
                break;
            }
    
            case 2:
            {
                string fnm;
                cout << "\n\tEnter Name to be searched : ";
                cin >> fnm;
                cb.search_contact(fnm);
                break;
            }
    
            case 3:
            {
                string usrnm;
                int ch;
                cout << "\n\tEnter the name to edit : ";
                cin >> usrnm;
                cout << "\n\t\tEnter choice to edit: \n\t1. First Name"
                        "\n\t2. Last Name\n\t3. Phone Number\n\t>";
                cin >> ch;
                cb.edit_contact(usrnm,ch);
                break;
            }

            case 4:
            {
                cb.display_contact_list();
                break;
            }

            case 5:
            {
                string usrnm;
                cout << "Enter the user name of contact whon you want to delete : ";
                cin >> usrnm;
                cb.delete_contact(usrnm);
                break;
            }

            case 6:
            {
                cb.self_exit();
                break;
            }

            default:
            {
                cout << "\n\n\tInvalid Input!";
                break;
            }
        }
    }
    return 0;
}