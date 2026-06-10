--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -439,7 +439,7 @@ void AvatarToolbarButton::MaybeShowProfileSwitchIPH() 
   state_manager_->MaybeShowProfileSwitchIPH();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   state_manager_->MaybeShowSupervisedUserSignInIPH();
 }
