--- src/utils/os_unix.c.orig	2022-01-16 12:51:29.000000000 -0800
+++ src/utils/os_unix.c	2024-06-01 22:20:49.333716000 -0700
@@ -103,10 +103,12 @@
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
