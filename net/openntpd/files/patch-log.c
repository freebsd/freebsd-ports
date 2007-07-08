
$FreeBSD$

--- log.c.orig
+++ log.c
@@ -28,6 +28,10 @@
 
 #include "ntpd.h"
 
+#ifndef LOG_NTP
+#define LOG_NTP	LOG_DAEMON
+#endif
+
 int	 debug;
 
 void	 logit(int, const char *, ...);
@@ -40,7 +44,7 @@
 	debug = n_debug;
 
 	if (!debug)
-		openlog(__progname, LOG_PID | LOG_NDELAY, LOG_DAEMON);
+		openlog(__progname, LOG_PID | LOG_NDELAY, LOG_NTP);
 
 	tzset();
 }
