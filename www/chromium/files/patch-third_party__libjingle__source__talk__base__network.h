--- ./third_party/libjingle/source/talk/base/network.h.orig	2014-08-20 21:03:47.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/network.h	2014-08-22 15:06:27.000000000 +0200
@@ -38,6 +38,10 @@
 #include "talk/base/messagehandler.h"
 #include "talk/base/sigslot.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/types.h>
+#endif
+
 #if defined(POSIX)
 struct ifaddrs;
 #endif  // defined(POSIX)
