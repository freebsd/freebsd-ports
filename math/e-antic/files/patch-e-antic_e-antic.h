--- e-antic/e-antic.h.orig	2020-06-13 18:49:26 UTC
+++ e-antic/e-antic.h
@@ -20,8 +20,8 @@ extern "C" {
 
 /* check flint version */
 
-#if __FLINT_RELEASE != 20502 && __FLINT_RELEASE != 20503 && __FLINT_RELEASE != 20600
-#error FLINT 2.5.2 or 2.5.3 required
+#if __FLINT_RELEASE < 20502
+#error FLINT >= 2.5.2 required
 #endif
 
 #ifdef __cplusplus
