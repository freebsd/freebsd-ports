--- chrome/browser/ui/views/profiles/profile_menu_coordinator.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_coordinator.cc
@@ -87,7 +87,7 @@ void ProfileMenuCoordinator::ShowWithPromoResults(
       ->NotifyFeaturePromoFeatureUsed(
           feature_engagement::kIPHProfileSwitchFeature,
           FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserUserEducationInterface::From(GetBrowser())
       ->NotifyFeaturePromoFeatureUsed(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature,
