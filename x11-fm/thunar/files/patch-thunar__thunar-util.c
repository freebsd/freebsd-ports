Add support for the GTK3 bookmarks file (bug #10627)

--- ./thunar/thunar-util.c.orig	2013-05-05 16:37:23.000000000 +0000
+++ ./thunar/thunar-util.c	2014-07-26 15:25:35.000000000 +0000
@@ -84,6 +84,15 @@
 
   /* append the GTK+ bookmarks (if any) */
   fp = fopen (bookmarks_path, "r");
+  g_free (bookmarks_path);
+
+  if (G_UNLIKELY (fp == NULL))
+    {
+      bookmarks_path = g_build_filename (g_get_home_dir (), ".gtk-bookmarks", NULL);
+      fp = fopen(bookmarks_path, "r");
+      g_free(bookmarks_path);
+    }
+
   if (G_LIKELY (fp != NULL))
     {
       while (fgets (line, sizeof (line), fp) != NULL)
@@ -119,7 +128,6 @@
       fclose (fp);
     }
 
-  g_free (bookmarks_path);
 }
 
 
