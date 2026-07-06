--- components/password_manager/core/browser/password_store/login_database_async_helper.cc.orig	2026-06-05 13:45:06 UTC
+++ components/password_manager/core/browser/password_store/login_database_async_helper.cc
@@ -138,7 +138,7 @@ StoredCredentialsResultOrError LoginDatabaseAsyncHelpe
     std::vector<StoredCredential> matched_credentials;
     if (!login_db_ ||
         !login_db_->GetLogins(form, include_psl, &matched_credentials)) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return PasswordStoreBackendError(
           is_encryption_available_
               ? PasswordStoreBackendErrorType::kUncategorized
