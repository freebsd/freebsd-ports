--- base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2026-02-15 10:01:45 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -279,7 +279,7 @@ bool DecommitAndZeroSystemPages(void* address,
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
