--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_config.h.orig	2025-11-06 10:11:34 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_config.h
@@ -171,7 +171,7 @@ constexpr bool kUseLazyCommit = false;
 // macOS, where it yielded no beenefit (nor any real downside).
 constexpr bool kUseFewerMemoryRegions =
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_ANDROID) || \
-    PA_BUILDFLAG(IS_CHROMEOS)
+    PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
     true;
 #else
     false;
@@ -181,7 +181,7 @@ constexpr bool kUseFewerMemoryRegions =
 // This may be required on more platforms in the future.
 #define PA_CONFIG_HAS_ATFORK_HANDLER()                 \
   (PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_LINUX) || \
-   PA_BUILDFLAG(IS_CHROMEOS))
+   PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD))
 
 #if PA_BUILDFLAG(MOVE_METADATA_OUT_OF_GIGACAGE_FOR_64_BITS_POINTERS) && \
     PA_BUILDFLAG(HAS_64_BIT_POINTERS)
@@ -238,7 +238,7 @@ constexpr bool kUseFewerMemoryRegions =
 // Also enabled on ARM64 macOS and iOS, as the 16kiB pages on this platform lead
 // to larger slot spans.
 #if PA_BUILDFLAG(IS_LINUX) || \
-    (PA_BUILDFLAG(IS_APPLE) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64))
+    (PA_BUILDFLAG(IS_APPLE) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)) || PA_BUILDFLAG(IS_BSD)
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() 1
 #else
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() 0
