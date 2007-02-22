Index: gtk/gtkfilechooserbutton.c
===================================================================
--- gtk/gtkfilechooserbutton.c	(revision 17341)
+++ gtk/gtkfilechooserbutton.c	(working copy)
@@ -1193,8 +1193,8 @@
 			       gpointer             user_data)
 {
   gboolean cancelled = handle->cancelled;
-  GdkPixbuf *pixbuf;
   struct ChangeIconThemeData *data = user_data;
+  GtkTreePath *path;
 
   if (!g_slist_find (data->button->priv->change_icon_theme_handles, handle))
     goto out;
@@ -1205,29 +1205,33 @@
   if (cancelled || error)
     goto out;
 
-  pixbuf = gtk_file_info_render_icon (info, GTK_WIDGET (data->button),
-				      data->button->priv->icon_size, NULL);
-
-  if (pixbuf)
+  path = gtk_tree_row_reference_get_path (data->row_ref);
+  if (path)
     {
-      gint width = 0;
-      GtkTreeIter iter;
-      GtkTreePath *path;
+      GdkPixbuf *pixbuf;
 
-      width = MAX (width, gdk_pixbuf_get_width (pixbuf));
+      pixbuf = gtk_file_info_render_icon (info, GTK_WIDGET (data->button),
+					  data->button->priv->icon_size, NULL);
+      if (pixbuf)
+	{
+	  gint width = 0;
+	  GtkTreeIter iter;
 
-      path = gtk_tree_row_reference_get_path (data->row_ref);
-      gtk_tree_model_get_iter (data->button->priv->model, &iter, path);
-      gtk_tree_path_free (path);
+	  width = MAX (width, gdk_pixbuf_get_width (pixbuf));
 
-      gtk_list_store_set (GTK_LIST_STORE (data->button->priv->model), &iter,
-			  ICON_COLUMN, pixbuf,
-			  -1);
-      g_object_unref (pixbuf);
+	  gtk_tree_model_get_iter (data->button->priv->model, &iter, path);
 
-      g_object_set (data->button->priv->icon_cell,
-		    "width", width,
-		    NULL);
+	  gtk_list_store_set (GTK_LIST_STORE (data->button->priv->model), &iter,
+			      ICON_COLUMN, pixbuf,
+			      -1);
+	  g_object_unref (pixbuf);
+
+	  g_object_set (data->button->priv->icon_cell,
+			"width", width,
+			NULL);
+	}
+
+      gtk_tree_path_free (path);
     }
 
 out:
