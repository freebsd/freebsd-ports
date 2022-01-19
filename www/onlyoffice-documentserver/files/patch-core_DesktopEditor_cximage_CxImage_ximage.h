--- core/DesktopEditor/cximage/CxImage/ximage.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/cximage/CxImage/ximage.h
@@ -52,7 +52,7 @@
 #pragma once
 #endif 
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
   #define _XOPEN_SOURCE
   #include <unistd.h>
   #include <arpa/inet.h>
