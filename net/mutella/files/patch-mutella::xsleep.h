--- mutella/xsleep.h.orig	Tue Dec  3 01:05:35 2002
+++ mutella/xsleep.h	Sun Jan  5 22:59:26 2003
@@ -64,7 +64,7 @@
 
 // Support dumb missing headers on OSX.
 #ifdef HAVE_NANOSLEEP
-#if defined HAVE_DECL_NANOSLEEP__ && !HAVE_DECL_NANOSLEEP__
+#if defined HAVE_DECL_NANOSLEEP__ && !HAVE_DECL_NANOSLEEP__ && !defined(__FreeBSD__)
 //#ifdef __APPLE__
 int nanosleep(struct timespec *, struct timespec *);
 #endif
