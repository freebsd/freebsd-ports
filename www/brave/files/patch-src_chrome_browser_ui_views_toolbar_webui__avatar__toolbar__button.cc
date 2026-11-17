--- src/chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc
@@ -223,7 +223,7 @@ void WebUIAvatarToolbarButton::MaybeShow
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebUIAvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (state_manager_ && delegate_->GetView()->GetWidget()) {
     state_manager_->MaybeShowSupervisedUserSignInIPH();
