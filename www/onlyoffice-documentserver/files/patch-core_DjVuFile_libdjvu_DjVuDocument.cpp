--- core/DjVuFile/libdjvu/DjVuDocument.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DjVuFile/libdjvu/DjVuDocument.cpp
@@ -78,7 +78,7 @@
 
 #include "debug.h"
 
-#if defined(__linux__) || defined(LINUX)
+#if defined(__linux__) || defined(LINUX) || defined(__FreeBSD__)
 typedef unsigned int	UINT;
 #endif
 
