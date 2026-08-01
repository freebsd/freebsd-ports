Use the implementation from Darwin for tvh_usleep() and tvh_usleep_abs()
in FreeBSD.

Submitted by:	Bernhard Froehlich <decke@FreeBSD.org>
--- src/wrappers.c.orig	2026-05-19 20:37:17 UTC
+++ src/wrappers.c
@@ -171,7 +171,7 @@ tvh_usleep(int64_t us)
 int64_t
 tvh_usleep(int64_t us)
 {
-#if defined(PLATFORM_DARWIN)
+#if defined(PLATFORM_DARWIN) || defined(PLATFORM_FREEBSD)
   return usleep(us);
 #else
   struct timespec ts;
@@ -192,7 +192,7 @@ tvh_usleep_abs(int64_t us)
 int64_t
 tvh_usleep_abs(int64_t us)
 {
-#if defined(PLATFORM_DARWIN)
+#if defined(PLATFORM_DARWIN) || defined(PLATFORM_FREEBSD)
   /* Convert to relative wait */
   int64_t now = getmonoclock();
   int64_t relative = us - now;
