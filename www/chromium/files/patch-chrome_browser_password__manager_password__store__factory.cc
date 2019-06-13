--- chrome/browser/password_manager/password_store_factory.cc.orig	2019-06-04 18:55:17 UTC
+++ chrome/browser/password_manager/password_store_factory.cc
@@ -302,7 +302,7 @@ PasswordStoreFactory::BuildServiceInstanceFor(
                                                   network_context_getter);
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
           profile);
