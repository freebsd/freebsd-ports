--- components/neterror/resources/neterror.js.orig	2019-04-30 22:22:42 UTC
+++ components/neterror/resources/neterror.js
@@ -160,7 +160,7 @@ function setUpCachedButton(buttonStrings) {
 }
 
 var primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
