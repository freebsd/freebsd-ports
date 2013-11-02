--- ./src/be13_api/sbuf.h.orig	2013-08-19 18:54:59.000000000 +0000
+++ ./src/be13_api/sbuf.h	2013-10-19 13:09:32.000000000 +0000
@@ -61,7 +61,7 @@
  * in a 64-bit number.  
  */
 
-inline int stoi(std::string str){
+inline int be13stoi(std::string str){
     std::istringstream ss(str);
     int val(0);
     ss >> val;
