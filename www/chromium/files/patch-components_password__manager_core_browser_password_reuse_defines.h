--- components/password_manager/core/browser/password_reuse_defines.h.orig	2017-09-08 16:48:55.608982000 +0200
+++ components/password_manager/core/browser/password_reuse_defines.h	2017-09-08 16:49:07.942575000 +0200
@@ -6,7 +6,7 @@
 #define COMPONENTS_PASSWORD_MANAGER_CORE_BROWSER_PASSWORD_REUSE_DEFINES_H_
 
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS)) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Enable the detection when the sync password is typed not on the sync domain.
 #define SYNC_PASSWORD_REUSE_DETECTION_ENABLED
 #endif
