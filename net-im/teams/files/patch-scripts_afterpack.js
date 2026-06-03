--- scripts/afterpack.js.orig	2025-07-28 16:14:12 UTC
+++ scripts/afterpack.js
@@ -14,7 +14,7 @@ function getAppFileName(context) {
       return `${productFileName}.app`;
     case "mas":
       return `${productFileName}.app`;
-    case "linux":
+    case "linux": case "freebsd":
       return context.packager.executableName;
     default:
       return "";
@@ -24,7 +24,7 @@ exports.default = async function afterPack(context) {
 exports.default = async function afterPack(context) {
   try {
     // Ensure release info is generated for Linux publishing
-    if (context.electronPlatformName === "linux") {
+    if (context.electronPlatformName === "linux" || context.electronPlatformName === "freebsd") {
       await generateReleaseInfoForLinux();
     }
 
