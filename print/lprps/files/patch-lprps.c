--- lprps.c.orig	1993-02-22 21:46:10.000000000 +0900
+++ lprps.c	2013-04-27 23:00:32.000000000 +0900
@@ -5,7 +5,9 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
+#include <string.h>
 #include <strings.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
@@ -15,8 +17,13 @@
 #include <sys/time.h>
 #include <signal.h>
 #include <syslog.h>
+#include <unistd.h>
 #include <errno.h>
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+#include <sys/param.h>
+#endif
+
 #ifndef errno
 extern int errno;
 #endif
@@ -27,7 +34,13 @@
 #define VOLATILE /* as nothing */
 #endif
 
-#define SENDMAIL "/usr/lib/sendmail"
+#ifndef SENDMAIL
+#    if (defined(BSD) && (BSD >= 199103))
+#	define SENDMAIL "/usr/sbin/sendmail"
+#    else
+#	define SENDMAIL "/usr/lib/sendmail"
+#    endif
+#endif
 
 #define EXIT_SUCCESS 0
 #define EXIT_REPRINT 1
@@ -43,8 +56,6 @@
 char ctrl_d = '\004';
 char ctrl_t = '\024';
 
-char *malloc();
-
 /* user's login name */
 char *login = 0;
 /* user's host */
@@ -346,7 +357,9 @@
 char *strsignal(n)
 int n;
 {
+# if !(defined(BSD) && (BSD >= 199103))
   extern char *sys_siglist[];
+# endif
   static char buf[32];
   if (n >= 0 && n < NSIG)
     return sys_siglist[n];
