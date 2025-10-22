--- components/password_manager/core/browser/password_autofill_manager.h.orig	2025-10-21 16:57:35 UTC
+++ components/password_manager/core/browser/password_autofill_manager.h
@@ -287,7 +287,7 @@ class PasswordAutofillManager : public autofill::Autof
 
   // Stores the controller of warning popup UI on cross domain filling.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PasswordCrossDomainConfirmationPopupController>
       cross_domain_confirmation_controller_;
 #endif
