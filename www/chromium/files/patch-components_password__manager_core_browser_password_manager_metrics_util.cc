--- components/password_manager/core/browser/password_manager_metrics_util.cc.orig	2017-09-08 15:25:36.564744000 +0200
+++ components/password_manager/core/browser/password_manager_metrics_util.cc	2017-09-08 15:26:19.968557000 +0200
@@ -200,7 +200,7 @@
 }
 
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS)) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void LogSyncPasswordHashChange(SyncPasswordHashChange event) {
   UMA_HISTOGRAM_ENUMERATION(
       "PasswordManager.SyncPasswordHashChange", event,
