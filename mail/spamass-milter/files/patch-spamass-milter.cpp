--- spamass-milter.cpp.orig	Thu Jun 26 18:10:44 2003
+++ spamass-milter.cpp	Wed Jul  2 14:12:25 2003
@@ -102,6 +102,10 @@
 #include <csignal>
 #include <string>
 #include <iostream>
+using std::string;
+using std::cout;
+using std::cerr;
+using std::endl;
 
 #ifdef  __cplusplus
 extern "C" {
