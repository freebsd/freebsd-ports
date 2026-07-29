--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -719,7 +719,7 @@ void ChromePasswordManagerClient::ContinueShowKeyboard
 bool ChromePasswordManagerClient::IsReauthBeforeFillingRequired(
     device_reauth::DeviceAuthenticator* authenticator) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -1002,7 +1002,7 @@ void ChromePasswordManagerClient::NotifyUserCredential
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   if (manage_passwords_ui_controller) {
@@ -2087,7 +2087,7 @@ void ChromePasswordManagerClient::HideFillingUI() {
 bool ChromePasswordManagerClient::IsPasswordManagementEnabledForCurrentPage(
     const GURL& url) const {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (IsPasswordManagerForUrlDisallowedByPolicy(url)) {
     return false;
   }
@@ -2126,7 +2126,7 @@ bool ChromePasswordManagerClient::IsPasswordManagement
 }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool ChromePasswordManagerClient::IsPasswordManagerForUrlDisallowedByPolicy(
     const GURL& url) const {
   if (!GetPrefs() || !GetPrefs()->HasPrefPath(
