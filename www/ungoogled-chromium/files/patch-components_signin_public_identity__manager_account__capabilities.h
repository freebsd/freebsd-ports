--- components/signin/public/identity_manager/account_capabilities.h.orig	2026-05-09 18:09:27 UTC
+++ components/signin/public/identity_manager/account_capabilities.h
@@ -88,7 +88,7 @@ class AccountCapabilities {
   signin::Tribool can_sign_in_to_chrome() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Whether the account can submit feedback. For iOS, this is implemented by
   // Aloha FeedbackKit. For Android, this is implemented by GMS Core.
   signin::Tribool can_submit_feedback() const;
