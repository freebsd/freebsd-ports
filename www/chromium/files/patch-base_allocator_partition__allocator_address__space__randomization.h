--- base/allocator/partition_allocator/address_space_randomization.h.orig	2022-02-28 16:54:41 UTC
+++ base/allocator/partition_allocator/address_space_randomization.h
@@ -38,7 +38,7 @@ AslrMask(uintptr_t bits) {
 
 #if defined(ARCH_CPU_64_BITS)
 
-  #if defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
+  #if defined(MEMORY_TOOL_REPLACES_ALLOCATOR) && !defined(OS_BSD)
 
     // We shouldn't allocate system pages at all for sanitizer builds. However,
     // we do, and if random hint addresses interfere with address ranges
