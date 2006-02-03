--- ospfd/ospfd.h.orig	Fri Feb  3 13:39:58 2006
+++ ospfd/ospfd.h	Fri Feb  3 13:40:51 2006
@@ -26,6 +26,10 @@
 #include "filter.h"
 #include "log.h"
 
+#if !defined(UINT16_MAX)
+#define UINT16_MAX 0xffff
+#endif
+
 #define OSPF_VERSION            2
 
 /* Default protocol, port number. */
