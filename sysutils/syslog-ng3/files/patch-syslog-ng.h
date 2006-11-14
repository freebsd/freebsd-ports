--- src/syslog-ng.h.orig	Wed Nov  8 14:45:18 2006
+++ src/syslog-ng.h	Wed Nov  8 14:45:44 2006
@@ -38,10 +38,10 @@
 
 #if ENABLE_DEBUG
 #define PATH_SYSLOG_NG_CONF     "syslog-ng.conf"
-#define PATH_PIDFILE            "syslog-ng.pid"
+#define PATH_PIDFILE            "syslog.pid"
 #else
 #define PATH_SYSLOG_NG_CONF     PATH_SYSCONFDIR "/syslog-ng.conf"
-#define PATH_PIDFILE            "/var/run/syslog-ng.pid"
+#define PATH_PIDFILE            "/var/run/syslog.pid"
 #endif
 
 #define LOG_PRIORITY_LISTEN 100
