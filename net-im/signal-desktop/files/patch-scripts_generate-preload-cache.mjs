--- scripts/generate-preload-cache.mjs.orig	2026-04-30 14:53:56 UTC
+++ scripts/generate-preload-cache.mjs
@@ -20,7 +20,7 @@ const argv = [`--js-flags=${V8_ARGS.join(' ')}`];
 const storagePath = await mkdtemp(join(tmpdir(), 'signal-preload-cache-'));
 
 const argv = [`--js-flags=${V8_ARGS.join(' ')}`];
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
   argv.push('--no-sandbox');
 }
 argv.push('ci.js');
