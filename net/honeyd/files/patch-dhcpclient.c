--- dhcpclient.c.orig	Thu Apr 20 08:23:52 2006
+++ dhcpclient.c	Thu Apr 20 08:24:15 2006
@@ -211,8 +211,8 @@
 {
 	struct dhcpclient_req *req = tmpl->dhcp_req;
 	struct dhcp_msg *msg = (struct dhcp_msg *)buf;
-	size_t optlen = buflen - sizeof(*msg);
-	uint8_t *p, *end, opt1, opt1len, *opt1p;
+	size_t optlen = buflen - sizeof(*msg), opt1len;
+	uint8_t *p, *end, opt1, *opt1p;
 	short replyreq = 0, ack = 0, done = 0;
 	struct netconf nc;
 	struct addr *which = NULL, ipmask;
