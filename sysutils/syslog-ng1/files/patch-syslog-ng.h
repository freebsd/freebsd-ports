--- src/syslog-ng.h.orig	Fri Apr 26 02:43:54 2002
+++ src/syslog-ng.h	Wed Mar  5 12:08:02 2003
@@ -32,10 +32,10 @@
 
 #if WITH_DEBUG
 #define PATH_SYSLOG_NG_CONF     "syslog-ng.conf"
-#define PATH_PIDFILE            "syslog-ng.pid"
+#define PATH_PIDFILE            "syslog.pid"
 #else
 #define PATH_SYSLOG_NG_CONF     PATH_SYSCONFDIR "/syslog-ng.conf"
-#define PATH_PIDFILE            "/var/run/syslog-ng.pid"
+#define PATH_PIDFILE            "/var/run/syslog.pid"
 #endif
 
 #define ST_QUIT                 16
