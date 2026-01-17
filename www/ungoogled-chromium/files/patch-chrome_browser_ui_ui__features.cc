--- chrome/browser/ui/ui_features.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/ui/ui_features.cc
@@ -30,7 +30,7 @@ BASE_FEATURE(kAllowEyeDropperWGCScreenCapture,
 BASE_FEATURE(kCreateNewTabGroupAppMenuTopLevel,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
 BASE_FEATURE(kFewerUpdateConfirmations, base::FEATURE_ENABLED_BY_DEFAULT);
@@ -90,7 +90,7 @@ BASE_FEATURE(kPressAndHoldEscToExitBrowserFullscreen,
 // context menu will only reload the active tab. The tab context menu will still
 // use the selection model to reload.
 BASE_FEATURE(kReloadSelectionModel,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -100,7 +100,7 @@ BASE_FEATURE(kReloadSelectionModel,
 // Enforces close tab hotkey to only close the active view of a split tab,
 // when it is the only tab in selection model.
 BASE_FEATURE(kCloseActiveTabInSplitViewViaHotkey,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -113,7 +113,7 @@ BASE_FEATURE(kShowTabGroupsMacSystemMenu, base::FEATUR
 #endif  // BUILDFLAG(IS_MAC)
 
 BASE_FEATURE(kSideBySide,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -178,7 +178,7 @@ BASE_FEATURE_PARAM(int,
                    "drop_target_hide_for_os_width",
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
                    32
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                    50
 #else
                    0
@@ -197,7 +197,7 @@ BASE_FEATURE_PARAM(double,
 );
 
 BASE_FEATURE(kSideBySideDropTargetNudge,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -279,7 +279,7 @@ BASE_FEATURE_PARAM(int,
 // When enabled along with SideBySide flag, split tabs will be restored on
 // startup.
 BASE_FEATURE(kSideBySideSessionRestore,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -293,7 +293,7 @@ bool IsRestoringSplitViewEnabled() {
 
 BASE_FEATURE(kSideBySideLinkMenuNewBadge,
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -514,7 +514,7 @@ BASE_FEATURE(kViewsFirstRunDialog, base::FEATURE_ENABL
 BASE_FEATURE(kViewsJSAppModalDialog, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
@@ -756,7 +756,7 @@ bool IsBookmarkTabGroupConversionEnabled() {
   return base::FeatureList::IsEnabled(kBookmarkTabGroupConversion);
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSessionRestoreInfobar, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE_PARAM(bool,
