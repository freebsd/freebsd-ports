--- config.h.orig	2015-02-13 06:11:21 UTC
+++ config.h
@@ -23,6 +23,13 @@
 #define STATEFILE "/var/log/logrotate.status"
 #endif
 
+#ifdef __FreeBSD__
+    #define DEFAULT_MAIL_COMMAND "/usr/bin/mailx"
+    #define COMPRESS_COMMAND "/usr/bin/gzip"
+    #define UNCOMPRESS_COMMAND "/usr/bin/gunzip"
+    #define STATEFILE "/var/run/logrotate.status"
+#endif
+
 /*
  * Default settings for Linux - leave these last.
  */
