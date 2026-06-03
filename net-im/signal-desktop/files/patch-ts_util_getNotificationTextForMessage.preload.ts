--- ts/util/getNotificationTextForMessage.preload.ts.orig	2025-05-23 12:11:17 UTC
+++ ts/util/getNotificationTextForMessage.preload.ts
@@ -56,7 +56,7 @@ export function getNotificationTextForMessage(
       });
     }
 
-    if (!window.Signal.OS.isLinux()) {
+    if (!(window.Signal.OS.isLinux() || window.Signal.OS.isFreeBSD())) {
       return attributes.storyReaction.emoji;
     }
 
@@ -73,7 +73,7 @@ export function getNotificationTextForMessage(
 
   // Linux emoji support is mixed, so we disable it. (Note that this doesn't touch
   //   the `text`, which can contain emoji.)
-  const shouldIncludeEmoji = Boolean(emoji) && !window.Signal.OS.isLinux();
+  const shouldIncludeEmoji = Boolean(emoji) && (!(window.Signal.OS.isLinux() || window.Signal.OS.isFreeBSD()))
   if (shouldIncludeEmoji) {
     return window.i18n('icu:message--getNotificationText--text-with-emoji', {
       text: result.body,
