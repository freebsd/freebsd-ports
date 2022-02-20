--- components/translate/core/common/translate_util.cc.orig	2022-02-07 13:39:41 UTC
+++ components/translate/core/common/translate_util.cc
@@ -29,7 +29,7 @@ const base::Feature kTranslateSubFrames{"TranslateSubF
 const base::Feature kTFLiteLanguageDetectionEnabled{
   "TFLiteLanguageDetectionEnabled",
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else  // !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_WIN) &&
        // !defined(OS_MAC)
