--- components/translate/core/common/translate_util.cc.orig	2022-01-21 13:24:45 UTC
+++ components/translate/core/common/translate_util.cc
@@ -28,10 +28,10 @@ const base::Feature kTranslateSubFrames{"TranslateSubF
 
 const base::Feature kTFLiteLanguageDetectionEnabled{
   "TFLiteLanguageDetectionEnabled",
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_MAC)
       base::FEATURE_ENABLED_BY_DEFAULT
-#else  // !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_WIN) &&
+#else  // !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_WIN) && !defined(OS_BSD) &&
        // !defined(OS_MAC)
       base::FEATURE_DISABLED_BY_DEFAULT
 #endif
