--- src/ssrfpack.c.orig	2020-03-05 09:15:01 UTC
+++ src/ssrfpack.c
@@ -15,6 +15,10 @@
 #  define sincos(x,s,c) (*s = sin(x), *c = cos(x))
 #endif
 
+#ifdef __FreeBSD__
+#define sincos(x,s,c) *s = sin(x); *c = cos(x)
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
