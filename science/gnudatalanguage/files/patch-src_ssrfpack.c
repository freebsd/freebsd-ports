--- src/ssrfpack.c.orig	2018-04-07 19:40:08 UTC
+++ src/ssrfpack.c
@@ -7,6 +7,10 @@
 #define sincosf(x, s, c) __sincosf(x, s, c)
 #endif
 
+#ifdef __FreeBSD__
+#define sincos(x,s,c) *s = sin(x); *c = cos(x)
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
