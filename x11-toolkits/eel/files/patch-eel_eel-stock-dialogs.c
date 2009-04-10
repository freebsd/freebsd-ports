--- eel/eel-stock-dialogs.c.orig	2008-10-07 11:34:27.000000000 +0200
+++ eel/eel-stock-dialogs.c	2009-02-22 16:33:40.000000000 +0100
@@ -96,6 +96,8 @@ timed_wait_delayed_close_timeout_callbac
 {
 	guint handler_id;
 
+	GDK_THREADS_ENTER ();
+
 	handler_id = GPOINTER_TO_UINT (g_object_get_data (G_OBJECT (callback_data),
 							  "eel-stock-dialogs/delayed_close_handler_timeout_id"));
 	
@@ -105,6 +107,8 @@ timed_wait_delayed_close_timeout_callbac
 	
 	gtk_object_destroy (GTK_OBJECT (callback_data));
 
+	GDK_THREADS_LEAVE ();
+
 	return FALSE;
 }
 
