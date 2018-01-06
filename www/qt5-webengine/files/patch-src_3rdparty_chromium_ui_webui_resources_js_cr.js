--- src/3rdparty/chromium/ui/webui/resources/js/cr.js.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/webui/resources/js/cr.js
@@ -451,6 +451,11 @@ var cr = cr || function() {
     get doc() {
       return document;
     },
+    
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.userAgent);
+    },
 
     /** Whether we are using a Mac or not. */
     get isMac() {
