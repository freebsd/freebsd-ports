--- ts/util/getUserAgent.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/util/getUserAgent.ts
@@ -9,6 +9,7 @@ const PLATFORM_STRINGS: { [platform: string]: string }
   win32: 'Windows',
   darwin: 'macOS',
   linux: 'Linux',
+  freebsd: 'FreeBSD',
 };
 
 export function getUserAgent(
