--- core/DesktopEditor/cximage/CxImage/ximainfo.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/cximage/CxImage/ximainfo.cpp
@@ -5,7 +5,7 @@
 
 #include "ximage.h"
 
-#if defined(_LINUX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
     #ifdef UNICODE
         #define _tcsnicmp(a,b,c) wcscasecmp(a,b)
     #else
