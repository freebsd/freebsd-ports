--- include/fluent-bit/flb_coro.h.orig	2024-12-30 22:32:11.000000000 +0100
+++ include/fluent-bit/flb_coro.h	2025-01-06 23:50:52.035541000 +0100
@@ -68,7 +68,11 @@
 #define STACK_FACTOR 2   /* Use 24KiB for coro stacks */
 #endif
 #else
+#ifdef FLB_SYSTEM_FREEBSD
+#define FLB_CORO_STACK_SIZE 24576 /* FreeBSD's PTHREAD_STACK_MIN is just 2048 */
+#else
 #define STACK_FACTOR 1
+#endif
 #endif
 
 #ifdef FLB_CORO_STACK_SIZE
