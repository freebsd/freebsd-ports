--- components/password_manager/core/browser/password_store/password_store_built_in_backend.cc.orig	2024-08-26 12:06:38 UTC
+++ components/password_manager/core/browser/password_store/password_store_built_in_backend.cc
@@ -211,7 +211,7 @@ void PasswordStoreBuiltInBackend::InitBackend(
           std::move(clearing_undecryptable_passwords_cb)));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   background_task_runner_->PostTask(
       FROM_HERE,
       base::BindOnce(&LoginDatabaseAsyncHelper::
