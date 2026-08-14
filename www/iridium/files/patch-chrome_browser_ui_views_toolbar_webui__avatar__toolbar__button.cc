--- chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc
@@ -216,7 +216,7 @@ void WebUIAvatarToolbarButton::MaybeShowProfileSwitchI
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebUIAvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (state_manager_ && delegate_->GetView()->GetWidget()) {
     state_manager_->MaybeShowSupervisedUserSignInIPH();
