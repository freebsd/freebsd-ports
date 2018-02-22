--- chrome/browser/about_flags.cc.orig	2017-12-15 02:04:07.000000000 +0100
+++ chrome/browser/about_flags.cc	2017-12-24 00:29:31.459851000 +0100
@@ -878,7 +878,7 @@
         {"Learning", kSpeculativeResourcePrefetchingLearning,
          arraysize(kSpeculativeResourcePrefetchingLearning), nullptr}};
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kPauseBackgroundTabsMinimalEngagment[] = {
     {pausetabs::kFeatureName, pausetabs::kModeParamMinimal}};
 
@@ -1875,7 +1875,7 @@
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableTranslateNewUX,
                                switches::kDisableTranslateNewUX)},
 #endif  // OS_MACOSX
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     {"translate-2016q2-ui", flag_descriptions::kTranslate2016q2UiName,
      flag_descriptions::kTranslate2016q2UiDescription,
      kOsCrOS | kOsWin | kOsLinux,
@@ -2407,12 +2407,12 @@
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
@@ -3008,7 +3008,7 @@
      flag_descriptions::kLeftToRightUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kLeftToRightUrls)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-entity-suggestions",
      flag_descriptions::kOmniboxEntitySuggestionsName,
      flag_descriptions::kOmniboxEntitySuggestionsDescription, kOsDesktop,
@@ -3086,7 +3086,7 @@
      FEATURE_VALUE_TYPE(chrome::android::kCustomContextMenu)},
 #endif  // OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {pausetabs::kFeatureName, flag_descriptions::kPauseBackgroundTabsName,
      flag_descriptions::kPauseBackgroundTabsDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(pausetabs::kFeature,
