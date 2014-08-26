--- ./net/base/dns_reloader.cc.orig	2014-08-20 21:02:28.000000000 +0200
+++ ./net/base/dns_reloader.cc	2014-08-22 15:06:26.000000000 +0200
@@ -7,6 +7,9 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
     !defined(OS_ANDROID)
 
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
 #include <resolv.h>
 
 #include "base/basictypes.h"
