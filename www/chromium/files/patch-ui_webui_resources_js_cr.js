--- ui/webui/resources/js/cr.js.orig	2021-01-18 21:29:49 UTC
+++ ui/webui/resources/js/cr.js
@@ -450,6 +450,11 @@ var cr = cr || function(global) {
     get isMac() {
       return /Mac/.test(navigator.platform);
     },
+    
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.userAgent);
+    },
 
     /** Whether this is on the Windows platform or not. */
     get isWindows() {
