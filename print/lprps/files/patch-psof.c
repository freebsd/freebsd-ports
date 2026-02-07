--- psof.c.orig	1993-02-22 21:46:11.000000000 +0900
+++ psof.c	2013-04-27 23:05:56.000000000 +0900
@@ -11,11 +11,14 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <strings.h>
 #include <signal.h>
 #include <syslog.h>
 #include <errno.h>
 #include <ctype.h>
+#include <unistd.h>
 
 #ifndef errno
 extern int errno;
@@ -216,7 +219,7 @@
     if ((status & 0xff) != 0) {
       int sig = status & 0x7f;
       if (sig < NSIG) {
-	extern char *sys_siglist[];
+	/* extern char *sys_siglist[]; */
 	syslog(LOG_ERR, "%s: %s%s", LPRPS, sys_siglist[sig],
 	       (status & 0x80) ? " (core dumped)" : "");
       }
