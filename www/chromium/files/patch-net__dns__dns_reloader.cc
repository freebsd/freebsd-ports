--- net/dns/dns_reloader.cc.orig	2016-01-21 16:39:42.984956172 +0100
+++ net/dns/dns_reloader.cc	2016-01-21 16:40:30.288952815 +0100
@@ -7,6 +7,10 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
     !defined(OS_ANDROID)
 
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
+
 #include <resolv.h>
 
 #include "base/basictypes.h"
