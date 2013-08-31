--- gtk/gtkmm/treeview.h.orig	2013-08-31 15:49:24.000000000 +0200
+++ gtk/gtkmm/treeview.h	2013-08-31 15:59:45.000000000 +0200
@@ -3,6 +3,7 @@
 #ifndef _GTKMM_TREEVIEW_H
 #define _GTKMM_TREEVIEW_H
 
+#include <cstdlib>
 #include <glibmm.h>
 
 /* $Id: treeview.hg,v 1.71 2004/06/03 09:38:35 murrayc Exp $ */
@@ -1296,7 +1297,7 @@
     
     //Convert the text to a number, using the same logic used by GtkCellRendererText when it stores numbers.
     char* pchEnd = 0;
-    ColumnType new_value = static_cast<ColumnType>( strtod(new_text.c_str(), &pchEnd) );
+    ColumnType new_value = static_cast<ColumnType>( std::strtod(new_text.c_str(), &pchEnd) );
 
     //Store the user's new text in the model:
     Gtk::TreeRow row = *iter;
