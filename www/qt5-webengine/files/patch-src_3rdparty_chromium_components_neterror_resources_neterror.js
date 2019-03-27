--- src/3rdparty/chromium/components/neterror/resources/neterror.js.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/components/neterror/resources/neterror.js
@@ -153,7 +153,7 @@ function setUpCachedButton(buttonStrings) {
 }
 
 var primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
