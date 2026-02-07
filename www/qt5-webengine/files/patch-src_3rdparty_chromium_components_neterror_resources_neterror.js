--- src/3rdparty/chromium/components/neterror/resources/neterror.js.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/components/neterror/resources/neterror.js
@@ -153,7 +153,7 @@ let primaryControlOnLeft = true;
 }
 
 let primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
