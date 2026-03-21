--- chrome/browser/ui/ui_features.h.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ui/ui_features.h
@@ -26,7 +26,7 @@ BASE_DECLARE_FEATURE(kBrowserWidgetCacheThemeService);
 
 BASE_DECLARE_FEATURE(kCreateNewTabGroupAppMenuTopLevel);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDseIntegrity);
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
@@ -66,7 +66,7 @@ BASE_DECLARE_FEATURE_PARAM(int,
                            kSeparateDefaultAndPinPromptDefaultCooldownDays);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, user may see the session restore UI flow.
 BASE_DECLARE_FEATURE(kSessionRestoreInfobar);
 
@@ -286,7 +286,7 @@ BASE_DECLARE_FEATURE(kViewsFirstRunDialog);
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
@@ -394,7 +394,7 @@ BASE_DECLARE_FEATURE(kWhatsNewDesktopRefresh);
 BASE_DECLARE_FEATURE(kTabGroupsFocusing);
 BASE_DECLARE_FEATURE_PARAM(bool, kTabGroupsFocusingPinnedTabs);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUpdaterUI);
 #endif
 
