--- CimXml.h.orig	2013-03-25 04:05:49 UTC
+++ CimXml.h
@@ -54,7 +54,7 @@ class StringArray : public vector<string> {
    StringArray() : vector<string>() {}
    StringArray(int n) : vector<string>(n) {}
    StringArray(int n, const string& s) : vector<string>(n,s) {}
-   void add(const string& t) { push_back(t); }
+   void add(const string& t) { this->push_back(t); }
    void toStringBuffer(string &sb, const char *sep=" ",const char *q="") {
      for (size_type n=0; n<size(); n++) {
        sb = sb + (*this).at(n) + q;
