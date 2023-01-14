--- src/3rdparty/chromium/ui/webui/resources/js/cr.js.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/webui/resources/js/cr.js
@@ -438,6 +438,11 @@ var cr = cr || function(global) {
       return returnValue;
     },
 
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.userAgent);
+    },
+
     /** Whether this is on vanilla Linux (not chromeOS). */
     get isLinux() {
       return /Linux/.test(navigator.userAgent);
