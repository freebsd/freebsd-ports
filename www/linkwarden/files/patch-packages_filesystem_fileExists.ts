--- packages/filesystem/fileExists.ts.orig	2026-09-23 10:10:21 UTC
+++ packages/filesystem/fileExists.ts
@@ -20,7 +20,7 @@
   }
 
   const storagePath = process.env.STORAGE_FOLDER || "data";
-  const creationPath = path.join(process.cwd(), "../..", storagePath, filePath);
+  const creationPath = path.resolve(process.cwd(), "../..", storagePath, filePath);
 
   return fs.existsSync(creationPath);
 }
