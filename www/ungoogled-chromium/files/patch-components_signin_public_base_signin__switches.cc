--- components/signin/public/base/signin_switches.cc.orig	2026-03-15 18:32:51 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -78,7 +78,7 @@ base::TimeDelta GetAvatarSyncPromoFeatureMinimumCookeA
 #endif
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kBeforeFirstRunDesktopRefreshSurvey,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -113,7 +113,7 @@ BASE_FEATURE(kChromeAndroidIdentitySurveyBookmarkPromo
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kHatsSurveyProbabilityName[] = "probability";
 constexpr double kMediumSurveyProbability = 0.08;
 constexpr double kLowSurveyProbability = 0.008;
@@ -206,7 +206,7 @@ BASE_FEATURE_PARAM(
     kMediumSurveyProbability);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kChromeIdentitySurveyLaunchWithDelay,
              base::FEATURE_ENABLED_BY_DEFAULT);
 BASE_FEATURE_PARAM(base::TimeDelta,
@@ -413,7 +413,7 @@ BASE_FEATURE_PARAM(base::TimeDelta,
                    base::Days(7));
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kOpenAllProfilesFromProfilePickerExperiment,
              base::FEATURE_DISABLED_BY_DEFAULT);
 const base::FeatureParam<int>
@@ -422,7 +422,7 @@ const base::FeatureParam<int>
         "max_profiles_count_to_show_open_all_button_in_profile_picker", 5};
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kPasswordUploadUiUpdate, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kProfileCreationDeclineSigninCTAExperiment,
@@ -467,7 +467,7 @@ BASE_FEATURE(kRestrictDeviceManagementServiceOAuthScop
 BASE_FEATURE(kRollbackDiceMigration, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kShowProfilePickerToAllUsersExperiment,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -488,7 +488,7 @@ const base::FeatureParam<int> kContextualSigninPromoDi
     "contextual_signin_promo_dismissed_threshold",
     2);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSignInPromoMaterialNextUI, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -544,7 +544,7 @@ BASE_FEATURE(kStableDeviceId, base::FEATURE_DISABLED_B
 BASE_FEATURE(kSupportAddSessionEmailPrefill, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Kill switch for displaying sign-in errors in the profile picker.
 BASE_FEATURE(kSupportErrorsInProfilePicker, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
