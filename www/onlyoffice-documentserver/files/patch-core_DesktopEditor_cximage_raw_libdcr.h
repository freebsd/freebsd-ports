--- core/DesktopEditor/cximage/raw/libdcr.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/cximage/raw/libdcr.h
@@ -50,7 +50,7 @@
  #include <sys/types.h>
 #endif
 
-#if defined(_LINUX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
  #include <setjmp.h>
  #include <sys/types.h>
  #define _getcwd getcwd
