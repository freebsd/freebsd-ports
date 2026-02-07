--- core/DesktopEditor/cximage/CxImage/ximapng.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/cximage/CxImage/ximapng.h
@@ -22,7 +22,7 @@
 #if CXIMAGE_SUPPORT_PNG
 
 extern "C" {
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #undef _DLL
  #include <png.h>
  #include <pngstruct.h>
