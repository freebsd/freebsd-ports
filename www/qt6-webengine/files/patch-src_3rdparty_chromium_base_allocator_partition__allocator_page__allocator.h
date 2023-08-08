--- src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator.h
@@ -231,7 +231,7 @@ constexpr PA_COMPONENT_EXPORT(
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
