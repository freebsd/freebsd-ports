--- core/DesktopEditor/cximage/CxImage/ximajas.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/cximage/CxImage/ximajas.h
@@ -16,7 +16,7 @@
 
 #if CXIMAGE_SUPPORT_JASPER
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #include <jasper/jasper.h>
 #else
  #include "../jasper/include/jasper/jasper.h"
