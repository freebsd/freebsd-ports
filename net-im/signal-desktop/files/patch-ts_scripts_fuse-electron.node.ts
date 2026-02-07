--- ts/scripts/fuse-electron.node.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/scripts/fuse-electron.node.ts
@@ -17,7 +17,7 @@ export async function afterPack({
     target = `${productFilename}.app`;
   } else if (electronPlatformName === 'win32') {
     target = `${productFilename}.exe`;
-  } else if (electronPlatformName === 'linux') {
+  } else if (electronPlatformName === 'linux' || electronPlatformName === 'freebsd') {
     // Sadly, `LinuxPackager` type is not exported by electron-builder so we
     // have to improvise
     target = (packager as unknown as { executableName: string }).executableName;
