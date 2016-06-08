--- ui/webui/resources/js/util.js.orig	2016-05-11 19:02:36 UTC
+++ ui/webui/resources/js/util.js
@@ -52,7 +52,7 @@ function announceAccessibleMessage(msg) 
  */
 function getSupportedScaleFactors() {
   var supportedScaleFactors = [];
-  if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux) {
+  if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux || cr.isBSD) {
     // All desktop platforms support zooming which also updates the
     // renderer's device scale factors (a.k.a devicePixelRatio), and
     // these platforms has high DPI assets for 2.0x. Use 1x and 2x in
