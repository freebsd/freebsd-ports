--- scripts/fuse-electron.mjs.orig	2026-04-30 14:53:08 UTC
+++ scripts/fuse-electron.mjs
@@ -18,7 +18,7 @@ export async function afterPack({ appOutDir, packager,
     target = `${productFilename}.app`;
   } else if (electronPlatformName === 'win32') {
     target = `${productFilename}.exe`;
-  } else if (electronPlatformName === 'linux') {
+  } else if (electronPlatformName === 'linux' || electronPlatformName === 'freebsd') {
     target = /** @type {LinuxPackager} */ (packager).executableName;
   } else {
     throw new Error(`Unsupported platform: ${electronPlatformName}`);
