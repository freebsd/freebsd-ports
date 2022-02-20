--- third_party/vulkan-deps/vulkan-loader/src/loader/allocation.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/allocation.h
@@ -39,8 +39,8 @@ void loader_device_heap_free(const struct loader_devic
 void *loader_device_heap_realloc(const struct loader_device *device, void *pMemory, size_t orig_size, size_t size,
                                  VkSystemAllocationScope alloc_scope);
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #define loader_stack_alloc(size) alloca(size)
 #elif defined(_WIN32)
 #define loader_stack_alloc(size) _alloca(size)
-#endif  // defined(_WIN32)
\ No newline at end of file
+#endif  // defined(_WIN32)
