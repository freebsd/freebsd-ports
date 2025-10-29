--- base/allocator/partition_alloc_features.cc.orig	2025-10-28 14:29:43 UTC
+++ base/allocator/partition_alloc_features.cc
@@ -143,7 +143,7 @@ BASE_FEATURE(PartitionAllocEventuallyZeroFreedMemory,
 // Evaluated and positive stability and peformance-wise on Linux-based systems,
 // disabled elsewhere (for now). Does not apply to Windows.
 BASE_FEATURE(PartitionAllocFewerMemoryRegions,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
