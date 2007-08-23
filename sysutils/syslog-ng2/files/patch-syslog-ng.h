--- src/syslog-ng.h.orig	Wed Aug 22 15:50:25 2007
+++ src/syslog-ng.h	Wed Aug 22 15:55:18 2007
@@ -38,11 +38,11 @@
 
 #if ENABLE_DEBUG
 #define PATH_SYSLOG_NG_CONF     "syslog-ng.conf"
-#define PATH_PIDFILE            "syslog-ng.pid"
+#define PATH_PIDFILE            "syslog.pid"
 #define PATH_PERSIST_CONFIG     "syslog-ng.persist"
 #else
 #define PATH_SYSLOG_NG_CONF     PATH_SYSCONFDIR "/syslog-ng.conf"
-#define PATH_PIDFILE            "/var/run/syslog-ng.pid"
+#define PATH_PIDFILE            "/var/run/syslog.pid"
 #define PATH_PERSIST_CONFIG     PATH_LOCALSTATEDIR "/syslog-ng.persist"
 #endif
 
