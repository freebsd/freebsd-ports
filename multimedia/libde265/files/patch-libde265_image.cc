--- libde265/image.cc.orig	2015-07-14 13:51:51.000000000 +0200
+++ libde265/image.cc	2015-07-22 17:32:34.455583000 +0200
@@ -47,7 +47,7 @@
 #elif _WIN32
 #define ALLOC_ALIGNED(alignment, size)         _aligned_malloc((size), (alignment))
 #define FREE_ALIGNED(mem)                      _aligned_free((mem))
-#elif __APPLE__
+#elif defined(HAVE_POSIX_MEMALIGN)
 static inline void *ALLOC_ALIGNED(size_t alignment, size_t size) {
     void *mem = NULL;
     if (posix_memalign(&mem, alignment, size) != 0) {
