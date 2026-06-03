--- scripts/copy-language-packs.mjs.orig	2026-04-30 14:51:33 UTC
+++ scripts/copy-language-packs.mjs
@@ -34,6 +34,7 @@ export async function afterPack({ appOutDir, packager,
       'Resources'
     );
   } else if (
+    electronPlatformName === 'freebsd' ||
     electronPlatformName === 'linux' ||
     electronPlatformName === 'win32'
   ) {
