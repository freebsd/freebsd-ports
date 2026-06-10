--- chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h
@@ -44,7 +44,7 @@ class WebUIAvatarToolbarButton : public AvatarToolbarB
           explicit_action) override;
   bool HasExplicitButtonState() const override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
