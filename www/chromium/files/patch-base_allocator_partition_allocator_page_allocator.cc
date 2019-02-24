--- base/allocator/partition_allocator/page_allocator.cc.orig	2019-02-06 21:56:56.953755000 +0100
+++ base/allocator/partition_allocator/page_allocator.cc	2019-02-06 21:57:23.721544000 +0100
@@ -114,7 +114,7 @@
   uintptr_t align_base_mask = ~align_offset_mask;
   DCHECK(!(reinterpret_cast<uintptr_t>(address) & align_offset_mask));
 
-#if defined(OS_LINUX) && defined(ARCH_CPU_64_BITS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(ARCH_CPU_64_BITS)
   // On 64 bit Linux, we may need to adjust the address space limit for
   // guarded allocations.
   if (length >= kMinimumGuardedMemorySize) {
