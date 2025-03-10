--- aeron-client/src/main/c/util/aeron_clock.c.orig	2024-12-10 01:20:47 UTC
+++ aeron-client/src/main/c/util/aeron_clock.c
@@ -87,7 +87,7 @@ int aeron_clock_gettime_monotonic(struct timespec *tp)
 
 int aeron_clock_gettime_monotonic(struct timespec *tp)
 {
-#if defined(__CYGWIN__) || defined(__linux__)
+#if defined(__CYGWIN__) || defined(__linux__) | defined(__FreeBSD__)
     return clock_gettime(CLOCK_MONOTONIC, tp);
 #else
     return clock_gettime(CLOCK_MONOTONIC_RAW, tp);
