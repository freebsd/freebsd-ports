--- components/signin/public/identity_manager/account_capabilities.h.orig	2026-11-17 21:17:00 UTC
+++ components/signin/public/identity_manager/account_capabilities.h
@@ -91,7 +91,7 @@ class AccountCapabilities {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   // Whether the account can submit feedback. For iOS, this is implemented by
   // Aloha FeedbackKit. For Android, this is implemented by GMS Core.
   signin::Tribool can_submit_feedback() const;
