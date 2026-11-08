--- chrome/browser/ui/ui_features.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/ui_features.h
@@ -26,7 +26,7 @@ BASE_DECLARE_FEATURE(kAllowEyeDropperWGCScreenCapture)
 
 BASE_DECLARE_FEATURE(kCtrlTabMru);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDseIntegrity);
 BASE_DECLARE_FEATURE(kFeedbackDisabledDialog);
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
@@ -90,7 +90,7 @@ BASE_DECLARE_FEATURE_PARAM(int,
 BASE_DECLARE_FEATURE_PARAM(int, kSeparateDefaultAndPinPromptMessageVersion);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, SessionService respects the should_trigger_session_restore
 // flag on BrowserInitState when deciding whether to restore a session for a
 // newly opened browser window.
