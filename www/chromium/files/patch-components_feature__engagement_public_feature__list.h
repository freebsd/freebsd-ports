--- components/feature_engagement/public/feature_list.h.orig	2026-11-19 12:25:27 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -418,7 +418,7 @@ DEFINE_VARIATION_PARAM(kIPHiOSPinMostVisitedSiteFeatur
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 DEFINE_VARIATION_PARAM(kEsbDownloadRowPromoFeature, "EsbDownloadRowPromo");
 #endif
@@ -588,7 +588,7 @@ DEFINE_VARIATION_PARAM(kIPHTabGroupsSharedTabFeedbackF
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPH_AutofillAmbientAutofillSpiiDisclaimer,
                        "IPH_AutofillAmbientAutofillSpiiDisclaimer");
 DEFINE_VARIATION_PARAM(kIPHAutofillAccountNameEmailSuggestionFeature,
@@ -634,7 +634,7 @@ DEFINE_VARIATION_PARAM(kIPHGoogleOneOfferNotificationF
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunch,
                        "IPH_DesktopPWAsLinkCapturingLaunch");
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunchAppInTab,
@@ -642,7 +642,7 @@ DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLau
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHSignInBenefitsFeature, "IPH_SignInBenefits");
 DEFINE_VARIATION_PARAM(kIPHSupervisedUserProfileSigninFeature,
                        "IPH_SupervisedUserProfileSignin");
@@ -896,7 +896,7 @@ inline constexpr flags_ui::FeatureEntry::FeatureVariat
         VARIATION_ENTRY(kIPHWhatsNewUpdatedFeature),
 // keep-sorted end
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE)
         VARIATION_ENTRY(kIPHExtensionsMenuFeature),
         VARIATION_ENTRY(kIPHExtensionsRequestAccessButtonFeature),
@@ -984,7 +984,7 @@ inline constexpr flags_ui::FeatureEntry::FeatureVariat
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // keep-sorted start case=no
         VARIATION_ENTRY(kIPH_AutofillAmbientAutofillSpiiDisclaimer),
         VARIATION_ENTRY(kIPHAutofillAccountNameEmailSuggestionFeature),
@@ -1011,13 +1011,13 @@ inline constexpr flags_ui::FeatureEntry::FeatureVariat
         VARIATION_ENTRY(kIPHGrowthFramework),
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHDesktopPWAsLinkCapturingLaunch),
         VARIATION_ENTRY(kIPHDesktopPWAsLinkCapturingLaunchAppInTab),
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHSignInBenefitsFeature),
         VARIATION_ENTRY(kIPHSupervisedUserProfileSigninFeature),
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
