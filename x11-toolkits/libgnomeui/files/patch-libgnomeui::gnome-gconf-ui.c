--- libgnomeui/gnome-gconf-ui.c.orig	Sun Mar 20 20:38:41 2005
+++ libgnomeui/gnome-gconf-ui.c	Sun Mar 20 20:39:51 2005
@@ -148,6 +148,8 @@
         g_return_val_if_fail(eid.client != NULL, FALSE);
         g_return_val_if_fail(pending_errors != NULL, FALSE);
 
+        GDK_THREADS_ENTER();
+
         if (current_dialog == NULL) {
                 GtkWidget *dialog;
                 gboolean have_overridden = FALSE;
@@ -245,6 +247,8 @@
 
         gtk_window_present (GTK_WINDOW (current_dialog));
         
+        GDK_THREADS_LEAVE();
+
         return FALSE;
 }
 
