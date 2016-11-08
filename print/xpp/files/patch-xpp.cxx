--- xpp.cxx.orig	2004-12-06 11:00:04.000000000 -0800
+++ xpp.cxx	2016-11-08 12:49:34.251265000 -0800
@@ -30,6 +30,7 @@
  * Include necessary headers...
  */
 
+#include <stdio.h>
 #include "xpp.h"
 
 #ifndef WIN32
@@ -48,7 +49,7 @@
  * Globals...
  */
 
-char	tempfile[1024];		/* Temporary file for printing from stdin */
+static char	*tempfile;	/* Temporary file for printing from stdin */
 
 /*
  *  Parse options and send files for printing.
@@ -651,7 +652,7 @@
 #endif
 #endif // !WIN32
 
-  temp = fopen(cupsTempFile(tempfile, sizeof(tempfile)), "w");
+  temp = fopen((tempfile = tmpnam(NULL)), "w");
 
   if (temp == NULL)
   {
@@ -2500,7 +2501,7 @@
     // Redraw the destination menu in the main window
 
     printerPack->parent()->redraw();
-    printerPack->draw();
+    printerPack->redraw();
   
   }
 
@@ -2674,7 +2675,7 @@
   // Redraw the destination menu in the main window
 
   printerPack->parent()->redraw();
-  printerPack->draw();
+  printerPack->redraw();
   
   return(dest_index);
 }
