--- packages/filesystem/createFile.ts.orig	2026-09-23 10:10:21 UTC
+++ packages/filesystem/createFile.ts
@@ -48,7 +48,7 @@
     }
   } else {
     const storagePath = process.env.STORAGE_FOLDER || "data";
-    const creationPath = path.join(
+    const creationPath = path.resolve(
       process.cwd(),
       "../..",
       storagePath,
