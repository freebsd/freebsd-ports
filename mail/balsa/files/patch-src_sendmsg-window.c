--- src/sendmsg-window.c.orig	Sun Jul 24 12:51:49 2005
+++ src/sendmsg-window.c	Sun Jul 24 12:52:57 2005
@@ -2009,7 +2009,7 @@ add_attachment(BalsaSendmsg * bsmsg, gch
 		       ATTACH_ICON_COLUMN, pixbuf,
 		       ATTACH_TYPE_COLUMN, content_type,
 		       ATTACH_MODE_COLUMN, attach_data->mode,
-		       ATTACH_SIZE_COLUMN, attach_stat.st_size,
+		       ATTACH_SIZE_COLUMN, (guint64) attach_stat.st_size,
 		       ATTACH_DESC_COLUMN, utf8name,
 		       -1);
     g_object_unref(attach_data);
@@ -2659,7 +2659,7 @@ render_attach_size(GtkTreeViewColumn *co
 		   GtkTreeModel *model, GtkTreeIter *iter, gpointer data)
 {
     gint mode;
-    gint size;
+    guint64 size;
     gchar *sstr;
 
     gtk_tree_model_get(model, iter, ATTACH_MODE_COLUMN, &mode,
@@ -2780,7 +2780,7 @@ create_info_pane(BalsaSendmsg * bsmsg, S
 			       GDK_TYPE_PIXBUF,
 			       G_TYPE_STRING,
 			       G_TYPE_INT,
-			       G_TYPE_INT,
+			       G_TYPE_UINT64,
 			       G_TYPE_STRING);
 
     bsmsg->attachments[1] = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
