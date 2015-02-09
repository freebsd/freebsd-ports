--- ./ppapi/shared_impl/private/net_address_private_impl.cc.orig	2014-04-30 22:41:41.000000000 +0200
+++ ./ppapi/shared_impl/private/net_address_private_impl.cc	2014-05-04 14:38:48.000000000 +0200
@@ -14,6 +14,10 @@
 #include <sys/types.h>
 #endif
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include <string.h>
 
 #include <string>
@@ -28,7 +32,7 @@
 #include "ppapi/shared_impl/var.h"
 #include "ppapi/thunk/thunk.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // This is a bit evil, but it's standard operating procedure for |s6_addr|....
 #define s6_addr16 __u6_addr.__u6_addr16
 #endif
