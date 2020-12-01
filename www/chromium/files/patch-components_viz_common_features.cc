--- components/viz/common/features.cc.orig	2020-11-13 06:36:42 UTC
+++ components/viz/common/features.cc
@@ -22,7 +22,7 @@ const base::Feature kForcePreferredIntervalForVideo{
 
 // Use the SkiaRenderer.
 #if defined(OS_WIN) || \
-    (defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST)))
+    (defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST))) || defined(OS_BSD)
 const base::Feature kUseSkiaRenderer{"UseSkiaRenderer",
                                      base::FEATURE_ENABLED_BY_DEFAULT};
 #else
