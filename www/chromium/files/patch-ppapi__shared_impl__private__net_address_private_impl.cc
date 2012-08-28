--- ppapi/shared_impl/private/net_address_private_impl.cc.orig	2012-07-25 22:05:38.000000000 +0300
+++ ppapi/shared_impl/private/net_address_private_impl.cc	2012-07-25 22:24:11.000000000 +0300
@@ -4,6 +4,10 @@
 
 #include "ppapi/shared_impl/private/net_address_private_impl.h"
 
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
+
 #include <string.h>
 
 #include <string>
