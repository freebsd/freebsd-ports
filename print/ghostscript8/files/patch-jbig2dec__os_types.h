--- jbig2dec/os_types.h.orig	Thu Dec 29 04:56:24 2005
+++ jbig2dec/os_types.h	Sun May 28 01:10:59 2006
@@ -47,7 +47,7 @@
 
 #if defined(HAVE_STDINT_H) || defined(__MACOS__)
 # include <stdint.h>
-#elif defined(__VMS)
+#elif defined(__VMS) || defined(__FreeBSD__)
 # include <inttypes.h>
 #endif
 
