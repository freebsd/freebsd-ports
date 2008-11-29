--- xfburn/xfburn-data-composition.c.orig	2008-09-14 04:41:53.000000000 -0400
+++ xfburn/xfburn-data-composition.c	2008-11-16 19:57:03.000000000 -0500
@@ -1099,6 +1099,7 @@
                           DATA_COMPOSITION_COLUMN_ICON, icon_directory,
                           DATA_COMPOSITION_COLUMN_CONTENT, name,
                           DATA_COMPOSITION_COLUMN_TYPE, DATA_COMPOSITION_TYPE_DIRECTORY, 
+                          DATA_COMPOSITION_COLUMN_PATH, path,
                           DATA_COMPOSITION_COLUMN_SIZE, (guint64) 4, -1);
       xfburn_disc_usage_add_size (XFBURN_DISC_USAGE (priv->disc_usage), (guint64) 4);
       gdk_threads_leave ();
@@ -1742,10 +1743,7 @@
       gtk_tree_model_get (model, iter, DATA_COMPOSITION_COLUMN_TYPE, &type,
 			  DATA_COMPOSITION_COLUMN_CONTENT, &name, DATA_COMPOSITION_COLUMN_PATH, &src, -1);
 
-      if (type == DATA_COMPOSITION_TYPE_DIRECTORY)
-        r = iso_tree_add_new_dir (parent, name, &dir);
-      else
-        r = iso_tree_add_node (image, parent, src, &node);
+      r = iso_tree_add_node (image, parent, src, &node);
 
       if (r < 0) {
         if (r == ISO_NULL_POINTER)
@@ -1758,9 +1756,11 @@
           g_error ("Failed adding %s as a node to the image: code %d!", src, r);
       }
 
-      /* FIXME: do we need to call iso_node_ref on node? Probably not... */
+      /* why was this called again? iso_tree_add_node seems to do
+       * a good job setting the name by itself.
       if (type != DATA_COMPOSITION_TYPE_DIRECTORY)
         iso_node_set_name (node, name);
+      */
 
       g_free (name);
       g_free (src);
@@ -1768,10 +1768,9 @@
       if (type == DATA_COMPOSITION_TYPE_DIRECTORY && gtk_tree_model_iter_has_child (model, iter)) {
 	GtkTreeIter child;
 
-        /* FIXME: this should not cause a sigfault... 
         if (iso_node_get_type(node) != LIBISO_DIR)
             g_error ("Expected %s to be a directory, but it isn't...\n", src);
-        */
+        dir = (IsoDir *)node;
 
 	gtk_tree_model_iter_children (model, &child, iter);
 	fill_image_with_composition (model, image, dir, &child);
