Index: bgpd/mrt.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/mrt.c,v
retrieving revision 1.1.1.7
retrieving revision 1.1.1.8
diff -u -p -r1.1.1.7 -r1.1.1.8
--- bgpd/mrt.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/mrt.c	14 Feb 2010 20:27:06 -0000	1.1.1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: mrt.c,v 1.63 2009/06/29 12:22:16 claudio Exp $ */
+/*	$OpenBSD: mrt.c,v 1.66 2009/12/01 14:28:05 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -194,7 +194,7 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 	struct bgpd_addr addr, nexthop, *nh;
 	u_int16_t	 len;
 	u_int8_t	 p_len;
-	sa_family_t	 af;
+	u_int8_t	 aid;
 
 	if ((buf = buf_dynamic(0, MAX_PKTSIZE)) == NULL) {
 		log_warn("mrt_dump_entry_mp: buf_dynamic");
@@ -219,14 +219,15 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 	DUMP_SHORT(h2buf, /* ifindex */ 0);
 
 	/* XXX is this for peer self? */
-	af = peer->remote_addr.af == 0 ? p->prefix->af : peer->remote_addr.af;
-	switch (af) {
-	case AF_INET:
+	aid = peer->remote_addr.aid == AID_UNSPEC ? p->prefix->aid :
+	     peer->remote_addr.aid;
+	switch (aid) {
+	case AID_INET:
 		DUMP_SHORT(h2buf, AFI_IPv4);
 		DUMP_NLONG(h2buf, peer->local_v4_addr.v4.s_addr);
 		DUMP_NLONG(h2buf, peer->remote_addr.v4.s_addr);
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		DUMP_SHORT(h2buf, AFI_IPv6);
 		if (buf_add(h2buf, &peer->local_v6_addr.v6,
 		    sizeof(struct in6_addr)) == -1 ||
@@ -237,7 +238,7 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 		}
 		break;
 	default:
-		log_warnx("king bula found new AF %d in mrt_dump_entry_mp", af);
+		log_warnx("king bula found new AF in mrt_dump_entry_mp");
 		goto fail;
 	}
 
@@ -247,20 +248,20 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 
 	if (p->aspath->nexthop == NULL) {
 		bzero(&nexthop, sizeof(struct bgpd_addr));
-		nexthop.af = addr.af;
+		nexthop.aid = addr.aid;
 		nh = &nexthop;
 	} else
 		nh = &p->aspath->nexthop->exit_nexthop;
 
 	pt_getaddr(p->prefix, &addr);
-	switch (addr.af) {
-	case AF_INET:
+	switch (addr.aid) {
+	case AID_INET:
 		DUMP_SHORT(h2buf, AFI_IPv4);	/* afi */
 		DUMP_BYTE(h2buf, SAFI_UNICAST);	/* safi */
 		DUMP_BYTE(h2buf, 4);		/* nhlen */
 		DUMP_NLONG(h2buf, nh->v4.s_addr);	/* nexthop */
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		DUMP_SHORT(h2buf, AFI_IPv6);	/* afi */
 		DUMP_BYTE(h2buf, SAFI_UNICAST);	/* safi */
 		DUMP_BYTE(h2buf, 16);		/* nhlen */
@@ -300,7 +301,7 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 fail:
 	if (hbuf)
 		buf_free(hbuf);
-	if (h2buf);
+	if (h2buf)
 		buf_free(h2buf);
 	buf_free(buf);
 	return (-1);
@@ -314,7 +315,8 @@ mrt_dump_entry(struct mrt *mrt, struct p
 	struct bgpd_addr addr, *nh;
 	size_t		 len;
 
-	if (p->prefix->af != AF_INET && peer->remote_addr.af == AF_INET)
+	if (p->prefix->aid != AID_INET &&
+	    peer->remote_addr.aid == AID_INET)
 		/* only able to dump IPv4 */
 		return (0);
 
@@ -325,7 +327,7 @@ mrt_dump_entry(struct mrt *mrt, struct p
 
 	if (p->aspath->nexthop == NULL) {
 		bzero(&addr, sizeof(struct bgpd_addr));
-		addr.af = AF_INET;
+		addr.aid = AID_INET;
 		nh = &addr;
 	} else
 		nh = &p->aspath->nexthop->exit_nexthop;
@@ -387,7 +389,7 @@ mrt_dump_upcall(struct rib_entry *re, vo
 }
 
 void
-mrt_dump_done(void *ptr)
+mrt_done(void *ptr)
 {
 	struct mrt		*mrtbuf = ptr;
 
@@ -541,6 +543,7 @@ mrt_write(struct mrt *mrt)
 	if ((r = buf_write(&mrt->wbuf)) < 0) {
 		log_warn("mrt dump aborted, mrt_write");
 		mrt_clean(mrt);
+		mrt_done(mrt);
 	}
 }
 
