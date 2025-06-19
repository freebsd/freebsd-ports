--- chrome/browser/ui/views/profiles/profile_menu_coordinator.cc.orig	2025-06-19 07:37:57 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_coordinator.cc
@@ -52,7 +52,7 @@ void ProfileMenuCoordinator::Show(
   browser.window()->NotifyFeaturePromoFeatureUsed(
       feature_engagement::kIPHProfileSwitchFeature,
       FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser.window()->NotifyFeaturePromoFeatureUsed(
       feature_engagement::kIPHSupervisedUserProfileSigninFeature,
       FeaturePromoFeatureUsedAction::kClosePromoIfPresent);
