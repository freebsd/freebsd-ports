--- gnome/callbacks.c.orig	Fri Nov  7 21:08:34 2003
+++ gnome/callbacks.c	Fri Nov 21 12:57:20 2003
@@ -82,7 +82,7 @@
 on_user_manual1_activate               (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-	gnome_help_display("manual/index.html",NULL,NULL);
+	gnome_help_display("index.html",NULL,NULL);
 }
 
 
