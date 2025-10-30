--- components/signin/public/base/signin_switches.h.orig	2025-10-30 15:44:36 UTC
+++ components/signin/public/base/signin_switches.h
@@ -77,7 +77,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kCctSignInPrompt);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables surveys to measure the effectiveness of the identity model.
 // These surveys would be displayed after interactions such as signin, profile
 // switching, etc. Please keep sorted alphabetically.
@@ -109,7 +109,7 @@ BASE_DECLARE_FEATURE(kChromeIdentitySurveySwitchProfil
 // LINT.ThenChange(//chrome/browser/signin/signin_hats_util.cc)
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls the duration for which the launch of an identity survey is delayed.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kChromeIdentitySurveyLaunchWithDelay);
@@ -277,7 +277,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kRollbackDiceMigration);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Uses the Material Next theme for the signin promo.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSignInPromoMaterialNextUI);
