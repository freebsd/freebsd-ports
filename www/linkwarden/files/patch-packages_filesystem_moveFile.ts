--- packages/filesystem/moveFile.ts.orig	2026-09-23 10:10:21 UTC
+++ packages/filesystem/moveFile.ts
@@ -28,7 +28,7 @@
     const storagePath = process.env.STORAGE_FOLDER || "data";
 
     const directory = (file: string) =>
-      path.join(process.cwd(), "../..", storagePath, file);
+      path.resolve(process.cwd(), "../..", storagePath, file);
 
     if (fs.existsSync(directory(from))) {
       fs.rename(directory(from), directory(to), (err) => {
