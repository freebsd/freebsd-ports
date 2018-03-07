--- components/password_manager/core/browser/password_manager.cc.orig	2018-02-24 16:25:13.000000000 +0100
+++ components/password_manager/core/browser/password_manager.cc	2018-03-03 22:48:08.497290000 +0100
@@ -823,7 +823,7 @@
   if (!client_->GetStoreResultFilter()->ShouldSave(
           *provisional_save_manager_->submitted_form())) {
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS)) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     // When |username_value| is empty, it's not clear whether the submitted
     // credentials are really sync credentials. Don't save sync password hash
     // in that case.
