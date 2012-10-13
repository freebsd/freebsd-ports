Index: bgpctl/irrfilter.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/irrfilter.h,v
retrieving revision 1.1.1.5
retrieving revision 1.4
diff -u -p -r1.1.1.5 -r1.4
--- bgpctl/irrfilter.h	14 Feb 2010 20:20:14 -0000	1.1.1.5
+++ bgpctl/irrfilter.h	13 Oct 2012 18:35:56 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: irrfilter.h,v 1.7 2007/03/06 16:45:34 henning Exp $ */
+/*	$OpenBSD: irrfilter.h,v 1.8 2009/09/08 15:40:25 claudio Exp $ */
 
 /*
  * Copyright (c) 2007 Henning Brauer <henning@openbsd.org>
@@ -16,11 +16,17 @@
  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#if defined(__FreeBSD__)	/* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
+
 #include <sys/queue.h>
 #include <sys/tree.h>
 #include <netinet/in.h>
 
 #define	F_IMPORTONLY	0x01	/* skip export: items */
+#define	F_IPV4		0x02	/* use IPv4 items */
+#define	F_IPV6		0x04	/* use IPv6 items */
 
 int	irrflags;
 int	irrverbose;
@@ -37,7 +43,7 @@ struct policy_item {
 	char				*action;
 	char				*filter;
 	enum pdir			 dir;
-	u_int16_t			 peer_as;
+	u_int32_t			 peer_as;
 };
 
 TAILQ_HEAD(policy_head, policy_item);
@@ -55,7 +61,8 @@ enum qtype {
 	QTYPE_NONE,
 	QTYPE_OWNAS,
 	QTYPE_ASSET,
-	QTYPE_ROUTE
+	QTYPE_ROUTE,
+	QTYPE_ROUTE6
 };
 
 struct as_set {
@@ -72,6 +79,7 @@ struct as_set {
 struct irr_prefix {
 	union {
 		struct in_addr	in;
+		struct in6_addr	in6;
 	} addr;
 	sa_family_t	af;
 	u_int8_t	len;
