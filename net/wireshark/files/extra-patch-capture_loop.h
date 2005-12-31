--- capture_loop.h.orig	Sat Dec 31 01:44:43 2005
+++ capture_loop.h	Sat Dec 31 01:45:19 2005
@@ -68,7 +68,7 @@ extern void capture_loop_stop(void);
  * XXX - the various BSDs appear to define BSD in <sys/param.h>; we don't
  * want to include it if it's not present on this platform, however.
  */
-#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && \
+#if !defined(__NetBSD__) && !defined(__OpenBSD__) && \
     !defined(__bsdi__) && !defined(__APPLE__) && !defined(_WIN32) && \
     !defined(__CYGWIN__)
 # define MUST_DO_SELECT
