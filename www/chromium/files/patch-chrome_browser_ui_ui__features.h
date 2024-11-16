--- chrome/browser/ui/ui_features.h.orig	2024-11-14 07:57:23 UTC
+++ chrome/browser/ui/ui_features.h
@@ -76,7 +76,7 @@ bool IsExtensionMenuInRootAppMenu();
 BASE_DECLARE_FEATURE(kAccessCodeCastUI);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -279,7 +279,7 @@ BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 
 BASE_DECLARE_FEATURE(kStopLoadingAnimationForHiddenWindow);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
