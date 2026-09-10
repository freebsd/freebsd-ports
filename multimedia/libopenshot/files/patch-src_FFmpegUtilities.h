--- src/FFmpegUtilities.h.orig	2026-07-22 19:42:15 UTC
+++ src/FFmpegUtilities.h
@@ -410,7 +410,7 @@ inline static void* aligned_malloc(size_t size, size_t
 {
 #if defined(_WIN32)
     return _aligned_malloc(size, alignment);
-#elif defined(__APPLE__) || defined(__linux__)
+#elif defined(__APPLE__) || defined(__unix__)
     void* ptr = nullptr;
     if (posix_memalign(&ptr, alignment, size) != 0)
         return nullptr;
