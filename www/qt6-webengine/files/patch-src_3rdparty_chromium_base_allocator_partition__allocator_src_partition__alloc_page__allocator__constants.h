--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/page_allocator_constants.h.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/page_allocator_constants.h
@@ -31,8 +31,8 @@
 #define PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR __attribute__((const))
 
 #elif (PA_BUILDFLAG(IS_ANDROID) && PA_BUILDFLAG(PA_ARCH_CPU_64_BITS)) || \
-    (PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)) ||       \
-    (PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_PPC64))
+    ((PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)) ||       \
+    ((PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_PPC64))
 // This should work for all POSIX (if needed), but currently all other
 // supported OS/architecture combinations use either hard-coded values
 // (such as x86) or have means to determine these values without needing
@@ -124,7 +124,7 @@ PageAllocationGranularityShift() {
     page_characteristics.shift.store(shift, std::memory_order_relaxed);
   }
   return shift;
-#elif PA_BUILDFLAG(IS_WIN) || PA_BUILDFLAG(PA_ARCH_CPU_PPC64)
+#elif PA_BUILDFLAG(IS_WIN)
   // Modern ppc64 systems support 4kB (shift = 12) and 64kB (shift = 16) page
   // sizes.  Since 64kB is the de facto standard on the platform and binaries
   // compiled for 64kB are likely to work on 4kB systems, 64kB is a good choice
