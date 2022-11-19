--- tools/wpt/utils.ts.orig	2022-10-26 10:28:29 UTC
+++ tools/wpt/utils.ts
@@ -174,6 +174,7 @@ export async function generateRunInfo(): Promise<unkno
     "windows": "win",
     "darwin": "mac",
     "linux": "linux",
+    "freebsd": "freebsd",
   };
   const proc = await Deno.spawn("git", {
     args: ["rev-parse", "HEAD"],
