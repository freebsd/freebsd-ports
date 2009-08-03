$FreeBSD$
--- log.c.orig	2007-08-22 23:04:30.000000000 +0200
+++ log.c	2009-08-01 22:08:01.000000000 +0200
@@ -26,6 +26,10 @@
 
 #include "ntpd.h"
 
+#ifndef LOG_NTP
+#define LOG_NTP	LOG_DAEMON
+#endif
+
 int	 debug;
 extern int debugsyslog;
 
@@ -39,7 +43,7 @@ log_init(int n_debug)
 	debug = n_debug;
 
 	if (!debug)
-		openlog(__progname, LOG_PID | LOG_NDELAY, LOG_DAEMON);
+		openlog(__progname, LOG_PID | LOG_NDELAY, LOG_NTP);
 
 	tzset();
 }
