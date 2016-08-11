--- ui/webui/resources/js/cr.js.orig	2016-05-11 19:02:36 UTC
+++ ui/webui/resources/js/cr.js
@@ -444,6 +444,11 @@ var cr = function() {
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
