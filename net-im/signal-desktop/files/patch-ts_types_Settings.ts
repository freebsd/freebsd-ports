--- ts/types/Settings.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/types/Settings.ts
@@ -34,7 +34,7 @@ export const isSystemTraySupported = (
   appVersion: string
 ): boolean =>
   // We eventually want to support Linux in production.
-  OS.isWindows() || (OS.isLinux() && !isProduction(appVersion));
+  OS.isWindows() || (OS.isLinux() && !isProduction(appVersion)) || (OS.isFreeBSD() && !isProduction(appVersion));
 
 // On Windows minimize and start in system tray is default when app is selected
 // to launch at login, because we can provide `['--start-in-tray']` args.
