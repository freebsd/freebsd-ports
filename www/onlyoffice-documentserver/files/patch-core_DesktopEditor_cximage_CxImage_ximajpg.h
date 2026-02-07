--- core/DesktopEditor/cximage/CxImage/ximajpg.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/cximage/CxImage/ximajpg.h
@@ -29,7 +29,7 @@
 #define CXIMAGEJPG_SUPPORT_EXIF CXIMAGE_SUPPORT_EXIF
 
 extern "C" {
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #include <jpeglib.h>
  #include <jerror.h>
 #else
