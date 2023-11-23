--- content/common/features.cc.orig	2023-11-22 14:00:11 UTC
+++ content/common/features.cc
@@ -147,7 +147,7 @@ BASE_FEATURE(kEnableBackForwardCacheForScreenReader,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              "EnableDevToolsJsErrorReporting",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -219,7 +219,7 @@ BASE_FEATURE(kGpuInfoCollectionSeparatePrefetch,
 // process and having browser process handle adjusting thread properties (nice
 // value, c-group, latency sensitivity...) for renderers which have sandbox
 // restrictions.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kHandleRendererThreadTypeChangesInBrowser,
              "HandleRendererThreadTypeChangesInBrowser",
              base::FEATURE_ENABLED_BY_DEFAULT);
