--- app/main.ts.orig	2023-10-19 19:29:53 UTC
+++ app/main.ts
@@ -648,7 +648,7 @@ if (OS.isWindows()) {
 
 if (OS.isWindows()) {
   windowIcon = join(__dirname, '../build/icons/win/icon.ico');
-} else if (OS.isLinux()) {
+} else if (OS.isLinux() || OS.isFreeBSD()) {
   windowIcon = join(__dirname, '../images/signal-logo-desktop-linux.png');
 } else {
   windowIcon = join(__dirname, '../build/icons/png/512x512.png');
