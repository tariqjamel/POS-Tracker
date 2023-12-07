#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

struct FileHandler{
    string toStore;
    string myText;

    vector<string> read(string fileName){
        vector<string> words;
        ifstream file;
        file.open(fileName);
        string word;
        while (file >> word){       // this operator >> sepate words on spaces in file.
            words.push_back(word); // these word are added in vector words.
        }
        return words;
    }

    void write(string fileName){
        ifstream readFile(fileName);

        vector<string> update;
        while (!readFile.eof()){ // adding words from file to vector.
            cin.ignore();
            getline(readFile, myText);
            update.push_back(myText);
        }
        string allString = "";
        for (auto stringVec : update){ // separate words in vector through spaces.
            allString = allString + " " + stringVec;
        }
        string fileWords = allString; // each word in file is separated.
        cout << "Write to store: ";
        getline(cin, toStore);
        fileWords = fileWords + " " + toStore; // new word is store with old words but not yet in file.

        ofstream writeFile(fileName);
        writeFile << fileWords; // all words are again stored back in the file.
    }
};

struct Find{
    void find(vector<string> var, string paragraph){
        istringstream iss(paragraph); // It divide the paragraph into different varible
        string s;                     //  istringstream to separate the paragraph into individual words.

        while (getline(iss, s, ' ')){  // paragraph is now iss and each word is storing to s.
            string word = s.c_str(); // c_str() divide the string in char but last char must be null
            if (count(var.begin(), var.end(), word)){
                cout << word << " ";
            }
        }
        cout << endl;
    }
};

class Verb{
public:
    vector<string> read(){
        FileHandler fileHandler;
        vector<string> verbs = fileHandler.read("verb.txt"); // sending file name to FileHandler struct
        return verbs;
    }
    void write(){
        FileHandler fileHandler;
        fileHandler.write("verb.txt");
    }
    void find(vector<string> verbs, string paragraph){
        cout << "Verb: ";
        Find find;
        find.find(verbs, paragraph);
    }
};

class Noun{
public:
    vector<string> read(){
        FileHandler fileHandler;
        vector<string> noun = fileHandler.read("noun.txt");
        return noun;
    }
    void write(){
        FileHandler fileHandler;
        fileHandler.write("noun.txt");
    }
    void find(vector<string> noun, string paragraph){
        cout << "noun: ";
        Find find;
        find.find(noun, paragraph);
    }
};

class Article{
public:
    vector<string> read(){
        FileHandler fileHandler;
        vector<string> article = fileHandler.read("article.txt");
        return article;
    }
    void write(){
        FileHandler fileHandler;
        fileHandler.write("article.txt");
    }
    void find(vector<string> article, string paragraph){
        cout << "Article: ";
        Find find;
        find.find(article, paragraph);
    }
};

class Pronoun{
public:
    vector<string> read(){
        FileHandler fileHandler;
        vector<string> pronoun = fileHandler.read("pronoun.txt");
        return pronoun;
    }
    void write(){
        FileHandler fileHandler;
        fileHandler.write("pronoun.txt");
    }
    void find(vector<string> pronoun, string paragraph){
        cout << "Pronoun: ";
        Find find;
        find.find(pronoun, paragraph);
    }
};

class Preposition{
public:
    vector<string> read(){
        FileHandler fileHandler;
        vector<string> prep = fileHandler.read("preposition.txt");
        return prep;
    }
    void write(){
        FileHandler fileHandler;
        fileHandler.write("preposition.txt");
    }
    void find(vector<string> prep, string paragraph){
        cout << "Preposition: ";
        Find find;
        find.find(prep, paragraph);
    }
};

int main(){
    char cont;
    do{
        Verb verb;
        Noun noun;
        Article article;
        Pronoun pronoun;
        Preposition prep;

        vector<string> verbs = verb.read();
        vector<string> nouns = noun.read();
        vector<string> articles = article.read();
        vector<string> pronouns = pronoun.read();
        vector<string> preps = prep.read();

        char option;
        cout << "For updating, enter 'u'. For finding enter 'f': ";
        cin >> option;

        if (option == 'u'){
            char addOpt;
            cout << "For Verb adding, Press 'v'. For noun adding, Press 'n': ";
            cin >> addOpt;
            if (addOpt == 'v'){
                verb.write();
            } else if (addOpt == 'n'){
                noun.write();
            } else{
                cout << "invalid.";
            }
        } else if (option == 'f'){
            string paragraph;
            cout << "Enter a paragraph or word: ";
            cin.ignore();
            getline(cin, paragraph);

            verb.find(verbs, paragraph);
            noun.find(nouns, paragraph);
            article.find(articles, paragraph);
            pronoun.find(pronouns, paragraph);
            prep.find(preps, paragraph);
        } else{
            cout << "Invalid option.";
        }
        cout << endl
             << "To continue, press 'c': ";
        cin >> cont;
    } while (cont == 'c');
    
    return 0;
}
