--- fxstrings.cpp.orig	Sat Jul  6 18:36:20 2002
+++ fxstrings.cpp	Thu Aug  5 15:17:58 2004
@@ -3,12 +3,14 @@
  * $Id: fxstrings.cpp,v 1.3 2002/01/19 19:23:50 fx Exp $
  */
 
-#include <iostream.h>
+#include <iostream>
 #include <string.h>
 #include <stdlib.h>
 
 #include "fxstrings.h"
 
+using namespace std;
+
 /* Initializes the protected variables */
 String::String(void) {
     str=NULL;
@@ -58,7 +60,7 @@
     if ((str=(char*)malloc(strlen(s)+1))==NULL) {
 #ifdef _DEBUG
 		cerr << "String::set(): malloc failed\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExMalloc();
     }
     memset(str,0,strlen(s)+1);
@@ -79,7 +81,7 @@
 	if ((p=(char *)malloc(length+1))==NULL) {
 #ifdef _DEBUG
 		cerr << "String::set(char,len): malloc failed\n" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExMalloc();
 	}
 
@@ -93,7 +95,7 @@
     if ((str=(char*)malloc(strlen(p)+1))==NULL) {
 #ifdef _DEBUG
 		cerr << "String::set(char,len): malloc failed\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExMalloc();
     }
     memset(str,0,strlen(p)+1);
