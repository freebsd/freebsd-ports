--- chrome/browser/password_manager/password_store_factory.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/password_manager/password_store_factory.cc
@@ -300,7 +300,7 @@ PasswordStoreFactory::BuildServiceInstanceFor(
   password_manager_util::RemoveUselessCredentials(ps, profile->GetPrefs(), 60,
                                                   network_context_getter);
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
