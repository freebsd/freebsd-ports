--- helper/helper-candwin-gtk.c.orig	Sun Nov  9 02:26:21 2003
+++ helper/helper-candwin-gtk.c	Sun Nov  9 02:27:22 2003
@@ -160,10 +160,11 @@
 {
   int index;
   char idx[20];
+  GtkTreePath* path;
   sscanf(str[1],"%d",&index);
   cwin.candidate_index = index;
 
-  GtkTreePath* path = gtk_tree_path_new_from_indices(index, -1);
+  path = gtk_tree_path_new_from_indices(index, -1);
   gtk_tree_view_set_cursor(GTK_TREE_VIEW(m_view),
 			   path, NULL, FALSE);
   gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(m_view),
