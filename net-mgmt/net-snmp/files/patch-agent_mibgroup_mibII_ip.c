--- agent/mibgroup/mibII/ip.c.orig	2021-05-25 15:19:35.000000000 -0700
+++ agent/mibgroup/mibII/ip.c	2022-09-27 20:25:12.959145000 -0700
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
 
 #if HAVE_SYS_HASHING_H
 #include <sys/hashing.h>
