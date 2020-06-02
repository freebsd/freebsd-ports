--- components/viz/common/features.cc.orig	2020-05-13 18:39:42 UTC
+++ components/viz/common/features.cc
@@ -20,7 +20,7 @@ const base::Feature kUseSkiaForGLReadback{"UseSkiaForG
                                           base::FEATURE_ENABLED_BY_DEFAULT};
 
 // Use the SkiaRenderer.
-#if defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST))
+#if (defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST))) || defined(OS_BSD)
 const base::Feature kUseSkiaRenderer{"UseSkiaRenderer",
                                      base::FEATURE_ENABLED_BY_DEFAULT};
 #else
