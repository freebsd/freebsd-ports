Use the Linux window chrome on FreeBSD; the app refuses to start on an
unknown platform.

--- packages/desktop/src/window/chrome.ts.orig	2026-11-05 23:40:38 UTC
+++ packages/desktop/src/window/chrome.ts
@@ -5,7 +5,7 @@
 function systemWindowChromeMode(platform: NodeJS.Platform): DesktopWindowChromeMode {
   if (platform === "darwin") return "native-mac";
   if (platform === "win32") return "custom-windows";
-  if (platform === "linux") return "custom-linux";
+  if (platform === "linux" || platform === "freebsd") return "custom-linux";
   throw new Error(`Unsupported desktop window chrome platform: ${platform}`);
 }
 
