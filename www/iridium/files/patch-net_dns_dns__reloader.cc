--- net/dns/dns_reloader.cc.orig	2017-04-19 19:06:36 UTC
+++ net/dns/dns_reloader.cc
@@ -7,6 +7,10 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
     !defined(OS_ANDROID)
 
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
+
 #include <resolv.h>
 
 #include "base/lazy_instance.h"
