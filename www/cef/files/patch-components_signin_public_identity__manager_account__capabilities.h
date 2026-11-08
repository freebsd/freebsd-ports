--- components/signin/public/identity_manager/account_capabilities.h.orig	2026-08-12 09:02:10 UTC
+++ components/signin/public/identity_manager/account_capabilities.h
@@ -93,7 +93,7 @@ class AccountCapabilities {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   // Whether the account can submit feedback. For iOS, this is implemented by
   // Aloha FeedbackKit. For Android, this is implemented by GMS Core.
   signin::Tribool can_submit_feedback() const;
