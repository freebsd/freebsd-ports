--- components/password_manager/core/browser/password_manager_client.h.orig	2024-07-31 14:19:23 UTC
+++ components/password_manager/core/browser/password_manager_client.h
@@ -30,7 +30,7 @@
 #include "net/cert/cert_status_flags.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/i18n/rtl.h"
 #include "components/password_manager/core/browser/password_cross_domain_confirmation_popup_controller.h"
 #include "ui/gfx/geometry/rect_f.h"
@@ -507,7 +507,7 @@ class PasswordManagerClient {
   virtual void RefreshPasswordManagerSettingsIfNeeded() const;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Creates and show the cross domain confirmation popup.
   virtual std::unique_ptr<PasswordCrossDomainConfirmationPopupController>
   ShowCrossDomainConfirmationPopup(const gfx::RectF& element_bounds,
