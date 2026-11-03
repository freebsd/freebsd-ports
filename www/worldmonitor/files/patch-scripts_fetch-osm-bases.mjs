--- scripts/fetch-osm-bases.mjs.orig	2026-11-03 16:09:19 UTC
+++ scripts/fetch-osm-bases.mjs
@@ -39,7 +39,7 @@ async function fetchOverpassData() {
   try {
     const res = await fetch(OVERPASS_URL, {
       method: 'POST',
-      headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
+      headers: { 'Content-Type': 'application/x-www-form-urlencoded', 'User-Agent': 'worldmonitor-freebsd-port' },
       body: `data=${encodeURIComponent(OVERPASS_QUERY)}`,
       signal: controller.signal,
     });
