--- lib/vscode-reh-web-linux-x64/node_modules/@vscode/deviceid/dist/index.js.orig
+++ lib/vscode-reh-web-linux-x64/node_modules/@vscode/deviceid/dist/index.js
@@ -20,7 +20,8 @@
 Object.defineProperty(exports, "__esModule", { value: true });
 if (process.platform !== "win32" &&
     process.platform !== "darwin" &&
-    process.platform !== "linux") {
+    process.platform !== "linux" &&
+    process.platform !== "freebsd") {
     throw new Error("Unsupported platform");
 }
 __exportStar(require("./devdeviceid.js"), exports);
\ No newline at end of file
