--- core/PdfWriter/Src/Types.h.orig	2021-09-30 12:13:32 UTC
+++ core/PdfWriter/Src/Types.h
@@ -46,7 +46,7 @@
 #include <algorithm>
 #include <math.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <string.h>
 #endif
 
