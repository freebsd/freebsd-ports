--- chrome/browser/supervised_user/supervised_user_google_auth_navigation_throttle.cc.orig	2024-08-27 06:28:16 UTC
+++ chrome/browser/supervised_user/supervised_user_google_auth_navigation_throttle.cc
@@ -25,7 +25,7 @@
 
 #if BUILDFLAG(IS_ANDROID)
 #include "chrome/browser/supervised_user/child_accounts/child_account_service_android.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page.h"
 #endif
@@ -139,7 +139,7 @@ SupervisedUserGoogleAuthNavigationThrottle::ShouldProc
     return content::NavigationThrottle::DEFER;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // When an unauthenticated supervised user tries to access YouTube, we force
   // re-authentication with an interstitial so that YouTube can be subject to
   // content restrictions. This interstitial is only available on Desktop
