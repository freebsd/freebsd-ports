--- chrome/browser/ui/ui_features.h.orig	2025-02-19 07:43:18 UTC
+++ chrome/browser/ui/ui_features.h
@@ -68,7 +68,7 @@ extern const base::FeatureParam<bool> kAppMenuChipColo
 BASE_DECLARE_FEATURE(kExtensionsMenuInAppMenu);
 bool IsExtensionMenuInRootAppMenu();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -244,7 +244,7 @@ BASE_DECLARE_FEATURE(kViewsFirstRunDialog);
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
