--- gtkgui/SaveImageDialog.cc.orig	Tue Jul 22 16:24:13 2003
+++ gtkgui/SaveImageDialog.cc	Tue Jul 22 16:26:31 2003
@@ -23,9 +23,11 @@
  */
 
 
-#include <strstream.h>
+#include <strstream>
 
 #include "SaveImageDialog.h"
+
+using std::ostrstream;
 
 void SaveImageDialog::toggled_dither_method (GtkWidget *w, gpointer data)
 {
