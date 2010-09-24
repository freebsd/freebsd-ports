--- ./libs/libFN/FNFun.cpp.orig	2009-10-09 02:23:29.000000000 -0400
+++ ./libs/libFN/FNFun.cpp	2010-09-22 15:29:22.000000000 -0400
@@ -35,6 +35,14 @@
 	double trunc( double x );
 	float truncf( float x );
 #endif 
+#ifdef __cplusplus
+extern "C" {
+#endif
+    float lgammaf(float x);
+    float tgammaf(float x);
+#ifdef __cplusplus
+}
+#endif
 
 //!
 //@Module ERFC Complimentary Error Function
