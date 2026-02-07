--- components/signin/public/base/signin_switches.cc.orig	2026-01-14 08:33:23 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -108,7 +108,7 @@ BASE_FEATURE(kChromeAndroidIdentitySurveyBookmarkPromo
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kChromeIdentitySurveyAddressBubbleSignin,
              base::FEATURE_DISABLED_BY_DEFAULT);
 BASE_FEATURE(kChromeIdentitySurveyDiceWebSigninAccepted,
@@ -135,7 +135,7 @@ BASE_FEATURE(kChromeIdentitySurveySwitchProfileFromPro
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kChromeIdentitySurveyLaunchWithDelay,
              base::FEATURE_ENABLED_BY_DEFAULT);
 BASE_FEATURE_PARAM(base::TimeDelta,
@@ -356,7 +356,7 @@ BASE_FEATURE_PARAM(base::TimeDelta,
                    base::Days(7));
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kOpenAllProfilesFromProfilePickerExperiment,
              base::FEATURE_DISABLED_BY_DEFAULT);
 const base::FeatureParam<int>
@@ -365,7 +365,7 @@ const base::FeatureParam<int>
         "max_profiles_count_to_show_open_all_button_in_profile_picker", 5};
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kProfileCreationDeclineSigninCTAExperiment,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
@@ -403,7 +403,7 @@ BASE_FEATURE(kProfilesReordering, base::FEATURE_DISABL
 BASE_FEATURE(kRollbackDiceMigration, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kShowProfilePickerToAllUsersExperiment,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -418,7 +418,7 @@ const base::FeatureParam<int> kContextualSigninPromoDi
     "contextual_signin_promo_dismissed_threshold",
     2);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSignInPromoMaterialNextUI, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
