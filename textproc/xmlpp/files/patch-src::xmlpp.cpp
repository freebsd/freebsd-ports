--- ./src/xmlpp.cpp.orig	Wed Jul 23 04:12:52 2003
+++ ./src/xmlpp.cpp	Wed Jul 23 04:13:52 2003
@@ -21,6 +21,12 @@
 //debug
 #include <iostream>
 
+using std::cout;
+using std::cerr;
+using std::endl;
+using std::ifstream;
+using std::ofstream;
+
 namespace xmlpp {
 
 // internal use for saving
