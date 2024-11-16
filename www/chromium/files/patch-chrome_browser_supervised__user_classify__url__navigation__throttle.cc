--- chrome/browser/supervised_user/classify_url_navigation_throttle.cc.orig	2024-11-14 07:57:23 UTC
+++ chrome/browser/supervised_user/classify_url_navigation_throttle.cc
@@ -219,7 +219,7 @@ void ClassifyUrlNavigationThrottle::OnInterstitialResu
     case SupervisedUserNavigationThrottle::kCancelWithInterstitial: {
       CHECK(navigation_handle());
 // LINT.IfChange(cancel_with_interstitial)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (ShouldShowReAuthInterstitial(*navigation_handle(), is_main_frame)) {
         // Show the re-authentication interstitial if the user signed out of
         // the content area, as parent's approval requires authentication.
