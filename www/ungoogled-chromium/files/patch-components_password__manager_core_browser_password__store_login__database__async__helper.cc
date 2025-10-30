--- components/password_manager/core/browser/password_store/login_database_async_helper.cc.orig	2025-11-01 06:40:37 UTC
+++ components/password_manager/core/browser/password_store/login_database_async_helper.cc
@@ -146,7 +146,7 @@ LoginsResultOrError LoginDatabaseAsyncHelper::FillMatc
     std::vector<PasswordForm> matched_forms;
     if (!login_db_ ||
         !login_db_->GetLogins(form, include_psl, &matched_forms)) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return PasswordStoreBackendError(
           OSCrypt::IsEncryptionAvailable()
               ? PasswordStoreBackendErrorType::kUncategorized
