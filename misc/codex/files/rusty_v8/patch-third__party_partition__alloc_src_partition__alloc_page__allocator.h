--- third_party/partition_alloc/src/partition_alloc/page_allocator.h.orig	1970-01-01 00:00:00 UTC
+++ third_party/partition_alloc/src/partition_alloc/page_allocator.h
@@ -279,7 +279,7 @@ constexpr PA_COMPONENT_EXPORT(
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
