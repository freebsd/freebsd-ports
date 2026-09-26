--- chrome/browser/ui/ui_features.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/ui_features.cc
@@ -104,7 +104,7 @@ bool IsWebuiRefresh2026Enabled() {
          base::FeatureList::IsEnabled(kWebuiRefresh2026);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDseIntegrity, base::FEATURE_ENABLED_BY_DEFAULT);
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
@@ -357,7 +357,7 @@ BASE_FEATURE(kTabsFromOtherDevicesSidePanelPinnedByDef
 BASE_FEATURE(kNonMilestoneUpdateToast, base::FEATURE_ENABLED_BY_DEFAULT);
 
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSessionRestoreInfobar, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE_PARAM(bool,
