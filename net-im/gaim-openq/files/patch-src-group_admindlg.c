--- src/group_admindlg.c.orig	Sat Oct  2 17:48:11 2004
+++ src/group_admindlg.c	Sat Oct 16 17:44:20 2004
@@ -133,6 +133,17 @@
 	GaimConnection *gc;
 	qun_info_window *info_window;
 
+	gint page, group_category, i = 0;
+	qq_group *group;
+	qq_data *qd;
+	GtkTextIter start, end;
+	GtkTreeModel *model;
+	GtkTreeIter iter;
+	GValue value = { 0, };
+	guint32 *new_members;
+	guint32 uid;
+	gboolean selected;
+
 	g_return_if_fail(data != NULL);
 	info_window = (qun_info_window *) data;
 
@@ -145,17 +156,6 @@
 //                        _("This version of GTK-2 does not support this function"), NULL);
 //        return;
 //#else
-	gint page, group_category, i = 0;
-	qq_group *group;
-	qq_data *qd;
-	GtkTextIter start, end;
-	GtkTreeModel *model;
-	GtkTreeIter iter;
-	GValue value = { 0, };
-	guint32 *new_members;
-	guint32 uid;
-	gboolean selected;
-
 	qd = (qq_data *) gc->proto_data;
 
 	// we assume the modification can succeed
@@ -253,6 +253,12 @@
 	GaimConnection *gc;
 	qq_group *group;
 
+	GtkTreeModel *model;
+	GtkTreeIter iter;
+	GtkTreePath *path;
+	gboolean selected;
+	guint32 uid;
+
 	info_window = (qun_info_window *) data;
 	g_return_if_fail(info_window != NULL);
 
@@ -262,11 +268,8 @@
 	group = qq_group_find_by_internal_group_id(gc, info_window->internal_group_id);
 	g_return_if_fail(group != NULL);
 
-	GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(info_window->tre_members));
-	GtkTreeIter iter;
-	GtkTreePath *path = gtk_tree_path_new_from_string(path_str);
-	gboolean selected;
-	guint32 uid;
+	model = gtk_tree_view_get_model(GTK_TREE_VIEW(info_window->tre_members));
+	path = gtk_tree_path_new_from_string(path_str);
 
 	gtk_tree_model_get_iter(model, &iter, path);
 	gtk_tree_model_get(model, &iter, COLUMN_SELECTED, &selected, -1);
