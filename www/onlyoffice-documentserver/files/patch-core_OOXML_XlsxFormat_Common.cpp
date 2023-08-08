--- core/OOXML/XlsxFormat/Common.cpp.orig	2023-02-13 11:53:45.780601000 +0100
+++ core/OOXML/XlsxFormat/Common.cpp	2023-02-13 11:54:15.232608000 +0100
@@ -48,6 +48,10 @@ char* gcvt(double x, int n, char* b)
 #define _gcvt gcvt
 #endif
 
+#ifdef __FreeBSD__
+#define _gcvt(x,n,b) sprintf(b, "%.17g", x)
+#endif
+
 #define DBL_MAX 15
 #define DBL_MAXDIG10 17
 
