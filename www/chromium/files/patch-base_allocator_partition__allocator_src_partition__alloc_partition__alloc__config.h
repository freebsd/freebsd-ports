--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_config.h.orig	2024-07-30 11:12:21 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_config.h
@@ -236,7 +236,7 @@ constexpr bool kUseLazyCommit = false;
 // This may be required on more platforms in the future.
 #define PA_CONFIG_HAS_ATFORK_HANDLER()                 \
   (PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_LINUX) || \
-   PA_BUILDFLAG(IS_CHROMEOS))
+   PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD))
 
 // PartitionAlloc uses PartitionRootEnumerator to acquire all
 // PartitionRoots at BeforeFork and to release at AfterFork.
@@ -284,7 +284,7 @@ constexpr bool kUseLazyCommit = false;
 // Also enabled on ARM64 macOS and iOS, as the 16kiB pages on this platform lead
 // to larger slot spans.
 #if PA_BUILDFLAG(IS_LINUX) || \
-    (PA_BUILDFLAG(IS_APPLE) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64))
+    (PA_BUILDFLAG(IS_APPLE) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)) || PA_BUILDFLAG(IS_BSD)
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() 1
 #else
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() 0
