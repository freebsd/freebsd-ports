--- core/OOXML/XlsxFormat/Common.cpp.orig	2025-08-02 18:33:34 UTC
+++ core/OOXML/XlsxFormat/Common.cpp
@@ -48,6 +48,10 @@ char* gcvt(double x, int n, char* b)
 #define _gcvt gcvt
 #endif
 
+#ifdef __FreeBSD__
+#define _gcvt(x,n,b) sprintf(b, "%.17g", x)
+#endif
+
 #define DBL_MAX 15
 #define DBL_MAXDIG10 17
 
