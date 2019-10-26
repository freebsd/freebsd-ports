--- src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator.cc
@@ -115,7 +115,7 @@ void* AllocPages(void* address,
   uintptr_t align_base_mask = ~align_offset_mask;
   DCHECK(!(reinterpret_cast<uintptr_t>(address) & align_offset_mask));
 
-#if defined(OS_LINUX) && defined(ARCH_CPU_64_BITS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(ARCH_CPU_64_BITS)
   // On 64 bit Linux, we may need to adjust the address space limit for
   // guarded allocations.
   if (length >= kMinimumGuardedMemorySize) {
