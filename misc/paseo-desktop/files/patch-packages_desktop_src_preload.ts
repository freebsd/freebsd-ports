Use the Linux window chrome on FreeBSD.

--- packages/desktop/src/preload.ts.orig	2026-11-05 23:40:38 UTC
+++ packages/desktop/src/preload.ts
@@ -24,7 +24,9 @@ function readWindowChromeMode(): DesktopWindowChromeMo
   }
   // COMPAT(windowChromeMode): added in v0.5.3; remove after 2026-11-25.
   if (process.platform === "darwin") return "native-mac";
-  return process.platform === "linux" ? "custom-linux" : "custom-windows";
+  return process.platform === "linux" || process.platform === "freebsd"
+    ? "custom-linux"
+    : "custom-windows";
 }
 
 interface AttachedBrowserRegistration {
