--- chrome/browser/about_flags.cc.orig	2018-05-09 21:05:36.000000000 +0200
+++ chrome/browser/about_flags.cc	2018-08-16 03:29:45.979149000 +0200
@@ -593,7 +593,7 @@
      switches::kForceDirectionRTL},
 };
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 // Feature used to enable the identification of open tabs given URLs in
 // suggestions, and converting those suggestions to ones that allow switching to
 // the tab if found.  Currently only on the desktop. Includes button option
@@ -2441,7 +2441,7 @@
      flag_descriptions::kEnableMaterialDesignExtensionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kMaterialDesignExtensions)},
 #endif  // ENABLE_EXTENSIONS
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-input-ime-api", flag_descriptions::kEnableInputImeApiName,
      flag_descriptions::kEnableInputImeApiDescription, kOsWin | kOsLinux,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableInputImeAPI,
@@ -3058,7 +3058,7 @@
      flag_descriptions::kLeftToRightUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kLeftToRightUrls)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-entity-suggestions",
      flag_descriptions::kOmniboxEntitySuggestionsName,
      flag_descriptions::kOmniboxEntitySuggestionsDescription, kOsDesktop,
