--- ./src/purple/purple-dnsquery.c.orig	2010-11-03 05:13:51.000000000 +0100
+++ ./src/purple/purple-dnsquery.c	2011-06-21 11:23:35.000000000 +0200
@@ -22,6 +22,10 @@
 
 #include "glib.h"
 
+#include "version.h"
+#if PURPLE_VERSION_CHECK(2,8,0)
+#include "account.h"
+#endif
 #include "dnssrv.h"
 
 #include "sipe-backend.h"
