Honor FreeBSD's hier(7) layout for the system-wide configuration directory.

Upstream falls back to /etc/opencode on every platform that is neither Darwin
nor Windows.  FreeBSD ports install into LOCALBASE, so use
/usr/local/etc/opencode there instead, alongside the rest of the package's
configuration.

Upstream PR: https://github.com/anomalyco/opencode/pull/58347

--- packages/core/src/config/discovery.ts.orig
+++ packages/core/src/config/discovery.ts
@@ -28,6 +28,7 @@
 export function systemDirectory(platform: NodeJS.Platform = process.platform, env: NodeJS.ProcessEnv = process.env) {
   if (platform === "darwin") return AbsolutePath.make("/Library/Application Support/opencode")
   if (platform === "win32") return AbsolutePath.make(path.join(env.ProgramData || "C:\\ProgramData", "opencode"))
+  if (platform === "freebsd") return AbsolutePath.make("/usr/local/etc/opencode")
   return AbsolutePath.make("/etc/opencode")
 }
 
