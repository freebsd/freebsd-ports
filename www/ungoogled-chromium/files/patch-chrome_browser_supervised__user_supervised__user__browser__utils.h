--- chrome/browser/supervised_user/supervised_user_browser_utils.h.orig	2024-10-01 07:26:23 UTC
+++ chrome/browser/supervised_user/supervised_user_browser_utils.h
@@ -11,7 +11,7 @@
 #include "content/public/browser/web_contents.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_page.h"
 #endif
 
@@ -59,7 +59,7 @@ void AssertChildStatusOfTheUser(Profile* profile, bool
 // content area.
 bool IsAuthenticatedSupervisedProfile(Profile* profile);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns the html content of the reauthentication interstitial for blocked
 // sites. This interstitial is associated with the given NavigationHandle.
 std::string CreateReauthenticationInterstitial(
