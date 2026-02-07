--- ts/state/getInitialState.preload.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/state/getInitialState.preload.ts
@@ -72,7 +72,7 @@ export function getInitialState({
 
   const theme = getThemeType();
 
-  let osName: 'windows' | 'macos' | 'linux' | undefined;
+  let osName: 'windows' | 'macos' | 'linux' | 'freebsd' | undefined;
 
   if (OS.isWindows()) {
     osName = 'windows';
@@ -80,6 +80,8 @@ export function getInitialState({
     osName = 'macos';
   } else if (OS.isLinux()) {
     osName = 'linux';
+  } else if (OS.isFreeBSD()) {
+    osName = 'freebsd';
   }
 
   return {
