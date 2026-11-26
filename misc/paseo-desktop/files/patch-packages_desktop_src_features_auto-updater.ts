Leave updates to pkg(8): electron-updater has no FreeBSD target.

--- packages/desktop/src/features/auto-updater.ts.orig	2026-11-26 15:38:03 UTC
+++ packages/desktop/src/features/auto-updater.ts
@@ -374,7 +374,8 @@
 
 const appUpdateService = createAppUpdateService({
   runtime: new ElectronAppUpdateRuntime(),
-  isPackaged: () => app.isPackaged,
+  // FreeBSD: updates come from the package manager, not electron-updater.
+  isPackaged: () => app.isPackaged && process.platform !== "freebsd",
   now: () => Date.now(),
   bucket: async (version) => rolloutBucket(await getStagingUserId(), version),
   pacing: appUpdatePacing,
