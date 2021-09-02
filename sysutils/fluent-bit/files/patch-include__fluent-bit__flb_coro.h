--- include/fluent-bit/flb_coro.h.orig	2021-09-02 23:11:40.144014000 +0200
+++ include/fluent-bit/flb_coro.h	2021-09-02 23:12:34.983243000 +0200
@@ -65,7 +65,7 @@
 #ifdef FLB_CORO_STACK_SIZE
 #define FLB_CORO_STACK_SIZE      FLB_CORO_STACK_SIZE
 #else
-#define FLB_CORO_STACK_SIZE      ((3 * PTHREAD_STACK_MIN) / 2)
+#define FLB_CORO_STACK_SIZE      ((6 * PTHREAD_STACK_MIN) / 2)
 #endif
 
 #define FLB_CORO_DATA(coro)      (((char *) coro) + sizeof(struct flb_coro))
