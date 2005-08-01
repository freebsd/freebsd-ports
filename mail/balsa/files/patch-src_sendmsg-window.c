--- src/sendmsg-window.c.orig	Fri Jun 24 04:36:25 2005
+++ src/sendmsg-window.c	Sun Jul 31 22:10:14 2005
@@ -2009,7 +2009,7 @@ add_attachment(BalsaSendmsg * bsmsg, gch
 		       ATTACH_ICON_COLUMN, pixbuf,
 		       ATTACH_TYPE_COLUMN, content_type,
 		       ATTACH_MODE_COLUMN, attach_data->mode,
-		       ATTACH_SIZE_COLUMN, attach_stat.st_size,
+		       ATTACH_SIZE_COLUMN, (glong) attach_stat.st_size,
 		       ATTACH_DESC_COLUMN, utf8name,
 		       -1);
     g_object_unref(attach_data);
@@ -2659,7 +2659,7 @@ render_attach_size(GtkTreeViewColumn *co
 		   GtkTreeModel *model, GtkTreeIter *iter, gpointer data)
 {
     gint mode;
-    gint size;
+    glong size;
     gchar *sstr;
 
     gtk_tree_model_get(model, iter, ATTACH_MODE_COLUMN, &mode,
@@ -2674,7 +2674,7 @@ render_attach_size(GtkTreeViewColumn *co
     else if (size > 1200)
 	sstr = g_strdup_printf("%.2fkB", (gfloat)size / (gfloat)1024);
     else
-	sstr = g_strdup_printf("%dB", size);
+	sstr = g_strdup_printf("%ldB", size);
     g_object_set(cell, "text", sstr, NULL);
 }
 
@@ -2780,7 +2780,7 @@ create_info_pane(BalsaSendmsg * bsmsg, S
 			       GDK_TYPE_PIXBUF,
 			       G_TYPE_STRING,
 			       G_TYPE_INT,
-			       G_TYPE_INT,
+			       G_TYPE_LONG,
 			       G_TYPE_STRING);
 
     bsmsg->attachments[1] = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
