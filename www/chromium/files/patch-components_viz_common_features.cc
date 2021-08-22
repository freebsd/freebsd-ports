--- components/viz/common/features.cc.orig	2021-07-19 18:45:15 UTC
+++ components/viz/common/features.cc
@@ -42,7 +42,7 @@ const base::Feature kSimpleFrameRateThrottling{
 const base::Feature kUseSkiaRenderer {
   "UseSkiaRenderer",
 #if defined(OS_WIN) || defined(OS_ANDROID) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #elif defined(OS_MAC)
       base::FEATURE_ENABLED_BY_DEFAULT
