--- src/main.cc.orig	2019-01-10 17:32:50 UTC
+++ src/main.cc
@@ -43,6 +43,10 @@
 #include "ccurl_thread.h"
 #endif /* BUILD_CURL */
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include "freebsd.h"
+#endif /* FreeBSD */
+
 #ifdef BUILD_BUILTIN_CONFIG
 #include "defconfig.h"
 
