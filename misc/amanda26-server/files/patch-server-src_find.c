--- server-src/find.c.orig	2011-06-25 22:52:09.000000000 +0200
+++ server-src/find.c	2011-06-25 22:53:37.000000000 +0200
@@ -257,7 +257,7 @@
 	dumpfile_free_data(&file);
     }
 
-    g_slist_free_full(holding_file_list);
+    _slist_free_full(holding_file_list, g_free);
 }
 
 static char *
