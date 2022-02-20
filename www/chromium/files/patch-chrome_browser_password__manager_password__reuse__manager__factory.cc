--- chrome/browser/password_manager/password_reuse_manager_factory.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/password_manager/password_reuse_manager_factory.cc
@@ -94,7 +94,7 @@ KeyedService* PasswordReuseManagerFactory::BuildServic
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
           IdentityManagerFactory::GetForProfile(profile));
