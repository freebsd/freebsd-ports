--- components/signin/public/base/signin_switches.h.orig	2026-08-31 10:59:09 UTC
+++ components/signin/public/base/signin_switches.h
@@ -62,7 +62,7 @@ base::TimeDelta GetAvatarSyncPromoFeatureMinimumCookeA
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kAvoidAutoTriggerListAccountsOnStale);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback before any changes
 // to the FRE as part of Chrome Desktop FRE Refresh project.
 //
@@ -136,7 +136,7 @@ BASE_DECLARE_FEATURE_PARAM(
     kChromeAndroidIdentitySurveyBookmarkPromoProbability);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables surveys to measure the effectiveness of the identity model.
 // These surveys would be displayed after interactions such as signin, profile
 // switching, etc. Please keep sorted alphabetically.
@@ -213,7 +213,7 @@ BASE_DECLARE_FEATURE_PARAM(
 // LINT.ThenChange(//chrome/browser/signin/signin_hats_util.cc)
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls the duration for which the launch of an identity survey is delayed.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kChromeIdentitySurveyLaunchWithDelay);
@@ -238,7 +238,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 extern const base::FeatureParam<std::string> kCrossDeviceSigninUrl;
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Feature flag to enable cross-device sign-in promo.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kCrossDeviceSigninFromDesktop);
@@ -264,7 +264,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kDiceLinkedAccounts);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If enabled, disables feedback for U18 users on desktop platforms.
 // The iOS version is kDisableFeedbackForIneligibleUsers flag.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
@@ -453,7 +453,7 @@ extern const base::FeatureParam<base::TimeDelta>
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFetchAccountInfoOnRestart);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This feature controls running visually refreshed first run and profile
 // creation flows for users outside of the search engine choice regions. To
 // enable the refresh in search engine choice screen regions,
@@ -507,7 +507,7 @@ extern const base::FeatureParam<FirstRunDesktopSignInP
     kFirstRunDesktopSignInPromoVariation;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kFirstRunDesktopRefresh`.
 //
@@ -517,7 +517,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFirstRunDesktopRefreshSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // It enables the first run revamp (introduce new UIs and additional effects).
 // This feature is no-op if `kFirstRunDesktopRefresh` is disabled.
 //
@@ -537,7 +537,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 bool IsFirstRunDesktopRevampEnabled(bool is_in_search_engine_choice_region);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kFirstRunDesktopRevamp` for users who are not eligible for
 // the Feature Showcase.
@@ -548,7 +548,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFirstRunDesktopRevampNoFeatureShowcaseSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kFirstRunDesktopRevamp` for users who are eligible for the
 // Feature Showcase.
@@ -559,7 +559,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFirstRunDesktopRevampSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This feature controls whether Gemini step can be shown in the feature
 // showcase. This feature is no-op if IsFirstRunDesktopRevamp() equals false.
 //
@@ -660,7 +660,7 @@ BASE_DECLARE_FEATURE(kNoAccountWebSignin);
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kNonDefaultGaiaOriginCheck);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // It enables the pre first run desktop refresh (changes to the onboarding flow
 // prior to the core first run).
 //
@@ -679,7 +679,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 bool IsPreFirstRunDesktopRefreshEnabled(bool is_in_search_engine_choice_region);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Experimenting with changing the secondary CTA for FRE and new profile
 // creation.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
@@ -741,7 +741,7 @@ extern const base::FeatureParam<int> kContextualSignin
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 extern const base::FeatureParam<int> kContextualSigninPromoDismissedThreshold;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Uses the Material Next theme for the signin promo.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSignInPromoMaterialNextUI);
@@ -796,7 +796,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSupportAddSessionEmailPrefill);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Kill switch for displaying sign-in errors in the profile picker.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSupportErrorsInProfilePicker);
