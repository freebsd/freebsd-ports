diff -ruN config.h config.h
--- logrotate-3.6.5/config.h	Sat Aug  3 11:47:41 2002
+++ logrotate-3.6.5/config.h	Wed Mar 17 12:50:04 2004
@@ -18,7 +18,7 @@
 #endif
 
 #ifndef COMPRESS_COMMAND
-    #define COMPRESS_COMMAND "/bin/gzip"
+    #define COMPRESS_COMMAND "/usr/bin/gzip"
 #endif
 
 #ifndef COMPRESS_OPTIONS
@@ -30,10 +30,10 @@
 #endif
 
 #ifndef UNCOMPRESS_COMMAND
-    #define UNCOMPRESS_COMMAND "/bin/gunzip"
+    #define UNCOMPRESS_COMMAND "/usr/bin/gunzip"
 #endif
 
 #ifndef STATEFILE
-    #define STATEFILE "/var/lib/logrotate/status"
+    #define STATEFILE "/var/lib/logrotate.status"
 #endif
