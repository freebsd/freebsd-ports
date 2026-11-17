--- src/chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h
@@ -55,7 +55,7 @@ class WebUIAvatarToolbarButton : public
       bool should_announce) override;
   bool HasExplicitButtonState() const override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
