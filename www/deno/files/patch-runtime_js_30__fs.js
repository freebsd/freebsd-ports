--- runtime/js/30_fs.js.orig	2022-07-08 08:14:40 UTC
+++ runtime/js/30_fs.js
@@ -209,7 +209,7 @@ function createByteStruct(types) {
   // `?` prefix means optional on windows.
   let offset = 0;
   let str =
-    'const unix = Deno.build.os === "darwin" || Deno.build.os === "linux"; return {';
+    'const unix = Deno.build.os === "darwin" || Deno.build.os === "linux" || Deno.build.os === "freebsd"; return {';
   const typeEntries = ObjectEntries(types);
   for (let i = 0; i < typeEntries.length; ++i) {
     let { 0: name, 1: type } = typeEntries[i];
@@ -262,7 +262,7 @@ function parseFileInfo(response) {
 });
 
 function parseFileInfo(response) {
-  const unix = build.os === "darwin" || build.os === "linux";
+  const unix = build.os === "darwin" || build.os === "linux" || build.os === "freebsd";
   return {
     isFile: response.isFile,
     isDirectory: response.isDirectory,
