--- src/utils/os_unix.c.orig	2019-08-07 06:25:25.000000000 -0700
+++ src/utils/os_unix.c	2024-06-01 22:07:44.791894000 -0700
@@ -97,10 +97,12 @@
 			break;
 #endif
 #ifdef CLOCK_MONOTONIC
+#if !(defined(CLOCK_BOOTTIME) && CLOCK_BOOTTIME == CLOCK_MONOTONIC)
 		case CLOCK_MONOTONIC:
 			clock_id = CLOCK_REALTIME;
 			break;
 #endif
+#endif
 		case CLOCK_REALTIME:
 			return -1;
 		}
