--- components/feature_engagement/public/feature_list.h.orig	2026-09-25 15:26:43 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -411,7 +411,7 @@ DEFINE_VARIATION_PARAM(kIPHiOSPinMostVisitedSiteFeatur
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 DEFINE_VARIATION_PARAM(kEsbDownloadRowPromoFeature, "EsbDownloadRowPromo");
 #endif
@@ -569,7 +569,7 @@ DEFINE_VARIATION_PARAM(kIPHTabGroupsSharedTabFeedbackF
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHAutofillAccountNameEmailSuggestionFeature,
                        "IPH_AutofillAccountNameEmailSuggestion");
 DEFINE_VARIATION_PARAM(kIPHAutofillAiOptInFeature, "IPH_AutofillAiOptIn");
@@ -616,7 +616,7 @@ DEFINE_VARIATION_PARAM(kIPHLauncherSearchHelpUiFeature
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunch,
                        "IPH_DesktopPWAsLinkCapturingLaunch");
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunchAppInTab,
@@ -624,7 +624,7 @@ DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLau
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHSignInBenefitsFeature, "IPH_SignInBenefits");
 DEFINE_VARIATION_PARAM(kIPHSupervisedUserProfileSigninFeature,
                        "IPH_SupervisedUserProfileSignin");
@@ -875,7 +875,7 @@ inline constexpr flags_ui::FeatureEntry::FeatureVariat
         VARIATION_ENTRY(kIPHWhatsNewUpdatedFeature),
 // keep-sorted end
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE)
         VARIATION_ENTRY(kIPHExtensionsMenuFeature),
         VARIATION_ENTRY(kIPHExtensionsRequestAccessButtonFeature),
@@ -954,7 +954,7 @@ inline constexpr flags_ui::FeatureEntry::FeatureVariat
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // keep-sorted start case=no
         VARIATION_ENTRY(kIPHAutofillAccountNameEmailSuggestionFeature),
         VARIATION_ENTRY(kIPHAutofillAiOptInFeature),
@@ -982,13 +982,13 @@ inline constexpr flags_ui::FeatureEntry::FeatureVariat
         VARIATION_ENTRY(kIPHLauncherSearchHelpUiFeature),
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
