--- base/allocator/partition_alloc_features.cc.orig	2025-09-10 13:22:16 UTC
+++ base/allocator/partition_alloc_features.cc
@@ -154,7 +154,7 @@ BASE_FEATURE(kPartitionAllocEventuallyZeroFreedMemory,
 // disabled elsewhere (for now). Does not apply to Windows.
 BASE_FEATURE(kPartitionAllocFewerMemoryRegions,
              "PartitionAllocFewerMemoryRegions",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
