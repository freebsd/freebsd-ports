--- pfflowd.c.orig	Tue Sep  7 00:25:57 2004
+++ pfflowd.c	Wed Nov 10 13:46:53 2004
@@ -40,7 +40,11 @@
 #include <syslog.h>
 #include <time.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+#include "pidfile.h"
+#else
 #include <util.h>
+#endif
 #include <netdb.h>
 #include "pfflowd.h"
 
@@ -115,9 +119,7 @@
 /* Signal handlers */
 static void sighand_exit(int signum)
 {
-	struct syslog_data sd = SYSLOG_DATA_INIT;
-
-	syslog_r(LOG_INFO, &sd, "%s exiting on signal %d", PROGNAME, signum);
+	syslog(LOG_INFO, "%s exiting on signal %d", PROGNAME, signum);
 
 	_exit(0);
 }
