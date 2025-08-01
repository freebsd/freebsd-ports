--- src/3rdparty/chromium/components/password_manager/core/browser/password_manual_fallback_flow.h.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/password_manual_fallback_flow.h
@@ -17,7 +17,7 @@
 #include "components/password_manager/core/browser/ui/saved_passwords_presenter.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/password_manager/core/browser/password_cross_domain_confirmation_popup_controller.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -178,7 +178,7 @@ class PasswordManualFallbackFlow : public autofill::Au
   std::unique_ptr<device_reauth::DeviceAuthenticator> authenticator_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PasswordCrossDomainConfirmationPopupController>
       cross_domain_confirmation_popup_controller_;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
