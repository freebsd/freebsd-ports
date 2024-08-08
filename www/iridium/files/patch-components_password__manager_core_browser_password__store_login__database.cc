--- components/password_manager/core/browser/password_store/login_database.cc.orig	2024-08-01 05:47:53 UTC
+++ components/password_manager/core/browser/password_store/login_database.cc
@@ -1020,7 +1020,7 @@ void RecordShouldDeleteUndecryptablePasswordsMetric(
 }
 
 bool ShouldDeleteUndecryptablePasswords() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string user_data_dir_string;
   std::unique_ptr<base::Environment> environment(base::Environment::Create());
   // On Linux user data directory ca be specified using an env variable. If it
@@ -1039,7 +1039,7 @@ bool ShouldDeleteUndecryptablePasswords() {
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(password_manager::kPasswordStore)) {
     RecordShouldDeleteUndecryptablePasswordsMetric(
         ShouldDeleteUndecryptablePasswordsResult::
