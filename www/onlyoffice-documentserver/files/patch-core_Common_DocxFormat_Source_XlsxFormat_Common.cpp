--- core/Common/DocxFormat/Source/XlsxFormat/Common.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/Common/DocxFormat/Source/XlsxFormat/Common.cpp
@@ -48,6 +48,11 @@ char* gcvt(double x, int n, char* b)
 #define _gcvt gcvt
 #endif
 
+#ifdef __FreeBSD__
+#define _gcvt(x,n,b) sprintf(b, "%.17g", x)
+#endif
+
+
 #define DBL_MAX 15
 #define DBL_MAXDIG10 17
 
