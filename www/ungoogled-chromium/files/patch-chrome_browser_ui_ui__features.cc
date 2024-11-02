diff --git chrome/browser/ui/ui_features.cc chrome/browser/ui/ui_features.cc	2024-11-02 08:11:27 UTC
index c92ebcbca5..55b0da1030 100644
--- chrome/browser/ui/ui_features.cc
+++ chrome/browser/ui/ui_features.cc
@@ -103,7 +103,7 @@ BASE_FEATURE(kAccessCodeCastUI,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
 BASE_FEATURE(kFewerUpdateConfirmations,
@@ -402,7 +402,7 @@ BASE_FEATURE(kTopChromeWebUIUsesSpareRenderer,
              "TopChromeWebUIUsesSpareRenderer",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables alternate update-related text to be displayed in browser app menu
 // button, menu item and confirmation dialog.
 BASE_FEATURE(kUpdateTextOptions,
@@ -474,7 +474,7 @@ BASE_FEATURE(kStopLoadingAnimationForHiddenWindow,
              "StopLoadingAnimationForHiddenWindow",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor,
              "UsePortalAccentColor",
              base::FEATURE_ENABLED_BY_DEFAULT);
