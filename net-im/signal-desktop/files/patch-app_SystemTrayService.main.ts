--- app/SystemTrayService.main.ts.orig	2025-05-23 13:46:10 UTC
+++ app/SystemTrayService.main.ts
@@ -308,7 +308,7 @@ function getIcon(unreadCount: number) {
 
   let image: NativeImage;
 
-  if (platform === 'linux') {
+  if (platform === 'linux' || platform === 'freebsd') {
     // Linux: Static tray icons
     // Use a single tray icon for Linux, as it does not support scale factors.
     // We choose the best icon based on the highest display scale factor.
