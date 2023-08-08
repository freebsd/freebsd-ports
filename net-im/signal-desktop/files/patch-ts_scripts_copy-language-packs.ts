--- ts/scripts/copy-language-packs.ts.orig	2022-12-04 09:58:27 UTC
+++ ts/scripts/copy-language-packs.ts
@@ -31,6 +31,7 @@ export async function afterPack({
       'Resources'
     );
   } else if (
+    electronPlatformName === 'freebsd' ||
     electronPlatformName === 'linux' ||
     electronPlatformName === 'win32'
   ) {
