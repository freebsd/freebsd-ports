--- app/main.main.ts.orig	2023-10-19 19:29:53 UTC
+++ app/main.main.ts
@@ -623,7 +623,7 @@ if (OS.isWindows()) {
 
 if (OS.isWindows()) {
   windowIcon = join(rootDir, 'build', 'icons', 'win', 'icon.ico');
-} else if (OS.isLinux()) {
+} else if (OS.isLinux() || OS.isFreeBSD()) {
   windowIcon = join(rootDir, 'images', 'signal-logo-desktop-linux.png');
 } else {
   windowIcon = join(rootDir, 'build', 'icons', 'png', '512x512.png');
@@ -1013,7 +1013,7 @@ async function createWindow() {
     }
   };
 
-  if (OS.isLinux() && OS.isWaylandEnabled()) {
+  if ((OS.isLinux() || OS.isFreeBSD()) && OS.isWaylandEnabled()) {
     mainWindow.webContents.once('did-finish-load', async () => {
       log.info('main window webContents did-finish-load');
       drop(maybeShowMainWindow());
@@ -1627,13 +1627,14 @@ function getSQLKey(): string {
 function getSQLKey(): string {
   let update = false;
   const isLinux = OS.isLinux();
+  const isFreeBSD = OS.isFreeBSD();
   const legacyKeyValue = userConfig.get('key');
   const modernKeyValue = userConfig.get('encryptedKey');
-  const previousBackend = isLinux
+  const previousBackend = (isLinux || isFreeBSD)
     ? userConfig.get('safeStorageBackend')
     : undefined;
 
-  const safeStorageBackend: string | undefined = isLinux
+  const safeStorageBackend: string | undefined = (isLinux || isFreeBSD)
     ? safeStorage.getSelectedStorageBackend()
     : undefined;
   const isEncryptionAvailable =
@@ -1643,12 +1644,12 @@ function getSQLKey(): string {
       (!process.env.GENERATE_PRELOAD_CACHE &&
         !isTestEnvironment(getEnvironment()))) &&
     safeStorage.isEncryptionAvailable() &&
-    (!isLinux || safeStorageBackend !== 'basic_text');
+    (!(isLinux || isFreeBSD) || safeStorageBackend !== 'basic_text');
 
   // On Linux the backend can change based on desktop environment and command line flags.
   // If the backend changes we won't be able to decrypt the key.
   if (
-    isLinux &&
+    (isLinux || isFreeBSD) &&
     typeof previousBackend === 'string' &&
     previousBackend !== safeStorageBackend
   ) {
@@ -1688,7 +1689,7 @@ function getSQLKey(): string {
       }
     }
 
-    if (isLinux && previousBackend == null) {
+    if ((isLinux || isFreeBSD) && previousBackend == null) {
       log.info(`getSQLKey: saving safeStorageBackend: ${safeStorageBackend}`);
       userConfig.set('safeStorageBackend', safeStorageBackend);
     }
@@ -1724,7 +1725,7 @@ function getSQLKey(): string {
       userConfig.set('key', undefined);
     }
 
-    if (isLinux && safeStorageBackend) {
+    if ((isLinux || isFreeBSD) && safeStorageBackend) {
       log.info(`getSQLKey: saving safeStorageBackend: ${safeStorageBackend}`);
       userConfig.set('safeStorageBackend', safeStorageBackend);
     }
@@ -2669,7 +2670,7 @@ ipc.on('draw-attention', () => {
     return;
   }
 
-  if (OS.isWindows() || OS.isLinux()) {
+  if (OS.isWindows() || OS.isLinux() || OS.isFreeBSD()) {
     mainWindow.flashFrame(true);
   }
 });
