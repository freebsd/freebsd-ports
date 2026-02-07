--- src/3rdparty/chromium/components/password_manager/core/browser/password_store/login_database_async_helper.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/password_store/login_database_async_helper.cc
@@ -154,7 +154,7 @@ LoginsResultOrError LoginDatabaseAsyncHelper::FillMatc
     std::vector<PasswordForm> matched_forms;
     if (!login_db_ ||
         !login_db_->GetLogins(form, include_psl, &matched_forms)) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return PasswordStoreBackendError(
           OSCrypt::IsEncryptionAvailable()
               ? PasswordStoreBackendErrorType::kUncategorized
