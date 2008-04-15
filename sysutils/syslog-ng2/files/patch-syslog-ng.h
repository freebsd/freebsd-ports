--- src/syslog-ng.h.orig	Thu Apr  3 15:18:31 2008
+++ src/syslog-ng.h	Thu Apr  3 15:17:05 2008
@@ -37,7 +37,7 @@
 #include <glib.h>
 
 #define PATH_SYSLOG_NG_CONF     PATH_SYSCONFDIR "/syslog-ng.conf"
-#define PATH_PIDFILE            "/var/run/syslog-ng.pid"
+#define PATH_PIDFILE            "/var/run/syslog.pid"
 #define PATH_PERSIST_CONFIG     PATH_LOCALSTATEDIR "/syslog-ng.persist"
 
 #define LOG_PRIORITY_LISTEN 0
