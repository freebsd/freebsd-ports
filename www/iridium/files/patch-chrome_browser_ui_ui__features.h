--- chrome/browser/ui/ui_features.h.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/ui_features.h
@@ -30,7 +30,7 @@ BASE_DECLARE_FEATURE(kCreateNewTabGroupAppMenuTopLevel
 
 BASE_DECLARE_FEATURE(kCtrlTabMru);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDseIntegrity);
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
@@ -83,7 +83,7 @@ BASE_DECLARE_FEATURE_PARAM(int,
 BASE_DECLARE_FEATURE_PARAM(int, kSeparateDefaultAndPinPromptMessageVersion);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, user may see the session restore UI flow.
 BASE_DECLARE_FEATURE(kSessionRestoreInfobar);
 
@@ -276,7 +276,7 @@ BASE_DECLARE_FEATURE(kManagedProfileRequiredInterstiti
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
