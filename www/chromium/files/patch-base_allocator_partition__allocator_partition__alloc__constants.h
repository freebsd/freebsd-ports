--- base/allocator/partition_allocator/partition_alloc_constants.h.orig	2022-06-17 14:20:10 UTC
+++ base/allocator/partition_allocator/partition_alloc_constants.h
@@ -84,7 +84,7 @@ PartitionPageShift() {
   return 18;  // 256 KiB
 }
 #elif (BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)) || \
-    (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64))
 PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR ALWAYS_INLINE size_t
 PartitionPageShift() {
   return PageAllocationGranularityShift() + 2;
