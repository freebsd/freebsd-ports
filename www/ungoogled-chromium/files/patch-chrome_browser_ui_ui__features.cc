--- chrome/browser/ui/ui_features.cc.orig	2024-05-23 20:04:36 UTC
+++ chrome/browser/ui/ui_features.cc
@@ -426,7 +426,7 @@ BASE_FEATURE(kTopChromeWebUIUsesSpareRenderer,
              "TopChromeWebUIUsesSpareRenderer",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables alternate update-related text to be displayed in browser app menu
 // button, menu item and confirmation dialog.
 BASE_FEATURE(kUpdateTextOptions,
