--- chrome/browser/ui/views/profiles/profile_menu_coordinator.cc.orig	2026-06-04 10:12:25 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_coordinator.cc
@@ -82,7 +82,7 @@ void ProfileMenuCoordinator::ShowWithPromoResults(
       ->NotifyFeaturePromoFeatureUsed(
           feature_engagement::kIPHProfileSwitchFeature,
           FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserUserEducationInterface::From(GetBrowser())
       ->NotifyFeaturePromoFeatureUsed(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature,
