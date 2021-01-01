--- ui/webui/resources/js/cr.js.orig	2019-12-16 21:51:34 UTC
+++ ui/webui/resources/js/cr.js
@@ -437,6 +437,11 @@ var cr = cr || function(global) {
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
