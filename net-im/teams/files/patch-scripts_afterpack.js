--- scripts/afterpack.js.orig	2026-11-15 10:01:49 UTC
+++ scripts/afterpack.js
@@ -16,7 +16,7 @@ function getAppFileName(context) {
       return `${productFileName}.app`;
     case "mas":
       return `${productFileName}.app`;
-    case "linux":
+    case "linux": case "freebsd":
       return context.packager.executableName;
     default:
       return "";
@@ -26,7 +26,7 @@ exports.default = async function afterPack(context) {
 exports.default = async function afterPack(context) {
   try {
     // Ensure release info is generated for Linux publishing
-    if (context.electronPlatformName === "linux") {
+    if (context.electronPlatformName === "linux" || context.electronPlatformName === "freebsd") {
       await generateReleaseInfoForLinux();
       await patchSnapLauncherIfNeeded(context);
     }
