--- beep/util.c.orig	Fri Nov 14 05:06:54 2003
+++ beep/util.c	Fri Nov 14 05:21:01 2003
@@ -707,9 +707,11 @@
 
 static void filebrowser_add_files(gchar** files, GtkFileSelection * filesel)
 {
+	int ctr = 0;
+	char * ptr;
+	
 	if (GTK_IS_WIDGET(mainwin_jtf)) gtk_widget_set_sensitive(mainwin_jtf,FALSE);
 
-	int ctr = 0;
 	while(files[ctr] != NULL) {
 		playlist_add(files[ctr++]);
 	}
@@ -717,7 +719,6 @@
 
 	if (GTK_IS_WIDGET(mainwin_jtf)) gtk_widget_set_sensitive(mainwin_jtf,TRUE);
 
-	char * ptr;
 	gtk_label_get(GTK_LABEL(GTK_BIN(filesel->history_pulldown)->child), &ptr);
 
 	/* This will give an extra slash if the current dir is the root. */
@@ -726,19 +727,23 @@
 
 static void filebrowser_ok(GtkWidget * w, GtkWidget * filesel)
 {
+	gchar** files;
+	
 	if (util_filebrowser_is_dir(GTK_FILE_SELECTION(filesel)))
  		return;
-	gchar** files = gtk_file_selection_get_selections(GTK_FILE_SELECTION(filesel));
+	files = gtk_file_selection_get_selections(GTK_FILE_SELECTION(filesel));
 	filebrowser_add_files(files,GTK_FILE_SELECTION(filesel));
 	gtk_widget_destroy(filesel);
 }
 
 static void filebrowser_play(GtkWidget * w, GtkWidget * filesel)
 {
+	gchar** files;
+	
 	if (util_filebrowser_is_dir(GTK_FILE_SELECTION(GTK_FILE_SELECTION(filesel))))
 		return;
 	playlist_clear();
-	gchar** files = gtk_file_selection_get_selections(GTK_FILE_SELECTION(filesel));
+	files = gtk_file_selection_get_selections(GTK_FILE_SELECTION(filesel));
 	filebrowser_add_files(files,GTK_FILE_SELECTION(filesel));
 	gtk_widget_destroy(filesel);
 	playlist_play();
@@ -746,8 +751,10 @@
 
 static void filebrowser_add_selected_files(GtkWidget * w, gpointer data)
 {
+	gchar** files;
+	
 	GtkFileSelection *filesel = GTK_FILE_SELECTION(data);
-	gchar** files = gtk_file_selection_get_selections(filesel);
+	files = gtk_file_selection_get_selections(filesel);
 
 	filebrowser_add_files(files,filesel);
 	gtk_tree_selection_unselect_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(filesel->file_list)));
@@ -758,10 +765,12 @@
 
 static void filebrowser_add_all_files(GtkWidget * w, gpointer data)
 {
+	gchar** files;
 	GtkFileSelection * filesel;
+	
 	filesel = data;
 	gtk_tree_selection_select_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(filesel->file_list)));
-	gchar** files = gtk_file_selection_get_selections(filesel);
+	files = gtk_file_selection_get_selections(filesel);
 	filebrowser_add_files(files,filesel);
 	gtk_tree_selection_unselect_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(filesel->file_list)));
 	gtk_entry_set_text(GTK_ENTRY(filesel->selection_entry), "");
