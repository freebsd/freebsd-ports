--- net/net_tcp_proc.c.orig	2015-04-22 08:20:03 UTC
+++ net/net_tcp_proc.c
@@ -26,6 +26,7 @@
 
 #include "../timer.h"
 #include "../reactor.h"
+#include "../pt.h"
 #include "tcp_conn.h"
 #include "tcp_passfd.h"
 
