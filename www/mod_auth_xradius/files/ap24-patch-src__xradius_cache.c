--- ./src/xradius_cache.c.orig	2005-04-27 08:49:25.000000000 +0200
+++ ./src/xradius_cache.c	2014-08-12 11:56:22.000000000 +0200
@@ -143,9 +143,9 @@
     /* Running as Root */
     if (geteuid() == 0)  {
         /* Allow the configured Apache use to read/write to the DBM */
-        chown(path1, unixd_config.user_id, -1);
+        chown(path1, ap_unixd_config.user_id, -1);
         if (path2 != NULL) { 
-            chown(path2, unixd_config.user_id, -1);
+            chown(path2, ap_unixd_config.user_id, -1);
         }
     }
 #endif
