--- lib/cap/ablog.c.orig	Mon Feb  3 01:16:00 2003
+++ lib/cap/ablog.c	Mon Feb  3 03:48:59 2003
@@ -24,6 +24,7 @@
  *
 */
 
+#include <osreldate.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/time.h>
@@ -66,8 +67,13 @@
  * This is something all machine should, but don't have :-)
  */
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 470000
 static FILE *lfp = stderr;
-
+#else
+static FILE *lfp;
+static void lfp_construct (void) __attribute__((constructor));
+static void lfp_construct (void) { lfp = stderr; }
+#endif
 
 #ifndef USEVPRINTF
 /* Bletch - gotta do it because pyramids don't work the other way */
@@ -91,7 +97,7 @@
 #endif USEVPRINTF
   int saveerr;
   extern int errno;
-  extern int sys_nerr;
+  extern __const int sys_nerr;
 #ifndef __FreeBSD__
   extern char *sys_errlist[];
 #endif
