--- base/allocator/partition_allocator/src/partition_alloc/address_space_randomization.h.orig	2023-12-23 12:33:28 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/address_space_randomization.h
@@ -38,7 +38,7 @@ AslrMask(uintptr_t bits) {
 
 #if defined(ARCH_CPU_64_BITS)
 
-  #if defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
+  #if defined(MEMORY_TOOL_REPLACES_ALLOCATOR) && !BUILDFLAG(IS_BSD)
 
     // We shouldn't allocate system pages at all for sanitizer builds. However,
     // we do, and if random hint addresses interfere with address ranges
@@ -124,7 +124,7 @@ AslrMask(uintptr_t bits) {
         return AslrAddress(0x20000000ULL);
       }
 
-      #elif BUILDFLAG(IS_LINUX)
+      #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
       // Linux on arm64 can use 39, 42, 48, or 52-bit user space, depending on
       // page size and number of levels of translation pages used. We use
