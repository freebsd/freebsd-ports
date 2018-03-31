--- chrome/browser/about_flags.cc.orig	2018-03-20 23:05:16.000000000 +0100
+++ chrome/browser/about_flags.cc	2018-03-24 13:04:35.001279000 +0100
@@ -2429,12 +2429,12 @@
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
@@ -3047,7 +3047,7 @@
      flag_descriptions::kLeftToRightUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kLeftToRightUrls)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-entity-suggestions",
      flag_descriptions::kOmniboxEntitySuggestionsName,
      flag_descriptions::kOmniboxEntitySuggestionsDescription, kOsDesktop,
@@ -3066,7 +3066,7 @@
     {"enable-new-app-menu-icon", flag_descriptions::kEnableNewAppMenuIconName,
      flag_descriptions::kEnableNewAppMenuIconDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kAnimatedAppMenuIcon)},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"enable-custom-feedback-ui",
