--- core/PdfFile/SrcWriter/Types.h.orig	2025-08-02 18:33:34 UTC
+++ core/PdfFile/SrcWriter/Types.h
@@ -47,7 +47,7 @@
 #include <algorithm>
 #include <math.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <string.h>
 #endif
 
