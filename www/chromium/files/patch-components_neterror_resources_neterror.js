--- components/neterror/resources/neterror.js.orig	2020-11-13 06:36:41 UTC
+++ components/neterror/resources/neterror.js
@@ -153,7 +153,7 @@ function detailsButtonClick() {
 }
 
 let primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
