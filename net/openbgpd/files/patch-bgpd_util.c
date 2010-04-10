Index: bgpd/util.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/util.c,v
retrieving revision 1.1.1.6
retrieving revision 1.5
diff -u -p -r1.1.1.6 -r1.5
--- bgpd/util.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/util.c	10 Apr 2010 12:16:23 -0000	1.5
@@ -1,4 +1,4 @@
-/*	$OpenBSD: util.c,v 1.6 2009/06/12 16:42:53 claudio Exp $ */
+/*	$OpenBSD: util.c,v 1.11 2010/03/29 09:04:43 claudio Exp $ */
 
 /*
  * Copyright (c) 2006 Claudio Jeker <claudio@openbsd.org>
@@ -18,6 +18,9 @@
  */
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(__FreeBSD__)	/* sys/limits.h */
+#include <sys/limits.h>
+#endif /* defined(__FreeBSD__) */
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
@@ -32,11 +35,24 @@ const char *
 log_addr(const struct bgpd_addr *addr)
 {
 	static char	buf[48];
+	char		tbuf[16];
 
-	if (inet_ntop(addr->af, &addr->ba, buf, sizeof(buf)) == NULL)
-		return ("?");
-	else
+	switch (addr->aid) {
+	case AID_INET:
+	case AID_INET6:
+		if (inet_ntop(aid2af(addr->aid), &addr->ba, buf,
+		    sizeof(buf)) == NULL)
+			return ("?");
+		return (buf);
+	case AID_VPN_IPv4:
+		if (inet_ntop(AF_INET, &addr->vpn4.addr, tbuf,
+		    sizeof(tbuf)) == NULL)
+			return ("?");
+		snprintf(buf, sizeof(buf), "%s %s", log_rd(addr->vpn4.rd),
+		   tbuf);
 		return (buf);
+	}
+	return ("???");
 }
 
 const char *
@@ -90,6 +106,64 @@ log_as(u_int32_t as)
 	return (buf);
 }
 
+const char *
+log_rd(u_int64_t rd)
+{
+	static char	buf[32];
+	struct in_addr	addr;
+	u_int32_t	u32;
+	u_int16_t	u16;
+
+	rd = betoh64(rd);
+	switch (rd >> 48) {
+	case EXT_COMMUNITY_TWO_AS:
+		u32 = rd & 0xffffffff;
+		u16 = (rd >> 32) & 0xffff;
+		snprintf(buf, sizeof(buf), "rd %i:%i", u16, u32);
+		break;
+	case EXT_COMMUNITY_FOUR_AS:
+		u32 = (rd >> 16) & 0xffffffff;
+		u16 = rd & 0xffff;
+		snprintf(buf, sizeof(buf), "rd %s:%i", log_as(u32), u16);
+		break;
+	case EXT_COMMUNITY_IPV4:
+		u32 = (rd >> 16) & 0xffffffff;
+		u16 = rd & 0xffff;
+		addr.s_addr = htonl(u32);
+		snprintf(buf, sizeof(buf), "rd %s:%i", inet_ntoa(addr), u16);
+		break;
+	default:
+		return ("rd ?");
+	}
+	return (buf);
+}
+
+/* NOTE: this function does not check if the type/subtype combo is
+ * actually valid. */
+const char *
+log_ext_subtype(u_int8_t subtype)
+{
+	static char etype[6];
+
+	switch (subtype) {
+	case EXT_COMMUNITY_ROUTE_TGT:
+		return ("rt");	/* route target */
+	case EXT_CUMMUNITY_ROUTE_ORIG:
+		return ("soo");	/* source of origin */
+	case EXT_COMMUNITY_OSPF_DOM_ID:
+		return ("odi");	/* ospf domain id */
+	case EXT_COMMUNITY_OSPF_RTR_TYPE:
+		return ("ort");	/* ospf route type */
+	case EXT_COMMUNITY_OSPF_RTR_ID:
+		return ("ori");	/* ospf router id */
+	case EXT_COMMUNITY_BGP_COLLECT:
+		return ("bdc");	/* bgp data collection */
+	default:
+		snprintf(etype, sizeof(etype), "[%i]", (int)subtype);
+		return (etype);
+	}
+}
+
 int
 aspath_snprint(char *buf, size_t size, void *data, u_int16_t len)
 {
@@ -276,3 +350,115 @@ inet6applymask(struct in6_addr *dest, co
 	for (i = 0; i < 16; i++)
 		dest->s6_addr[i] = src->s6_addr[i] & mask.s6_addr[i];
 }
+
+/* address family translation functions */
+const struct aid aid_vals[AID_MAX] = AID_VALS;
+
+const char *
+aid2str(u_int8_t aid)
+{
+	if (aid < AID_MAX)
+		return (aid_vals[aid].name);
+	return ("unknown AID");
+}
+
+int
+aid2afi(u_int8_t aid, u_int16_t *afi, u_int8_t *safi)
+{
+	if (aid < AID_MAX) {
+		*afi = aid_vals[aid].afi;
+		*safi = aid_vals[aid].safi;
+		return (0);
+	}
+	return (-1);
+}
+
+int
+afi2aid(u_int16_t afi, u_int8_t safi, u_int8_t *aid)
+{
+	u_int8_t i;
+
+	for (i = 0; i < AID_MAX; i++)
+		if (aid_vals[i].afi == afi && aid_vals[i].safi == safi) {
+			*aid = i;
+			return (0);
+		}
+
+	return (-1);
+}
+
+sa_family_t
+aid2af(u_int8_t aid)
+{
+	if (aid < AID_MAX)
+		return (aid_vals[aid].af);
+	return (AF_UNSPEC);
+}
+
+int
+af2aid(sa_family_t af, u_int8_t safi, u_int8_t *aid)
+{
+	u_int8_t i;
+
+	if (safi == 0) /* default to unicast subclass */
+		safi = SAFI_UNICAST;
+
+	for (i = 0; i < AID_MAX; i++)
+		if (aid_vals[i].af == af && aid_vals[i].safi == safi) {
+			*aid = i;
+			return (0);
+		}
+
+	return (-1);
+}
+
+struct sockaddr *
+addr2sa(struct bgpd_addr *addr, u_int16_t port)
+{
+	static struct sockaddr_storage	 ss;
+	struct sockaddr_in		*sa_in = (struct sockaddr_in *)&ss;
+	struct sockaddr_in6		*sa_in6 = (struct sockaddr_in6 *)&ss;
+
+	if (addr->aid == AID_UNSPEC)
+		return (NULL);
+
+	bzero(&ss, sizeof(ss));
+	switch (addr->aid) {
+	case AID_INET:
+		sa_in->sin_family = AF_INET;
+		sa_in->sin_len = sizeof(struct sockaddr_in);
+		sa_in->sin_addr.s_addr = addr->v4.s_addr;
+		sa_in->sin_port = htons(port);
+		break;
+	case AID_INET6:
+		sa_in6->sin6_family = AF_INET6;
+		sa_in6->sin6_len = sizeof(struct sockaddr_in6);
+		memcpy(&sa_in6->sin6_addr, &addr->v6,
+		    sizeof(sa_in6->sin6_addr));
+		sa_in6->sin6_port = htons(port);
+		sa_in6->sin6_scope_id = addr->scope_id;
+		break;
+	}
+
+	return ((struct sockaddr *)&ss);
+}
+
+void
+sa2addr(struct sockaddr *sa, struct bgpd_addr *addr)
+{
+	struct sockaddr_in		*sa_in = (struct sockaddr_in *)sa;
+	struct sockaddr_in6		*sa_in6 = (struct sockaddr_in6 *)sa;
+
+	bzero(addr, sizeof(*addr));
+	switch (sa->sa_family) {
+	case AF_INET:
+		addr->aid = AID_INET;
+		memcpy(&addr->v4, &sa_in->sin_addr, sizeof(addr->v4));
+		break;
+	case AF_INET6:
+		addr->aid = AID_INET6;
+		memcpy(&addr->v6, &sa_in6->sin6_addr, sizeof(addr->v6));
+		addr->scope_id = sa_in6->sin6_scope_id; /* I hate v6 */
+		break;
+	}
+}
