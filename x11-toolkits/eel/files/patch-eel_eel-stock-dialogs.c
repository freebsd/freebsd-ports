--- eel/eel-stock-dialogs.c.orig	Mon Mar 21 06:35:10 2005
+++ eel/eel-stock-dialogs.c	Mon Mar 21 06:36:23 2005
@@ -104,6 +104,8 @@
 {
 	guint handler_id;
 
+	GDK_THREADS_ENTER ();
+
 	handler_id = GPOINTER_TO_UINT (g_object_get_data (G_OBJECT (callback_data),
 							  "eel-stock-dialogs/delayed_close_handler_timeout_id"));
 	
@@ -113,6 +115,8 @@
 	
 	gtk_object_destroy (GTK_OBJECT (callback_data));
 
+	GDK_THREADS_LEAVE ();
+
 	return FALSE;
 }
 
@@ -202,7 +206,10 @@
 
 	wait = callback_data;
 
+	GDK_THREADS_ENTER ();
+
 	if (gnome_authentication_manager_dialog_is_visible ()) {
+		GDK_THREADS_LEAVE ();
 		return TRUE;
 	}
 	
@@ -249,6 +256,8 @@
 
 	wait->timeout_handler_id = 0;
 	wait->dialog = dialog;
+
+	GDK_THREADS_LEAVE ();
 	
 	return FALSE;
 }
