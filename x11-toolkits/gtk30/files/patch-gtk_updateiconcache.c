--- gtk/updateiconcache.c.orig	2009-05-11 18:05:35.000000000 +0200
+++ gtk/updateiconcache.c	2009-05-30 12:03:39.000000000 +0200
@@ -1505,7 +1505,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
