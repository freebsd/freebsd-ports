--- eel/eel-gnome-extensions.c.orig	Mon Mar 21 06:20:58 2005
+++ eel/eel-gnome-extensions.c	Mon Mar 21 06:21:00 2005
@@ -246,7 +246,9 @@
 	IconSelectionData *selection_data;
 
 	selection_data = (IconSelectionData *) callback_data;
+	GDK_THREADS_ENTER ();
 	gtk_widget_destroy (selection_data->dialog);
+	GDK_THREADS_LEAVE ();
 	g_free (selection_data);	
 	return FALSE;
 }
