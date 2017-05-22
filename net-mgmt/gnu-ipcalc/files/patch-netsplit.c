--- netsplit.c.orig	2017-05-15 12:33:58 UTC
+++ netsplit.c
@@ -32,9 +32,19 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <stdint.h>
+#include <sys/socket.h>
 
 #include "ipcalc.h"
 
+#if defined(__FreeBSD__) || defined(__darwin__) || defined(__APPLE__)
+#ifndef s6_addr16
+#define s6_addr16 __u6_addr.__u6_addr16
+#endif
+#ifndef s6_addr32
+#define s6_addr32 __u6_addr.__u6_addr32
+#endif
+#endif
+
 static const char *numtoquad(uint32_t num)
 {
 	static char quad[64];
