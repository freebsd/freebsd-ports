------------------------------------------------------------------------
r181918 | des | 2008-08-20 05:40:07 -0500 (Wed, 20 Aug 2008) | 6 lines
Changed paths:
   M /head/crypto/openssh/readconf.c

Use net.inet.ip.portrange.reservedhigh instead of IPPORT_RESERVED.
Submitted upstream, no reaction.

Submitted by:   delphij@
[rewritten for 7.4 by bdrewery@]

--- serverloop.c.orig	2018-11-10 11:38:16.728617000 -0800
+++ serverloop.c	2018-11-10 11:38:19.497300000 -0800
@@ -55,6 +55,8 @@
 #include <unistd.h>
 #include <stdarg.h>
 
+#include <sys/sysctl.h>
+
 #include "openbsd-compat/sys-queue.h"
 #include "xmalloc.h"
 #include "packet.h"
@@ -109,7 +111,19 @@ bind_permitted(int port, uid_t uid)
 {
 	if (use_privsep)
 		return 1; /* allow system to decide */
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
