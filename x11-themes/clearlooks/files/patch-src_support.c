--- src/support.c.orig	Sat Feb 19 06:50:22 2005
+++ src/support.c	Sun Feb 27 01:44:57 2005
@@ -503,8 +503,9 @@
 static void gtk_treeview_get_header_index (GtkWidget *tv, GtkWidget *header,
                                            gint *column_index, gint *columns)
 {
+	GList *list;
 	*column_index = *columns = 0;
-	GList *list = gtk_tree_view_get_columns (GTK_TREE_VIEW (tv));
+        list = gtk_tree_view_get_columns (GTK_TREE_VIEW (tv));
 
 	do
 	{
