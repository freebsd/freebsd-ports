--- docker/redis-rest-proxy.mjs.orig	2026-11-03 16:09:19 UTC
+++ docker/redis-rest-proxy.mjs
@@ -1211,6 +1211,15 @@ const server = http.createServer(async (req, res) => {
   }
 });
 
-server.listen(PORT, '0.0.0.0', () => {
-  console.log(`Redis REST proxy listening on 0.0.0.0:${PORT}`);
+server.listen(PORT, '127.0.0.1', () => {
+  console.log(`Redis REST proxy listening on 127.0.0.1:${PORT}`);
 });
+
+// FreeBSD port: also allow the Lua scripts of the military bases seeder.
+{
+  const extra = JSON.parse(process.getBuiltinModule('node:fs').readFileSync(
+    new URL('./military-eval-scripts.json', import.meta.url), 'utf8'));
+  for (const script of extra) {
+    ALLOWED_EVAL_SCRIPTS.add(script);
+  }
+}
