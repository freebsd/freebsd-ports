--- src/support.c.orig	Wed Mar  2 13:09:43 2005
+++ src/support.c	Thu Mar  3 20:05:51 2005
@@ -507,8 +507,9 @@
 void gtk_treeview_get_header_index (GtkWidget *tv, GtkWidget *header,
                                            gint *column_index, gint *columns)
 {
+	GList *list;
 	*column_index = *columns = 0;
-	GList *list = gtk_tree_view_get_columns (GTK_TREE_VIEW (tv));
+        list = gtk_tree_view_get_columns (GTK_TREE_VIEW (tv));
 
 	do
 	{
@@ -627,16 +628,17 @@
                 int x, int y, int width, int height,
                 GdkColor *left_color, GdkColor *right_color)
 {
+	int i;
+        GdkColor col;
+        int dr, dg, db;
+        GdkGCValues old_values;
+
 	if ( left_color == NULL || right_color == NULL )
 	{
 		gdk_draw_rectangle (drawable, gc, TRUE, x, y, width, height);
 		return;
 	}
 
-	int i;
-	GdkColor col;
-	int dr, dg, db;
-	GdkGCValues old_values;
 
 	gdk_gc_get_values (gc, &old_values);
 	
