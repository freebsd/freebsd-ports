--- chrome/browser/ui/views/passwords/password_bubble_view_base.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/views/passwords/password_bubble_view_base.cc
@@ -37,7 +37,7 @@
 #include "content/public/browser/navigation_controller.h"
 #include "ui/base/metadata/metadata_impl_macros.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/passwords/password_relaunch_chrome_view.h"
 #endif
 
@@ -159,7 +159,7 @@ PasswordBubbleViewBase* PasswordBubbleViewBase::Create
   } else if (model_state ==
              password_manager::ui::NOTIFY_RECEIVED_SHARED_CREDENTIALS) {
     view = new SharedPasswordsNotificationView(web_contents, anchor_view);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (model_state == password_manager::ui::KEYCHAIN_ERROR_STATE) {
     view = new RelaunchChromeView(
         web_contents, anchor_view,
