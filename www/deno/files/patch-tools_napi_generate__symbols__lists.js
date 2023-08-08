--- tools/napi/generate_symbols_lists.js.orig	2022-10-26 10:19:15 UTC
+++ tools/napi/generate_symbols_lists.js
@@ -6,6 +6,7 @@ const symbolExportLists = {
 };
 
 const symbolExportLists = {
+  freebsd: `{ ${exports.symbols.map((s) => `"${s}"`).join("; ")}; };`,
   linux: `{ ${exports.symbols.map((s) => `"${s}"`).join("; ")}; };`,
   windows: `LIBRARY\nEXPORTS\n${
     exports.symbols
