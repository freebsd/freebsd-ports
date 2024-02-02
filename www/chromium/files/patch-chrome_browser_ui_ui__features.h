--- chrome/browser/ui/ui_features.h.orig	2024-01-30 07:53:34 UTC
+++ chrome/browser/ui/ui_features.h
@@ -219,7 +219,7 @@ BASE_DECLARE_FEATURE(kToolbarUseHardwareBitmapDraw);
 
 BASE_DECLARE_FEATURE(kTopChromeWebUIUsesSpareRenderer);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUpdateTextOptions);
 extern const base::FeatureParam<int> kUpdateTextOptionNumber;
 #endif
