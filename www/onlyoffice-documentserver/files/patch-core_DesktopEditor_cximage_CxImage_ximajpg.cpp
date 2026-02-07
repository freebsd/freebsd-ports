--- core/DesktopEditor/cximage/CxImage/ximajpg.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/cximage/CxImage/ximajpg.cpp
@@ -9,7 +9,7 @@
 
 #if CXIMAGE_SUPPORT_JPG
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #include <jmorecfg.h>
 #else
  #include "../jpeg/jmorecfg.h"
