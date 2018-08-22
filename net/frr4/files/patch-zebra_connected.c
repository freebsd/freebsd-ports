--- zebra/connected.c.orig	2018-03-12 01:53:37.000000000 +0100
+++ zebra/connected.c	2018-07-12 09:11:27.490278000 +0200
@@ -486,7 +486,9 @@
 
 /* Add connected IPv6 route to the interface. */
 void connected_add_ipv6(struct interface *ifp, int flags, struct in6_addr *addr,
-			u_char prefixlen, const char *label)
+			struct in6_addr *broad, uint8_t prefixlen,
+			const char *label)
+
 {
 	struct prefix_ipv6 *p;
 	struct connected *ifc;
@@ -508,6 +510,19 @@
 	IPV6_ADDR_COPY(&p->prefix, addr);
 	p->prefixlen = prefixlen;
 	ifc->address = (struct prefix *)p;
+	if (broad) {
+		p = prefix_ipv6_new();
+		p->family = AF_INET6;
+		IPV6_ADDR_COPY(&p->prefix, broad);
+		p->prefixlen = prefixlen;
+		ifc->destination = (struct prefix *)p;
+	} else {
+		if (CHECK_FLAG(ifc->flags, ZEBRA_IFA_PEER)) {
+			zlog_warn("warning: %s called for interface %s with peer flag set, but no peer address supplied",
+				  __func__, ifp->name);
+			UNSET_FLAG(ifc->flags, ZEBRA_IFA_PEER);
+		}
+	}
 
 	/* Label of this address. */
 	if (label)
@@ -527,9 +542,9 @@
 }
 
 void connected_delete_ipv6(struct interface *ifp, struct in6_addr *address,
-			   u_char prefixlen)
+						struct in6_addr *broad, uint8_t prefixlen)
 {
-	struct prefix p;
+	struct prefix p, d;
 	struct connected *ifc;
 
 	memset(&p, 0, sizeof(struct prefix));
@@ -537,7 +552,14 @@
 	memcpy(&p.u.prefix6, address, sizeof(struct in6_addr));
 	p.prefixlen = prefixlen;
 
-	ifc = connected_check(ifp, &p);
+	if (broad) {
+		memset(&d, 0, sizeof(struct prefix));
+		d.family = AF_INET6;
+		IPV6_ADDR_COPY(&d.u.prefix, broad);
+		d.prefixlen = prefixlen;
+		ifc = connected_check_ptp(ifp, &p, &d);
+	} else
+		ifc = connected_check_ptp(ifp, &p, NULL);
 
 	connected_delete_helper(ifc, &p);
 }
