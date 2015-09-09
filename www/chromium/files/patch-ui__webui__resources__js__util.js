--- ui/webui/resources/js/util.js.orig	2015-09-05 09:31:35.172857000 -0400
+++ ui/webui/resources/js/util.js	2015-09-05 09:31:57.588607000 -0400
@@ -58,7 +58,7 @@
  */
 function getSupportedScaleFactors() {
   var supportedScaleFactors = [];
-  if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux) {
+  if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux || cr.isBSD) {
     // All desktop platforms support zooming which also updates the
     // renderer's device scale factors (a.k.a devicePixelRatio), and
     // these platforms has high DPI assets for 2.0x. Use 1x and 2x in
