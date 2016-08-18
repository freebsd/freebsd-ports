--- ui/webui/resources/js/icon.js.orig	2016-08-04 10:04:19.233504000 -0400
+++ ui/webui/resources/js/icon.js	2016-08-04 10:04:37.016751000 -0400
@@ -9,7 +9,7 @@
    */
   function getSupportedScaleFactors() {
     var supportedScaleFactors = [];
-    if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux) {
+    if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux || cr.isBSD) {
       // All desktop platforms support zooming which also updates the
       // renderer's device scale factors (a.k.a devicePixelRatio), and
       // these platforms has high DPI assets for 2.0x. Use 1x and 2x in
