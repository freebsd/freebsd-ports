--- chrome/browser/ui/ui_features.h.orig	2023-06-05 19:39:05 UTC
+++ chrome/browser/ui/ui_features.h
@@ -203,7 +203,7 @@ BASE_DECLARE_FEATURE(kToolbarUseHardwareBitmapDraw);
 
 BASE_DECLARE_FEATURE(kTopChromeWebUIUsesSpareRenderer);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUpdateTextOptions);
 extern const base::FeatureParam<int> kUpdateTextOptionNumber;
 #endif
