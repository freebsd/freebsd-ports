diff -ruN logrotate-3.7.7-orig/config.h logrotate-3.7.7/config.h
--- logrotate-3.7.7-orig/config.h	Sat Nov 12 19:07:56 2005
+++ logrotate-3.7.7/config.h	Sun Jun 22 22:02:29 2008
@@ -16,6 +16,13 @@
 #define STATEFILE "/var/log/logrotate.status"
 #endif
 
+#ifdef __FreeBSD__
+    #define DEFAULT_MAIL_COMMAND "/usr/bin/mailx -s"
+    #define COMPRESS_COMMAND "/usr/bin/gzip"
+    #define UNCOMPRESS_COMMAND "/usr/bin/gunzip"
+    #define STATEFILE "/var/run/logrotate.status"
+#endif
+
 /*
  * Default settings for Linux - leave these last.
  */
