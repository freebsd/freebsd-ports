--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2024-07-31 14:19:23 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -559,7 +559,7 @@ void ChromePasswordManagerClient::
 
 bool ChromePasswordManagerClient::CanUseBiometricAuthForFilling(
     device_reauth::DeviceAuthenticator* authenticator) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -785,7 +785,7 @@ void ChromePasswordManagerClient::NotifyUserCredential
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   manage_passwords_ui_controller->OnKeychainError();
