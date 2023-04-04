--- ext/fs/30_fs.js.orig	2022-07-08 08:14:40 UTC
+++ ext/fs/30_fs.js
@@ -217,7 +217,7 @@ function createByteStruct(types) {
   // types can be "date", "bool" or "u64".
   let offset = 0;
   let str =
-    'const unix = Deno.build.os === "darwin" || Deno.build.os === "linux"; return {';
+    'const unix = Deno.build.os === "darwin" || Deno.build.os === "linux" || Deno.build.os === "freebsd"; return {';
   const typeEntries = ObjectEntries(types);
   for (let i = 0; i < typeEntries.length; ++i) {
     let { 0: name, 1: type } = typeEntries[i];
@@ -270,7 +270,7 @@ function parseFileInfo(response) {
 });
 
 function parseFileInfo(response) {
-  const unix = core.build.os === "darwin" || core.build.os === "linux";
+  const unix = core.build.os === "darwin" || core.build.os === "linux" || Deno.build.os === "freebsd";
   return {
     isFile: response.isFile,
     isDirectory: response.isDirectory,
