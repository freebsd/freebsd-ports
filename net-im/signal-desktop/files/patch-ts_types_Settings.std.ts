--- ts/types/Settings.std.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/types/Settings.std.ts
@@ -31,7 +31,7 @@ export const isSystemTraySupported = (OS: OSType): boo
  * option with a command line flag, but that is not officially supported.
  */
 export const isSystemTraySupported = (OS: OSType): boolean =>
-  OS.isWindows() || OS.isLinux();
+  OS.isWindows() || OS.isLinux() || OS.isFreeBSD();
 
 export const getDefaultSystemTraySetting = (
   OS: OSType,
@@ -43,7 +43,7 @@ export const getDefaultSystemTraySetting = (
 
   // System tray on linux may not be well supported, so we default to it being off in
   // production
-  if (OS.isLinux() && isProduction(appVersion)) {
+  if ((OS.isLinux() || OS.isFreeBSD()) && isProduction(appVersion)) {
     return SystemTraySetting.DoNotUseSystemTray;
   }
 
