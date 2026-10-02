--- third_party/partition_alloc/src/partition_alloc/shim/allocator_shim_override_libc_symbols.h.orig	2026-05-28 04:51:26 UTC
+++ third_party/partition_alloc/src/partition_alloc/shim/allocator_shim_override_libc_symbols.h
@@ -80,7 +80,12 @@ SHIM_ALWAYS_EXPORT size_t malloc_size(const void* addr
   return ShimGetSizeEstimate(address, nullptr);
 }
 
+#if PA_BUILDFLAG(IS_FREEBSD)
+// FreeBSD's malloc_np.h declares malloc_usable_size with const void*.
+SHIM_ALWAYS_EXPORT size_t malloc_usable_size(const void* address) __THROW {
+#else
 SHIM_ALWAYS_EXPORT size_t malloc_usable_size(void* address) __THROW {
+#endif
   return ShimGetSizeEstimate(address, nullptr);
 }
 
