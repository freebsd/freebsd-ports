--- spamass-milter.cpp.orig	Fri Aug 16 12:42:23 2002
+++ spamass-milter.cpp	Fri Aug 16 12:44:00 2002
@@ -83,6 +83,10 @@
 #include <string>
 #include <iostream>
 #include <fstream>
+using std::string;
+using std::cout;
+using std::cerr;
+using std::endl;
 
 #ifdef  __cplusplus
 extern "C" {
