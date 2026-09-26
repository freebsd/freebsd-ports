--- chrome/browser/glic/public/features.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/glic/public/features.cc
@@ -86,7 +86,7 @@ BASE_FEATURE(kGlicCreateTabAdjacent, base::FEATURE_ENA
 
 // When off, disables both live mode and the glic floating panel.
 BASE_FEATURE(kGlicLiveMode,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
