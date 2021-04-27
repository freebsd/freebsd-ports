--- chrome/browser/password_manager/password_store_factory.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/password_manager/password_store_factory.cc
@@ -166,7 +166,7 @@ PasswordStoreFactory::BuildServiceInstanceFor(
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
           IdentityManagerFactory::GetForProfile(profile));
