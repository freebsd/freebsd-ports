------------------------------------------------------------------------
r181918 | des | 2008-08-20 05:40:07 -0500 (Wed, 20 Aug 2008) | 6 lines
Changed paths:
   M /head/crypto/openssh/readconf.c

Use net.inet.ip.portrange.reservedhigh instead of IPPORT_RESERVED.
Submitted upstream, no reaction.

Submitted by:   delphij@
[rewritten for 7.4 by bdrewery@]

--- misc.c.orig	2017-01-12 11:54:41.058558000 -0800
+++ misc.c	2017-01-12 11:55:16.531356000 -0800
@@ -56,6 +56,8 @@
 #include <net/if.h>
 #endif
 
+#include <sys/sysctl.h>
+
 #include "xmalloc.h"
 #include "misc.h"
 #include "log.h"
@@ -1253,7 +1255,19 @@ forward_equals(const struct Forward *a, 
 int
 bind_permitted(int port, uid_t uid)
 {
-	if (port < IPPORT_RESERVED && uid != 0)
+	int ipport_reserved;
+#ifdef __FreeBSD__
+	size_t len_ipport_reserved = sizeof(ipport_reserved);
+
+	if (sysctlbyname("net.inet.ip.portrange.reservedhigh",
+	    &ipport_reserved, &len_ipport_reserved, NULL, 0) != 0)
+		ipport_reserved = IPPORT_RESERVED;
+	else
+		ipport_reserved++;
+#else
+	ipport_reserved = IPPORT_RESERVED;
+#endif
+	if (port < ipport_reserved && uid != 0)
 		return 0;
 	return 1;
 }
