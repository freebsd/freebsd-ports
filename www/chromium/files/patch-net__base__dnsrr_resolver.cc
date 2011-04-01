--- net/base/dnsrr_resolver.cc.orig	2011-01-19 12:11:29.000000000 +0100
+++ net/base/dnsrr_resolver.cc	2011-01-21 20:49:12.000000000 +0100
@@ -4,10 +4,6 @@
 
 #include "net/base/dnsrr_resolver.h"
 
-#if defined(OS_POSIX)
-#include <resolv.h>
-#endif
-
 #if defined(OS_WIN)
 #include <windns.h>
 #endif
@@ -23,6 +19,10 @@
 #include "net/base/dns_reload_timer.h"
 #include "net/base/dns_util.h"
 #include "net/base/net_errors.h"
+#if defined(OS_POSIX)
+#include <netinet/in.h>
+#include <resolv.h>
+#endif
 
 // Life of a query:
 //
