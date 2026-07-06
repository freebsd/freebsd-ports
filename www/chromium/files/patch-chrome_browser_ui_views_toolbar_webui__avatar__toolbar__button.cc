--- chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc
@@ -136,7 +136,7 @@ void WebUIAvatarToolbarButton::MaybeShowProfileSwitchI
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebUIAvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (state_manager_ && delegate_->GetView()->GetWidget()) {
     state_manager_->MaybeShowSupervisedUserSignInIPH();
