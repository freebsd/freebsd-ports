--- src/3rdparty/chromium/ui/webui/resources/js/cr.js.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/webui/resources/js/cr.js
@@ -456,6 +456,11 @@ var cr = cr || function() {
       return document;
     },
 
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.userAgent);
+    },
+
     /** Whether we are using a Mac or not. */
     get isMac() {
       return /Mac/.test(navigator.platform);
