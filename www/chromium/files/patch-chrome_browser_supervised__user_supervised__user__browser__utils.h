--- chrome/browser/supervised_user/supervised_user_browser_utils.h.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/supervised_user/supervised_user_browser_utils.h
@@ -47,14 +47,14 @@ ProfileSelections BuildProfileSelectionsForRegularAndG
 std::string GetAccountGivenName(Profile& profile);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Returns the html content of the reauthentication interstitial for blocked
 // sites. This interstitial is associated with the given NavigationHandle.
 std::string CreateReauthenticationInterstitialForBlockedSites(
     content::NavigationHandle& navigation_handle);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitialForYouTube(
     content::NavigationHandle& navigation_handle);
 #endif
