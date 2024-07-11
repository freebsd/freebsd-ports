--- src/lib/bsys.c.orig
+++ src/lib/bsys.c
@@ -1270,7 +1270,7 @@
 /*
  * Determine the amount of heap used
  * macOS - sbrk(0) is deprecated, use malloc info
- * Windows - not implemented
+ * Windows - not implemented and FreeBSD
  * others - use sbrk(0)
  */
 
@@ -1279,7 +1279,7 @@
 
 void mark_heap()
 {
-#if defined(HAVE_WIN32)
+#if defined(HAVE_WIN32) || defined(__FreeBSD__)
    start_heap = 0;
 #elif defined(HAVE_DARWIN_OS)
    struct mstats ms = mstats();
@@ -1296,6 +1296,8 @@
 #elif defined(HAVE_DARWIN_OS)
    struct mstats ms = mstats();
    return (int64_t) ms.bytes_used - start_heap;
+#elif defined(__FreeBSD__)
+   return 0;
 #else
    return (int64_t) sbrk(0) - start_heap;
 #endif
