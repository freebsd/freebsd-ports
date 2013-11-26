--- print_cb.cc.orig
+++ print_cb.cc
@@ -2,9 +2,9 @@
 /* Print LaTeX Module     */
 /* Last change 18.08.1996 */
 
-#include <iostream.h>
-#include <fstream.h>
-#include <string.h>
+#include <iostream>
+#include <fstream>
+#include <cstring>
 #include <X11/cursorfont.h>
 #include "globals.h"
 
@@ -13,18 +13,18 @@
   char          *filename;
   char          *db, *pdb;
   unsigned long n;
-  ofstream      out;
+  std::ofstream out;
   Cursor        uhr, pfeil;
 
   XmFileSelectionBoxCallbackStruct *cbs=
     (XmFileSelectionBoxCallbackStruct *) call_data;
 
   if (!XmStringGetLtoR(cbs->value, XmFONTLIST_DEFAULT_TAG, &filename)) {
-    cout << "Internal error pasting filename! \n";
+    std::cout << "Internal error pasting filename! \n";
     return;
   }
   if (!*filename) {
-    cout << "No file selected! \n";
+    std::cout << "No file selected! \n";
     XtFree(filename);
     return;
   }
@@ -37,7 +37,7 @@
 
   out.open(filename);
   if(!out) {
-    cout << "Cannot open LaTeX file for output! \n";
+    std::cout << "Cannot open LaTeX file for output! \n";
     return;
   }
