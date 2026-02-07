--- ./src/xradius_cache.c.orig	2005-04-27 08:49:25.000000000 +0200
+++ ./src/xradius_cache.c	2014-08-25 17:00:48.000000000 +0200
@@ -143,10 +143,17 @@
     /* Running as Root */
     if (geteuid() == 0)  {
         /* Allow the configured Apache use to read/write to the DBM */
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20111130
+        chown(path1, ap_unixd_config.user_id, -1);
+        if (path2 != NULL) { 
+            chown(path2, ap_unixd_config.user_id, -1);
+        }
+#else
         chown(path1, unixd_config.user_id, -1);
         if (path2 != NULL) { 
             chown(path2, unixd_config.user_id, -1);
         }
+#endif
     }
 #endif
     
