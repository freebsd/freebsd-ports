--- ts/util/os/promptOSAuthMain.main.ts.orig	2026-04-10 16:44:02 UTC
+++ ts/util/os/promptOSAuthMain.main.ts
@@ -49,7 +49,7 @@ export async function promptOSAuth({
     return promptOSAuthMacOS(localeString ?? '');
   }
 
-  if (OS.isLinux()) {
+  if (OS.isLinux() || OS.isFreeBSD()) {
     return promptOSAuthLinux(reason);
   }
 
