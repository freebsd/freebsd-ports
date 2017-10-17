--- components/password_manager/core/browser/password_manager_metrics_util.h.orig	2017-09-08 15:25:43.691124000 +0200
+++ components/password_manager/core/browser/password_manager_metrics_util.h	2017-09-08 15:36:05.359582000 +0200
@@ -227,7 +227,7 @@
 };
 
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS)) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 enum class SyncPasswordHashChange {
   SAVED_ON_CHROME_SIGNIN,
   SAVED_IN_CONTENT_AREA,
@@ -332,7 +332,7 @@
 void LogSubmittedFormFrame(SubmittedFormFrame frame);
 
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS)) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Log a save sync password change event.
 void LogSyncPasswordHashChange(SyncPasswordHashChange event);
 
