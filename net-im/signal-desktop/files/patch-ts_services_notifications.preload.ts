--- ts/services/notifications.preload.ts.orig	2025-05-23 12:14:12 UTC
+++ ts/services/notifications.preload.ts
@@ -277,7 +277,7 @@ export class NotificationService extends EventEmitter 
       this.#lastShown = { notification: null, data };
     } else {
       const notification = new window.Notification(title, {
-        body: OS.isLinux() ? filterNotificationBody(body) : body,
+        body: (OS.isLinux() || OS.isFreeBSD()) ? filterNotificationText(body) : body,
         icon: iconUrl ?? undefined,
         silent: true,
         tag: messageId,
