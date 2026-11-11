--- aeron-client/src/main/c/util/aeron_clock.c.orig	2026-11-10 20:08:28 UTC
+++ aeron-client/src/main/c/util/aeron_clock.c
@@ -90,7 +90,7 @@ int aeron_clock_gettime_monotonic(struct timespec *tp)
 
 int aeron_clock_gettime_monotonic(struct timespec *tp)
 {
-#if defined(__CYGWIN__) || defined(__linux__)
+#if defined(__CYGWIN__) || defined(__linux__) || defined(__FreeBSD__)
     return clock_gettime(CLOCK_MONOTONIC, tp);
 #else
     return clock_gettime(CLOCK_MONOTONIC_RAW, tp);
