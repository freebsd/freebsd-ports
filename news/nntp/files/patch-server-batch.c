--- server/batch.c.orig	Fri Dec  9 03:52:44 1994
+++ server/batch.c	Mon Sep  6 12:25:18 2004
@@ -20,18 +20,22 @@
 */
 #include "common.h"
 #include <signal.h>
+#ifndef __FreeBSD__
 #ifdef sparc
 #ifndef SVR4
 #include <vfork.h>
 #endif
 #endif
+#endif
 #ifdef BATCHED_INPUT
 #define YES 1
 #define NO 0
 
 /* imports */
 extern time_t time();
+#ifndef __FreeBSD__
 extern char *malloc(), *mktemp(), *index(), *rindex();
+#endif
 /* forwards */
 static char *strsave();
 #ifdef XFER_TIMEOUT
