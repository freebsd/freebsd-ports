--- lib/cap/ablog.c.orig	Thu Jan 23 01:45:08 2003
+++ lib/cap/ablog.c	Thu Jan 23 03:14:28 2003
@@ -66,8 +66,17 @@
  * This is something all machine should, but don't have :-)
  */
 
-static FILE *lfp = stderr;
+#define GCC_VERSION (__GNUC__ * 10000 \
+			       + __GNUC_MINOR__ * 100 \
+			       + __GNUC_PATCHLEVEL__)
 
+#if GCC_VERSION <= 30200
+static FILE *lfp = stderr;
+#else
+static FILE *lfp;
+static void lfp_construct (void) __attribute__((constructor));
+static void lfp_construct (void) { lfp = stderr; }
+#endif
 
 #ifndef USEVPRINTF
 /* Bletch - gotta do it because pyramids don't work the other way */
@@ -91,7 +100,7 @@
 #endif USEVPRINTF
   int saveerr;
   extern int errno;
-  extern int sys_nerr;
+  extern __const int sys_nerr;
 #ifndef __FreeBSD__
   extern char *sys_errlist[];
 #endif
@@ -164,7 +173,7 @@
 static char *
 mytod()
 {
-  long tloc;
+  time_t tloc;
   struct tm *tm, *localtime();
   static char buf[100];		/* should be large enough */
 
