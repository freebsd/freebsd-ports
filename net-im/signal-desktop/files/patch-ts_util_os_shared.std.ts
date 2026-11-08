--- ts/util/os/shared.std.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/util/os/shared.std.ts
@@ -24,6 +24,7 @@ export type OSType = {
   getName: () => string;
   isLinux: (minVersion?: string) => boolean;
   isLinuxAppImage: () => boolean;
+  isFreeBSD: (minVersion?: string) => boolean;
   isMacOS: (minVersion?: string) => boolean;
   isMAS: () => boolean;
   isWindows: (minVersion?: string) => boolean;
@@ -33,6 +34,7 @@ export function getOSFunctions(osRelease: string): OST
   const isMacOS = createIsPlatform('darwin', osRelease);
   const isLinux = createIsPlatform('linux', osRelease);
   const isWindows = createIsPlatform('win32', osRelease);
+  const isFreeBSD = createIsPlatform('freebsd', osRelease);
 
   const isLinuxAppImage = (): boolean => {
     return process.platform === 'linux' && process.env.APPIMAGE != null;
@@ -45,6 +47,9 @@ export function getOSFunctions(osRelease: string): OST
     if (isWindows()) {
       return 'Windows';
     }
+    if (isFreeBSD()) {
+      return 'FreeBSD';
+    }
     return 'Linux';
   };
 
@@ -56,6 +61,9 @@ export function getOSFunctions(osRelease: string): OST
       // oxlint-disable-next-line signal-desktop/enforce-class-name-has-styles
       return 'os-windows';
     }
+    if (isFreeBSD()) {
+      return 'os-freebsd';
+    }
     // oxlint-disable-next-line signal-desktop/enforce-class-name-has-styles
     return 'os-linux';
   };
@@ -68,5 +76,6 @@ export function getOSFunctions(osRelease: string): OST
     isMacOS,
     isMAS: () => process.mas,
     isWindows,
+    isFreeBSD,
   };
 }
