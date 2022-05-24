--- core/DjVuFile/libdjvu/DjVuDocument.cpp.orig	2022-05-11 19:33:56 UTC
+++ core/DjVuFile/libdjvu/DjVuDocument.cpp
@@ -78,7 +78,7 @@
 
 #include "debug.h"
 
-#if defined(__linux__) || defined(LINUX) || defined (BUILDING_WASM_MODULE)
+#if defined(__linux__) || defined(LINUX) || defined (BUILDING_WASM_MODULE) || defined(__FreeBSD__)
 typedef unsigned int	UINT;
 #endif
 
