diff -ruN logrotate-3.7-orig/config.h logrotate-3.7/config.h
--- logrotate-3.7-orig/config.h	Mon Sep 22 21:11:12 2003
+++ logrotate-3.7/config.h	Mon May 24 08:05:29 2004
@@ -16,6 +16,13 @@
     #define STATEFILE "/var/log/logrotate.status"
 #endif
 
+#ifdef __FreeBSD__
+    #define DEFAULT_MAIL_COMMAND "/usr/bin/mailx -s"
+    #define COMPRESS_COMMAND "/usr/bin/gzip"
+    #define UNCOMPRESS_COMMAND "/usr/bin/gunzip"
+    #define STATEFILE "/var/lib/logrotate.status"
+#endif
+
 /*
  * Default settings for Linux - leave these last.
  */
