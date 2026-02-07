--- chrome/browser/supervised_user/supervised_user_browser_utils.h.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/supervised_user/supervised_user_browser_utils.h
@@ -52,7 +52,7 @@ std::string GetAccountGivenName(Profile& profile);
 // of the user.
 void AssertChildStatusOfTheUser(Profile* profile, bool is_child);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns the html content of the reauthentication interstitial for blocked
 // sites. This interstitial is associated with the given NavigationHandle.
 std::string CreateReauthenticationInterstitialForBlockedSites(
