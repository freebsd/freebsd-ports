--- scripts/seed-military-bases.mjs.orig	2026-11-03 16:09:19 UTC
+++ scripts/seed-military-bases.mjs
@@ -691,7 +691,7 @@ async function main() {
     console.warn(`Version-key sweep skipped: ${err instanceof Error ? err.message : err}`);
   }
 
-  const volumePath = '/data/military-bases-final.json';
+  const volumePath = '/var/db/worldmonitor/military/scripts/data/military-bases-final.json';
   const localPath = join(__dirname, 'data', 'military-bases-final.json');
   let dataPath = existsSync(volumePath) ? volumePath : existsSync(localPath) ? localPath : null;
 
