--- src/chrome/browser/ui/ui_features.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/ui_features.cc
@@ -135,7 +135,7 @@ bool ShouldUseActionsForBrowserCommands(
          base::FeatureList::IsEnabled(kAppMenuGlowUp);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDseIntegrity, base::FEATURE_ENABLED_BY_DEFAULT);
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
@@ -374,7 +374,7 @@ BASE_FEATURE(kTabsFromOtherDevicesSidePa
 
 BASE_FEATURE(kNonMilestoneUpdateToast, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRespectShouldTriggerSessionRestoreOnDesktop,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
