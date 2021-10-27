--- components/neterror/resources/neterror.js.orig	2021-09-14 01:51:54 UTC
+++ components/neterror/resources/neterror.js
@@ -123,7 +123,7 @@ function detailsButtonClick() {
 }
 
 let primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
