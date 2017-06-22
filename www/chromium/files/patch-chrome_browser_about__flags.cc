--- chrome/browser/about_flags.cc.orig	2017-06-05 19:03:01 UTC
+++ chrome/browser/about_flags.cc
@@ -1588,12 +1588,12 @@ const FeatureEntry kFeatureEntries[] = {
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableTranslateNewUX,
                                switches::kDisableTranslateNewUX)},
 #endif  // OS_MACOSX
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"translate-2016q2-ui", flag_descriptions::kTranslate2016q2UiName,
      flag_descriptions::kTranslate2016q2UiDescription,
      kOsCrOS | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(translate::kTranslateUI2016Q2)},
-#endif  // OS_LINUX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_WIN || OS_CHROMEOS || OS_BSD
     {"translate-lang-by-ulp", flag_descriptions::kTranslateLanguageByUlpName,
      flag_descriptions::kTranslateLanguageByUlpDescription, kOsAll,
      FEATURE_VALUE_TYPE(translate::kTranslateLanguageByULP)},
@@ -2071,12 +2071,12 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableMaterialDesignExtensionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kMaterialDesignExtensions)},
 #endif  // ENABLE_EXTENSIONS
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-input-ime-api", flag_descriptions::kEnableInputImeApiName,
      flag_descriptions::kEnableInputImeApiDescription, kOsWin | kOsLinux,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableInputImeAPI,
                                switches::kDisableInputImeAPI)},
-#endif  // OS_WIN || OS_LINUX
+#endif  // OS_WIN || OS_LINUX || OS_BSD
     {"enable-origin-trials", flag_descriptions::kOriginTrialsName,
      flag_descriptions::kOriginTrialsDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kOriginTrials)},
