--- ./libs/libFN/mathfunc4.cpp.orig	2010-09-22 15:28:16.000000000 -0400
+++ ./libs/libFN/mathfunc4.cpp	2010-09-22 15:27:09.000000000 -0400
@@ -248,11 +248,17 @@
 	return r;
 }
 
+#ifdef __cplusplus
+extern "C" {
+#endif
 float lgammaf(float x)
 {
   int local_signgam;
   return lgammaf_r(x, &local_signgam/*(_REENT_SIGNGAM(_REENT))*/);
 }
+#ifdef __cplusplus
+}
+#endif
 
 float gammaf_r(float x, int *signgamp)
 {
@@ -264,6 +270,9 @@
   return gammaf_r(x, &(_REENT_SIGNGAM(_REENT)));
 }*/
 
+#ifdef __cplusplus
+extern "C" {
+#endif
 float tgammaf(float x)
 {
         float y;
@@ -272,3 +281,6 @@
         if (local_signgam < 0) y = -y;
         return y;
 }
+#ifdef __cplusplus
+}
+#endif
