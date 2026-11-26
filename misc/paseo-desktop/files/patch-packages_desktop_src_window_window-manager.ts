Set the badge count on FreeBSD as on Linux.

--- packages/desktop/src/window/window-manager.ts.orig	2026-11-05 23:40:38 UTC
+++ packages/desktop/src/window/window-manager.ts
@@ -179,7 +179,11 @@
   });
 
   ipcMain.handle("paseo:window:setBadgeCount", (_event, count?: unknown) => {
-    if (process.platform === "darwin" || process.platform === "linux") {
+    if (
+      process.platform === "darwin" ||
+      process.platform === "linux" ||
+      process.platform === "freebsd"
+    ) {
       const badgeCount = readBadgeCount(count);
       try {
         app.setBadgeCount(badgeCount);
