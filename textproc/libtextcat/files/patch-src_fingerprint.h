--- ./src/fingerprint.h.orig	2003-05-19 14:16:31.000000000 +0200
+++ ./src/fingerprint.h	2010-12-21 16:18:55.000000000 +0100
@@ -41,7 +41,13 @@
 extern int fp_Read( void *handle, const char *fname, int maxngrams );
 extern sint4 fp_Compare( void *cat, void *unknown, int cutoff );
 extern void fp_Show( void *handle );
+#ifdef __cplusplus
+extern "C" {
+#endif
 extern const char *fp_Name( void *handle );
+#ifdef __cplusplus
+}
+#endif
 extern void fp_Print( void *handle, FILE *fp );
 
 #endif
