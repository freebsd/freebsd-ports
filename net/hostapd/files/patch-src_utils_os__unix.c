--- src/utils/os_unix.c.orig	2026-08-07 06:10:53.000000000 -0700
+++ src/utils/os_unix.c	2026-08-10 08:16:05.134675000 -0700
@@ -124,11 +124,13 @@
 #endif
 
 #ifdef CLOCK_MONOTONIC
+#if !(defined(CLOCK_BOOTTIME) && CLOCK_BOOTTIME == CLOCK_MONOTONIC)
 		if (clock_id == CLOCK_MONOTONIC) {
 			clock_id = CLOCK_REALTIME;
 			continue;
 		}
 #endif
+#endif
 
 		/* No additional clockid_t values to fall back to */
 		return -1;
