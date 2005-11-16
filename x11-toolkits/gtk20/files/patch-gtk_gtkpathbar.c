--- gtk/gtkpathbar.c.orig	Wed Nov 16 10:40:00 2005
+++ gtk/gtkpathbar.c	Wed Nov 16 10:41:05 2005
@@ -933,6 +933,7 @@
   GtkPathBar *path_bar;
   GList *button_list;
   gboolean child_is_hidden;
+  GtkFilePath *child_path;
 
   button_data = BUTTON_DATA (data);
   if (button_data->ignore_changes)
@@ -945,7 +946,6 @@
 
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button), TRUE);
 
-  GtkFilePath *child_path;
   if (button_list->prev)
     {
       ButtonData *child_data;
