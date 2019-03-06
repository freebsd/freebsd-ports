--- pxyconn.h.orig	2019-02-20 19:30:43 UTC
+++ pxyconn.h
@@ -30,6 +30,10 @@
 #ifndef PXYCONN_H
 #define PXYCONN_H
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <netinet/in.h>
+#endif
+
 #include "proxy.h"
 #include "opts.h"
 #include "attrib.h"
