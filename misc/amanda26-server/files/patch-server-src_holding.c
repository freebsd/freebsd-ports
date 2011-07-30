--- server-src/holding.c.orig	2011-06-25 22:51:58.000000000 +0200
+++ server-src/holding.c	2011-06-25 22:53:27.000000000 +0200
@@ -565,7 +565,7 @@
 	dumpfile_free_data(&file);
     }
 
-    if (file_list) g_slist_free_full(file_list);
+    if (file_list) _slist_free_full(file_list, g_free);
 
     return result_list;
 }
@@ -591,7 +591,7 @@
 	dumpfile_free_data(&dfile);
     }
 
-    g_slist_free_full(all_files);
+    _slist_free_full(all_files, g_free);
 
     return datestamps;
 }
