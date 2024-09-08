--- components/password_manager/core/browser/stub_password_manager_client.cc.orig	2024-08-27 06:28:16 UTC
+++ components/password_manager/core/browser/stub_password_manager_client.cc
@@ -180,7 +180,7 @@ version_info::Channel StubPasswordManagerClient::GetCh
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::unique_ptr<
     password_manager::PasswordCrossDomainConfirmationPopupController>
 StubPasswordManagerClient::ShowCrossDomainConfirmationPopup(
