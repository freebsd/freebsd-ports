--- CimXml.h.orig	2009-06-24 17:44:48.000000000 +0000
+++ CimXml.h
@@ -54,7 +54,7 @@ class StringArray : public vector<string
    StringArray() : vector<string>() {}
    StringArray(int n) : vector<string>(n) {}
    StringArray(int n, const string& s) : vector<string>(n,s) {}
-   void add(const string& t) { push_back(t); }
+   void add(const string& t) { this->push_back(t); }
    void toStringBuffer(string &sb, const char *sep=" ",const char *q="") {
      for (size_type n=0; n<size(); n++) {
        sb = sb + (*this).at(n) + q;
@@ -129,10 +129,10 @@ template<class T> class ArrayXml : publi
   public:
    ArrayXml() {}
    ArrayXml<T> * clone() const { return new ArrayXml<T>(*this);}
-   void add(const T& t) { push_back(t); }
+   void add(const T& t) { this->push_back(t); }
 #if !defined(GCC_VERSION) || GCC_VERSION >= 3000
-   T& operator[] (size_type n) {return at(n);}
-   const T& operator[] (size_type n) const {return at(n);}
+   T& operator[] (size_type n) {return this->at(n);}
+   const T& operator[] (size_type n) const {return this->at(n);}
 #endif
    T *get(int n)    { return &(*this)[n]; }
    void toStringBuffer(string &sb, const char *sep=" ",const char *q="") {
