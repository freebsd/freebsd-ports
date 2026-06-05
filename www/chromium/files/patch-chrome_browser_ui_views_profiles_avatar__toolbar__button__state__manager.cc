--- chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.cc.orig	2026-06-04 10:12:25 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button_state_manager.cc
@@ -2488,7 +2488,7 @@ void AvatarToolbarButtonStateManager::MaybeShowProfile
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButtonStateManager::MaybeShowSupervisedUserSignInIPH() {
   if (!base::FeatureList::IsEnabled(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature)) {
