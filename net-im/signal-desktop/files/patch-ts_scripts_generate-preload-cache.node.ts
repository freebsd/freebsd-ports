--- ts/scripts/generate-preload-cache.node.ts.orig	2025-05-23 12:11:57 UTC
+++ ts/scripts/generate-preload-cache.node.ts
@@ -19,7 +19,7 @@ async function main(): Promise<void> {
   const storagePath = await mkdtemp(join(tmpdir(), 'signal-preload-cache-'));
 
   const argv = [`--js-flags=${V8_ARGS.join(' ')}`];
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     argv.push('--no-sandbox');
   }
   argv.push('ci.js');
