--- src/apachetop.h.orig	Tue Dec 30 01:03:05 2003
+++ src/apachetop.h	Tue Dec 30 01:03:32 2003
@@ -190,7 +190,7 @@
 #define DEBUG_OUTPUT "/tmp/atop.debug"
 
 #ifndef DEFAULT_LOGFILE
-# define DEFAULT_LOGFILE "/var/httpd/apache_log"
+# define DEFAULT_LOGFILE "/var/log/httpd-access.log"
 #endif
 #define DEFAULT_CIRCLE_SIZE 30
 #define DEFAULT_CIRCLE_MODE TIMED_CIRCLE
