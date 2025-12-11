--- base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2025-12-10 15:04:57 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -284,7 +284,7 @@ bool DecommitAndZeroSystemPages(void* address,
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
