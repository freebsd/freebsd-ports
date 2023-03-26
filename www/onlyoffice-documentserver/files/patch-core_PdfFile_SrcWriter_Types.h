--- core/PdfFile/SrcWriter/Types.h.orig	2023-02-13 11:25:36.702286000 +0100
+++ core/PdfFile/SrcWriter/Types.h	2023-02-13 11:25:55.342494000 +0100
@@ -46,7 +46,7 @@
 #include <algorithm>
 #include <math.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <string.h>
 #endif
 
