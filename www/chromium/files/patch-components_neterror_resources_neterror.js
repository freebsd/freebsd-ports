--- components/neterror/resources/neterror.js.orig	2016-05-11 19:02:18 UTC
+++ components/neterror/resources/neterror.js
@@ -153,7 +153,7 @@ function setUpCachedButton(buttonStrings
 }
 
 var primaryControlOnLeft = true;
-<if expr="is_macosx or is_ios or is_linux or is_android">
+<if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 </if>
 
