--- lib/cap/ablog.c.orig	Sat Aug 30 18:19:18 2003
+++ lib/cap/ablog.c	Sat Aug 30 18:25:05 2003
@@ -24,13 +24,14 @@
  *
 */
 
+#include <osreldate.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <netat/appletalk.h>
 
 #ifdef USEVPRINTF
-# include <varargs.h>
+# include <stdarg.h>
 #endif USEVPRINTF
 #ifdef USETIMES
 # include <time.h>
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
@@ -79,19 +85,16 @@
 char *fmt;
 #else USEVPRINTF
 /*VARARGS*/
-logit(va_alist)
-va_dcl
+logit(int level, char *fmt, ...)
 #endif USEVPRINTF
 {
   static char *mytod();
 #ifdef USEVPRINTF
-  register char *fmt;
   va_list args;
-  int level;
 #endif USEVPRINTF
   int saveerr;
   extern int errno;
-  extern int sys_nerr;
+  extern __const int sys_nerr;
 #ifndef __FreeBSD__
   extern char *sys_errlist[];
 #endif
@@ -101,9 +104,7 @@
 
   saveerr = errno;
 #ifdef USEVPRINTF
-  va_start(args);
-  level = va_arg(args, int);
-  fmt = va_arg(args, char *);
+  va_start(args, fmt);
 #endif USEVPRINTF
 
   if (dlevel < (level & L_LVL))
