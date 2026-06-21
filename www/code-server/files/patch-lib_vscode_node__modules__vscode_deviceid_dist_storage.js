--- lib/vscode/node_modules/@vscode/deviceid/dist/storage.js.orig
+++ lib/vscode/node_modules/@vscode/deviceid/dist/storage.js
@@ -42,7 +42,7 @@
     if (process.platform === "darwin") {
         folder = path.join(process.env.HOME, "Library", "Application Support");
     }
-    else if (process.platform === "linux") {
+    else if (process.platform === "linux" || process.platform === "freebsd") {
         folder =
             process.env.XDG_CACHE_HOME ?? path.join(process.env.HOME, ".cache");
     }
