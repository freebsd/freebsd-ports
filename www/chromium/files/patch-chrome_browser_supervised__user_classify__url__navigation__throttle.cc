--- chrome/browser/supervised_user/classify_url_navigation_throttle.cc.orig	2026-02-11 09:05:39 UTC
+++ chrome/browser/supervised_user/classify_url_navigation_throttle.cc
@@ -42,7 +42,7 @@ namespace supervised_user {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool ShouldShowReAuthInterstitial(
     content::NavigationHandle& navigation_handle) {
   Profile* profile = Profile::FromBrowserContext(
@@ -209,7 +209,7 @@ void ClassifyUrlNavigationThrottle::OnInterstitialResu
     }
     case InterstitialResultCallbackActions::kCancelWithInterstitial: {
       CHECK(navigation_handle());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (ShouldShowReAuthInterstitial(*navigation_handle())) {
         // Show the re-authentication interstitial if the user signed out of
         // the content area, as parent's approval requires authentication.
