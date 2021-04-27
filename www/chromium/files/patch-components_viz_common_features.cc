--- components/viz/common/features.cc.orig	2021-04-14 18:41:02 UTC
+++ components/viz/common/features.cc
@@ -33,7 +33,7 @@ const base::Feature kEnableOverlayPrioritization {
 const base::Feature kUseSkiaRenderer {
   "UseSkiaRenderer",
 #if defined(OS_WIN) || defined(OS_ANDROID) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
