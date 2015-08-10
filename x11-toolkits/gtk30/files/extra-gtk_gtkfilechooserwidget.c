--- gtk/gtkfilechooserwidget.c.orig	2015-08-10 13:02:47.225114000 +0200
+++ gtk/gtkfilechooserwidget.c	2015-08-10 13:03:58.007015000 +0200
@@ -1895,7 +1895,6 @@ file_list_set_sort_column_ids (GtkFileCh
 {
   GtkFileChooserWidgetPrivate *priv = impl->priv;
 
-  gtk_tree_view_set_search_column (GTK_TREE_VIEW (priv->browse_files_tree_view), -1);
 
   gtk_tree_view_column_set_sort_column_id (priv->list_name_column, MODEL_COL_NAME);
   gtk_tree_view_column_set_sort_column_id (priv->list_mtime_column, MODEL_COL_MTIME);
@@ -3468,6 +3467,7 @@ load_set_model (GtkFileChooserWidget *im
   gtk_tree_view_set_model (GTK_TREE_VIEW (priv->browse_files_tree_view),
 			   GTK_TREE_MODEL (priv->browse_files_model));
   gtk_tree_view_columns_autosize (GTK_TREE_VIEW (priv->browse_files_tree_view));
+  gtk_tree_view_set_search_column (GTK_TREE_VIEW (priv->browse_files_tree_view), MODEL_COL_NAME);
   file_list_set_sort_column_ids (impl);
   set_sort_column (impl);
   profile_msg ("    gtk_tree_view_set_model end", NULL);
