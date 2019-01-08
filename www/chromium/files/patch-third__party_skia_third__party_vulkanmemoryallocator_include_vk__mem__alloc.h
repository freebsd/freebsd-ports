--- third_party/skia/third_party/vulkanmemoryallocator/include/vk_mem_alloc.h.orig	2018-12-12 23:03:06.000000000 +0100
+++ third_party/skia/third_party/vulkanmemoryallocator/include/vk_mem_alloc.h	2018-12-16 02:27:17.323830000 +0100
@@ -2232,7 +2232,7 @@
 #include <mutex> // for std::mutex
 #include <atomic> // for std::atomic
 
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
     #include <malloc.h> // for aligned_alloc()
 #endif
 
