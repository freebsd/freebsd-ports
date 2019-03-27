--- src/3rdparty/chromium/third_party/skia/third_party/vulkanmemoryallocator/include/vk_mem_alloc.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/skia/third_party/vulkanmemoryallocator/include/vk_mem_alloc.h
@@ -2232,7 +2232,7 @@ remove them if not needed.
 #include <mutex> // for std::mutex
 #include <atomic> // for std::atomic
 
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
     #include <malloc.h> // for aligned_alloc()
 #endif
 
