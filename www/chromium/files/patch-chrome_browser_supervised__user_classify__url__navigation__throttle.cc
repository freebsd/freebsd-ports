--- chrome/browser/supervised_user/classify_url_navigation_throttle.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/supervised_user/classify_url_navigation_throttle.cc
@@ -45,7 +45,7 @@ namespace supervised_user {
 namespace {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 bool ShouldShowReAuthInterstitial(
     content::NavigationHandle& navigation_handle) {
 #if BUILDFLAG(IS_ANDROID)
@@ -245,7 +245,7 @@ void ClassifyUrlNavigationThrottle::OnInterstitialResu
     case InterstitialResultCallbackActions::kCancelWithInterstitial: {
       CHECK(navigation_handle());
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       if (ShouldShowReAuthInterstitial(*navigation_handle())) {
         // Show the re-authentication interstitial if the user signed out of
         // the content area, as parent's approval requires authentication.
