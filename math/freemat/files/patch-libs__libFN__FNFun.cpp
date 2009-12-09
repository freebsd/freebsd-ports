--- ./libs/libFN/FNFun.cpp.orig	2009-11-14 18:51:06.000000000 -0500
+++ ./libs/libFN/FNFun.cpp	2009-11-14 20:26:43.000000000 -0500
@@ -35,6 +35,14 @@
 	double trunc( double x );
 	float truncf( float x );
 #endif 
+#if defined(__FreeBSD__)
+#ifdef __cplusplus
+extern "C" {
+    float lgammaf(float x);
+    float tgammaf(float x);
+}
+#endif
+#endif
 
 //!
 //@Module ERFC Complimentary Error Function
