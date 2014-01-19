--- makelist/args.c.orig
+++ makelist/args.c
@@ -1,6 +1,6 @@
-#include <strstream>
+#include <sstream>
 #include <iostream>
-#include <stdlib.h>
+#include <cstdlib>
 
 using namespace std;
 
@@ -35,7 +35,7 @@
     exit(-1);
 }    
 
-static void set_string_arg(strstream& ss, string& val) 
+static void set_string_arg(stringstream& ss, string& val) 
 {
     string argvalue;
     ss >> argvalue;
@@ -62,7 +62,7 @@
 
 static void process(const string& argline) 
 {
-    strstream ss;
+    stringstream ss;
     ss << argline;
 
     string arg;
