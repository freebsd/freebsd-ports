--- components/viz/common/features.cc.orig	2020-03-17 09:49:01 UTC
+++ components/viz/common/features.cc
@@ -17,7 +17,7 @@
 namespace features {
 
 // Use Skia's readback API instead of GLRendererCopier.
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 const base::Feature kUseSkiaForGLReadback{"UseSkiaForGLReadback",
                                           base::FEATURE_ENABLED_BY_DEFAULT};
 #else
@@ -26,7 +26,7 @@ const base::Feature kUseSkiaForGLReadback{"UseSkiaForG
 #endif
 
 // Use the SkiaRenderer.
-#if defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST))
+#if (defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST))) || defined(OS_BSD)
 const base::Feature kUseSkiaRenderer{"UseSkiaRenderer",
                                      base::FEATURE_ENABLED_BY_DEFAULT};
 #else
