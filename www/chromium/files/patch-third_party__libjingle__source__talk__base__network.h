--- third_party/libjingle/source/talk/base/network.h.orig	2013-05-26 21:44:12.257312749 +0200
+++ third_party/libjingle/source/talk/base/network.h	2013-05-26 21:45:08.869297313 +0200
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
