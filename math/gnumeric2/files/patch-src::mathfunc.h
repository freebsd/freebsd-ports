--- src/mathfunc.h.orig	Thu Apr 26 20:47:46 2001
+++ src/mathfunc.h	Mon May 21 12:08:51 2001
@@ -7,2 +7,6 @@
 
+#ifdef __FreeBSD__
+#define FINITE finite
+#endif
+
 #ifndef FINITE
