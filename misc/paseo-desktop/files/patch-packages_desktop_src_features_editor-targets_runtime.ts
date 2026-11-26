Find the editor icons in %%DATADIR%%.

--- packages/desktop/src/features/editor-targets/runtime.ts.orig	2026-11-05 23:40:38 UTC
+++ packages/desktop/src/features/editor-targets/runtime.ts
@@ -134,7 +134,7 @@
 
 function iconPath(fileName: string): string {
   if (app.isPackaged) {
-    return path.join(process.resourcesPath, "editor-target-icons", fileName);
+    return path.join("%%DATADIR%%", "editor-target-icons", fileName);
   }
   return path.resolve(__dirname, "../../../assets/editor-targets", fileName);
 }
