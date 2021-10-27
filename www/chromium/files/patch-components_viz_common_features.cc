--- components/viz/common/features.cc.orig	2021-09-24 04:26:05 UTC
+++ components/viz/common/features.cc
@@ -46,7 +46,7 @@ const base::Feature kSimpleFrameRateThrottling{
 const base::Feature kUseSkiaRenderer {
   "UseSkiaRenderer",
 #if defined(OS_WIN) || defined(OS_ANDROID) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_MAC)
+    defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_MAC) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
