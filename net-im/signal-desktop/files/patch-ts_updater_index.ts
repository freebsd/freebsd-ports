--- ts/updater/index.ts.orig	2022-12-04 09:57:09 UTC
+++ ts/updater/index.ts
@@ -61,6 +61,6 @@ function autoUpdateDisabled() {
 
 function autoUpdateDisabled() {
   return (
-    process.platform === 'linux' || process.mas || !config.get('updatesEnabled')
+    process.platform === 'freebsd' || process.platform === 'linux' || process.mas || !config.get('updatesEnabled')
   );
 }
