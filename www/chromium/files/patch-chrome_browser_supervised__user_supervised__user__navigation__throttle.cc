--- chrome/browser/supervised_user/supervised_user_navigation_throttle.cc.orig	2024-09-30 07:45:04 UTC
+++ chrome/browser/supervised_user/supervised_user_navigation_throttle.cc
@@ -212,7 +212,7 @@ void SupervisedUserNavigationThrottle::OnInterstitialR
       Profile* profile = Profile::FromBrowserContext(
           navigation_handle()->GetWebContents()->GetBrowserContext());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (base::FeatureList::IsEnabled(
               supervised_user::
                   kForceSupervisedUserReauthenticationForBlockedSites) &&
