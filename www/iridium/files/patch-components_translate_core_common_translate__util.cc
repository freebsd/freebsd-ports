--- components/translate/core/common/translate_util.cc.orig	2022-12-06 08:09:13 UTC
+++ components/translate/core/common/translate_util.cc
@@ -35,7 +35,7 @@ BASE_FEATURE(kTranslateSubFrames,
 BASE_FEATURE(kTFLiteLanguageDetectionEnabled,
              "TFLiteLanguageDetectionEnabled",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
