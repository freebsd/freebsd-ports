--- src/components/password_manager/core/browser/stub_password_manager_client.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/password_manager/core/browser/stub_password_manager_client.cc
@@ -235,7 +235,7 @@ version_info::Channel StubPasswordManage
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void StubPasswordManagerClient::OpenPasswordDetailsBubble(
     const password_manager::PasswordForm& form) {}
 void StubPasswordManagerClient::MaybeShowSavePasswordPrimingPromo(
