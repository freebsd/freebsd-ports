--- netmap/args.c.orig
+++ netmap/args.c
@@ -1,4 +1,4 @@
-#include <strstream>
+#include <sstream>
 #include <iostream>
 #include <string>
 
@@ -47,7 +47,7 @@
     exit(0);
 }
 
-static void set_string_arg(strstream& ss, string& val) 
+static void set_string_arg(stringstream& ss, string& val) 
 {
     string argvalue;
     ss >> argvalue;
@@ -60,7 +60,7 @@
 
 static void process(const string& argline) 
 {
-    strstream ss;
+    stringstream ss;
     ss << argline;
 
     string arg;
