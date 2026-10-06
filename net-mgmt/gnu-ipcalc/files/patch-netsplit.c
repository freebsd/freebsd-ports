--- netsplit.c.orig	2026-10-04 09:20:17 UTC
+++ netsplit.c
@@ -33,8 +33,18 @@
 #include <arpa/inet.h>
 #include <stdint.h>
 #include <inttypes.h>
+#include <sys/socket.h>
 
 #include "ipcalc.h"
+
+#if defined(__FreeBSD__) || defined(__darwin__) || defined(__APPLE__)
+#ifndef s6_addr16
+#define s6_addr16 __u6_addr.__u6_addr16
+#endif
+#ifndef s6_addr32
+#define s6_addr32 __u6_addr.__u6_addr32
+#endif
+#endif
 
 /* Splitting of a network into subnets.
  *
