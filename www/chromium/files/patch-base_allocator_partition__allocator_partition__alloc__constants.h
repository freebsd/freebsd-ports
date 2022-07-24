--- base/allocator/partition_allocator/partition_alloc_constants.h.orig	2022-07-22 17:30:31 UTC
+++ base/allocator/partition_allocator/partition_alloc_constants.h
@@ -96,7 +96,7 @@ PartitionPageShift() {
   return 18;  // 256 KiB
 }
 #elif (BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)) || \
-    (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64))
 PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR PA_ALWAYS_INLINE size_t
 PartitionPageShift() {
   return PageAllocationGranularityShift() + 2;
@@ -252,7 +252,7 @@ constexpr size_t kSuperPageBaseMask = ~kSuperPageOffse
 #if defined(PA_HAS_64_BITS_POINTERS)
 // The Configurable Pool is only available in 64-bit mode
 constexpr size_t kNumPools = 3;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Special-case macOS. Contrary to other platforms, there is no sandbox limit
 // there, meaning that a single renderer could "happily" consume >8GiB. So the
 // 8GiB pool size is a regression. Make the limit higher on this platform only
