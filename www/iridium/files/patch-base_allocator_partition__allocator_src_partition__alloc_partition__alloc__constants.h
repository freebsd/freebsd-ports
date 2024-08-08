--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h.orig	2024-08-01 05:47:53 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h
@@ -329,7 +329,7 @@ PA_DEFINE_OPERATORS_FOR_FLAGS(PoolHandleMask);
 // 8GB for each of the glued pools).
 #if PA_BUILDFLAG(HAS_64_BIT_POINTERS)
 #if PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_IOS) || \
-    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION)
+    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION) || PA_BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
