Index: bgpd/kroute.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/kroute.c,v
retrieving revision 1.1.1.7
retrieving revision 1.9
diff -u -p -r1.1.1.7 -r1.9
--- bgpd/kroute.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/kroute.c	10 Apr 2010 12:16:23 -0000	1.9
@@ -1,4 +1,4 @@
-/*	$OpenBSD: kroute.c,v 1.169 2009/06/25 15:54:22 claudio Exp $ */
+/*	$OpenBSD: kroute.c,v 1.176 2010/04/06 13:25:08 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -463,25 +463,30 @@ kr_nexthop_add(struct bgpd_addr *addr)
 		bzero(&nh, sizeof(nh));
 		memcpy(&nh.nexthop, addr, sizeof(nh.nexthop));
 		nh.valid = 1;
-		if (h->kroute != NULL && addr->af == AF_INET) {
+		if (h->kroute != NULL && addr->aid == AID_INET) {
 			k = h->kroute;
 			nh.connected = k->r.flags & F_CONNECTED;
 			if (k->r.nexthop.s_addr != 0) {
-				nh.gateway.af = AF_INET;
+				nh.gateway.aid = AID_INET;
 				nh.gateway.v4.s_addr =
 				    k->r.nexthop.s_addr;
 			}
-			memcpy(&nh.kr.kr4, &k->r, sizeof(nh.kr.kr4));
-		} else if (h->kroute != NULL && addr->af == AF_INET6) {
+			nh.net.aid = AID_INET;
+			nh.net.v4.s_addr = k->r.prefix.s_addr;
+			nh.netlen = k->r.prefixlen;
+		} else if (h->kroute != NULL && addr->aid == AID_INET6) {
 			k6 = h->kroute;
 			nh.connected = k6->r.flags & F_CONNECTED;
 			if (memcmp(&k6->r.nexthop, &in6addr_any,
 			    sizeof(struct in6_addr)) != 0) {
-				nh.gateway.af = AF_INET6;
+				nh.gateway.aid = AID_INET6;
 				memcpy(&nh.gateway.v6, &k6->r.nexthop,
 				    sizeof(struct in6_addr));
 			}
-			memcpy(&nh.kr.kr6, &k6->r, sizeof(nh.kr.kr6));
+			nh.net.aid = AID_INET6;
+			memcpy(&nh.net.v6, &k6->r.nexthop,
+			    sizeof(struct in6_addr));
+			nh.netlen = k6->r.prefixlen;
 		}
 
 		send_nexthop_update(&nh);
@@ -563,14 +568,14 @@ kr_show_route(struct imsg *imsg)
 		}
 		addr = imsg->data;
 		kr = NULL;
-		switch (addr->af) {
-		case AF_INET:
+		switch (addr->aid) {
+		case AID_INET:
 			kr = kroute_match(addr->v4.s_addr, 1);
 			if (kr != NULL)
 				send_imsg_session(IMSG_CTL_KROUTE,
 				    imsg->hdr.pid, &kr->r, sizeof(kr->r));
 			break;
-		case AF_INET6:
+		case AID_INET6:
 			kr6 = kroute6_match(&addr->v6, 1);
 			if (kr6 != NULL)
 				send_imsg_session(IMSG_CTL_KROUTE6,
@@ -583,15 +588,21 @@ kr_show_route(struct imsg *imsg)
 			bzero(&snh, sizeof(snh));
 			memcpy(&snh.addr, &h->nexthop, sizeof(snh.addr));
 			if (h->kroute != NULL) {
-				switch (h->nexthop.af) {
-				case AF_INET:
+				switch (h->nexthop.aid) {
+				case AID_INET:
 					kr = h->kroute;
 					snh.valid = kroute_validate(&kr->r);
+					snh.krvalid = 1;
+					memcpy(&snh.kr.kr4, &kr->r,
+					    sizeof(snh.kr.kr4));
 					ifindex = kr->r.ifindex;
 					break;
-				case AF_INET6:
+				case AID_INET6:
 					kr6 = h->kroute;
 					snh.valid = kroute6_validate(&kr6->r);
+					snh.krvalid = 1;
+					memcpy(&snh.kr.kr6, &kr6->r,
+					    sizeof(snh.kr.kr6));
 					ifindex = kr6->r.ifindex;
 					break;
 				}
@@ -846,26 +857,28 @@ kroute6_compare(struct kroute6_node *a, 
 int
 knexthop_compare(struct knexthop_node *a, struct knexthop_node *b)
 {
-	u_int32_t	r;
+	int	i;
 
-	if (a->nexthop.af != b->nexthop.af)
-		return (b->nexthop.af - a->nexthop.af);
+	if (a->nexthop.aid != b->nexthop.aid)
+		return (b->nexthop.aid - a->nexthop.aid);
 
-	switch (a->nexthop.af) {
-	case AF_INET:
-		if ((r = b->nexthop.addr32[0] - a->nexthop.addr32[0]) != 0)
-			return (r);
+	switch (a->nexthop.aid) {
+	case AID_INET:
+		if (ntohl(a->nexthop.v4.s_addr) < ntohl(b->nexthop.v4.s_addr))
+			return (-1);
+		if (ntohl(a->nexthop.v4.s_addr) > ntohl(b->nexthop.v4.s_addr))
+			return (1);
 		break;
-	case AF_INET6:
-		if ((r = b->nexthop.addr32[3] - a->nexthop.addr32[3]) != 0)
-			return (r);
-		if ((r = b->nexthop.addr32[2] - a->nexthop.addr32[2]) != 0)
-			return (r);
-		if ((r = b->nexthop.addr32[1] - a->nexthop.addr32[1]) != 0)
-			return (r);
-		if ((r = b->nexthop.addr32[0] - a->nexthop.addr32[0]) != 0)
-			return (r);
+	case AID_INET6:
+		for (i = 0; i < 16; i++) {
+			if (a->nexthop.v6.s6_addr[i] < b->nexthop.v6.s6_addr[i])
+				return (-1);
+			if (a->nexthop.v6.s6_addr[i] > b->nexthop.v6.s6_addr[i])
+				return (1);
+		}
 		break;
+	default:
+		fatalx("knexthop_compare: unknown AF");
 	}
 
 	return (0);
@@ -945,7 +958,7 @@ kroute_insert(struct kroute_node *kr)
 		mask = prefixlen2mask(kr->r.prefixlen);
 		ina = ntohl(kr->r.prefix.s_addr);
 		RB_FOREACH(h, knexthop_tree, &knt)
-			if (h->nexthop.af == AF_INET &&
+			if (h->nexthop.aid == AID_INET &&
 			    (ntohl(h->nexthop.v4.s_addr) & mask) == ina)
 				knexthop_validate(h);
 
@@ -1065,7 +1078,7 @@ kroute6_matchgw(struct kroute6_node *kr,
 	memcpy(&nexthop, &sa_in6->sin6_addr, sizeof(nexthop));
 
 	while (kr) {
-		if (memcmp(&kr->r.nexthop, &nexthop, sizeof(nexthop)) == NULL)
+		if (memcmp(&kr->r.nexthop, &nexthop, sizeof(nexthop)) == 0)
 			return (kr);
 		kr = kr->next;
 	}
@@ -1091,7 +1104,7 @@ kroute6_insert(struct kroute6_node *kr)
 	if (kr->r.flags & F_KERNEL) {
 		inet6applymask(&ina, &kr->r.prefix, kr->r.prefixlen);
 		RB_FOREACH(h, knexthop_tree, &knt)
-			if (h->nexthop.af == AF_INET6) {
+			if (h->nexthop.aid == AID_INET6) {
 				inet6applymask(&inb, &h->nexthop.v6,
 				    kr->r.prefixlen);
 				if (memcmp(&ina, &inb, sizeof(ina)) == 0)
@@ -1184,6 +1197,7 @@ knexthop_find(struct bgpd_addr *addr)
 {
 	struct knexthop_node	s;
 
+	bzero(&s, sizeof(s));
 	memcpy(&s.nexthop, addr, sizeof(s.nexthop));
 
 	return (RB_FIND(knexthop_tree, &knt, &s));
@@ -1480,17 +1494,17 @@ knexthop_validate(struct knexthop_node *
 	struct kroute_nexthop	 n;
 	int			 was_valid = 0;
 
-	if (kn->nexthop.af == AF_INET && (kr = kn->kroute) != NULL)
+	if (kn->nexthop.aid == AID_INET && (kr = kn->kroute) != NULL)
 		was_valid = kroute_validate(&kr->r);
-	if (kn->nexthop.af == AF_INET6 && (kr6 = kn->kroute) != NULL)
+	if (kn->nexthop.aid == AID_INET6 && (kr6 = kn->kroute) != NULL)
 		was_valid = kroute6_validate(&kr6->r);
 
 	bzero(&n, sizeof(n));
 	memcpy(&n.nexthop, &kn->nexthop, sizeof(n.nexthop));
 	kroute_detach_nexthop(kn);
 
-	switch (kn->nexthop.af) {
-	case AF_INET:
+	switch (kn->nexthop.aid) {
+	case AID_INET:
 		if ((kr = kroute_match(kn->nexthop.v4.s_addr, 0)) == NULL) {
 			if (was_valid)
 				send_nexthop_update(&n);
@@ -1500,8 +1514,10 @@ knexthop_validate(struct knexthop_node *
 				n.connected = kr->r.flags & F_CONNECTED;
 				if ((n.gateway.v4.s_addr =
 				    kr->r.nexthop.s_addr) != 0)
-					n.gateway.af = AF_INET;
-				memcpy(&n.kr.kr4, &kr->r, sizeof(n.kr.kr4));
+					n.gateway.aid = AID_INET;
+				n.net.aid = AID_INET;
+				n.net.v4.s_addr = kr->r.prefix.s_addr;
+				n.netlen = kr->r.prefixlen;
 				send_nexthop_update(&n);
 			} else					/* down */
 				if (was_valid)
@@ -1511,7 +1527,7 @@ knexthop_validate(struct knexthop_node *
 			kr->r.flags |= F_NEXTHOP;
 		}
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		if ((kr6 = kroute6_match(&kn->nexthop.v6, 0)) == NULL) {
 			if (was_valid)
 				send_nexthop_update(&n);
@@ -1521,11 +1537,14 @@ knexthop_validate(struct knexthop_node *
 				n.connected = kr6->r.flags & F_CONNECTED;
 				if (memcmp(&kr6->r.nexthop, &in6addr_any,
 				    sizeof(struct in6_addr)) != 0) {
-					n.gateway.af = AF_INET6;
+					n.gateway.aid = AID_INET6;
 					memcpy(&n.gateway.v6, &kr6->r.nexthop,
 					    sizeof(struct in6_addr));
 				}
-				memcpy(&n.kr.kr6, &kr6->r, sizeof(n.kr.kr6));
+				n.net.aid = AID_INET6;
+				memcpy(&n.net.v6, &kr6->r.nexthop,
+				    sizeof(struct in6_addr));
+				n.netlen = kr6->r.prefixlen;
 				send_nexthop_update(&n);
 			} else					/* down */
 				if (was_valid)
@@ -1551,27 +1570,32 @@ knexthop_track(void *krn)
 			bzero(&n, sizeof(n));
 			memcpy(&n.nexthop, &kn->nexthop, sizeof(n.nexthop));
 
-			switch (kn->nexthop.af) {
-			case AF_INET:
+			switch (kn->nexthop.aid) {
+			case AID_INET:
 				kr = krn;
 				n.valid = 1;
 				n.connected = kr->r.flags & F_CONNECTED;
 				if ((n.gateway.v4.s_addr =
 				    kr->r.nexthop.s_addr) != 0)
-					n.gateway.af = AF_INET;
-				memcpy(&n.kr.kr4, &kr->r, sizeof(n.kr.kr4));
+					n.gateway.aid = AID_INET;
+				n.net.aid = AID_INET;
+				n.net.v4.s_addr = kr->r.prefix.s_addr;
+				n.netlen = kr->r.prefixlen;
 				break;
-			case AF_INET6:
+			case AID_INET6:
 				kr6 = krn;
 				n.valid = 1;
 				n.connected = kr6->r.flags & F_CONNECTED;
 				if (memcmp(&kr6->r.nexthop, &in6addr_any,
 				    sizeof(struct in6_addr)) != 0) {
-					n.gateway.af = AF_INET6;
+					n.gateway.aid = AID_INET6;
 					memcpy(&n.gateway.v6, &kr6->r.nexthop,
 					    sizeof(struct in6_addr));
 				}
-				memcpy(&n.kr.kr6, &kr6->r, sizeof(n.kr.kr6));
+				n.net.aid = AID_INET6;
+				memcpy(&n.net.v6, &kr6->r.nexthop,
+				    sizeof(struct in6_addr));
+				n.netlen = kr6->r.prefixlen;
 				break;
 			}
 			send_nexthop_update(&n);
@@ -1645,12 +1669,12 @@ kroute_detach_nexthop(struct knexthop_no
 		;	/* nothing */
 
 	if (s == NULL) {
-		switch (kn->nexthop.af) {
-		case AF_INET:
+		switch (kn->nexthop.aid) {
+		case AID_INET:
 			k = kn->kroute;
 			k->r.flags &= ~F_NEXTHOP;
 			break;
-		case AF_INET6:
+		case AID_INET6:
 			k6 = kn->kroute;
 			k6->r.flags &= ~F_NEXTHOP;
 			break;
@@ -1675,7 +1699,7 @@ protect_lo(void)
 		log_warn("protect_lo");
 		return (-1);
 	}
-	kr->r.prefix.s_addr = htonl(INADDR_LOOPBACK);
+	kr->r.prefix.s_addr = htonl(INADDR_LOOPBACK & IN_CLASSA_NET);
 	kr->r.prefixlen = 8;
 	kr->r.flags = F_KERNEL|F_CONNECTED;
 
@@ -1689,7 +1713,7 @@ protect_lo(void)
 	}
 	memcpy(&kr6->r.prefix, &in6addr_loopback, sizeof(kr6->r.prefix));
 	kr6->r.prefixlen = 128;
-	kr->r.flags = F_KERNEL|F_CONNECTED;
+	kr6->r.flags = F_KERNEL|F_CONNECTED;
 
 	if (RB_INSERT(kroute6_tree, &krt6, kr6) != NULL)
 		free(kr6);	/* kernel route already there, no problem */
@@ -1788,7 +1812,7 @@ prefixlen2mask6(u_int8_t prefixlen)
 }
 
 #define	ROUNDUP(a)	\
-    (((a) & ((sizeof(long)) - 1)) ? (1 + ((a) | ((sizeof(long)) - 1))) : (a))
+    (((a) & (sizeof(long) - 1)) ? (1 + ((a) | (sizeof(long) - 1))) : (a))
 
 void
 get_rtaddrs(int addrs, struct sockaddr *sa, struct sockaddr **rti_info)
@@ -1849,10 +1873,11 @@ if_change(u_short ifindex, int flags, st
 					nh.connected = 1;
 					if ((nh.gateway.v4.s_addr =
 					    kkr->kr->r.nexthop.s_addr) != 0)
-						nh.gateway.af = AF_INET;
+						nh.gateway.aid = AID_INET;
 				}
-				memcpy(&nh.kr.kr4, &kkr->kr->r,
-				    sizeof(nh.kr.kr4));
+				nh.net.aid = AID_INET;
+				nh.net.v4.s_addr = kkr->kr->r.prefix.s_addr;
+				nh.netlen = kkr->kr->r.prefixlen;
 				send_nexthop_update(&nh);
 			}
 	}
@@ -1873,14 +1898,16 @@ if_change(u_short ifindex, int flags, st
 					if (memcmp(&kkr6->kr->r.nexthop,
 					    &in6addr_any, sizeof(struct
 					    in6_addr))) {
-						nh.gateway.af = AF_INET6;
+						nh.gateway.aid = AID_INET6;
 						memcpy(&nh.gateway.v6,
 						    &kkr6->kr->r.nexthop,
 						    sizeof(struct in6_addr));
 					}
 				}
-				memcpy(&nh.kr.kr6, &kkr6->kr->r,
-				    sizeof(nh.kr.kr6));
+				nh.net.aid = AID_INET6;
+				memcpy(&nh.net.v6, &kkr6->kr->r.nexthop,
+				    sizeof(struct in6_addr));
+				nh.netlen = kkr6->kr->r.prefixlen;
 				send_nexthop_update(&nh);
 			}
 	}
@@ -1924,7 +1951,9 @@ send_rtmsg(int fd, int action, struct kr
 	struct sockaddr_in	prefix;
 	struct sockaddr_in	nexthop;
 	struct sockaddr_in	mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
@@ -1934,8 +1963,13 @@ send_rtmsg(int fd, int action, struct kr
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */
 	hdr.rtm_tableid = kr_state.rtableid;
+#endif /* !defined(__FreeBSD__) */
+	hdr.rtm_flags = RTF_PROTO1;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no rtm_priority */
 	hdr.rtm_priority = RTP_BGP;
+#endif /* !defined(__FreeBSD__) */
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
 	if (kroute->flags & F_REJECT)
@@ -1984,6 +2018,7 @@ send_rtmsg(int fd, int action, struct kr
 	iov[iovcnt].iov_base = &mask;
 	iov[iovcnt++].iov_len = sizeof(mask);
 
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	if (kroute->labelid) {
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
@@ -1996,6 +2031,7 @@ send_rtmsg(int fd, int action, struct kr
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
 	}
+#endif /* !defined(__FreeBSD__) */
 
 retry:
 	if (writev(fd, iov, iovcnt) == -1) {
@@ -2037,7 +2073,9 @@ send_rt6msg(int fd, int action, struct k
 		struct sockaddr_in6	addr;
 		char			pad[sizeof(long)];
 	} prefix, nexthop, mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
@@ -2047,7 +2085,10 @@ send_rt6msg(int fd, int action, struct k
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 	hdr.rtm_tableid = kr_state.rtableid;
+#endif /* !defined(__FreeBSD__) */
+	hdr.rtm_flags = RTF_PROTO1;
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
 	if (kroute->flags & F_REJECT)
@@ -2100,6 +2141,7 @@ send_rt6msg(int fd, int action, struct k
 	iov[iovcnt].iov_base = &mask;
 	iov[iovcnt++].iov_len = ROUNDUP(sizeof(struct sockaddr_in6));
 
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	if (kroute->labelid) {
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
@@ -2112,6 +2154,7 @@ send_rt6msg(int fd, int action, struct k
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
 	}
+#endif /* !defined(__FreeBSD__) */
 
 retry:
 	if (writev(fd, iov, iovcnt) == -1) {
@@ -2147,8 +2190,8 @@ retry:
 int
 fetchtable(u_int rtableid, int connected_only)
 {
-	size_t			 len;
-	int			 mib[7];
+	size_t			len;
+	int		 	mib[6];
 	char			*buf, *next, *lim;
 	struct rt_msghdr	*rtm;
 	struct sockaddr		*sa, *gw, *rti_info[RTAX_MAX];
@@ -2163,9 +2206,8 @@ fetchtable(u_int rtableid, int connected
 	mib[3] = 0;
 	mib[4] = NET_RT_DUMP;
 	mib[5] = 0;
-	mib[6] = rtableid;
 
-	if (sysctl(mib, 7, NULL, &len, NULL, 0) == -1) {
+	if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) {
 		if (rtableid != 0 && errno == EINVAL)	/* table nonexistent */
 			return (0);
 		log_warn("sysctl");
@@ -2175,7 +2217,7 @@ fetchtable(u_int rtableid, int connected
 		log_warn("fetchtable");
 		return (-1);
 	}
-	if (sysctl(mib, 7, buf, &len, NULL, 0) == -1) {
+	if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
 		log_warn("sysctl");
 		free(buf);
 		return (-1);
@@ -2186,7 +2228,11 @@ fetchtable(u_int rtableid, int connected
 		rtm = (struct rt_msghdr *)next;
 		if (rtm->rtm_version != RTM_VERSION)
 			continue;
+#if !defined(__FreeBSD__)	/* no rtm_hdrlen on FreeBSD */
 		sa = (struct sockaddr *)(next + rtm->rtm_hdrlen);
+#else
+		sa = (struct sockaddr *)(next + sizeof(struct rt_msghdr));
+#endif
 		get_rtaddrs(rtm->rtm_addrs, sa, rti_info);
 
 		if ((sa = rti_info[RTAX_DST]) == NULL)
@@ -2205,7 +2251,11 @@ fetchtable(u_int rtableid, int connected
 			}
 
 			kr->r.flags = F_KERNEL;
+#if defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
+			kr->r.priority = RTP_BGP;
+#else
 			kr->r.priority = rtm->rtm_priority;
+#endif
 			kr->r.ifindex = rtm->rtm_index;
 			kr->r.prefix.s_addr =
 			    ((struct sockaddr_in *)sa)->sin_addr.s_addr;
@@ -2223,8 +2273,12 @@ fetchtable(u_int rtableid, int connected
 					break;
 				kr->r.prefixlen =
 				    mask2prefixlen(sa_in->sin_addr.s_addr);
-			} else if (rtm->rtm_flags & RTF_HOST)
+			} else if (rtm->rtm_flags & RTF_HOST) {
 				kr->r.prefixlen = 32;
+#if defined(__FreeBSD__)	/* RTF_HOST means connected route */
+				kr->r.flags |= F_CONNECTED;
+#endif
+			}
 			else
 				kr->r.prefixlen =
 				    prefixlen_classful(kr->r.prefix.s_addr);
@@ -2238,7 +2292,11 @@ fetchtable(u_int rtableid, int connected
 			}
 
 			kr6->r.flags = F_KERNEL;
+#if defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
+			kr6->r.priority = RTP_BGP;
+#else
 			kr6->r.priority = rtm->rtm_priority;
+#endif
 			kr6->r.ifindex = rtm->rtm_index;
 			memcpy(&kr6->r.prefix,
 			    &((struct sockaddr_in6 *)sa)->sin6_addr,
@@ -2257,8 +2315,12 @@ fetchtable(u_int rtableid, int connected
 				if (sa_in6->sin6_len == 0)
 					break;
 				kr6->r.prefixlen = mask2prefixlen6(sa_in6);
-			} else if (rtm->rtm_flags & RTF_HOST)
+			} else if (rtm->rtm_flags & RTF_HOST) {
 				kr6->r.prefixlen = 128;
+#if defined(__FreeBSD__)	/* RTF_HOST means connected route */
+				kr6->r.flags |= F_CONNECTED;
+#endif
+			}
 			else
 				fatalx("INET6 route without netmask");
 			break;
@@ -2290,7 +2352,12 @@ fetchtable(u_int rtableid, int connected
 			}
 
 		if (sa->sa_family == AF_INET) {
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
 			if (rtm->rtm_priority == RTP_BGP)  {
+#else
+			/* never delete route */
+			if (0) {
+#endif
 				send_rtmsg(kr_state.fd, RTM_DELETE, &kr->r);
 				free(kr);
 			} else if (connected_only &&
@@ -2299,7 +2366,12 @@ fetchtable(u_int rtableid, int connected
 			else
 				kroute_insert(kr);
 		} else if (sa->sa_family == AF_INET6) {
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
 			if (rtm->rtm_priority == RTP_BGP)  {
+#else
+			/* never delete route */
+			if (0) {
+#endif
 				send_rt6msg(kr_state.fd, RTM_DELETE, &kr6->r);
 				free(kr6);
 			} else if (connected_only &&
@@ -2418,7 +2490,11 @@ dispatch_rtmsg(void)
 		case RTM_ADD:
 		case RTM_CHANGE:
 		case RTM_DELETE:
+#if !defined(__FreeBSD__)	/* no rtm_hdrlen on FreeBSD */
 			sa = (struct sockaddr *)(next + rtm->rtm_hdrlen);
+#else
+			sa = (struct sockaddr *)(next + sizeof(struct rt_msghdr));
+#endif
 			get_rtaddrs(rtm->rtm_addrs, sa, rti_info);
 
 			if (rtm->rtm_pid == kr_state.pid) /* cause by us */
@@ -2431,12 +2507,14 @@ dispatch_rtmsg(void)
 				continue;
 
 			connected_only = 0;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 			if (rtm->rtm_tableid != kr_state.rtableid) {
 				if (rtm->rtm_tableid == 0)
 					connected_only = 1;
 				else
 					continue;
 			}
+#endif /* !defined(__FreeBSD__) */
 
 			if (dispatch_rtmsg_addr(rtm, rti_info,
 			    connected_only) == -1)
@@ -2494,31 +2572,44 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 		mpath = 1;
 #endif
 
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
 	prio = rtm->rtm_priority;
-	prefix.af = sa->sa_family;
-	switch (prefix.af) {
+#else
+	prio = RTP_BGP;
+#endif
+	switch (sa->sa_family) {
 	case AF_INET:
+		prefix.aid = AID_INET;
 		prefix.v4.s_addr = ((struct sockaddr_in *)sa)->sin_addr.s_addr;
 		sa_in = (struct sockaddr_in *)rti_info[RTAX_NETMASK];
 		if (sa_in != NULL) {
 			if (sa_in->sin_len != 0)
 				prefixlen = mask2prefixlen(
 				    sa_in->sin_addr.s_addr);
-		} else if (rtm->rtm_flags & RTF_HOST)
+		} else if (rtm->rtm_flags & RTF_HOST) {
 			prefixlen = 32;
+#if defined(__FreeBSD__)	/* RTF_HOST means connected route */
+			flags |= F_CONNECTED;
+#endif
+		}
 		else
 			prefixlen =
 			    prefixlen_classful(prefix.v4.s_addr);
 		break;
 	case AF_INET6:
+		prefix.aid = AID_INET6;
 		memcpy(&prefix.v6, &((struct sockaddr_in6 *)sa)->sin6_addr,
 		    sizeof(struct in6_addr));
 		sa_in6 = (struct sockaddr_in6 *)rti_info[RTAX_NETMASK];
 		if (sa_in6 != NULL) {
 			if (sa_in6->sin6_len != 0)
 				prefixlen = mask2prefixlen6(sa_in6);
-		} else if (rtm->rtm_flags & RTF_HOST)
+		} else if (rtm->rtm_flags & RTF_HOST) {
 			prefixlen = 128;
+#if defined(__FreeBSD__)	/* RTF_HOST means connected route */
+			flags |= F_CONNECTED;
+#endif
+		}
 		else
 			fatalx("in6 net addr without netmask");
 		break;
@@ -2537,8 +2628,8 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 		}
 
 	if (rtm->rtm_type == RTM_DELETE) {
-		switch (prefix.af) {
-		case AF_INET:
+		switch (prefix.aid) {
+		case AID_INET:
 			sa_in = (struct sockaddr_in *)sa;
 			if ((kr = kroute_find(prefix.v4.s_addr,
 			    prefixlen, prio)) == NULL)
@@ -2557,7 +2648,7 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 			if (kroute_remove(kr) == -1)
 				return (-1);
 			break;
-		case AF_INET6:
+		case AID_INET6:
 			sa_in6 = (struct sockaddr_in6 *)sa;
 			if ((kr6 = kroute6_find(&prefix.v6, prefixlen,
 			    prio)) == NULL)
@@ -2590,8 +2681,8 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 		return (0);
 	}
 
-	switch (prefix.af) {
-	case AF_INET:
+	switch (prefix.aid) {
+	case AID_INET:
 		sa_in = (struct sockaddr_in *)sa;
 		if ((kr = kroute_find(prefix.v4.s_addr, prefixlen,
 		    prio)) != NULL) {
@@ -2654,7 +2745,7 @@ add4:
 			kroute_insert(kr);
 		}
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		sa_in6 = (struct sockaddr_in6 *)sa;
 		if ((kr6 = kroute6_find(&prefix.v6, prefixlen, prio)) != NULL) {
 			if (kr6->r.flags & F_KERNEL) {
