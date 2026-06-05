--- chrome/browser/glic/public/features.cc.orig	2026-06-04 10:12:25 UTC
+++ chrome/browser/glic/public/features.cc
@@ -58,7 +58,7 @@ BASE_FEATURE(kGlicCreateTabAdjacent, base::FEATURE_ENA
 
 // When off, disables both live mode and the glic floating panel.
 BASE_FEATURE(kGlicLiveMode,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
