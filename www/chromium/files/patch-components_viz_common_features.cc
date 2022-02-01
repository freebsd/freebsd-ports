--- components/viz/common/features.cc.orig	2021-12-14 11:45:04 UTC
+++ components/viz/common/features.cc
@@ -54,7 +54,7 @@ const base::Feature kSimpleFrameRateThrottling{
 const base::Feature kUseSkiaRenderer {
   "UseSkiaRenderer",
 #if defined(OS_WIN) || defined(OS_ANDROID) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_MAC)
+    defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_MAC) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
