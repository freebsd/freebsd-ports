--- app/main.ts.orig	2023-10-19 19:29:53 UTC
+++ app/main.ts
@@ -616,7 +616,7 @@ if (OS.isWindows()) {
 
 if (OS.isWindows()) {
   windowIcon = join(__dirname, '../build/icons/win/icon.ico');
-} else if (OS.isLinux()) {
+} else if (OS.isLinux() || OS.isFreeBSD()) {
   windowIcon = join(__dirname, '../images/signal-logo-desktop-linux.png');
 } else {
   windowIcon = join(__dirname, '../build/icons/png/512x512.png');
@@ -1613,6 +1613,7 @@ function getSQLKey(): string {
 function getSQLKey(): string {
   let update = false;
   const isLinux = OS.isLinux();
+  const isFreeBSD = OS.isFreeBSD();
   const legacyKeyValue = userConfig.get('key');
   const modernKeyValue = userConfig.get('encryptedKey');
   const previousBackend = isLinux
@@ -1945,7 +1946,7 @@ app.commandLine.appendSwitch('disable-features', featu
 )}`;
 app.commandLine.appendSwitch('disable-features', featuresToDisable);
 
-if (OS.isLinux()) {
+if (OS.isLinux() || OS.isFreeBSD()) {
   // https://github.com/electron/electron/issues/46538#issuecomment-2808806722
   app.commandLine.appendSwitch('gtk-version', '3');
 }
@@ -2570,7 +2571,7 @@ ipc.on('draw-attention', () => {
     return;
   }
 
-  if (OS.isWindows() || OS.isLinux()) {
+  if (OS.isWindows() || OS.isLinux() || OS.isFreeBSD()) {
     mainWindow.flashFrame(true);
   }
 });
