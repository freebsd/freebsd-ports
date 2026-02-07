--- src/dnmalloc.c.orig
+++ src/dnmalloc.c
@@ -660,8 +660,18 @@
   sample version for pre-OSX macos.
 */
 
+#ifdef __FreeBSD__
+static void *nosbrk(ptrdiff_t len __unused) {
+  return MORECORE_FAILURE;
+}
+#endif
+
 #ifndef MORECORE
+#ifdef __FreeBSD__
+#define MORECORE nosbrk
+#else
 #define MORECORE sbrk
+#endif
 #endif
 
 
