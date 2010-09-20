--- lib/sockopt.c.orig	2008-01-11 16:47:21.000000000 +0300
+++ lib/sockopt.c	2008-01-11 16:47:57.000000000 +0300
@@ -23,6 +23,10 @@
 #include "log.h"
 #include "sockopt.h"
 
+#ifdef HAVE_STRUCT_IP_MREQN_IMR_IFINDEX
+#undef HAVE_STRUCT_IP_MREQN_IMR_IFINDEX
+#endif
+
 int
 setsockopt_so_recvbuf (int sock, int size)
 {
