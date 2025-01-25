--- chrome/browser/supervised_user/supervised_user_navigation_throttle.cc.orig	2025-01-25 09:34:31 UTC
+++ chrome/browser/supervised_user/supervised_user_navigation_throttle.cc
@@ -215,7 +215,7 @@ void SupervisedUserNavigationThrottle::OnInterstitialR
     case kCancelWithInterstitial: {
       CHECK(navigation_handle());
 // LINT.IfChange(cancel_with_interstitial)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (supervised_user::ShouldShowReAuthInterstitial(*navigation_handle(),
                                                         is_main_frame)) {
         // Show the re-authentication interstitial if the user signed out of
@@ -246,7 +246,7 @@ void SupervisedUserNavigationThrottle::OnInterstitialR
 }
 
 namespace supervised_user {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 bool ShouldShowReAuthInterstitial(content::NavigationHandle& navigation_handle,
                                   bool is_main_frame) {
