--- ts/updater/index.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/updater/index.ts
@@ -72,6 +72,6 @@ function autoUpdateDisabled() {
 
 function autoUpdateDisabled() {
   return (
-    process.platform === 'linux' || process.mas || !config.get('updatesEnabled')
+    process.platform === 'freebsd' || process.platform === 'linux' || process.mas || !config.get('updatesEnabled')
   );
 }
