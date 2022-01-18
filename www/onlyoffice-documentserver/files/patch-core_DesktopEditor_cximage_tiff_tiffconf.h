--- core/DesktopEditor/cximage/tiff/tiffconf.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/cximage/tiff/tiffconf.h
@@ -33,7 +33,7 @@
 #define TIFF_UINT64_T unsigned __int64
 #endif
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
 #include <inttypes.h>
 
 /* Signed 64-bit type */
