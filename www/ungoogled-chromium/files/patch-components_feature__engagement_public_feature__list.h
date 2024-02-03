--- components/feature_engagement/public/feature_list.h.orig	2024-02-03 15:42:55 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -278,7 +278,7 @@ DEFINE_VARIATION_PARAM(kIPHiOSBlueDotPromoEnhancedSafe
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHBatterySaverModeFeature, "IPH_BatterySaverMode");
 DEFINE_VARIATION_PARAM(kIPHCompanionSidePanelFeature, "IPH_CompanionSidePanel");
 DEFINE_VARIATION_PARAM(kIPHCompanionSidePanelRegionSearchFeature,
@@ -369,7 +369,7 @@ DEFINE_VARIATION_PARAM(kIPHBackNavigationMenuFeature, 
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 DEFINE_VARIATION_PARAM(kIPHAutofillExternalAccountProfileSuggestionFeature,
                        "IPH_AutofillExternalAccountProfileSuggestion");
@@ -453,7 +453,7 @@ DEFINE_VARIATION_PARAM(kIPHScalableIphHelpAppBasedTenF
 DEFINE_VARIATION_PARAM(kIPHScalableIphGamingFeature, "IPH_ScalableIphGaming");
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunch,
                        "IPH_DesktopPWAsLinkCapturingLaunch");
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -592,7 +592,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHiOSPullToRefreshFeature),
         VARIATION_ENTRY(kIPHiOSReplaceSyncPromosWithSignInPromos),
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHBatterySaverModeFeature),
         VARIATION_ENTRY(kIPHCompanionSidePanelFeature),
         VARIATION_ENTRY(kIPHCompanionSidePanelRegionSearchFeature),
@@ -647,7 +647,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
         VARIATION_ENTRY(kIPHAutofillExternalAccountProfileSuggestionFeature),
         VARIATION_ENTRY(kIPHAutofillVirtualCardCVCSuggestionFeature),
@@ -695,7 +695,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHScalableIphGamingFeature),
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHDesktopPWAsLinkCapturingLaunch),
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
