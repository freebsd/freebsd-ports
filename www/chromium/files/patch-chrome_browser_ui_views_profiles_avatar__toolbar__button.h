--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -70,7 +70,7 @@ class AvatarToolbarButton : public ToolbarButton,
   void SetAnnounceCallbackForTesting(
       base::OnceCallback<void(std::u16string)> callback) override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif
