--- chrome/browser/about_flags.cc.orig	2016-12-01 23:02:06 UTC
+++ chrome/browser/about_flags.cc
@@ -766,7 +766,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsLinux | kOsCrOS | kOsWin | kOsAndroid,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableSmoothScrolling,
                                switches::kDisableSmoothScrolling)},
-#if defined(USE_AURA) || defined(OS_LINUX)
+#if defined(USE_AURA) || defined(OS_LINUX) || defined(OS_BSD)
     {"overlay-scrollbars", IDS_FLAGS_OVERLAY_SCROLLBARS_NAME,
      IDS_FLAGS_OVERLAY_SCROLLBARS_DESCRIPTION,
      // Uses the system preference on Mac (a different implementation).
@@ -1771,7 +1771,7 @@ const FeatureEntry kFeatureEntries[] = {
      IDS_FLAGS_ENABLE_MATERIAL_DESIGN_EXTENSIONS_DESCRIPTION, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kMaterialDesignExtensions)},
 #endif  // ENABLE_EXTENSIONS
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-input-ime-api", IDS_FLAGS_ENABLE_INPUT_IME_API_NAME,
      IDS_FLAGS_ENABLE_INPUT_IME_API_DESCRIPTION, kOsWin | kOsLinux,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableInputImeAPI,
