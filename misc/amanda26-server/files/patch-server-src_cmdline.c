--- server-src/cmdline.c.orig	2011-06-25 22:50:58.000000000 +0200
+++ server-src/cmdline.c	2011-06-25 22:51:17.000000000 +0200
@@ -255,7 +255,7 @@
 	dumpfile_free_data(&file);
     }
 
-    g_slist_free_full(holding_files);
+    _slist_free_full(holding_files, g_free);
 
     return matching_files;
 }
