--- lib/cximage-6.0/raw/libdcr.h.orig
+++ lib/cximage-6.0/raw/libdcr.h
@@ -41,7 +41,7 @@
 #include <setjmp.h>
 #include <sys/types.h>
 #endif
-#if defined(_LINUX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <setjmp.h>
 #include <sys/types.h>
 #define _swab   swab
