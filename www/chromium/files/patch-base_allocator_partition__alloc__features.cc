--- base/allocator/partition_alloc_features.cc.orig	2025-08-07 06:57:29 UTC
+++ base/allocator/partition_alloc_features.cc
@@ -164,7 +164,7 @@ BASE_FEATURE(kPartitionAllocEventuallyZeroFreedMemory,
 // disabled elsewhere (for now). Does not apply to Windows.
 BASE_FEATURE(kPartitionAllocFewerMemoryRegions,
              "PartitionAllocFewerMemoryRegions",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
@@ -489,7 +489,7 @@ BASE_FEATURE(kPartitionAllocAdjustSizeWhenInForeground
 #if PA_CONFIG(ENABLE_SHADOW_METADATA)
 BASE_FEATURE(kPartitionAllocShadowMetadata,
              "PartitionAllocShadowMetadata",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
