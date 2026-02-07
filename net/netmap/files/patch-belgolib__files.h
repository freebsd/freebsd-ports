--- belgolib/files.h.orig	Sun Dec 15 14:54:27 2002
+++ belgolib/files.h	Sun Dec 15 14:54:27 2002
@@ -1,4 +1,5 @@
 #include <fstream>
+using namespace std;
 
 #ifndef __make_dep__
 #include <string>  //makedepend bug
@@ -15,8 +16,8 @@
 class Infile : public ifstream  {
 public:
     Infile();
-    Infile(const string &, int mode=ios::in, bool=false);
-    int Open(const string &, int mode=ios::in, bool=false);
+    Infile(const string &, ios::openmode mode=ios::in, bool=false);
+    int Open(const string &, ios::openmode mode=ios::in, bool=false);
 
 protected:
     int check_open() const;
