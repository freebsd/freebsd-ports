
$FreeBSD$

--- c_src/gtk2.h.orig	Tue Nov  4 13:25:21 2003
+++ c_src/gtk2.h	Tue Nov  4 13:25:36 2003
@@ -1008,7 +1008,7 @@
 gchar*  gtk_type_name (GtkType type) = g_type_name;
 
 /* NEW STUFF */
-typedef gpointer GtkClipboard;
+/*typedef gpointer GtkClipboard;*/
 
 
 /****************************************************************************
