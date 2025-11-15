--- ts/util/os/shared.std.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/util/os/shared.std.ts
@@ -23,6 +23,7 @@ export type OSType = {
   getClassName: () => string;
   getName: () => string;
   isLinux: (minVersion?: string) => boolean;
+  isFreeBSD: (minVersion?: string) => boolean;
   isMacOS: (minVersion?: string) => boolean;
   isWindows: (minVersion?: string) => boolean;
 };
@@ -31,6 +32,7 @@ export function getOSFunctions(osRelease: string): OST
   const isMacOS = createIsPlatform('darwin', osRelease);
   const isLinux = createIsPlatform('linux', osRelease);
   const isWindows = createIsPlatform('win32', osRelease);
+  const isFreeBSD = createIsPlatform('freebsd', osRelease);
 
   const getName = (): string => {
     if (isMacOS()) {
@@ -39,6 +41,9 @@ export function getOSFunctions(osRelease: string): OST
     if (isWindows()) {
       return 'Windows';
     }
+    if (isFreeBSD()) {
+      return 'FreeBSD';
+    }
     return 'Linux';
   };
 
@@ -49,6 +54,9 @@ export function getOSFunctions(osRelease: string): OST
     if (isWindows()) {
       return 'os-windows';
     }
+    if (isFreeBSD()) {
+      return 'os-freebsd';
+    }
     return 'os-linux';
   };
 
@@ -58,5 +66,6 @@ export function getOSFunctions(osRelease: string): OST
     isLinux,
     isMacOS,
     isWindows,
+    isFreeBSD,
   };
 }
