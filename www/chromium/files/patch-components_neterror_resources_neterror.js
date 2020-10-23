--- components/neterror/resources/neterror.js.orig	2020-09-08 19:14:03 UTC
+++ components/neterror/resources/neterror.js
@@ -204,7 +204,7 @@ function setUpCachedButton(buttonStrings) {
 }
 
 let primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
