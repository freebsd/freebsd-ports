--- eel/eel-open-with-dialog.c.orig	Mon Oct  4 00:30:27 2004
+++ eel/eel-open-with-dialog.c	Mon Oct  4 00:30:40 2004
@@ -380,7 +380,7 @@
 	gtk_file_chooser_set_select_multiple (GTK_FILE_CHOOSER (chooser),
 					      FALSE);
 	gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (chooser),
-					     "/usr/bin");
+					     "%%X11BASE%%/bin");
 
 	gtk_widget_show (chooser);
 }
