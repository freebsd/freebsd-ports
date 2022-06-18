--- components/password_manager/core/browser/login_database.cc.orig	2022-06-17 14:20:10 UTC
+++ components/password_manager/core/browser/login_database.cc
@@ -699,7 +699,7 @@ std::string GeneratePlaceholders(size_t count) {
   return result;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Fills |form| with necessary data required to be removed from the database
 // and returns it.
 PasswordForm GetFormForRemoval(sql::Statement& statement) {
@@ -716,7 +716,7 @@ PasswordForm GetFormForRemoval(sql::Statement& stateme
 // Whether we should try to return the decryptable passwords while the
 // encryption service fails for some passwords.
 bool ShouldReturnPartialPasswords() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kSkipUndecryptablePasswords);
 #else
   return false;
@@ -1545,7 +1545,7 @@ bool LoginDatabase::DeleteAndRecreateDatabaseFile() {
 }
 
 DatabaseCleanupResult LoginDatabase::DeleteUndecryptableLogins() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   TRACE_EVENT0("passwords", "LoginDatabase::DeleteUndecryptableLogins");
   // If the Keychain in MacOS or the real secret key in Linux is unavailable,
   // don't delete any logins.
