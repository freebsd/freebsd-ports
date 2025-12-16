--- ts/util/os/shared.std.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/util/os/shared.std.ts
@@ -24,6 +24,7 @@ export type OSType = {
   getName: () => string;
   isLinux: (minVersion?: string) => boolean;
   isLinuxAppImage: () => boolean;
+  isFreeBSD: (minVersion?: string) => boolean;
   isMacOS: (minVersion?: string) => boolean;
   isWindows: (minVersion?: string) => boolean;
 };
@@ -32,6 +33,7 @@ export function getOSFunctions(osRelease: string): OST
   const isMacOS = createIsPlatform('darwin', osRelease);
   const isLinux = createIsPlatform('linux', osRelease);
   const isWindows = createIsPlatform('win32', osRelease);
+  const isFreeBSD = createIsPlatform('freebsd', osRelease);
 
   const isLinuxAppImage = (): boolean => {
     return process.platform === 'linux' && process.env.APPIMAGE != null;
@@ -44,6 +46,9 @@ export function getOSFunctions(osRelease: string): OST
     if (isWindows()) {
       return 'Windows';
     }
+    if (isFreeBSD()) {
+      return 'FreeBSD';
+    }
     return 'Linux';
   };
 
@@ -54,6 +59,9 @@ export function getOSFunctions(osRelease: string): OST
     if (isWindows()) {
       return 'os-windows';
     }
+    if (isFreeBSD()) {
+      return 'os-freebsd';
+    }
     return 'os-linux';
   };
 
@@ -64,5 +72,6 @@ export function getOSFunctions(osRelease: string): OST
     isLinuxAppImage,
     isMacOS,
     isWindows,
+    isFreeBSD,
   };
 }
