--- components/password_manager/core/browser/password_store/login_database_async_helper.cc.orig	2026-10-18 13:29:39 UTC
+++ components/password_manager/core/browser/password_store/login_database_async_helper.cc
@@ -143,7 +143,7 @@ LoginDatabaseAsyncHelper::FillMatchingLogins(
     std::vector<StoredCredential> matched_credentials;
     if (!login_db_ ||
         !login_db_->GetLogins(form, include_psl, &matched_credentials)) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
       return base::unexpected(PasswordStoreBackendError(
           is_encryption_available_
               ? PasswordStoreBackendErrorType::kUncategorized
