--- beep/dirbrowser.c.orig	Sat Feb  7 18:04:24 2004
+++ beep/dirbrowser.c	Sat Feb  7 18:18:23 2004
@@ -263,15 +263,17 @@
 static gchar *bmp_db_sanify_tag(gchar * value)
 {
 
-    if (!value)
-	return "(unknown)";
-
+	GString *chunk;
     gchar *frag = NULL;
     gchar **branches;
     guint ctr = 0;
     gboolean bracket_open = FALSE;
 
-    GString *chunk = g_string_new(NULL);
+    if (!value)
+             return "(unknown)";
+    
+
+    chunk = g_string_new(NULL);
     branches = g_strsplit(g_strstrip(value), " ", 0);
 
     while (frag || (ctr == 0)) {
@@ -346,6 +348,7 @@
     GList *list = NULL;
     gboolean first = TRUE;
     gchar *from_real;
+	GdkPixbuf *buf_dir, *buf_file, *buf_cda;
 
     from = g_locale_from_utf8(from, -1, NULL, NULL, NULL);
     from_real = bmp_db_get_path_real(from, model, &parent_iter);
@@ -353,18 +356,19 @@
     
     /* It's not really a waste creating both beforehand since we will
      * certainly need the folder one at least once, and most probably
-     * the audio one too anyway */
-    GdkPixbuf *buf_dir = gdk_pixbuf_new_from_inline(sizeof(folder_pixbuf),
+     * the audio one too anyway. 
+	*/
+    buf_dir = gdk_pixbuf_new_from_inline(sizeof(folder_pixbuf),
 						    folder_pixbuf,
 						    TRUE,
 						    NULL);
 
-    GdkPixbuf *buf_file = gdk_pixbuf_new_from_inline(sizeof(audio_pixbuf),
+    buf_file = gdk_pixbuf_new_from_inline(sizeof(audio_pixbuf),
 						     audio_pixbuf,
 						     TRUE,
 						     NULL);
 
-    GdkPixbuf *buf_cda = gdk_pixbuf_new_from_inline(sizeof(cda_pixbuf),
+    buf_cda = gdk_pixbuf_new_from_inline(sizeof(cda_pixbuf),
 						    cda_pixbuf,
 						    TRUE,
 						    NULL);
@@ -654,6 +658,7 @@
 
     GtkTreeModel *model;
     GtkTreeView *treeview;
+	GtkWidget *store;
 
     treeview = gtk_tree_selection_get_tree_view(sel);
     model = gtk_tree_view_get_model(treeview);
@@ -681,7 +686,7 @@
 	paths = paths->next;
     }
 
-    GtkWidget *store =
+    store =
 	GTK_WIDGET(bmp_db_return_filestore_model_fresh(paths_f));
 
     gtk_tree_view_set_model(user_data, GTK_TREE_MODEL(store));
@@ -706,6 +711,7 @@
 
     struct stat statbuf;
     GtkTreeModel *model;
+	gboolean valid;
 
     model = gtk_tree_view_get_model(treeview);
     paths = bmp_db_get_paths_from_selection(treeview);
@@ -735,7 +741,7 @@
 	    if (gtk_tree_model_iter_children(model, &iter_child, &iter)) {
 		if (click_play)
 		    playlist_clear();
-		gboolean valid = TRUE;
+		valid = TRUE;
 		while (valid) {
 		    gtk_tree_model_get(GTK_TREE_MODEL(model), &iter_child,
 				       FILENAME_COL, &node_name, -1);
@@ -1308,12 +1314,15 @@
 {
 
     GtkTreeStore *file_store;
-
+	GtkTreeModel *sort_model;
+	gdouble length_pl, frac;
+	int ctr=0;
+	GList *files;
 
     file_store =
 	gtk_tree_store_new(5, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_INT,
 			   G_TYPE_STRING, G_TYPE_INT);
-    GtkTreeModel *sort_model =
+    sort_model =
 	gtk_tree_model_sort_new_with_model(GTK_TREE_MODEL(file_store));
 
 
@@ -1321,17 +1330,16 @@
 					    bmp_db_mdb_sort_func, NULL, NULL);
 
 
-    gdouble length_pl = g_list_length(paths);
+    length_pl = g_list_length(paths);
     gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar_db), 0.0);
 
-    int ctr = 0;
 
     while (paths) {
 
 	gchar *path = paths->data;
 	ctr++;
 
-	GList *files = bmp_db_return_files_from_path(path);
+	files = bmp_db_return_files_from_path(path);
 
 	while (files) {
 	    gchar *title;
@@ -1356,7 +1364,7 @@
 	    files = files->next;
 	}
 
-	gdouble frac = 1 / length_pl;
+	frac = 1 / length_pl;
 	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar_db),
 				      frac * ctr);
 	while (gtk_events_pending()) {
@@ -1411,15 +1419,17 @@
     GtkWidget *treeview = NULL;
     GtkWidget *label_header;
     GtkWidget *paned;
+	GtkWidget *fstore;
+	GList *paths = NULL;
+	 PangoAttrList *attrs;
+	PangoAttribute *attr;
+	GtkTreeSelection *sel;
 
     if (!window) {
 
 	/* create window, etc */
 	/* yes this is all messed up */
 
-	PangoAttrList *attrs;
-	PangoAttribute *attr;
-
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_window_set_title(GTK_WINDOW(window), "bmp :: Add Files...");
 	gtk_container_set_border_width(GTK_CONTAINER(window), 8);
@@ -1489,17 +1499,15 @@
 			 G_CALLBACK(bmp_db_keypress), window);
 
 	gtk_container_add(GTK_CONTAINER(sw), treeview);
-	GtkWidget *fstore;
 
 	/* FIXME: clean up variables, move them to start */
 
 	/* FIXME: paths is not freed, and is resetted every iteration */
-	GList *paths = NULL;
 	paths = g_list_append(paths, g_strdup(g_get_home_dir()));
 	fstore = bmp_db_return_filestore_fresh(paths);
 	gtk_container_add(GTK_CONTAINER(sw_right), fstore);
 
-	GtkTreeSelection *sel =
+	sel =
 	    gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
 	g_signal_connect(G_OBJECT(sel), "changed",
 			 G_CALLBACK(bmp_db_row_activated), fstore);
