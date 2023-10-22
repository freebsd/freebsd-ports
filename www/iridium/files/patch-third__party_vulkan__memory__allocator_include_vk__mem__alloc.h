--- third_party/vulkan_memory_allocator/include/vk_mem_alloc.h.orig	2023-11-22 14:00:11 UTC
+++ third_party/vulkan_memory_allocator/include/vk_mem_alloc.h
@@ -2504,7 +2504,7 @@ void *vma_aligned_alloc(size_t alignment, size_t size)
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
+#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC)) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <cstdlib>
 
 #if defined(__APPLE__)
