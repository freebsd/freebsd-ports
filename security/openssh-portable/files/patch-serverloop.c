------------------------------------------------------------------------
r181918 | des | 2008-08-20 05:40:07 -0500 (Wed, 20 Aug 2008) | 6 lines
Changed paths:
   M /head/crypto/openssh/readconf.c

Use net.inet.ip.portrange.reservedhigh instead of IPPORT_RESERVED.
Submitted upstream, no reaction.

Submitted by:   delphij
[rewritten for 7.4 by bdrewery]
[base removed this in 7.8 but it is still useful - bdrewery]

--- serverloop.c.orig	2020-09-27 00:25:01.000000000 -0700
+++ serverloop.c	2020-11-16 12:58:44.823775000 -0800
@@ -56,6 +56,8 @@
 #include <unistd.h>
 #include <stdarg.h>
 
+#include <sys/sysctl.h>
+
 #include "openbsd-compat/sys-queue.h"
 #include "xmalloc.h"
 #include "packet.h"
@@ -104,13 +106,27 @@ static void server_init_dispatch(struct ssh *);
 /* requested tunnel forwarding interface(s), shared with session.c */
 char *tun_fwd_ifnames = NULL;
 
+static int
+ipport_reserved(void)
+{
+#ifdef __FreeBSD__
+	int old;
+	size_t len = sizeof(old);
+
+	if (sysctlbyname("net.inet.ip.portrange.reservedhigh",
+	    &old, &len, NULL, 0) == 0)
+		return (old + 1);
+#endif
+	return (IPPORT_RESERVED);
+}
+
 /* returns 1 if bind to specified port by specified user is permitted */
 static int
 bind_permitted(int port, uid_t uid)
 {
 	if (use_privsep)
 		return 1; /* allow system to decide */
-	if (port < IPPORT_RESERVED && uid != 0)
+	if (port < ipport_reserved() && uid != 0)
 		return 0;
 	return 1;
 }
