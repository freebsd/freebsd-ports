--- libk3b/tools/k3blibdvdcss.cpp.orig	2010-07-27 13:56:42.000000000 +0200
+++ libk3b/tools/k3blibdvdcss.cpp	2010-07-27 13:56:54.000000000 +0200
@@ -61,7 +61,7 @@
 #ifdef Q_OS_WIN32
 #define LIBDVDCSS_NAME "dvdcss.dll"
 #else
-#define LIBDVDCSS_NAME "libdvdcss.so.2"
+#define LIBDVDCSS_NAME "libdvdcss.so.3"
 #endif
 
 void* K3b::LibDvdCss::s_libDvdCss = 0;
