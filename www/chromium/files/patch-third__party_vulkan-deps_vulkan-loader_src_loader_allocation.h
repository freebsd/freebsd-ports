--- third_party/vulkan-deps/vulkan-loader/src/loader/allocation.h.orig	2022-07-22 17:30:31 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/allocation.h
@@ -60,7 +60,7 @@ void loader_free_with_instance_fallback(const VkAlloca
 void *loader_realloc_with_instance_fallback(const VkAllocationCallbacks *pAllocator, const struct loader_instance *instance,
                                             void *pMemory, size_t orig_size, size_t size, VkSystemAllocationScope allocation_scope);
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #define loader_stack_alloc(size) alloca(size)
 #elif defined(_WIN32)
 #define loader_stack_alloc(size) _alloca(size)
