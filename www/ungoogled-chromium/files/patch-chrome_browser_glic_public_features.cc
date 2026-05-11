--- chrome/browser/glic/public/features.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/glic/public/features.cc
@@ -44,7 +44,7 @@ BASE_FEATURE(kGlicInvoke, base::FEATURE_ENABLED_BY_DEF
 BASE_FEATURE(kGlicCreateTabAdjacent, base::FEATURE_ENABLED_BY_DEFAULT);
 
 BASE_FEATURE(kGlicLiveMode,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_DISABLED_BY_DEFAULT
 #else
              base::FEATURE_ENABLED_BY_DEFAULT
