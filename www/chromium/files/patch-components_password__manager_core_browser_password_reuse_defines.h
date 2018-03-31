--- components/password_manager/core/browser/password_reuse_defines.h.orig	2018-03-20 23:05:22.000000000 +0100
+++ components/password_manager/core/browser/password_reuse_defines.h	2018-03-24 13:50:16.794379000 +0100
@@ -6,7 +6,7 @@
 #define COMPONENTS_PASSWORD_MANAGER_CORE_BROWSER_PASSWORD_REUSE_DEFINES_H_
 
 #if defined(OS_WIN) || (defined(OS_MACOSX) && !defined(OS_IOS)) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Enable the detection when the sync password is typed not on the sync domain.
 #define SYNC_PASSWORD_REUSE_DETECTION_ENABLED
 #endif
