--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -67,7 +67,7 @@ class AvatarToolbarButton : public ToolbarButton,
   // void UpdateIcon() also overrides ToolbarButton
   void UpdateText() override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif
