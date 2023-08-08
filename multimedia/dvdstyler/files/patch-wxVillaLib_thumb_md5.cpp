--- wxVillaLib/thumb_md5.cpp	2023-07-24 10:20:48.138290000 +0100
+++ wxVillaLib/thumb_md5.cpp	2023-07-24 10:02:20.011636000 +0100
@@ -199,7 +199,7 @@
 static void 
 thumb_md5_transform (wxUint32 buf[4], wxUint32 const in[16])
 {
-    register wxUint32 a, b, c, d;
+    wxUint32 a, b, c, d;
 
     a = buf[0];
     b = buf[1];
