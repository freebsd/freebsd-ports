--- chrome/browser/ui/views/profiles/avatar_toolbar_button.cc.orig	2026-06-04 10:12:25 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.cc
@@ -440,7 +440,7 @@ void AvatarToolbarButton::MaybeShowProfileSwitchIPH() 
   state_manager_->MaybeShowProfileSwitchIPH();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   state_manager_->MaybeShowSupervisedUserSignInIPH();
 }
