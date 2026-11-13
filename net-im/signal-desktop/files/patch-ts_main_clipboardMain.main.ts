--- ts/main/clipboardMain.main.ts.orig	2026-11-03 11:03:44.001909000 +0100
+++ ts/main/clipboardMain.main.ts	2026-11-03 11:03:57.261219000 +0100
@@ -15,7 +15,7 @@ function clear(): void {
   clipboard.clear();
 
   // clipboard.clear is not reliable on Linux, so we actually have to overwrite it
-  if (OS.isLinux()) {
+  if (OS.isLinux() || OS.isFreeBSD()) {
     writeText(' ');
   }
 
