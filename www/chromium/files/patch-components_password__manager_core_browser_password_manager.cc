--- components/password_manager/core/browser/password_manager.cc.orig	2017-12-24 01:41:33.322933000 +0100
+++ components/password_manager/core/browser/password_manager.cc	2017-12-24 01:42:03.056816000 +0100
@@ -780,7 +780,7 @@
     if (!client_->GetStoreResultFilter()->ShouldSave(
             *provisional_save_manager_->submitted_form())) {
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS)) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       // When |username_value| is empty, it's not clear whether the submitted
       // credentials are really sync credentials. Don't save sync password hash
       // in that case.
