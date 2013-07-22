--- top_three.c.orig	2009-07-24 03:53:17.000000000 +0000
+++ top_three.c
@@ -16,6 +16,9 @@
  * because every OS has it's own way of revealing CPU/memory usage.
  * compile with gcc -DOS ...
  */
+#if defined(DRAGONFLY)
+#define FREEBSD
+#endif
 #if defined(FREEBSD)
 #define OS_DEFINED
 #endif        /* defined(FREEBSD) */
