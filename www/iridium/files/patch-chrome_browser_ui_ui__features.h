--- chrome/browser/ui/ui_features.h.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/ui/ui_features.h
@@ -28,7 +28,7 @@ BASE_DECLARE_FEATURE(kAllowEyeDropperWGCScreenCapture)
 
 BASE_DECLARE_FEATURE(kCloseOmniboxPopupOnInactiveAreaClick);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -56,7 +56,7 @@ enum class PdfInfoBarTrigger { kPdfLoad = 0, kStartup 
 BASE_DECLARE_FEATURE_PARAM(PdfInfoBarTrigger, kPdfInfoBarTrigger);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, user may see the session restore UI flow.
 BASE_DECLARE_FEATURE(kSessionRestoreInfobar);
 #endif
@@ -336,7 +336,7 @@ BASE_DECLARE_FEATURE(kViewsFirstRunDialog);
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
