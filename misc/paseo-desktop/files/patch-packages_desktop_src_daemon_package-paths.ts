Find the app at %%DATADIR%%.

The app runs from a plain directory under the system Electron rather than
from an app.asar in its own resources directory.

--- packages/desktop/src/daemon/package-paths.ts.orig	2026-11-05 23:40:38 UTC
+++ packages/desktop/src/daemon/package-paths.ts
@@ -47,5 +47,7 @@
 }
 
 export function resolvePackagedAsarPath(): string {
-  return path.join(process.resourcesPath, "app.asar");
+  // FreeBSD: the app runs from a plain directory under the system Electron,
+  // whose resourcesPath belongs to Electron itself.
+  return "%%DATADIR%%";
 }
