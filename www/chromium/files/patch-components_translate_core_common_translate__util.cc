--- components/translate/core/common/translate_util.cc.orig	2022-02-28 16:54:41 UTC
+++ components/translate/core/common/translate_util.cc
@@ -29,7 +29,7 @@ const base::Feature kTranslateSubFrames{"TranslateSubF
 const base::Feature kTFLiteLanguageDetectionEnabled{
   "TFLiteLanguageDetectionEnabled",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
