--- components/feature_engagement/public/feature_list.cc.orig	2024-07-31 14:19:23 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -152,7 +152,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHiOSSavedTabGroupClosed,
 #endif  // BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     &kEsbDownloadRowPromoFeature,
     &kIPHBatterySaverModeFeature,
     &kIPHCompanionSidePanelFeature,
@@ -218,7 +218,8 @@ const base::Feature* const kAllFeatures[] = {
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
     &kIPHAutofillCreditCardBenefitFeature,
     &kIPHAutofillExternalAccountProfileSuggestionFeature,
     &kIPHAutofillManualFallbackFeature,
@@ -267,7 +268,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHScalableIphGamingFeature,
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     &kIPHDesktopPWAsLinkCapturingLaunch,
 #endif  // BUILDFLAG(IS_WIN) ||  BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
