--- src/components/password_manager/core/browser/password_autofill_manager.h.orig	2026-10-18 18:43:23 UTC
+++ src/components/password_manager/core/browser/password_autofill_manager.h
@@ -306,7 +306,7 @@ class PasswordAutofillManager : public a
 
   // Stores the controller of warning popup UI on cross domain filling.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PasswordCrossDomainConfirmationPopupController>
       cross_domain_confirmation_controller_;
 #endif
