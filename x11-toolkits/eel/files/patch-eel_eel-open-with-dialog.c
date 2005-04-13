--- eel/eel-open-with-dialog.c.orig	Mon Mar 21 06:25:51 2005
+++ eel/eel-open-with-dialog.c	Mon Mar 21 06:39:29 2005
@@ -422,7 +422,7 @@
 	gtk_file_chooser_set_select_multiple (GTK_FILE_CHOOSER (chooser),
 					      FALSE);
 	gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (chooser),
-					     "/usr/bin");
+					     "%%X11BASE%%/bin");
 
 	gtk_widget_show (chooser);
 }
@@ -452,10 +452,13 @@
 	char         *file;
 	gboolean      long_operation;
 
+	GDK_THREADS_ENTER ();
+
 	long_operation = FALSE;
 	do {
 		if (!dialog->details->add_icon_paths) {
 			dialog->details->add_icons_idle_id = 0;
+			GDK_THREADS_LEAVE ();
 			return FALSE;
 		}
 
@@ -508,6 +511,8 @@
 	/* don't go back into the main loop if this wasn't very hard to do */
 	} while (!long_operation);
 
+	GDK_THREADS_LEAVE ();
+
 	return TRUE;
 }
 
@@ -575,6 +580,8 @@
 	GSList            *l;
 	const char        *prev_name;
 
+	GDK_THREADS_ENTER ();
+
 	/* create list store */
 	dialog->details->program_list_store = gtk_list_store_new (NUM_COLUMNS,
 								  GDK_TYPE_PIXBUF,
@@ -633,6 +640,8 @@
                                              NULL);
 					          
 	gtk_tree_view_append_column (GTK_TREE_VIEW (dialog->details->program_list), column);
+
+	GDK_THREADS_LEAVE ();
 
 	dialog->details->add_icon_paths = g_slist_reverse (dialog->details->add_icon_paths);
 
