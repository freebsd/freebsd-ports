--- src/ssrfpack.c.orig	2018-12-01 14:19:52 UTC
+++ src/ssrfpack.c
@@ -11,6 +11,10 @@
 #  define sincos(x,s,c) (*s = sin(x), *c = cos(x))
 #endif
 
+#ifdef __FreeBSD__
+#define sincos(x,s,c) *s = sin(x); *c = cos(x)
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
