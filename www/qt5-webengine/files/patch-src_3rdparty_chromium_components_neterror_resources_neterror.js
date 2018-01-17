--- src/3rdparty/chromium/components/neterror/resources/neterror.js.orig	2017-01-26 00:49:12 UTC
+++ src/3rdparty/chromium/components/neterror/resources/neterror.js
@@ -150,7 +150,7 @@ function setUpCachedButton(buttonStrings
 }
 
 var primaryControlOnLeft = true;
-<if expr="is_macosx or is_ios or is_linux or is_android">
+<if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 </if>
 
