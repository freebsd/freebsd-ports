--- chrome/browser/ui/ui_features.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/ui_features.cc
@@ -56,7 +56,7 @@ BASE_FEATURE(kInfoBarQueuedCountPill, base::FEATURE_DI
 BASE_FEATURE(kKeyboardLockHeldEscExitsTabFullscreen,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Gives browser windows of non-default profiles their own identity for the
 // desktop environment: the X11 WM_CLASS res_name and the Wayland app_id are set
 // to a per-profile desktop entry ID (e.g. "google-chrome-Profile_1"), so the
@@ -166,7 +166,7 @@ bool ShouldUseActionsForBrowserCommands() {
          base::FeatureList::IsEnabled(kAppMenuGlowUp);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDseIntegrity, base::FEATURE_ENABLED_BY_DEFAULT);
 
 // Enables the dialog shown when user feedback is disabled.
@@ -385,7 +385,7 @@ BASE_FEATURE(kTabsFromOtherDevicesSidePanelPinnedByDef
 
 BASE_FEATURE(kNonMilestoneUpdateToast, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRespectShouldTriggerSessionRestoreOnDesktop,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
