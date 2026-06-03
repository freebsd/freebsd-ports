--- src/utils/os_unix.c.orig	2024-07-20 18:04:37 UTC
+++ src/utils/os_unix.c
@@ -103,9 +103,11 @@ int os_get_reltime(struct os_reltime *t)
 			break;
 #endif
 #ifdef CLOCK_MONOTONIC
+#if !(defined(CLOCK_BOOTTIME) && CLOCK_BOOTTIME == CLOCK_MONOTONIC)
 		case CLOCK_MONOTONIC:
 			clock_id = CLOCK_REALTIME;
 			break;
+#endif
 #endif
 		case CLOCK_REALTIME:
 			return -1;
