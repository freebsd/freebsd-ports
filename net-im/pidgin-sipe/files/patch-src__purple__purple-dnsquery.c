--- src/purple/purple-dnsquery.c.orig	2011-08-29 17:05:26.000000000 +1100
+++ src/purple/purple-dnsquery.c	2012-01-23 12:24:33.000000000 +1100
@@ -29,6 +29,12 @@
 #endif
 
 #include <glib.h>
+#include <sys/socket.h>
+
+#include "version.h"
+#if PURPLE_VERSION_CHECK(2,8,0)
+#include "account.h"
+#endif
 
 #include "dnsquery.h"
 #include "dnssrv.h"
