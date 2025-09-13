--- chrome/browser/ui/views/profiles/profile_menu_coordinator.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_coordinator.cc
@@ -55,7 +55,7 @@ void ProfileMenuCoordinator::Show(
       ->NotifyFeaturePromoFeatureUsed(
           feature_engagement::kIPHProfileSwitchFeature,
           FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserUserEducationInterface::From(GetBrowser())
       ->NotifyFeaturePromoFeatureUsed(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature,
