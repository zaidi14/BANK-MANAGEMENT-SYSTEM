#include <iostream>      
#include <windows.h>          //for new interface
#include <conio.h>           //for maths functions
#include <stdlib.h>          //to make input output easy 
#include <string.h>           
#include <time.h>            //for printing current time and date
#include <fstream>           //file handling
#include <cstdio>            


// scanf(%d, &int)  is being used to store the value in specified memory location.  
/// can be replaced with cin if complex



using namespace std;

//global initializing integers

int x; 

int ca(int a);                                      //function for checking accounts

class gikipay{
	
   void check_balance();
   void withdrawl();
   void deposit();
   void transfer();
   void mainexit();                       // initializing member functions to the gikipay class
   void view();                              
   void add();
   void del();
   void edit();
   void search_name();
   void search_acn();                   
  
   
   

//continuous code starts from here.


//data encaptulation
	 
protected: 
          // data hiding
      char id[20],password[15];          //used for logging in the main system 
      
      
   private:
    int choice;                            // choice for admin or user
    
    
   public: // data abstraction
   
       gikipay(){                                      //constructor.
	     
		 cout << "\t\t\t    //////////////////////////////////" << endl;
         cout << "\t\t\t   //------------------------------//" << endl;
         cout << "\t\t\t  ///|        GIKI PAY          |///" << endl;
         cout << "\t\t\t ///----------------------------///" << endl;
         cout << "\t\t\t//////////////////////////////////" << endl;
         cout << "\t\t\t-----------------------------------" << endl;
         cout << "\t\t\t| AAPKAY DIL MAIN HAMARA ACCOUNT |" << endl;
         cout << "\t\t\t-----------------------------------" << endl;                                     
       
	   
	     cout << "CHOOSE ACCOUNT TYPE: ";
         cout << endl;
         
         cout << "[1] . ADMINISTRATOR ";
         cout << "\t\t\t" ;
         cout << "[2] . USER ";
         cout << endl;
         cout << "Enter Your Choice .... ";
         cin >> choice;
         
         if (choice != 1 && choice != 2) {
         	system("cls");// to a new screen  
            gikipay();
         }
         system("cls");
         authentication();
	   }
	   
	 	
	   
	   void authentication() {

      cout << "Welcome to GIKI Pay Banking System - where your finances are in safe hands! "<<endl;

      login();
      cout<<endl<<endl<<endl;
      if (verify() == 1) {
         if (choice== 1)
            main();                  //for admin
         else
            transaction();             // for user
      } 
	  else if (verify() == 0) {
         system("cls");
         cout << "Incorrect Username / Password !!!!";
         cout << endl;
         authentication();
      }
   }
	 
	 
	 
	 void login(){                                    // Takes the user-name and password .

      cout << "Enter The Username : ";
      cin >> id;                                          //initialized globally in gikipay function.

      cout << "Enter The Password : ";
      cin >> password;                                 //initialized globally in gikipay function.
   }

   

	 // verifies the user-name and password .
	 int verify(){ 
      char a;
      if (choice == 1) {                       //if choice is admin 
         
		 if ((strcmp(id, "admin") == 0 && strcmp(password, "admin") == 0)) {

            cout << "You Have Successfully Logged In : " << '"' << id << '"' << endl;
            time_t t;
            time( & t);

            cout << "Logged In Time : " << ctime( & t);

            cout << "Press any key to continue .... ";
            getch();          
            return 1;
         } else
            return 0;
      } else if (choice == 2) {
         if (strcmp(id, "user") == 0 && strcmp(password, "user") == 0) {

            cout << "You Have Successfully Logged In : " << '"' << id << '"' << endl;
            time_t t;
            time( & t);

            cout << "Logged In Time : " << ctime( & t);

            cout << "Press any key to continue .... ";
            getch();
            return 1;
         } else
            return 0;
      }
      return 0;
   }





  void main() {                                            // displays the main user interface screen of program .
     system("cls");

      cout << " WELCOME TO MAIN MENU ";
      cout << endl;

      cout << "[1] . View Customer Accounts";
      cout << endl;

      cout << "[2] . Customer Account Registration";
      cout << endl;

      cout << "[3] . Edit Customer Account";
      cout << endl;

      cout << "[4] . Delete Customer Account";
      cout << endl;

      cout << "[5] . Search Customer Account";
      cout << endl;

      cout << "[6] . Transaction";
      cout << endl;

      cout << "[7] . Log Out !!! ";
      cout << endl;

      cout << "[8] . About US ";
      cout << endl;

      cout << "Please Enter Your Choice [1-8] : ";
      mainchoice();
   }
   
   
   
   
   void mainchoice() {                                        // takes user choice in main  and goes to desired function .
   
      int i;
      cin >> i;
      cout<<endl;
      system("cls");
      
      switch (i) {
      case 1:
         view();
         break;
      case 2:
         add();
         break;
      case 3:
         edit();
         break;
      case 4:
         del();
         break;
      case 5:
         search();
         break;
      case 6:
         transaction();
         break;
      case 7:
         mainexit();
         break;
      case 8:
         about();
         break;
      default:
         main();
      }
   }


	
	
	
	
 void search() {                               //module for searching account ( 2 types by number and name )
 
 system("cls");
      int search_choice;

      cout << " SEARCH MENU: ";
      cout << endl;

      cout << "[1] . Search By Account ";
      cout << endl;

      cout << "[2] . Search By Name ";
      cout << endl;

      cout << "Enter Your Choice [1-2] : ";
      cin>>search_choice;
      system("cls");
      
      if (search_choice== 1) {
         search_acn();
      }
	   else if (search_choice== 2) {
         search_name();
      } else
         main();
   }
  
	
	
	
	
	
	
	
	void transaction(){                        // displays screen for the transaction options and takes the user choice .
	
	system("cls");
	
	  cout << " TRANSACTION MENU ";
      cout << endl;

      cout << "[1] . Balance Inquiry";
      cout << endl;

      cout << "[2] . Cash Deposit";
      cout << endl;

      cout << "[3] . Cash Withdrawal";
      cout << endl;

      cout << "[4] . Fund Transfer";
      cout << endl;
      
      
      if (choice == 1) {
           cout << "[5] . Main Menu";
      } 
	  else {
         cout << "[5] . Exit";
      }
		
		cout<<endl<<endl<<endl;
		
	  cout << "Please Enter Your Choice [1-5] : ";
      int transaction_choice;
      cin>> transaction_choice;
      
      switch (transaction_choice) {
      case 1:
         check_balance();
         break;
      case 2:
         deposit();
         break;
      case 3:
         withdrawl();
         break;
      case 4:
         transfer();
         break;
      case 5:
         if (transaction_choice == 1)
            main();
         else
            mainexit();
         break;
      default:
         transaction();
      }
   }
     
   
   
   
   
   
   
   void about(){
   	
   	  cout << " ABOUT US ";
	  cout<<endl;
	  
      cout << "It is a  Bank Management System Project for our 2nd Semester based on C++ programming language.";
      cout<<endl;
      	
      cout << "Members of Our Team: ";
      cout<<endl;
      	
      	
      	
      cout << "[1] . Saba Hareem Shaikh";
      cout<<endl;
      	
      cout << "[2] . Syed Mojiz Zaidi";
      cout<<endl;
      	
      cout<<"[3] .  Dua Tahir";
      cout<<endl;
      
      cout<<"[4] . Muhammad Abdullah";
      cout<<endl;
      
      
      cout << "Press any key to return back to main menu. ";
      char z = getch();
      
      if (z == 13) {
         main();
      }
   }
	
};               // class gikipay ends here. code of project mile stone 1;  file handling will be done in later classes.







class record {                                                                      //inheritance

   public: 
                                                                       
   char name[25];
   int account;
   char phone[15];
   char address[25];
   char email[35];
   char citizenship_no[20];
   double balance;
   char UserID[10];

};
   
//module for adding accounts.

void gikipay::add(){
	
	
	char choice_add;
	record recs;
	
	//app = append binary / write data to the file.
	
	ofstream xon;       //write data
	
	xon.open("record.bin", ios::app | ios::binary); // data will be written at end of the file
	
	 int i = 0, x;
   // first we evaluate body and check condition
    do {
      system("cls");

      cout << " CUSTOMER ACCOUNT REGISTRATION ";
      cout<<endl;
      
      cout << "[1] . Enter Your Name           : ";
      cin >> recs.name;

      cout << "[2] . Enter Your Account Number : ";
      cin>>recs.account;

      cout << "[3] . Enter Your Phone Number   : ";
      cin >> recs.phone;

      cout << "[4] . Enter Your Address        : ";
      cin >> recs.address;

      cout << "[5] . Enter Your E-mail         : ";
      cin >> recs.email;

      cout << "[6] . Enter Your Citizenship No.: ";
      cin >> recs.citizenship_no;

      cout << "[7] . Enter Amount To Deposit   : $";
      cin>>recs.balance;
                                                        
                                                        
      srand(time(0)); //random number
      
      for (int r = 0; r < 10; r++) {
         recs.UserID[r] = rand() % 10;
      }
      
      //write() = for writing binary data
      // reinterpret_cast - casting one pointer data type to another pointer data type
      //This helps to write contents in a class variable in the file and stores it in the variable rec.
      //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

	xon.write(reinterpret_cast < char * > ( & recs), sizeof(recs)); //whatever &rec is treat it as char *
	
	
      cout << "CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL";
      i++;
      cout << endl;
      cout << "Do You Want To Add Another Record ? (Y/N) : ";
      cin>>choice_add;
  }
      
    while (choice_add == 'Y' || choice_add == 'y');
    xon.close();

   cout << "Press any key to return back to main menu. ";
   char z = getch();
   
   if (z == 13) {
      main();
   }
   
    else
      view();
  }
  
  
  
    // module for deleting accout;
  void gikipay::del(){
  	
  	record recs;
  	ifstream con;
  	ofstream xon;
  	
  	int t,p;
  	
  	
  	re:
  		 cout << " DELETE CUSTOMER ACCOUNT ";
  		 cout<<endl;
  		 
  		 cout << "Enter Your Account Number To Delete : ";
         cin>>t;
         
         
         if(ca(t)==1){
         	con.open("record.bin", ios::in | ios::binary);
            xon.open("new.bin", ios::out | ios::binary);                                                 // if{ while  {if}  }
            
            while (con.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
                      if (recs.account != t)
                      xon.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
		 }
		 
	  con.close();
      xon.close();
      ifstream xon;
      ofstream con;
      con.open("record.bin", ios::out | ios::binary); // write only
      xon.open("new.bin", ios::in | ios::binary);
      
      
      while (xon.read(reinterpret_cast < char * > ( & recs), sizeof(recs)))
         con.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
      xon.close();
      con.close();	 
  }
  
  else if(ca(t)==0){


     system("cls");
      cout << "Account Doesn't Exist";
      cout<<endl;
      
      
      goto re;
   
  
  }
  
  
   cout << "CUSTOMER ACCOUNT DELETED SUCCESSFULLY";
cout<<endl;
   cout << "Press any key to return back to main menu. ";
   getch();
   main();

}


// module for viewing account details
void gikipay::view() {
   int i = 7;
   record rec;
   //read from the file
   ifstream f;
   f.open("record.bin", ios::in | ios::binary); //open file for read only

   cout << " CUSTOMERS LIST ";
   cout << endl;

   /* f.read() = for reading binary data
    This reads the contents of a class variable from the file and stores it in the variable rec.
    The f.read() function will keep returning 1 until there are records in the file.
    As soon as the EOF is encountered f.read() will return a value less than 1 and
    the condition in the while loop become false and the control comes out of the while loop.

   
   
/*f: It is an object of std::ifstream class, which is used to read data from a file.
.read(): It is a member function of std::ifstream class, which is used to read a specified number 
of bytes from a file and store them in a memory buffer.

reinterpret_cast<char*>(&rec): It is a type-casting operator that casts a pointer to an object of type 
record to a pointer to a char type. 

This is done because the .read() function expects a char* type buffer as its first argument.

sizeof(rec): It is an operator that returns the size of the record object in bytes. 
This is the number of bytes that will be read from the file.

while: It is a loop construct that repeatedly executes a block of statements as long as the specified condition is true.

f.read(...) inside the while loop: This reads a chunk of binary data from the file into the rec object, 

then returns true if the read operation was successful, 
and false if the end of file (EOF) has been reached.

Therefore, the while loop will continue to read data from the file until it reaches the end of file, storing each record object in the rec variable.
	
 while (f.read(reinterpret_cast < char * > ( & rec), sizeof(rec)))
*/
   
   while (f.read(reinterpret_cast < char * > ( & rec), sizeof(rec))) {

      cout << "A/C No:";
      cout << endl;
      cout << rec.account;
      cout << endl;

      cout << "Account Name:";
      cout << endl;
      cout << rec.name;
      cout << endl;

      cout << "UserID: ";

      for (int r = 0; r < 10; r++) {
         cout << (int) rec.UserID[r];
      }
      cout << endl;

      cout << "Email Address:";
      cout << endl;
      cout << rec.email;
      cout << endl;

      cout << "Phone No.:";
      cout << endl;
      cout << rec.phone;
      cout << endl;

      cout << "Balance:";
      cout << endl;
      cout << rec.balance << "$";
      cout << endl;
      
   }
   
   f.close();
   int x;
   cout << "Press [Enter] to return back to main menu. ";
   x = getch();
   if (x == 13) {                            // 13 = '\r' i.e carriage return
      main();
   } else
      view();                                //this is exception handling 
};




//module for editing details.
void gikipay::edit() {
   record rec;
   ifstream f1;
   ofstream f2;
   int a, c;
 

      cout << " EDIT CUSTOMER ACCOUNT ";
cout<<endl;
   cout << "Enter Your Account Number To Edit : ";
   cin>>a;
   
     system("CLS");

   
   if (ca(a) == 1) {
      f1.open("record.bin", ios::in | ios::binary); //read
      f2.open("new.bin", ios::app | ios::binary); //write


      while (f1.read(reinterpret_cast < char * > ( & rec), sizeof(rec))) {


         if (rec.account != a)
            f2.write(reinterpret_cast < char * > ( & rec), sizeof(rec));


         else if (rec.account == a) {

            cout << "Account Number Matched";

            cout << "Enter Your Details";

            cout << "[1] . Enter Your Name           : ";
            cin >> rec.name;

            cout << "[2] . Enter Your Account Number : ";
            cin >> rec.account;

            cout << "[3] . Enter Your Phone Number   : ";
            cin >> rec.phone;

            cout << "[4] . Enter Your Address        : ";
            cin >> rec.address;

            cout << "[5] . Enter Your E-mail         : ";
            cin >> rec.email;

            cout << "[6] . Enter Your Citizenship No : ";
            cin >> rec.citizenship_no;
            f2.write(reinterpret_cast < char * > ( & rec), sizeof(rec));
         }
      }
      f1.close();
      f2.close();
   }
   if (ca(a) == 0) {
      system("CLS");

      cout << "Account Doesn't Exist. ";
      cout<<endl;
    edit();
   }


   remove("record.bin");
   rename("new.bin", "record.bin");

   cout << "CUSTOMER ACCOUNT UPDATE SUCCESSFULL";

   cout << "Press any key to return back to main menu . ";
   getch();
   main();
}


// module for search details through account number.
void gikipay::search_acn() {
	
   record recs;
   ifstream con;
   int b = 0;
   
   int a, x, interestRate = 0.06;
   
   re:

      cout << " SEARCH CUSTOMER ACCOUNT ";
cout<<endl;
   cout << "Enter Your Account Number To Search : ";
   cin>>a;
   if (ca(a) == 1) {
      con.open("record.bin", ios::in | ios::binary);
      
      while (con.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
         if (recs.account == a) {

            cout << "Account Number Matched";
            cout<<endl;
            
            cout << "Detail Information of " << recs.name;
            cout<<endl;
            
            
            cout << "[1] . Account Number : " << recs.account;
            cout<<endl;
            cout << "[2] . Name           : " << recs.name;
            cout<<endl;
            cout << "[3] . UserID         : ";
            for (int r = 0; r < 10; r++) {
               cout << (int) recs.UserID[r];
            }
            cout<<endl;
            cout << "[4] . Phone Number   : " << recs.phone;
            cout<<endl;
            cout << "[5] . Address        : " << recs.address;
            cout<<endl;
            cout << "[6] . E-mail         : " << recs.email;
            cout<<endl;
            cout << "[7] . Citizenship No : " << recs.citizenship_no;
            cout<<endl;
            cout << "[8] . Current Balance: " << recs.balance;
            cout<<endl; 
            cout << "[9] . Status         : ";
            if (recs.balance > 25) {
               cout << "Active";
            } 
			else {
               cout << "Inactive";
            }
            cout<<endl;
            cout << "[10] . Acquired Interest: ";
            double monthlyInterestRate = interestRate / 12;
            double monthlyInterest = recs.balance * monthlyInterestRate;
            recs.balance += monthlyInterest;
            cout << recs.balance << "$";
            break;
         } 
		 else
            b = 1;
      }
      con.close();
   }
   
   if (ca(a) == 0) {
    	system("cls");
      cout << "Account Doesn't Exist. ";
  cout<<endl;
      goto re;
   }
  cout<<endl;
  cout<<endl;
  cout<<endl;
   cout << "Press [ENTER] to return back to main menu. ";
   char z = getch();
   if (z == 13)
      main();
   else
      search();	
}





//module for search details through name.
void gikipay::search_name(){
	
	
   int i = 0, b, x, interestRate = 0.06;
   char nam[30];

   cout << " SEARCH CUSTOMER ACCOUNT ";
cout<<endl;

   cout << "Enter Your Full Name To Search : ";
   cin >> nam;

   record recs;
   ifstream con;

   con.open("record.bin", ios::in | ios::binary);
   
   
   while (con.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
      b = 0;
      strupr(recs.name);
      strupr(nam);
      if (strcmp(recs.name, nam) == 0) {                        ///==1;


/*

The function strupr() is used to convert the characters in a string to uppercase.
 In this code, strupr(recs.name) is converting all the characters in the string recs.name to uppercase.
Similarly, strupr(nam) is converting all the characters in the string nam to uppercase.

The function strcmp() is used to compare two strings and returns an integer value based on their lexicographical order.
 If the strings are equal, it returns 0.
In this code, strcmp(recs.name, nam) == 0 is checking if the string recs.name is equal to the string nam (after converting both to uppercase). 
If they are equal, the condition evaluates to true and the code inside the if statement will be executed.*/


         cout << "Account Number Matched";
        cout<<endl;
         cout << "Detail Information of " << recs.name;
        cout<<endl;
         cout << "[1] . Account Number : " << recs.account;
        cout<<endl;
         cout << "[2] . Name           : " << recs.name;
        cout<<endl;
         cout << "[3] . UserID         : ";
         for (int r = 0; r < 10; r++) {
            cout << (int) recs.UserID[r];
         }
        cout<<endl;
         cout << "[4] . Phone Number   : " << recs.phone;
        cout<<endl;
         cout << "[5] . Address        : " << recs.address;
        cout<<endl;
         cout << "[6] . E-mail         : " << recs.email;
        cout<<endl;
         cout << "[7] . Citizenship No : " << recs.citizenship_no;
        cout<<endl;
         cout << "[8] . Current Balance: " << recs.balance;
        cout<<endl;
         cout << "[9] . Status         : ";
         if (recs.balance > 25) {
            cout << "Active";
         } 
		 else {
            cout << "Inactive";
         }
        cout<<endl;
         cout << "[10] . Acquired Interest: ";
         double monthlyInterestRate = interestRate / 12;
         double monthlyInterest = recs.balance * monthlyInterestRate;
         recs.balance += monthlyInterest;
         cout << recs.balance << "$";
         break;
      } else
         b = 1;
   }
   con.close();
   if (b == 1) {
   	
   		system("cls");
     

      cout << "Account Doesn't Exist. ";
cout<<endl;
   }
  cout<<endl;
   cout << "Press [ENTER] to return back to main menu. ";
   char z = getch();
   if (z == 13)
      main();
   else
      search();
}





// module for checking account balance and displaying it
// part of transaction
void gikipay::check_balance() {                                   
   record recs;
   ifstream con;
   int a;

   cout << " BALANCE INQUIRY ";
cout<<endl;
   cout << "Enter Your Account Number : ";
   cin>>a;
   if (ca(a) == 1) {
      con.open("record.bin", ios::in | ios::binary);
      while (con.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
         if (recs.account == a) {

            cout << "Your Balance is : $" << recs.balance;
            cout<<endl;
         }
      }
      con.close();
   }
   if (ca(a) == 0) {
     
	system("cls");
      cout << "Account Doesn't Exist.";
      check_balance();
      cout<<endl;
   }
   
   cout << "Press any key to return back to main menu. ";
   getch();
   transaction();

}


// module to withdraw amount from account
void gikipay::withdrawl() { 
   record recs;
   ifstream f1;
   ofstream f2;
   int a;
   double b, z;

   cout << " CASH WITHDRAWAL ";
cout<<endl;
   cout << "Enter Your Account Number : ";
   cin>>a;
   if (ca(a) == 1) {
      f1.open("record.bin", ios::in | ios::binary);
      f2.open("new.bin", ios::out | ios::binary);
     
      cout << "Enter The Amount To Withdraw : $ ";
      cin>>b;
      while (f1.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
         if (recs.account != a)
            f2.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
         else if (recs.account == a) {
            recs.name; cout<<endl;
            recs.account; cout<<endl;
            recs.phone; cout<<endl;
            recs.address; cout<<endl;
            recs.email; cout<<endl;
            recs.citizenship_no; cout<<endl;
            z = recs.balance; cout<<endl;
            if (b <= recs.balance) {
               recs.balance -= b;

               cout << "    CASH WITHDRAWAL SUCCESSFULL     ";
               
            }
            
            cout<<endl;
            
            
            if (recs.balance > 100) {
               recs.balance -= 1;

               cout << " 1$ withdrawn charge taken ";
            }
            
            cout<<endl;
            f2.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
         }
      }
      
    cout<<endl;
      f1.close();
      f2.close();
      remove("record.bin");
      rename("new.bin", "record.bin");
      if (z < b) {
         	system("cls");
  cout<<endl;
         cout << "Current Balance is " << z;
  cout<<endl;
         cout << "Entered amount exceeds current balance";
           cout<<endl;
         withdrawl();
      }
   }
   if (ca(a) == 0) {
   	
   		system("cls");
       cout<<endl;
      cout << "Account Doesn't Exist.";
  cout<<endl;
      withdrawl();
   }

   cout << "     Press Any Key To Continue ....   ";
   getch();
   transaction();
}
 	
 	
 	
 	
// module for adding amount to a account
void gikipay::deposit() { 
   int a;
   double b;
   record recs;
   ifstream f1;
   ofstream f2;

   cout << " CASH DEPOSIT ";
cout<<endl;
   cout << "Enter Your Account Number : ";
   cin>>a;
   if (ca(a) == 1) {
      f1.open("record.bin", ios::in | ios::binary);
      f2.open("new.bin", ios::out | ios::binary);
      while (f1.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
         if (recs.account != a)
            f2.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
         else if (recs.account == a) {
            recs.name;cout<<endl;
            recs.account;cout<<endl;
            recs.phone;cout<<endl;
            recs.address;cout<<endl;
            recs.email;cout<<endl;
            recs.citizenship_no;cout<<endl;
cout<<endl;
            cout << "Enter The Amount To Deposit : $ ";
            cin>>b;
            recs.balance += b;
            f2.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
         }
      }
      f1.close();
      f2.close();
      ifstream f2;
      ofstream f1;
      
      f1.open("record.bin", ios::out | ios::binary); // write only
      f2.open("new.bin", ios::in | ios::binary);
      
      while (f2.read(reinterpret_cast < char * > ( & recs), sizeof(recs)))
         f1.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
      f1.close();
      f2.close();
   }
   if (ca(a) == 0) {
   	
   		system("cls");
     cout<<endl;

      cout << "Account Doesn't Exist. ";
cout<<endl;
      deposit();
   }
cout<<endl;
   cout << "CASH DEPOSIT SUCCESSFULL";
cout<<endl;
   cout << "Press any key to return back...";
   getch();
   transaction();
}



// module for transfering amount from 1 acc to another
void gikipay::transfer() { 
   int a;
   double b, z;
   record recs;
   ifstream f1;
   ofstream f2;
   f1.open("record.bin", ios::in | ios::binary);
   f2.open("new.bin", ios::out | ios::binary);

   cout << " CASH TRANSFER ";

   cout << "Enter Your Account Number      : ";
   
      cin>>a;
      cout<<endl;
   if (ca(a) == 0) {
   	
   		system("cls");
     cout<<endl;
      cout << "Account Doesn't Exist.";
cout<<endl;
      transfer();
   } 
   
   else if (ca(a) == 1) {
     cout<<endl;
      cout << "Enter The Amount To Transfer   : $ ";
      cin>>b;
      cout<<endl;
      while (f1.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
         if (recs.account != a)
            f2.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
         else if (recs.account == a) {
            recs.name;cout<<endl;
            recs.account;cout<<endl;
            recs.phone;cout<<endl;
            recs.address;cout<<endl;
            recs.email;cout<<endl;
            recs.citizenship_no;cout<<endl;
            cout<<endl;
            if (b < recs.balance) {
               z = recs.balance;
               recs.balance -= b;
            }
            f2.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
         }
      }
   }
   
   cout<<endl;
   cout<<endl;
   
   
   f1.close();
   f2.close();
   remove("record.bin");
   rename("new.bin", "record.bin");
   if (b > z) {
cout<<endl;
      cout << "Current Balance is $" << z;
cout<<endl;
      cout << "Entered amount exceeds current balance";
      transaction();
   }

   f1.open("record.bin", ios::in | ios::binary);
   f2.open("new.bin", ios::out | ios::binary);

   cout << "Enter Recipient Account Number : ";
   cin>>a;
   if (ca(a) == 0) {
cout<<endl;
      cout << "Account Doesn't Exist.";
      transfer();
   } 
   else if (ca(a) == 1) {
      while (f1.read(reinterpret_cast < char * > ( & recs), sizeof(recs))) {
         if (recs.account != a)
            f2.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
         else if (recs.account == a) {
            recs.name;cout<<endl;
            recs.account;cout<<endl;
            recs.phone;cout<<endl;
            recs.address;cout<<endl;
            recs.email;cout<<endl;
            recs.citizenship_no;cout<<endl;
            
            cout<<endl;
            recs.balance += b;
            f2.write(reinterpret_cast < char * > ( & recs), sizeof(recs));
         }
      }
      f1.close();
      f2.close();
      remove("record.bin");
      rename("new.bin", "record.bin");
      cout<<endl;
      cout<<endl;
   }
   
   cout<<endl;

   cout << "        CASH TRANSFER SUCCESSFULL        ";
   cout<<endl;

   cout << "        Press Any Key To Continue ....        ";
   getch();
   	system("cls");
   

  
   transaction();
}




//module for logging out of the program.
void gikipay::mainexit() { 
   system("cls");

   cout << " THANK YOU ";
cout<<endl;
cout<<endl;
cout<<endl;
   cout << "USER            :: " << id;
   cout<<endl;
   time_t t;
   time( & t);
   cout<<endl;
   cout << "Logged Out Time :: " << ctime( & t);
   cout<<endl;
   fflush(stdin);
   getch();

   exit(0);
}


//module to check whether the entered account is in the database or not
int ca(int a) {
   record rec;
   //read binary
   ifstream f;
   f.open("record.bin", ios::in | ios::binary);
   while (!f.eof()) {
      f.read(reinterpret_cast < char * > ( & rec), sizeof(rec)); //whatever &rec is treat it as char *
      //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

      if (a == rec.account) {
         f.close();
         return 1;
      }
   }
   f.close();
   return 0;
}


int main() {
	
	
   cout << "\033[36m" ;// set color to red

   
   gikipay g;
   return 0;
   
   
    /*In this example, the escape sequence "\033[31m" sets the text color to red, and "\033[0m" resets the color to the default. 
  Note that not all terminals support these escape sequences, so it's a good idea to test your code in different environments.*/


}



















