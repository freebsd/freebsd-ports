Treat FreeBSD like Linux when resolving the CLI install path.

--- packages/desktop/src/integrations/cli-install/path.ts.orig	2026-11-05 23:40:38 UTC
+++ packages/desktop/src/integrations/cli-install/path.ts
@@ -19,7 +19,7 @@
     return input.shimPath;
   }
 
-  if (input.platform === "linux") {
+  if (input.platform === "linux" || input.platform === "freebsd") {
     const appImagePath = input.appImagePath?.trim();
     if (appImagePath) {
       return appImagePath;
