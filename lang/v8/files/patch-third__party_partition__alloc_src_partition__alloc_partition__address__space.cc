--- third_party/partition_alloc/src/partition_alloc/partition_address_space.cc.orig	2026-09-18 16:27:42 UTC
+++ third_party/partition_alloc/src/partition_alloc/partition_address_space.cc
@@ -36,6 +36,10 @@
 #include <windows.h>
 #endif  // PA_BUILDFLAG(IS_WIN)
 
+#if PA_BUILDFLAG(IS_FREEBSD)
+#include <sys/mman.h>
+#endif  // PA_BUILDFLAG(IS_FREEBSD)
+
 #if PA_BUILDFLAG(ENABLE_THREAD_ISOLATION)
 #include <sys/mman.h>
 #endif
@@ -263,6 +267,13 @@ void PartitionAddressSpace::InitZeroSegment() {
   // failure. Previously reserved regions are intentionally leaked allowing for
   // partial user space segment.
   const auto reserve_region = [](uintptr_t address, size_t size) -> bool {
+#if PA_BUILDFLAG(IS_FREEBSD)
+    // With ASLR enabled, FreeBSD does not honor mmap() hints. Reserve the
+    // exact range with a guard mapping instead, which fails (rather than
+    // replacing) if any part of the range is in use.
+    return mmap(reinterpret_cast<void*>(address), size, PROT_NONE,
+                MAP_GUARD | MAP_FIXED | MAP_EXCL, -1, 0) != MAP_FAILED;
+#else
     const uintptr_t allocated_base =
         AllocPages(address, size, PageAllocationGranularity(),
                    PageAccessibilityConfiguration(
@@ -275,6 +286,7 @@ void PartitionAddressSpace::InitZeroSegment() {
       FreePages(allocated_base, size);
     }
     return false;
+#endif  // PA_BUILDFLAG(IS_FREEBSD)
   };
 
   uintptr_t current_addr = 0;
