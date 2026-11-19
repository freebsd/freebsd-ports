--- components/signin/public/base/signin_switches.h.orig	2026-11-19 12:25:27 UTC
+++ components/signin/public/base/signin_switches.h
@@ -69,7 +69,7 @@ BASE_DECLARE_FEATURE(kAiSubscriptionAvatarRingFollowup
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kAvoidAutoTriggerListAccountsOnStale);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback before any changes
 // to the FRE as part of Chrome Desktop FRE Refresh project.
 //
@@ -137,7 +137,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE_PARAM(double, kChromeAndroidIdentitySurveyWebProbability);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables surveys to measure the effectiveness of the identity model.
 // These surveys would be displayed after interactions such as signin, profile
 // switching, etc. Please keep sorted alphabetically.
@@ -214,7 +214,7 @@ BASE_DECLARE_FEATURE_PARAM(
 // LINT.ThenChange(//chrome/browser/signin/signin_hats_util.cc)
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls the duration for which the launch of an identity survey is delayed.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kChromeIdentitySurveyLaunchWithDelay);
@@ -246,7 +246,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kCrossDeviceSigninDismissModals);
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Feature flag to enable cross-device sign-in promo.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kCrossDeviceSigninFromDesktop);
@@ -281,7 +281,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kDiceLinkedAccounts);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls whether the First Run animations are disabled or not. If the feature
 // is enabled, animations in the First Run are disabled, otherwise they're
 // enabled. It should be only used for the testing purposes (e.g. pixel tests)
@@ -539,7 +539,7 @@ extern const base::FeatureParam<base::TimeDelta>
     kPolicyDisclaimerRegistrationRetryDelay;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This feature controls showing the visually refreshed enterprise signin
 // dialogs, i.e. all the screens served by `ManagedUserProfileNoticeUI`
 // (enterprise profile welcome/creation, OIDC and the device signals
@@ -576,7 +576,7 @@ BASE_DECLARE_FEATURE(kExtensionWebAuthFlowInitiatorOri
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFetchAccountCapabilitiesOnRestart);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This feature controls running visually refreshed first run and profile
 // creation flows, including the choice screen, for users in search engine
 // choice screen regions. This feature is no-op if `kFirstRunDesktopRefresh` is
@@ -589,7 +589,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFirstRunDesktopChoiceScreenRefresh);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This feature controls running visually refreshed first run and profile
 // creation flows for users outside of the search engine choice regions. To
 // enable the refresh in search engine choice screen regions,
@@ -607,7 +607,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 bool IsFirstRunDesktopRefreshEnabled(bool is_in_search_engine_choice_region);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kFirstRunDesktopRefresh`.
 //
@@ -617,7 +617,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFirstRunDesktopRefreshSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // It enables the first run revamp (introduce new UIs and additional effects).
 // This feature is no-op if `kFirstRunDesktopRefresh` is disabled.
 //
@@ -633,7 +633,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 bool IsFirstRunDesktopRevampEnabled(bool is_in_search_engine_choice_region);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kFirstRunDesktopRevamp` for users who are not eligible for
 // the Feature Showcase.
@@ -644,14 +644,14 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFirstRunDesktopRevampNoFeatureShowcaseSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Killswitch for the sound experience in the first run desktop revamp.
 // This feature is no-op if `kFirstRunDesktopRevamp` is disabled.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFirstRunDesktopRevampSound);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kFirstRunDesktopRevamp` for users who are eligible for the
 // Feature Showcase.
@@ -662,7 +662,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kFirstRunDesktopRevampSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This feature controls whether Gemini step can be shown in the feature
 // showcase. This feature is no-op if IsFirstRunDesktopRevamp() equals false.
 //
@@ -772,7 +772,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kOpenSystemAccountSettingsDirectly);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // It enables the pre first run desktop refresh (changes to the onboarding flow
 // prior to the core first run).
 //
@@ -791,7 +791,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 bool IsPreFirstRunDesktopRefreshEnabled();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kPreFirstRunDesktopRefresh` for users who are not eligible
 // for the Feature Showcase.
@@ -802,7 +802,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kPreFirstRunDesktopRefreshNoFeatureShowcaseSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A HaTS survey flag for the survey to gather user feedback after the changes
 // introduced with `kPreFirstRunDesktopRefresh` for users who are eligible for
 // the Feature Showcase.
@@ -813,7 +813,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kPreFirstRunDesktopRefreshSurvey);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Experimenting with changing the secondary CTA for FRE and new profile
 // creation.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
@@ -888,7 +888,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSigninLevelUpButton);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Uses the Material Next theme for the signin promo.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSignInPromoMaterialNextUI);
@@ -948,7 +948,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSupportAddSessionEmailPrefill);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Kill switch for displaying sign-in errors in the profile picker.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSupportErrorsInProfilePicker);
