--- chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h
@@ -57,7 +57,7 @@ class WebUIAvatarToolbarButton : public AvatarToolbarB
       bool should_announce) override;
   bool HasExplicitButtonState() const override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
