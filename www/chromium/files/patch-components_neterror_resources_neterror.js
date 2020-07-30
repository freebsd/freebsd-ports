--- components/neterror/resources/neterror.js.orig	2020-07-07 21:58:15 UTC
+++ components/neterror/resources/neterror.js
@@ -202,7 +202,7 @@ function setUpCachedButton(buttonStrings) {
 }
 
 let primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
