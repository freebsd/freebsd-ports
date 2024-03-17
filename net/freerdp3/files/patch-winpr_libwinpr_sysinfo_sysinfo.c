--- winpr/libwinpr/sysinfo/sysinfo.c.orig	2024-03-14 10:28:33 UTC
+++ winpr/libwinpr/sysinfo/sysinfo.c
@@ -34,7 +34,7 @@
 #endif
 
 #if !defined(_WIN32)
-#if defined(_POSIX_SOURCE) && (_POSIX_C_SOURCE >= 200112L)
+#if (_POSIX_C_SOURCE >= 200112L) || defined(__FreeBSD__)
 #include <time.h>
 #elif !defined(__APPLE__)
 #include <sys/time.h>
@@ -579,7 +579,7 @@ ULONGLONG winpr_GetTickCount64(void)
 UINT64 winpr_GetTickCount64NS(void)
 {
 	UINT64 ticks = 0;
-#if defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)
+#if (_POSIX_C_SOURCE >= 200112L) || defined(__FreeBSD__)
 	struct timespec ts = { 0 };
 
 	if (clock_gettime(CLOCK_MONOTONIC_RAW, &ts) == 0)
@@ -632,7 +632,7 @@ UINT64 winpr_GetUnixTimeNS(void)
 	} t = { 0 };
 	GetSystemTimeAsFileTime(&t.ft);
 	return (t.u64 - FILETIME_TO_UNIX_OFFSET_S * 10000000ull) * 100ull;
-#elif _POSIX_C_SOURCE >= 200112L
+#elif (_POSIX_C_SOURCE >= 200112L) || defined(__FreeBSD__)
 	struct timespec ts = { 0 };
 	if (clock_gettime(CLOCK_REALTIME, &ts) != 0)
 		return 0;
