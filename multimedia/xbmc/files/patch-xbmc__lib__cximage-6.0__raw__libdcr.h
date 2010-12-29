--- ./xbmc/lib/cximage-6.0/raw/libdcr.h.orig	2009-05-21 08:01:34.000000000 +0200
+++ ./xbmc/lib/cximage-6.0/raw/libdcr.h	2010-12-01 12:17:34.248861773 +0100
@@ -41,7 +41,7 @@
 #include <setjmp.h>
 #include <sys/types.h>
 #endif
-#if defined(_LINUX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <setjmp.h>
 #include <sys/types.h>
 #define _swab   swab
