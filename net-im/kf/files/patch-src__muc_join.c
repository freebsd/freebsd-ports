--- src/muc_join.c.orig	Thu Nov 24 23:39:22 2005
+++ src/muc_join.c	Thu Nov 24 23:40:29 2005
@@ -294,6 +294,9 @@
         GtkTreeIter iter;
         GtkTreeModel *model;
 	gint n_selected;
+	GList *list;
+	GtkTreePath *path;
+	KfPrefMUCBookmark *bookmark;
 	
 	n_selected = gtk_tree_selection_count_selected_rows (selection);
 	self->multiple = (n_selected > 1);
@@ -303,10 +306,9 @@
 		
 	if (n_selected == 1) {
 //		if (gtk_tree_selection_get_selected (selection, &model, &iter)) {
-		GList *list = gtk_tree_selection_get_selected_rows (selection, &model);
-		GtkTreePath *path = list->data;
+		list = gtk_tree_selection_get_selected_rows (selection, &model);
+		path = list->data;
 		gtk_tree_model_get_iter (model, &iter, path);
-		KfPrefMUCBookmark *bookmark;
 		gtk_tree_model_get (model, &iter, 0, &bookmark, -1);
 
 		if (bookmark->server)
