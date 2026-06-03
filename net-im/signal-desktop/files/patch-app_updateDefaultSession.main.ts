--- app/updateDefaultSession.main.ts.orig	2026-04-10 16:35:46 UTC
+++ app/updateDefaultSession.main.ts
@@ -52,7 +52,7 @@ export function updateDefaultSession(
 
         // Wayland already shows a window/screen selection modal so we just
         // have to go with the source that we were given.
-        if (OS.isLinux() && OS.isWaylandEnabled() && sources.length === 1) {
+        if ((OS.isLinux() || OS.isFreeBSD()) && OS.isWaylandEnabled() && sources.length === 1) {
           callback({ video: sources[0] });
           return;
         }
