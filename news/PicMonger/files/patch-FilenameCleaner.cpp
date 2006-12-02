--- FilenameCleaner.cpp.orig	Tue Apr 11 12:01:47 2000
+++ FilenameCleaner.cpp	Fri Dec  1 22:46:08 2006
@@ -5,8 +5,11 @@
 #include "FileTypeState.h" // need enum FileTypes
 #include <ctype.h>	// need tolower()
 #include <strstream>
+#include <iostream>
 
 using std::strstream;
+using std::cerr;
+using std::endl;
 
 FilenameCleaner::FilenameCleaner()
 {
