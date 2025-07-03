--- app/main.ts.orig	2023-10-19 19:29:53 UTC
+++ app/main.ts
@@ -628,7 +628,7 @@ if (OS.isWindows()) {
 
 if (OS.isWindows()) {
   windowIcon = join(__dirname, '../build/icons/win/icon.ico');
-} else if (OS.isLinux()) {
+} else if (OS.isLinux() || OS.isFreeBSD()) {
   windowIcon = join(__dirname, '../images/signal-logo-desktop-linux.png');
 } else {
   windowIcon = join(__dirname, '../build/icons/png/512x512.png');
@@ -1665,6 +1665,7 @@ function getSQLKey(): string {
 function getSQLKey(): string {
   let update = false;
   const isLinux = OS.isLinux();
+  const isFreeBSD = OS.isFreeBSD();
   const legacyKeyValue = userConfig.get('key');
   const modernKeyValue = userConfig.get('encryptedKey');
   const previousBackend = isLinux
@@ -2618,7 +2619,7 @@ ipc.on('draw-attention', () => {
     return;
   }
 
-  if (OS.isWindows() || OS.isLinux()) {
+  if (OS.isWindows() || OS.isLinux() || OS.isFreeBSD()) {
     mainWindow.flashFrame(true);
   }
 });
