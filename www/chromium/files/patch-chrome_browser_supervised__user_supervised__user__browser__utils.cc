--- chrome/browser/supervised_user/supervised_user_browser_utils.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/supervised_user/supervised_user_browser_utils.cc
@@ -35,13 +35,13 @@
 #include "url/url_constants.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page_blocked_sites.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
         // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_page_youtube.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -143,7 +143,7 @@ std::string GetAccountGivenName(Profile& profile) {
   return std::string(account_info.GetGivenName().value_or(""));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitialForYouTube(
     content::NavigationHandle& navigation_handle) {
   content::WebContents* web_contents = navigation_handle.GetWebContents();
@@ -171,7 +171,7 @@ std::string CreateReauthenticationInterstitialForYouTu
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitialForBlockedSites(
     content::NavigationHandle& navigation_handle) {
   content::WebContents* web_contents = navigation_handle.GetWebContents();
