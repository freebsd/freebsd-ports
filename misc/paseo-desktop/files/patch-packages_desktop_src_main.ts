Run on FreeBSD like on Linux.

Use the Linux desktop name, window class, and show-on-load behavior, and
match the installed .desktop file.  Find the renderer and icon in
%%DATADIR%%.  On a second launch, drop the app directory, which the system
Electron passes on its command line, instead of opening it as a project.

--- packages/desktop/src/main.ts.orig	2026-11-05 23:40:38 UTC
+++ packages/desktop/src/main.ts
@@ -349,9 +349,9 @@ if (electronFlags) {
   log.info("[electron-flags]", electronFlags);
 }
 
-if (process.platform === "linux") {
+if (process.platform === "linux" || process.platform === "freebsd") {
   // Keep the desktop/dock identity independent of the wrapped Electron filename.
-  app.setDesktopName("Paseo.desktop");
+  app.setDesktopName("paseo-desktop.desktop");
   if (!app.commandLine.hasSwitch("class")) app.commandLine.appendSwitch("class", "Paseo");
   log.info("[linux-sandbox]", {
     enabled: !app.commandLine.hasSwitch("no-sandbox"),
@@ -581,7 +581,7 @@ function getAppDistDir(): string {
 
 function getAppDistDir(): string {
   if (app.isPackaged) {
-    return path.join(process.resourcesPath, "app-dist");
+    return path.join("%%DATADIR%%", "app-dist");
   }
 
   return path.resolve(__dirname, "../../app/dist");
@@ -595,7 +595,7 @@ function getWindowIconCandidates(): string[] {
         path.join(process.resourcesPath, "icon.png"),
       ];
     }
-    return [path.join(process.resourcesPath, "icon.png")];
+    return [path.join("%%DATADIR%%", "icon.png")];
   }
   if (process.platform === "win32") {
     return [
@@ -795,7 +795,7 @@ async function createWindow(
   });
 
   showWindowWhenReady(mainWindow, {
-    showOnLoad: process.platform === "linux",
+    showOnLoad: process.platform === "linux" || process.platform === "freebsd",
   });
 
   if (!app.isPackaged) {
@@ -904,7 +904,10 @@ function setupSingleInstanceLock(): boolean {
 
     log.info("[open-project] second-instance commandLine:", commandLine);
     const openProjectPath = parseOpenProjectPathFromArgv({
-      argv: commandLine,
+      // The system Electron runs the app from its directory, which this
+      // command line has after the switches Chromium adds: drop it rather
+      // than take it for a project to open.
+      argv: commandLine.filter((arg) => path.resolve(arg) !== app.getAppPath()),
       isDefaultApp: false,
     });
     log.info("[open-project] second-instance openProjectPath:", openProjectPath);
