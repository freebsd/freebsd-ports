$FreeBSD$

--- src/gtk--/editable.cc.orig	Sun Jun  9 11:15:59 2002
+++ src/gtk--/editable.cc	Sun Jun  9 11:16:09 2002
@@ -5,7 +5,7 @@
 namespace Gtk
 {
 
-  string Editable::get_chars (int start_pos = 0, int end_pos = - 1) const
+  string Editable::get_chars (int start_pos, int end_pos) const
   {
       gchar *chars = gtk_editable_get_chars (GTK_EDITABLE (gtkobj ()), start_pos, end_pos);
       string ret_val = chars;
