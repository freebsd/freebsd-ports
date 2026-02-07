--- agent/mibgroup/mibII/ip.c.orig	2023-08-15 20:32:01 UTC
+++ agent/mibgroup/mibII/ip.c
@@ -5,6 +5,13 @@
 
 #include <net-snmp/net-snmp-config.h>
 #include "mibII_common.h"
+#include <sys/param.h>
+
+#if defined(__FreeBSD_version) && __FreeBSD_version > 1400066
+#define IPFRAGTTL	60	/* time to live for frags, slowhz */
+#define PR_SLOWHZ	2	/* 2 slow timeouts per second */
+#define PR_FASTHZ	5	/* 5 fast timeouts per second */
+#endif
 
 #ifdef HAVE_SYS_HASHING_H
 #include <sys/hashing.h>
