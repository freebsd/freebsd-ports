--- chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h
@@ -55,7 +55,7 @@ class WebUIAvatarToolbarButton : public AvatarToolbarB
       bool should_announce) override;
   bool HasExplicitButtonState() const override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
