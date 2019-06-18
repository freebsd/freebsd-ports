--- ui/webui/resources/js/icon.js.orig	2019-03-11 22:01:19 UTC
+++ ui/webui/resources/js/icon.js
@@ -14,7 +14,7 @@ cr.define('cr.icon', function() {
       // supports SCALE_FACTOR_100P on all non-iOS platforms.
       supportedScaleFactors.push(1);
     }
-    if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux) {
+    if (cr.isMac || cr.isChromeOS || cr.isWindows || cr.isLinux || cr.isBSD) {
       // All desktop platforms support zooming which also updates the renderer's
       // device scale factors (a.k.a devicePixelRatio), and these platforms have
       // high DPI assets for 2x.  Let the renderer pick the closest image for
