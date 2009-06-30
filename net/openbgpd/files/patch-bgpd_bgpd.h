Index: bgpd/bgpd.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/bgpd.h,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpd/bgpd.h	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/bgpd.h	30 Jun 2009 06:56:51 -0000	1.3
@@ -30,9 +30,15 @@
 #include <poll.h>
 #include <stdarg.h>
 
+#if defined(__FreeBSD__)	/* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
+
 #define	BGP_VERSION			4
 #define	BGP_PORT			179
+#ifndef CONFFILE
 #define	CONFFILE			"/etc/bgpd.conf"
+#endif /* !CONFFILE */
 #define	BGPD_USER			"_bgpd"
 #define	PEER_DESCR_LEN			32
 #define	PFTABLE_LEN			16
