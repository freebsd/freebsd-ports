--- lib/vscode/node_modules/@vscode/deviceid/dist/index.js.orig
+++ lib/vscode/node_modules/@vscode/deviceid/dist/index.js
@@ -19,7 +19,8 @@
 Object.defineProperty(exports, "__esModule", { value: true });
 if (process.platform !== "win32" &&
     process.platform !== "darwin" &&
-    process.platform !== "linux") {
+    process.platform !== "linux" &&
+    process.platform !== "freebsd") {
     throw new Error("Unsupported platform");
 }
 __exportStar(require("./devdeviceid.js"), exports);
