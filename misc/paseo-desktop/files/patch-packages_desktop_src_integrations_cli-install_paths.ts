Use the paseo CLI from misc/paseo.

--- packages/desktop/src/integrations/cli-install/paths.ts.orig	2026-11-05 23:40:38 UTC
+++ packages/desktop/src/integrations/cli-install/paths.ts
@@ -14,6 +14,8 @@
 }
 
 export function getBundledCliShimPath(): string {
+  // FreeBSD: the CLI comes from misc/paseo.
+  if (process.platform === "freebsd") return "%%LOCALBASE%%/bin/paseo";
   return resolveCliShimPath({
     platform: process.platform,
     isPackaged: app.isPackaged,
