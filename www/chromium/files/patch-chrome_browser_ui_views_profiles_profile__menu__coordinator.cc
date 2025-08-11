--- chrome/browser/ui/views/profiles/profile_menu_coordinator.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_coordinator.cc
@@ -47,7 +47,7 @@ void ProfileMenuCoordinator::Show(
   user_education_->NotifyFeaturePromoFeatureUsed(
       feature_engagement::kIPHProfileSwitchFeature,
       FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   user_education_->NotifyFeaturePromoFeatureUsed(
       feature_engagement::kIPHSupervisedUserProfileSigninFeature,
       FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
