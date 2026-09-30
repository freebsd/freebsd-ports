--- packages/filesystem/createFolder.ts.orig	2026-09-23 10:10:21 UTC
+++ packages/filesystem/createFolder.ts
@@ -7,7 +7,7 @@
     // Do nothing, S3 creates directories recursively
   } else {
     const storagePath = process.env.STORAGE_FOLDER || "data";
-    const creationPath = path.join(
+    const creationPath = path.resolve(
       process.cwd(),
       "../..",
       storagePath,
