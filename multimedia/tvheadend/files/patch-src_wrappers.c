Use the implementation from Darwin for tvh_usleep() and tvh_usleep_abs()
in FreeBSD.

Submitted by:	Bernhard Froehlich <decke@FreeBSD.org>
--- src/wrappers.c.orig	2018-10-08 12:37:05.000000000 +0000
+++ src/wrappers.c	2018-10-16 14:27:38.788502000 +0000
@@ -324,7 +324,7 @@
 int64_t
 tvh_usleep(int64_t us)
 {
-#if defined(PLATFORM_DARWIN)
+#if defined(PLATFORM_DARWIN) || defined(PLATFORM_FREEBSD)
   return usleep(us);
 #else
   struct timespec ts;
@@ -345,7 +345,7 @@
 int64_t
 tvh_usleep_abs(int64_t us)
 {
-#if defined(PLATFORM_DARWIN)
+#if defined(PLATFORM_DARWIN) || defined(PLATFORM_FREEBSD)
   /* Convert to relative wait */
   int64_t now = getmonoclock();
   int64_t relative = us - now;
