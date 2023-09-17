--- components/supervised_user/core/browser/supervised_user_service.cc.orig	2023-09-17 07:59:53 UTC
+++ components/supervised_user/core/browser/supervised_user_service.cc
@@ -73,7 +73,7 @@ void SupervisedUserService::Init() {
       static_cast<supervised_user::FirstTimeInterstitialBannerState>(
           user_prefs_->GetInteger(prefs::kFirstTimeInterstitialBannerState));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (supervised_user::CanDisplayFirstTimeInterstitialBanner()) {
     if (banner_state ==
             supervised_user::FirstTimeInterstitialBannerState::kUnknown &&
