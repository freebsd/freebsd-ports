--- components/viz/common/features.cc.orig	2021-03-12 23:57:23 UTC
+++ components/viz/common/features.cc
@@ -32,7 +32,7 @@ const base::Feature kEnableOverlayPrioritization {
 // Use the SkiaRenderer.
 const base::Feature kUseSkiaRenderer {
   "UseSkiaRenderer",
-#if defined(OS_WIN) || (defined(OS_LINUX) && !(BUILDFLAG(IS_CHROMEOS_ASH) || \
+#if defined(OS_WIN) || defined(OS_BSD) || (defined(OS_LINUX) && !(BUILDFLAG(IS_CHROMEOS_ASH) || \
                                                BUILDFLAG(IS_CHROMECAST)))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
