-- Node reports no frsize on FreeBSD, so every product came out NaN and the
-- server reported no disk usage at all.
--
-- TODO: reported upstream, drop once statfs is read portably.

--- server/src/repositories/storage.repository.ts.orig	2026-11-13 09:57:00 UTC
+++ server/src/repositories/storage.repository.ts
@@ -218,9 +218,9 @@ export class StorageRepository {
   async checkDiskUsage(folder: string): Promise<DiskUsage> {
     const stats = await fs.statfs(folder);
     return {
-      available: stats.bavail * stats.frsize,
-      free: stats.bfree * stats.frsize,
-      total: stats.blocks * stats.frsize,
+      available: stats.bavail * (stats.frsize ?? stats.bsize),
+      free: stats.bfree * (stats.frsize ?? stats.bsize),
+      total: stats.blocks * (stats.frsize ?? stats.bsize),
     };
   }
 
