--- components/signin/public/base/signin_switches.cc.orig	2026-08-31 10:59:09 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -33,7 +33,7 @@ const char kForceFreFeatureShowcaseSteps[] = "force-fr
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Feature param to pass probability for identity surveys.
 constexpr char kHatsSurveyProbabilityName[] = "probability";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -84,7 +84,7 @@ base::TimeDelta GetAvatarSyncPromoFeatureMinimumCookeA
 BASE_FEATURE(kAvoidAutoTriggerListAccountsOnStale,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kBeforeFirstRunDesktopRefreshSurvey,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -160,7 +160,7 @@ BASE_FEATURE_PARAM(double,
                    0.42);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr double kMediumSurveyProbability = 0.08;
 constexpr double kLowSurveyProbability = 0.008;
 BASE_FEATURE(kChromeIdentitySurveyAddressBubbleSignin,
@@ -252,7 +252,7 @@ BASE_FEATURE_PARAM(
     kMediumSurveyProbability);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kChromeIdentitySurveyLaunchWithDelay,
              base::FEATURE_ENABLED_BY_DEFAULT);
 BASE_FEATURE_PARAM(base::TimeDelta,
@@ -267,13 +267,13 @@ BASE_FEATURE(kChromeOsUseConsentLevelSigninForNewUsers
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kCrossDeviceSignin, base::FEATURE_DISABLED_BY_DEFAULT);
 const base::FeatureParam<std::string> kCrossDeviceSigninUrl{&kCrossDeviceSignin,
                                                             "url", ""};
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kCrossDeviceSigninFromDesktop, base::FEATURE_DISABLED_BY_DEFAULT);
 const base::FeatureParam<std::string> kCrossDeviceSigninFromDesktopUrl{
     &kCrossDeviceSigninFromDesktop, "url",
@@ -290,7 +290,7 @@ BASE_FEATURE(kDiceHeaderVersion2, base::FEATURE_DISABL
 BASE_FEATURE(kDiceLinkedAccounts, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDisableU18FeedbackDesktop, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -560,7 +560,7 @@ const base::FeatureParam<base::TimeDelta>
 
 BASE_FEATURE(kFetchAccountInfoOnRestart, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_WIN)
 BASE_FEATURE(kFirstRunDesktopRefresh, base::FEATURE_ENABLED_BY_DEFAULT);
 #else
@@ -592,11 +592,11 @@ constexpr base::FeatureParam<FirstRunDesktopSignInProm
         &kFirstRunDesktopSignInPromoVariations};
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFirstRunDesktopRefreshSurvey, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFirstRunDesktopRevamp, base::FEATURE_DISABLED_BY_DEFAULT);
 BASE_FEATURE(kFirstRunDesktopRevampSound, base::FEATURE_ENABLED_BY_DEFAULT);
 bool IsFirstRunDesktopRevampEnabled(bool is_in_search_engine_choice_region) {
@@ -605,16 +605,16 @@ bool IsFirstRunDesktopRevampEnabled(bool is_in_search_
 }
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFirstRunDesktopRevampNoFeatureShowcaseSurvey,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFirstRunDesktopRevampSurvey, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFirstRunFeatureShowcaseGeminiStep,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -697,7 +697,7 @@ BASE_FEATURE(kNoAccountWebSignin, base::FEATURE_DISABL
 
 BASE_FEATURE(kNonDefaultGaiaOriginCheck, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kPreFirstRunDesktopRefresh, base::FEATURE_DISABLED_BY_DEFAULT);
 bool IsPreFirstRunDesktopRefreshEnabled(
     bool is_in_search_engine_choice_region) {
@@ -706,7 +706,7 @@ bool IsPreFirstRunDesktopRefreshEnabled(
 }
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kProfileCreationDeclineSigninCTAExperiment,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -748,7 +748,7 @@ const base::FeatureParam<int> kContextualSigninPromoDi
     "contextual_signin_promo_dismissed_threshold",
     2);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSignInPromoMaterialNextUI, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -818,7 +818,7 @@ BASE_FEATURE(kStableDeviceId, base::FEATURE_DISABLED_B
 BASE_FEATURE(kSupportAddSessionEmailPrefill, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Kill switch for displaying sign-in errors in the profile picker.
 BASE_FEATURE(kSupportErrorsInProfilePicker, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
