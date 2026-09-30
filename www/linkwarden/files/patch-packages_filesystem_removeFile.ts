--- packages/filesystem/removeFile.ts.orig	2026-09-23 10:10:21 UTC
+++ packages/filesystem/removeFile.ts
@@ -17,7 +17,7 @@
     }
   } else {
     const storagePath = process.env.STORAGE_FOLDER || "data";
-    const creationPath = path.join(
+    const creationPath = path.resolve(
       process.cwd(),
       "../..",
       storagePath,
