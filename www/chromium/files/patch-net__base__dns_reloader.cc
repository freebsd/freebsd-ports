--- net/base/dns_reloader.cc.orig	2011-10-09 01:12:14.189268935 +0300
+++ net/base/dns_reloader.cc	2011-10-09 01:32:07.358661959 +0300
@@ -6,6 +6,9 @@
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD)
 
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
 #include <resolv.h>
 
 #include "base/basictypes.h"
