Add support for the GTK3 bookmarks file (bug #10627)

--- ./thunar/thunar-shortcuts-model.c.orig	2013-05-05 16:37:23.000000000 +0000
+++ ./thunar/thunar-shortcuts-model.c	2014-07-26 15:25:27.000000000 +0000
@@ -1364,6 +1364,7 @@
   gchar          *uri;
   GList          *lp;
   GError         *err = NULL;
+  GFile          *parent = NULL;
 
   _thunar_return_if_fail (THUNAR_IS_SHORTCUTS_MODEL (model));
 
@@ -1389,6 +1390,22 @@
         }
     }
 
+  /* create folder if it does not exist */
+  parent = g_file_get_parent (model->bookmarks_file);
+  if (!g_file_make_directory_with_parents (parent, NULL, &err))
+    {
+       if (g_error_matches (err, G_IO_ERROR, G_IO_ERROR_EXISTS))
+         {
+           g_clear_error (&err);
+         }
+       else
+         {
+           g_warning ("Failed to create bookmarks folder: %s", err->message);
+           g_error_free (err);
+         }
+    }
+  g_clear_object (&parent);
+
   /* write data to the disk */
   bookmarks_path = g_file_get_path (model->bookmarks_file);
   if (!g_file_set_contents (bookmarks_path, contents->str, contents->len, &err))
