--- chrome/browser/supervised_user/classify_url_navigation_throttle.cc.orig	2025-02-20 09:59:21 UTC
+++ chrome/browser/supervised_user/classify_url_navigation_throttle.cc
@@ -218,7 +218,7 @@ void ClassifyUrlNavigationThrottle::OnInterstitialResu
     case SupervisedUserNavigationThrottle::kCancelWithInterstitial: {
       CHECK(navigation_handle());
 // LINT.IfChange(cancel_with_interstitial)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (ShouldShowReAuthInterstitial(*navigation_handle(), is_main_frame)) {
         // Show the re-authentication interstitial if the user signed out of
         // the content area, as parent's approval requires authentication.
