--- ./classes/include/ArtsAttribute.hh.orig	Mon Oct  2 13:05:14 2000
+++ ./classes/include/ArtsAttribute.hh	Wed Sep 25 16:38:10 2002
@@ -44,6 +44,7 @@
 #define _ARTSATTRIBUTE_HH_
 
 extern "C" {
+#include "artslocal.h"
 #include <sys/types.h>
 #include <assert.h>
   
@@ -51,7 +52,13 @@
 }
 
 #include <string>
-#include <istream.h>
+
+#ifdef HAVE_IOSTREAM
+# include <iostream>
+using namespace std;
+#else
+# include <istream.h>
+#endif
 
 //---------------------------------------------------------------------------
 //                 Object Attribute Identifiers               
