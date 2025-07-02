--- chrome/browser/ui/ui_features.h.orig	2025-07-02 06:08:04 UTC
+++ chrome/browser/ui/ui_features.h
@@ -28,7 +28,7 @@ BASE_DECLARE_FEATURE(kAllowEyeDropperWGCScreenCapture)
 
 BASE_DECLARE_FEATURE(kCloseOmniboxPopupOnInactiveAreaClick);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -225,7 +225,7 @@ BASE_DECLARE_FEATURE(kViewsFirstRunDialog);
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
