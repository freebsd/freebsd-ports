--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h.orig	2024-08-26 12:51:32 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h
@@ -112,7 +112,7 @@ PartitionPageShift() {
 }
 #elif (BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)) || \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_ARM64)) ||   \
-    (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64))
 PA_ALWAYS_INLINE PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR size_t
 PartitionPageShift() {
   return PageAllocationGranularityShift() + 2;
@@ -315,7 +315,7 @@ constexpr size_t kPoolMaxSize = 1 * kGiB;
 #if BUILDFLAG(HAS_64_BIT_POINTERS)
 #if BUILDFLAG(IS_IOS)
 constexpr size_t kPoolMaxSize = 1 * kGiB;
-#elif BUILDFLAG(IS_ANDROID) || \
+#elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(ENABLE_POINTER_COMPRESSION)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
