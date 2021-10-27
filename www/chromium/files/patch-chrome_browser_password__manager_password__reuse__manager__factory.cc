--- chrome/browser/password_manager/password_reuse_manager_factory.cc.orig	2021-09-24 18:25:48 UTC
+++ chrome/browser/password_manager/password_reuse_manager_factory.cc
@@ -92,7 +92,7 @@ KeyedService* PasswordReuseManagerFactory::BuildServic
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
