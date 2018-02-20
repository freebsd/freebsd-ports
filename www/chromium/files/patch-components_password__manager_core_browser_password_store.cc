--- components/password_manager/core/browser/password_store.cc.orig	2017-12-30 02:35:17.422703000 +0100
+++ components/password_manager/core/browser/password_store.cc	2017-12-30 02:35:55.798169000 +0100
@@ -274,7 +274,7 @@
   }
 
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS)) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (!sync_username.empty())
     hash_password_manager_.ReportIsSyncPasswordHashSavedMetric();
 #endif
