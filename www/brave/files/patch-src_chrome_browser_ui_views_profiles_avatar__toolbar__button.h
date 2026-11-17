--- src/chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -66,7 +66,7 @@ class AvatarToolbarButton : public Toolb
   void SetAnnounceCallbackForTesting(
       base::OnceCallback<void(std::u16string)> callback) override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif
