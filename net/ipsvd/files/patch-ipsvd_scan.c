--- src/ipsvd_scan.c.orig       Wed Oct  1 00:58:34 2003
+++ src/ipsvd_scan.c    Wed Oct  1 00:58:12 2003
@@ -1,3 +1,4 @@
+#include <sys/types.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include "scan.h"
