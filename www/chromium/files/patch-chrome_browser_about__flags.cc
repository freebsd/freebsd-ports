--- chrome/browser/about_flags.cc.orig	2018-08-01 00:08:29.000000000 +0200
+++ chrome/browser/about_flags.cc	2018-08-04 14:12:27.193526000 +0200
@@ -2408,7 +2408,7 @@
      flag_descriptions::kEnableMaterialDesignExtensionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kMaterialDesignExtensions)},
 #endif  // ENABLE_EXTENSIONS
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-input-ime-api", flag_descriptions::kEnableInputImeApiName,
      flag_descriptions::kEnableInputImeApiDescription, kOsWin | kOsLinux,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableInputImeAPI,
@@ -3024,7 +3024,7 @@
      flag_descriptions::kLeftToRightUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kLeftToRightUrls)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-new-answer-layout",
      flag_descriptions::kOmniboxNewAnswerLayoutName,
      flag_descriptions::kOmniboxNewAnswerLayoutDescription, kOsDesktop,
