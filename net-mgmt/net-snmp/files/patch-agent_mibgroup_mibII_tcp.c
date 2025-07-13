--- agent/mibgroup/mibII/tcp.c.orig	2023-08-15 13:32:01.000000000 -0700
+++ agent/mibgroup/mibII/tcp.c	2025-07-10 17:17:00.309421000 -0700
@@ -8,6 +8,14 @@
 #include <net-snmp/net-snmp-features.h>
 #include "mibII_common.h"
 
+#include <sys/param.h>
+
+#if defined(__FreeBSD_version) && __FreeBSD_version > 1400066
+#define IPFRAGTTL	60	/* time to live for frags, slowhz */
+#define PR_SLOWHZ	2	/* 2 slow timeouts per second */
+#define PR_FASTHZ	5	/* 5 fast timeouts per second */
+#endif
+
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
@@ -38,8 +46,17 @@
 #include <netinet/tcpip.h>
 #endif
 #ifdef HAVE_NETINET_TCP_TIMER_H
+#if __FreeBSD_version >= 1500048
+#define _KERNEL
+#define max(x, y) (((x) > (y)) ? (x) : (y))
+#define MSEC_2_TICKS(m) max(1, (uint32_t)((hz == 1000) ? \
+	(m) : ((uint64_t)(m) * (uint64_t)hz)/(uint64_t)1000)) 
+#endif
 #include <netinet/tcp_timer.h>
+#if __FreeBSD_version >= 1500048
+#undef _KERNEL
 #endif
+#endif
 #ifdef HAVE_NETINET_TCP_VAR_H
 #ifdef openbsd7
 #define _KERNEL /* OpenBSD 7.3 */
