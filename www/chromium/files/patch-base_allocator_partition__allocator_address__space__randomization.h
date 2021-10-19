--- base/allocator/partition_allocator/address_space_randomization.h.orig	2021-10-07 16:50:24 UTC
+++ base/allocator/partition_allocator/address_space_randomization.h
@@ -36,7 +36,7 @@ AslrMask(uintptr_t bits) {
 
 #if defined(ARCH_CPU_64_BITS)
 
-  #if defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
+  #if defined(MEMORY_TOOL_REPLACES_ALLOCATOR) && !defined(OS_BSD)
 
     // We shouldn't allocate system pages at all for sanitizer builds. However,
     // we do, and if random hint addresses interfere with address ranges
