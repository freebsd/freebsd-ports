--- src/settings_icons.c.orig	Thu Nov 24 23:44:55 2005
+++ src/settings_icons.c	Thu Nov 24 23:47:11 2005
@@ -53,6 +53,7 @@
 	GtkCellRenderer *renderer;
 	GtkTreeViewColumn *column;
 	GtkTreeSelection *select;
+	GtkTreeIter iter;
 
 	tv = glade_xml_get_widget (glade, "icons_treeview");
 	if ((model = gtk_tree_view_get_model (GTK_TREE_VIEW (tv)))) {
@@ -98,7 +99,6 @@
 		foo_debug ("evil things happen!\n");
 	}
 	
-	GtkTreeIter iter;
 	gtk_list_store_append (store, &iter);
 	gtk_list_store_set (store, &iter,
 		0, _("Default icon set"),
@@ -152,6 +152,10 @@
 static void install_cb (GtkWidget *button, GtkListStore *store) {
 	GtkWidget *win;
 	gint response;
+	GtkFileFilter *filter;
+	gchar *filename;
+	KfJisp *jisp;
+	GtkTreeIter iter;
 
 #if GTK_CHECK_VERSION(2,4,0)
 	win = gtk_file_chooser_dialog_new (_("Select icon set file to open"),
@@ -160,7 +164,7 @@
 			GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
 			GTK_STOCK_OPEN, GTK_RESPONSE_OK,
 			NULL);
-	GtkFileFilter *filter = gtk_file_filter_new ();
+	filter = gtk_file_filter_new ();
 	gtk_file_filter_set_name (filter, _("Jabber icon sets"));
 	gtk_file_filter_add_pattern (filter, "*.jisp");
 	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (win), filter);
@@ -175,18 +179,15 @@
 	response = gtk_dialog_run (GTK_DIALOG (win));
 	if (response == GTK_RESPONSE_OK) {
 	#if GTK_CHECK_VERSION(2,4,0)
-		gchar *filename;
-		KfJisp *jisp;
 		filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (win));
 		jisp = kf_jisp_install (filename);
 		g_free (filename);
 	#else	
-		KfJisp *jisp = kf_jisp_install (
+		jisp = kf_jisp_install (
 				gtk_file_selection_get_filename (GTK_FILE_SELECTION (win)));
 	#endif
 		
 		if (jisp) {
-			GtkTreeIter iter;
 			gtk_list_store_append (store, &iter);
 			gtk_list_store_set (store, &iter,
 				0, jisp->name,
