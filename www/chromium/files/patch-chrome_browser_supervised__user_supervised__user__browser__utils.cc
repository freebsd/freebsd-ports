--- chrome/browser/supervised_user/supervised_user_browser_utils.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/supervised_user/supervised_user_browser_utils.cc
@@ -39,10 +39,10 @@
 #include "components/user_manager/user.h"
 #include "components/user_manager/user_type.h"
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page_blocked_sites.h"
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_page_youtube.h"
 #endif
 #endif
@@ -166,7 +166,7 @@ void AssertChildStatusOfTheUser(Profile* profile, bool
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitialForYouTube(
     content::NavigationHandle& navigation_handle) {
   content::WebContents* web_contents = navigation_handle.GetWebContents();
@@ -194,7 +194,7 @@ std::string CreateReauthenticationInterstitialForYouTu
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitialForBlockedSites(
     content::NavigationHandle& navigation_handle) {
   content::WebContents* web_contents = navigation_handle.GetWebContents();
