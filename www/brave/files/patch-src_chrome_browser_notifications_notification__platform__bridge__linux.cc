--- src/chrome/browser/notifications/notification_platform_bridge_linux.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/notifications/notification_platform_bridge_linux.cc
@@ -368,6 +368,8 @@ NotificationResources WriteNotificationR
   result.has_logo = WriteImageFile(logo, dir_path.Append("logo.png"));
   result.has_icon = WriteImageFile(icon, dir_path.Append("icon.png"));
   result.has_image = WriteImageFile(image, dir_path.Append("image.png"));
+  // XXX
+#if !BUILDFLAG(IS_OPENBSD)
   if (result.has_icon) {
     result.icon_bytes = icon;
     if (icon && icon->size() > 0) {
@@ -386,6 +388,7 @@ NotificationResources WriteNotificationR
       }
     }
   }
+#endif
 
   result.dir_path = dir_path;
   result.dir = base::SequenceBound<base::ScopedTempDir>(
