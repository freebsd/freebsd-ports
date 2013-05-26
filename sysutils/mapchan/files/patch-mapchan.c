--- mapchan.c.orig	2008-09-12 01:47:59.000000000 +0500
+++ mapchan.c	2013-05-26 14:55:43.000000000 +0400
@@ -15,7 +15,12 @@
 #include <stdlib.h>
 #include <signal.h>
 #include <libgen.h>
+#ifdef __FreeBSD__
+#include <libutil.h>
+#include <sys/ioctl.h>
+#else
 #include <pty.h>
+#endif
 #include <utmp.h>
 #ifdef SYSLOG
 #include <syslog.h>
@@ -50,7 +55,7 @@ char *DEFAULT_LOGFILE = "mapchan.log";
 #endif
 
 #ifndef CPATH
-  #define CPATH "/etc/mapchan"
+  #define CPATH "/usr/local/etc/mapchan"
 #endif
 
 #define BUFSIZE 32*1024
