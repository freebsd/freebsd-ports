Run the daemon and the CLI from misc/paseo with the system Node.js.

The node entrypoint runner lives in %%DATADIR%%, not app.asar.unpacked.
misc/paseo's node-pty addon is built for the system Node.js, so use it
rather than Electron's.  Keep ELECTRON_FORCE_IS_PACKAGED, which the
launcher sets for the app only, out of the daemon's environment.

--- packages/desktop/src/daemon/runtime-paths.ts.orig	2026-11-06 00:00:40 UTC
+++ packages/desktop/src/daemon/runtime-paths.ts
@@ -29,8 +29,7 @@
 
 export function resolvePackagedNodeEntrypointRunnerPath(): string {
   return path.join(
-    process.resourcesPath,
-    "app.asar.unpacked",
+    "%%DATADIR%%",
     "dist",
     "daemon",
     "node-entrypoint-runner.js",
@@ -75,6 +74,9 @@
 }
 
 export function resolveNodeExecPath(): string {
+  // FreeBSD: run the daemon and the CLI with the system Node.js that
+  // misc/paseo, whose node-pty addon is built for it, uses.
+  if (process.platform === "freebsd") return "%%LOCALBASE%%/bin/node";
   if (app.isPackaged && process.platform === "darwin") {
     const marker = ".app/Contents/MacOS/";
     const markerIndex = process.execPath.indexOf(marker);
@@ -116,6 +118,8 @@
     entrypoint: input.entrypoint,
     argvMode: input.argvMode,
     args: input.args,
-    baseEnv: input.baseEnv,
+    // FreeBSD: bin/paseo-desktop sets this for the app only; keep it away
+    // from the daemon and the agents and terminals it starts.
+    baseEnv: { ...input.baseEnv, ELECTRON_FORCE_IS_PACKAGED: undefined },
   });
 }
