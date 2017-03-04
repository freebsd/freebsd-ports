--- chrome/browser/about_flags.cc.orig	2017-02-02 02:02:48 UTC
+++ chrome/browser/about_flags.cc
@@ -776,7 +776,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsLinux | kOsCrOS | kOsWin | kOsAndroid,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableSmoothScrolling,
                                switches::kDisableSmoothScrolling)},
-#if defined(USE_AURA) || defined(OS_LINUX)
+#if defined(USE_AURA) || defined(OS_LINUX) || defined(OS_BSD)
     {"overlay-scrollbars", IDS_FLAGS_OVERLAY_SCROLLBARS_NAME,
      IDS_FLAGS_OVERLAY_SCROLLBARS_DESCRIPTION,
      // Uses the system preference on Mac (a different implementation).
@@ -1291,11 +1291,11 @@ const FeatureEntry kFeatureEntries[] = {
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableTranslateNewUX,
                                switches::kDisableTranslateNewUX)},
 #endif  // OS_MACOSX
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"translate-2016q2-ui", IDS_FLAGS_TRANSLATE_2016Q2_UI_NAME,
      IDS_FLAGS_TRANSLATE_2016Q2_UI_DESCRIPTION, kOsCrOS | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(translate::kTranslateUI2016Q2)},
-#endif  // OS_LINUX || OS_WIN || OS_CHROMEOS
+#endif  // OS_LINUX || OS_WIN || OS_CHROMEOS || OS_BSD
     {"translate-lang-by-ulp", IDS_FLAGS_TRANSLATE_LANGUAGE_BY_ULP_NAME,
      IDS_FLAGS_TRANSLATE_LANGUAGE_BY_ULP_DESCRIPTION, kOsAll,
      FEATURE_VALUE_TYPE(translate::kTranslateLanguageByULP)},
@@ -1769,7 +1769,7 @@ const FeatureEntry kFeatureEntries[] = {
      IDS_FLAGS_ENABLE_MATERIAL_DESIGN_EXTENSIONS_DESCRIPTION, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kMaterialDesignExtensions)},
 #endif  // ENABLE_EXTENSIONS
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-input-ime-api", IDS_FLAGS_ENABLE_INPUT_IME_API_NAME,
      IDS_FLAGS_ENABLE_INPUT_IME_API_DESCRIPTION, kOsWin | kOsLinux,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableInputImeAPI,
