--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -406,7 +406,7 @@ void AvatarToolbarButton::MaybeShowProfileSwitchIPH() 
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (!base::FeatureList::IsEnabled(
           feature_engagement::kIPHSupervisedUserProfileSigninFeature)) {
