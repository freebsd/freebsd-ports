--- ts/services/notifications.preload.ts.orig	2025-05-23 12:14:12 UTC
+++ ts/services/notifications.preload.ts
@@ -196,7 +196,7 @@ class NotificationService extends EventEmitter {
       this.#lastNotification?.close();
 
       const notification = new window.Notification(title, {
-        body: OS.isLinux() ? filterNotificationText(message) : message,
+        body: (OS.isLinux() || OS.isFreeBSD()) ? filterNotificationText(message) : message,
         icon: iconUrl,
         silent: true,
         tag: messageId,
