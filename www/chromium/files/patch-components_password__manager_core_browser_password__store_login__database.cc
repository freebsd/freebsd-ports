--- components/password_manager/core/browser/password_store/login_database.cc.orig	2025-12-05 10:12:50 UTC
+++ components/password_manager/core/browser/password_store/login_database.cc
@@ -1043,7 +1043,7 @@ bool ShouldDeleteUndecryptablePasswords(
     bool is_enabled_by_policy,
     IsAccountStore is_account_store,
     const os_crypt_async::Encryptor* encryptor) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> environment(base::Environment::Create());
   // On Linux user data directory ca be specified using an env variable. If it
   // exists, passwords shouldn't be deleted.
@@ -1061,7 +1061,7 @@ bool ShouldDeleteUndecryptablePasswords(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(password_manager::kPasswordStore)) {
     RecordShouldDeleteUndecryptablePasswordsMetric(
         ShouldDeleteUndecryptablePasswordsResult::
