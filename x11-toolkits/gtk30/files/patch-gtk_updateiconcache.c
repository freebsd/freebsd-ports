--- gtk/updateiconcache.c.orig	2008-02-16 11:33:25.000000000 -0500
+++ gtk/updateiconcache.c	2008-02-16 11:33:33.000000000 -0500
@@ -1477,7 +1477,7 @@ build_cache (const gchar *path)
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
