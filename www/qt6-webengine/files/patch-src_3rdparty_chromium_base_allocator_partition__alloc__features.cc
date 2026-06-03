--- src/3rdparty/chromium/base/allocator/partition_alloc_features.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/base/allocator/partition_alloc_features.cc
@@ -157,7 +157,7 @@ BASE_FEATURE(kPartitionAllocFewerMemoryRegions,
 // disabled elsewhere (for now). Does not apply to Windows.
 BASE_FEATURE(kPartitionAllocFewerMemoryRegions,
              "PartitionAllocFewerMemoryRegions",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
