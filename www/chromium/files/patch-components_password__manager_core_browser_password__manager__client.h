--- components/password_manager/core/browser/password_manager_client.h.orig	2026-07-01 06:24:19 UTC
+++ components/password_manager/core/browser/password_manager_client.h
@@ -30,7 +30,7 @@
 #include "net/cert/cert_status_flags.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/i18n/rtl.h"
 #include "components/password_manager/core/browser/password_cross_domain_confirmation_popup_controller.h"
 #include "ui/gfx/geometry/rect_f.h"
@@ -552,7 +552,7 @@ class PasswordManagerClient {
   virtual void TriggerSignIn(signin_metrics::AccessPoint access_point) const;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Shows the bubble with the details of the `form`.
   virtual void OpenPasswordDetailsBubble(
       const password_manager::PasswordForm& form) = 0;
