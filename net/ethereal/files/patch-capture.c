--- capture.c.orig	Thu Jul 22 00:23:01 2004
+++ capture.c	Thu Jul 22 00:23:15 2004
@@ -126,7 +126,7 @@
  * XXX - the various BSDs appear to define BSD in <sys/param.h>; we don't
  * want to include it if it's not present on this platform, however.
  */
-#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && \
+#if !defined(__NetBSD__) && !defined(__OpenBSD__) && \
     !defined(__bsdi__) && !defined(__APPLE__) && !defined(_WIN32) && \
     !defined(__CYGWIN__)
 # define MUST_DO_SELECT
