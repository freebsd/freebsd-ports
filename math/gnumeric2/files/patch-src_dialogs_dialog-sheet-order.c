--- src/dialogs/dialog-sheet-order.c.orig	Thu Sep 25 14:22:18 2003
+++ src/dialogs/dialog-sheet-order.c	Thu Sep 25 14:25:48 2003
@@ -106,12 +106,12 @@
 static gint
 location_of_iter (GtkTreeIter  *iter, GtkListStore *model)
 {
+	gint loc;
 	/* Note: in gtk 2.2 we could just do: */
 /* 	gchar* path = gtk_tree_model_get_string_from_iter */
 /* 		(GTK_TREE_MODEL (model), iter); */
 
 	/* in gtk 2.0 we need: */
-	gint loc;
 	GtkTreePath *treepath = gtk_tree_model_get_path 
 		(GTK_TREE_MODEL (model), iter);
 	gchar* path = gtk_tree_path_to_string (treepath);
