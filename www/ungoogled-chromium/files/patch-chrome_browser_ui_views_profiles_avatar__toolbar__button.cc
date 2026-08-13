--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -459,7 +459,7 @@ void AvatarToolbarButton::MaybeShowProfileSwitchIPH() 
   state_manager_.MaybeShowProfileSwitchIPH();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   state_manager_.MaybeShowSupervisedUserSignInIPH();
 }
