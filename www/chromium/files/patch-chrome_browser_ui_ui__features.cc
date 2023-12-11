--- chrome/browser/ui/ui_features.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/ui/ui_features.cc
@@ -300,7 +300,7 @@ BASE_FEATURE(kTopChromeWebUIUsesSpareRenderer,
              "TopChromeWebUIUsesSpareRenderer",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables alternate update-related text to be displayed in browser app menu
 // button, menu item and confirmation dialog.
 BASE_FEATURE(kUpdateTextOptions,
