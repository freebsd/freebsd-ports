--- ts/util/os/shared.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/util/os/shared.ts
@@ -32,6 +32,7 @@ export function getOSFunctions(osRelease: string): OST
   const isMacOS = createIsPlatform('darwin', osRelease);
   const isLinux = createIsPlatform('linux', osRelease);
   const isWindows = createIsPlatform('win32', osRelease);
+  const isFreeBSD = createIsPlatform('freebsd', osRelease);
 
   // Windows 10 and above
   const hasCustomTitleBar = (): boolean =>
@@ -44,6 +45,9 @@ export function getOSFunctions(osRelease: string): OST
     if (isWindows()) {
       return 'Windows';
     }
+    if (isFreeBSD()) {
+      return 'FreeBSD';
+    }
     return 'Linux';
   };
 
@@ -54,6 +58,9 @@ export function getOSFunctions(osRelease: string): OST
     if (isWindows()) {
       return 'os-windows';
     }
+    if (isFreeBSD()) {
+      return 'os-freebsd';
+    }
     return 'os-linux';
   };
 
@@ -64,5 +71,6 @@ export function getOSFunctions(osRelease: string): OST
     isLinux,
     isMacOS,
     isWindows,
+    isFreeBSD,
   };
 }
