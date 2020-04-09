--- device-bsd44.c.orig	2018-02-18 22:45:02 UTC
+++ device-bsd44.c
@@ -126,7 +126,31 @@ ret:
 	return -1;
 }
 
-int setup_allrouters_membership(int sock, struct Interface *iface) { return 0; }
+int setup_allrouters_membership(int sock, struct Interface *iface) 
+{
+	struct ipv6_mreq mreq;
+
+	memset(&mreq, 0, sizeof(mreq));
+	mreq.ipv6mr_interface = iface->props.if_index;
+
+	/* all-routers multicast address */
+	if (inet_pton(AF_INET6, "ff02::2",
+			&mreq.ipv6mr_multiaddr.s6_addr) != 1) {
+		flog(LOG_ERR, "inet_pton failed");
+		return (-1);
+	}
+
+	/* if we leave unconditionally the join cannot fail */
+	setsockopt(sock, IPPROTO_IPV6, IPV6_LEAVE_GROUP, &mreq, sizeof(mreq));
+
+	if (setsockopt(sock, IPPROTO_IPV6, IPV6_JOIN_GROUP,
+			&mreq, sizeof(mreq)) < 0) {
+		flog(LOG_ERR, "can't join ipv6-allrouters on %s", iface->props.name);
+		return (-1);
+	}
+
+	return 0; 
+}
 
 int set_interface_linkmtu(const char *iface, uint32_t mtu)
 {
@@ -161,5 +185,5 @@ int check_ip6_forwarding(void)
 int check_ip6_iface_forwarding(const char *iface)
 {
 	dlog(LOG_DEBUG, 4, "checking ipv6 forwarding of interface not supported");
-	return -1;
+	return 1;
 }
