--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_public_constants.h.orig	2026-10-18 13:29:39 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_public_constants.h
@@ -162,7 +162,7 @@ enum pool_handle : unsigned {
 #if PA_BUILDFLAG(HAS_64_BIT_POINTERS)
 #if PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_IOS) ||             \
     PA_BUILDFLAG(IS_CHROMEOS) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64) || \
-    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION)
+    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION) || PA_BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
