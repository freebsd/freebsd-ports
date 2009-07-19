Index: bgpd/kroute.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/kroute.c,v
retrieving revision 1.1.1.1
retrieving revision 1.4
diff -u -p -r1.1.1.1 -r1.4
--- bgpd/kroute.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/kroute.c	9 Jul 2009 17:35:40 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: kroute.c,v 1.160 2008/05/09 12:45:25 henning Exp $ */
+/*	$OpenBSD: kroute.c,v 1.169 2009/06/25 15:54:22 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -48,11 +48,13 @@ struct {
 struct kroute_node {
 	RB_ENTRY(kroute_node)	 entry;
 	struct kroute		 r;
+	struct kroute_node	*next;
 };
 
 struct kroute6_node {
 	RB_ENTRY(kroute6_node)	 entry;
 	struct kroute6		 r;
+	struct kroute6_node	*next;
 };
 
 struct knexthop_node {
@@ -88,12 +90,17 @@ int	kroute6_compare(struct kroute6_node 
 int	knexthop_compare(struct knexthop_node *, struct knexthop_node *);
 int	kif_compare(struct kif_node *, struct kif_node *);
 
-struct kroute_node	*kroute_find(in_addr_t, u_int8_t);
+struct kroute_node	*kroute_find(in_addr_t, u_int8_t, u_int8_t);
+struct kroute_node	*kroute_matchgw(struct kroute_node *,
+			    struct sockaddr_in *);
 int			 kroute_insert(struct kroute_node *);
 int			 kroute_remove(struct kroute_node *);
 void			 kroute_clear(void);
 
-struct kroute6_node	*kroute6_find(const struct in6_addr *, u_int8_t);
+struct kroute6_node	*kroute6_find(const struct in6_addr *, u_int8_t,
+			     u_int8_t);
+struct kroute6_node	*kroute6_matchgw(struct kroute6_node *,
+			    struct sockaddr_in6 *);
 int			 kroute6_insert(struct kroute6_node *);
 int			 kroute6_remove(struct kroute6_node *);
 void			 kroute6_clear(void);
@@ -118,6 +125,7 @@ int			 kif_validate(struct kif *);
 int			 kroute_validate(struct kroute *);
 int			 kroute6_validate(struct kroute6 *);
 void			 knexthop_validate(struct knexthop_node *);
+void			 knexthop_track(void *);
 struct kroute_node	*kroute_match(in_addr_t, int);
 struct kroute6_node	*kroute6_match(struct in6_addr *, int);
 void			 kroute_detach_nexthop(struct knexthop_node *);
@@ -164,8 +172,8 @@ kr_init(int fs, u_int rtableid)
 	int		opt = 0, rcvbuf, default_rcvbuf;
 	socklen_t	optlen;
 
-	kr_state.fib_sync = fs;
 	kr_state.rtableid = rtableid;
+	kr_state.fib_sync = fs;
 
 	if ((kr_state.fd = socket(AF_ROUTE, SOCK_RAW, 0)) == -1) {
 		log_warn("kr_init: socket");
@@ -219,13 +227,9 @@ kr_change(struct kroute_label *kl)
 	struct kroute_node	*kr;
 	int			 action = RTM_ADD;
 
-	if ((kr = kroute_find(kl->kr.prefix.s_addr, kl->kr.prefixlen)) !=
-	    NULL) {
-		if (kr->r.flags & F_BGPD_INSERTED)
-			action = RTM_CHANGE;
-		else	/* a non-bgp route already exists. not a problem */
-			return (0);
-	}
+	if ((kr = kroute_find(kl->kr.prefix.s_addr, kl->kr.prefixlen, RTP_BGP))
+	    != NULL)
+		action = RTM_CHANGE;
 
 	/* nexthop within 127/8 -> ignore silently */
 	if ((kl->kr.nexthop.s_addr & htonl(IN_CLASSA_NET)) ==
@@ -252,6 +256,7 @@ kr_change(struct kroute_label *kl)
 		kr->r.prefixlen = kl->kr.prefixlen;
 		kr->r.nexthop.s_addr = kl->kr.nexthop.s_addr;
 		kr->r.flags = kl->kr.flags | F_BGPD_INSERTED;
+		kr->r.priority = RTP_BGP;
 		kr->r.labelid = kl->kr.labelid;
 
 		if (kroute_insert(kr) == -1)
@@ -277,8 +282,8 @@ kr_delete(struct kroute_label *kl)
 {
 	struct kroute_node	*kr;
 
-	if ((kr = kroute_find(kl->kr.prefix.s_addr, kl->kr.prefixlen)) ==
-	    NULL)
+	if ((kr = kroute_find(kl->kr.prefix.s_addr, kl->kr.prefixlen, RTP_BGP))
+	    == NULL)
 		return (0);
 
 	if (!(kr->r.flags & F_BGPD_INSERTED))
@@ -307,12 +312,9 @@ kr6_change(struct kroute6_label *kl)
 	int			 action = RTM_ADD;
 	struct in6_addr		 lo6 = IN6ADDR_LOOPBACK_INIT;
 
-	if ((kr6 = kroute6_find(&kl->kr.prefix, kl->kr.prefixlen)) != NULL) {
-		if (kr6->r.flags & F_BGPD_INSERTED)
-			action = RTM_CHANGE;
-		else	/* a non-bgp route already exists. not a problem */
-			return (0);
-	}
+	if ((kr6 = kroute6_find(&kl->kr.prefix, kl->kr.prefixlen, RTP_BGP))
+	     != NULL)
+		action = RTM_CHANGE;
 
 	/* nexthop to loopback -> ignore silently */
 	if (IN6_IS_ADDR_LOOPBACK(&kl->kr.nexthop))
@@ -340,6 +342,7 @@ kr6_change(struct kroute6_label *kl)
 		memcpy(&kr6->r.nexthop, &kl->kr.nexthop,
 		    sizeof(struct in6_addr));
 		kr6->r.flags = kl->kr.flags | F_BGPD_INSERTED;
+		kr6->r.priority = RTP_BGP;
 		kr6->r.labelid = kl->kr.labelid;
 
 		if (kroute6_insert(kr6) == -1)
@@ -366,7 +369,8 @@ kr6_delete(struct kroute6_label *kl)
 {
 	struct kroute6_node	*kr6;
 
-	if ((kr6 = kroute6_find(&kl->kr.prefix, kl->kr.prefixlen)) == NULL)
+	if ((kr6 = kroute6_find(&kl->kr.prefix, kl->kr.prefixlen, RTP_BGP))
+	    == NULL)
 		return (0);
 
 	if (!(kr6->r.flags & F_BGPD_INSERTED))
@@ -509,8 +513,8 @@ kr_nexthop_delete(struct bgpd_addr *addr
 void
 kr_show_route(struct imsg *imsg)
 {
-	struct kroute_node	*kr;
-	struct kroute6_node	*kr6;
+	struct kroute_node	*kr, *kn;
+	struct kroute6_node	*kr6, *kn6;
 	struct bgpd_addr	*addr;
 	int			 flags;
 	sa_family_t		 af;
@@ -530,16 +534,26 @@ kr_show_route(struct imsg *imsg)
 		memcpy(&af, (char *)imsg->data + sizeof(flags), sizeof(af));
 		if (!af || af == AF_INET)
 			RB_FOREACH(kr, kroute_tree, &krt)
-				if (!flags || kr->r.flags & flags)
-					send_imsg_session(IMSG_CTL_KROUTE,
-					    imsg->hdr.pid, &kr->r,
-					    sizeof(kr->r));
+				if (!flags || kr->r.flags & flags) {
+					kn = kr;
+					do {
+						send_imsg_session(
+						    IMSG_CTL_KROUTE,
+						    imsg->hdr.pid, &kn->r,
+						    sizeof(kn->r));
+					} while ((kn = kn->next) != NULL);
+				}
 		if (!af || af == AF_INET6)
 			RB_FOREACH(kr6, kroute6_tree, &krt6)
-				if (!flags || kr6->r.flags & flags)
-					send_imsg_session(IMSG_CTL_KROUTE6,
-					    imsg->hdr.pid, &kr6->r,
-					    sizeof(kr6->r));
+				if (!flags || kr6->r.flags & flags) {
+					kn6 = kr6;
+					do {
+						send_imsg_session(
+						    IMSG_CTL_KROUTE6,
+						    imsg->hdr.pid, &kn6->r,
+						    sizeof(kn6->r));
+					} while ((kn6 = kn6->next) != NULL);
+				}
 		break;
 	case IMSG_CTL_KROUTE_ADDR:
 		if (imsg->hdr.len != IMSG_HEADER_SIZE +
@@ -791,6 +805,14 @@ kroute_compare(struct kroute_node *a, st
 		return (-1);
 	if (a->r.prefixlen > b->r.prefixlen)
 		return (1);
+
+	/* if the priority is RTP_ANY finish on the first address hit */
+	if (a->r.priority == RTP_ANY || b->r.priority == RTP_ANY)
+		return (0);
+	if (a->r.priority < b->r.priority)
+		return (-1);
+	if (a->r.priority > b->r.priority)
+		return (1);
 	return (0);
 }
 
@@ -810,6 +832,14 @@ kroute6_compare(struct kroute6_node *a, 
 		return (-1);
 	if (a->r.prefixlen > b->r.prefixlen)
 		return (1);
+
+	/* if the priority is RTP_ANY finish on the first address hit */
+	if (a->r.priority == RTP_ANY || b->r.priority == RTP_ANY)
+		return (0);
+	if (a->r.priority < b->r.priority)
+		return (-1);
+	if (a->r.priority > b->r.priority)
+		return (1);
 	return (0);
 }
 
@@ -853,27 +883,62 @@ kif_compare(struct kif_node *a, struct k
  */
 
 struct kroute_node *
-kroute_find(in_addr_t prefix, u_int8_t prefixlen)
+kroute_find(in_addr_t prefix, u_int8_t prefixlen, u_int8_t prio)
 {
 	struct kroute_node	s;
+	struct kroute_node	*kn, *tmp;
 
 	s.r.prefix.s_addr = prefix;
 	s.r.prefixlen = prefixlen;
+	s.r.priority = prio;
+
+	kn = RB_FIND(kroute_tree, &krt, &s);
+	if (kn && prio == RTP_ANY) {
+		tmp = RB_PREV(kroute_tree, &krt, kn);
+		while (tmp) {
+			if (kroute_compare(&s, tmp) == 0)
+				kn = tmp;
+			else
+				break;
+			tmp = RB_PREV(kroute_tree, &krt, kn);
+		}
+	}
+	return (kn);
+}
+
+struct kroute_node *
+kroute_matchgw(struct kroute_node *kr, struct sockaddr_in *sa_in)
+{
+	in_addr_t	nexthop;
 
-	return (RB_FIND(kroute_tree, &krt, &s));
+	if (sa_in == NULL) {
+		log_warnx("kroute_matchgw: no nexthop defined");
+		return (NULL);
+	}
+	nexthop = sa_in->sin_addr.s_addr;
+
+	while (kr) {
+		if (kr->r.nexthop.s_addr == nexthop)
+			return (kr);
+		kr = kr->next;
+	}
+
+	return (NULL);
 }
 
 int
 kroute_insert(struct kroute_node *kr)
 {
+	struct kroute_node	*krm;
 	struct knexthop_node	*h;
 	in_addr_t		 mask, ina;
 
-	if (RB_INSERT(kroute_tree, &krt, kr) != NULL) {
-		log_warnx("kroute_tree insert failed for %s/%u",
-		    inet_ntoa(kr->r.prefix), kr->r.prefixlen);
-		free(kr);
-		return (-1);
+	if ((krm = RB_INSERT(kroute_tree, &krt, kr)) != NULL) {
+		/* multipath route, add at end of list */
+		while (krm->next != NULL)
+			krm = krm->next;
+		krm->next = kr;
+		kr->next = NULL; /* to be sure */
 	}
 
 	if (kr->r.flags & F_KERNEL) {
@@ -888,29 +953,61 @@ kroute_insert(struct kroute_node *kr)
 			if (kif_kr_insert(kr) == -1)
 				return (-1);
 
-		kr_redistribute(IMSG_NETWORK_ADD, &kr->r);
+		if (krm == NULL)
+			/* redistribute multipath routes only once */
+			kr_redistribute(IMSG_NETWORK_ADD, &kr->r);
 	}
 	return (0);
 }
 
+
 int
 kroute_remove(struct kroute_node *kr)
 {
+	struct kroute_node	*krm;
 	struct knexthop_node	*s;
 
-	if (RB_REMOVE(kroute_tree, &krt, kr) == NULL) {
-		log_warnx("kroute_remove failed for %s/%u",
+	if ((krm = RB_FIND(kroute_tree, &krt, kr)) == NULL) {
+		log_warnx("kroute_remove failed to find %s/%u",
 		    inet_ntoa(kr->r.prefix), kr->r.prefixlen);
 		return (-1);
 	}
 
+	if (krm == kr) {
+		/* head element */
+		if (RB_REMOVE(kroute_tree, &krt, kr) == NULL) {
+			log_warnx("kroute_remove failed for %s/%u",
+			    inet_ntoa(kr->r.prefix), kr->r.prefixlen);
+			return (-1);
+		}
+	       	if (kr->next != NULL) {
+			if (RB_INSERT(kroute_tree, &krt, kr->next) != NULL) {
+				log_warnx("kroute_remove failed to add %s/%u",
+				    inet_ntoa(kr->r.prefix), kr->r.prefixlen);
+				return (-1);
+			}
+		}
+	} else {
+		/* somewhere in the list */
+		while (krm->next != kr && krm->next != NULL)
+			krm = krm->next;
+		if (krm->next == NULL) {
+			log_warnx("kroute_remove multipath list corrupted "
+			    "for %s/%u", inet_ntoa(kr->r.prefix),
+			    kr->r.prefixlen);
+			return (-1);
+		}
+		krm->next = kr->next;
+	}
+
 	/* check whether a nexthop depends on this kroute */
 	if ((kr->r.flags & F_KERNEL) && (kr->r.flags & F_NEXTHOP))
 		RB_FOREACH(s, knexthop_tree, &knt)
 			if (s->kroute == kr)
 				knexthop_validate(s);
 
-	if (kr->r.flags & F_KERNEL)
+	if (kr->r.flags & F_KERNEL && kr == krm && kr->next == NULL)
+		/* again remove only once */
 		kr_redistribute(IMSG_NETWORK_REMOVE, &kr->r);
 
 	if (kr->r.flags & F_CONNECTED)
@@ -933,27 +1030,62 @@ kroute_clear(void)
 }
 
 struct kroute6_node *
-kroute6_find(const struct in6_addr *prefix, u_int8_t prefixlen)
+kroute6_find(const struct in6_addr *prefix, u_int8_t prefixlen, u_int8_t prio)
 {
 	struct kroute6_node	s;
+	struct kroute6_node	*kn6, *tmp;
 
 	memcpy(&s.r.prefix, prefix, sizeof(struct in6_addr));
 	s.r.prefixlen = prefixlen;
+	s.r.priority = prio;
+
+	kn6 = RB_FIND(kroute6_tree, &krt6, &s);
+	if (kn6 && prio == RTP_ANY) {
+		tmp = RB_PREV(kroute6_tree, &krt6, kn6);
+		while (tmp) {
+			if (kroute6_compare(&s, tmp) == 0)
+				kn6 = tmp;
+			else 
+				break;
+			tmp = RB_PREV(kroute6_tree, &krt6, kn6);
+		}
+	}
+	return (kn6);
+}
+
+struct kroute6_node *
+kroute6_matchgw(struct kroute6_node *kr, struct sockaddr_in6 *sa_in6)
+{
+	struct in6_addr	nexthop;
+
+	if (sa_in6 == NULL) {
+		log_warnx("kroute6_matchgw: no nexthop defined");
+		return (NULL);
+	}
+	memcpy(&nexthop, &sa_in6->sin6_addr, sizeof(nexthop));
+
+	while (kr) {
+		if (memcmp(&kr->r.nexthop, &nexthop, sizeof(nexthop)) == 0)
+			return (kr);
+		kr = kr->next;
+	}
 
-	return (RB_FIND(kroute6_tree, &krt6, &s));
+	return (NULL);
 }
 
 int
 kroute6_insert(struct kroute6_node *kr)
 {
+	struct kroute6_node	*krm;
 	struct knexthop_node	*h;
 	struct in6_addr		 ina, inb;
 
-	if (RB_INSERT(kroute6_tree, &krt6, kr) != NULL) {
-		log_warnx("kroute_tree insert failed for %s/%u",
-		    log_in6addr(&kr->r.prefix), kr->r.prefixlen);
-		free(kr);
-		return (-1);
+	if ((krm = RB_INSERT(kroute6_tree, &krt6, kr)) != NULL) {
+		/* multipath route, add at end of list */
+		while (krm->next != NULL)
+			krm = krm->next;
+		krm->next = kr;
+		kr->next = NULL; /* to be sure */
 	}
 
 	if (kr->r.flags & F_KERNEL) {
@@ -970,7 +1102,9 @@ kroute6_insert(struct kroute6_node *kr)
 			if (kif_kr6_insert(kr) == -1)
 				return (-1);
 
-		kr_redistribute6(IMSG_NETWORK_ADD, &kr->r);
+		if (krm == NULL)
+			/* redistribute multipath routes only once */
+			kr_redistribute6(IMSG_NETWORK_ADD, &kr->r);
 	}
 
 	return (0);
@@ -979,21 +1113,51 @@ kroute6_insert(struct kroute6_node *kr)
 int
 kroute6_remove(struct kroute6_node *kr)
 {
+	struct kroute6_node	*krm;
 	struct knexthop_node	*s;
 
-	if (RB_REMOVE(kroute6_tree, &krt6, kr) == NULL) {
-		log_warnx("kroute_remove failed for %s/%u",
+	if ((krm = RB_FIND(kroute6_tree, &krt6, kr)) == NULL) {
+		log_warnx("kroute6_remove failed for %s/%u",
 		    log_in6addr(&kr->r.prefix), kr->r.prefixlen);
 		return (-1);
 	}
 
+	if (krm == kr) {
+		/* head element */
+		if (RB_REMOVE(kroute6_tree, &krt6, kr) == NULL) {
+			log_warnx("kroute6_remove failed for %s/%u",
+			    log_in6addr(&kr->r.prefix), kr->r.prefixlen);
+			return (-1);
+		}
+	       	if (kr->next != NULL) {
+			if (RB_INSERT(kroute6_tree, &krt6, kr->next) != NULL) {
+				log_warnx("kroute6_remove failed to add %s/%u",
+				    log_in6addr(&kr->r.prefix),
+				    kr->r.prefixlen);
+				return (-1);
+			}
+		}
+	} else {
+		/* somewhere in the list */
+		while (krm->next != kr && krm->next != NULL)
+			krm = krm->next;
+		if (krm->next == NULL) {
+			log_warnx("kroute6_remove multipath list corrupted "
+			    "for %s/%u", log_in6addr(&kr->r.prefix),
+			    kr->r.prefixlen);
+			return (-1);
+		}
+		krm->next = kr->next;
+	}
+
 	/* check whether a nexthop depends on this kroute */
 	if ((kr->r.flags & F_KERNEL) && (kr->r.flags & F_NEXTHOP))
 		RB_FOREACH(s, knexthop_tree, &knt)
 			if (s->kroute == kr)
 				knexthop_validate(s);
 
-	if (kr->r.flags & F_KERNEL)
+	if (kr->r.flags & F_KERNEL && kr == krm && kr->next == NULL)
+		/* again remove only once */
 		kr_redistribute6(IMSG_NETWORK_REMOVE, &kr->r);
 
 	if (kr->r.flags & F_CONNECTED)
@@ -1374,6 +1538,46 @@ knexthop_validate(struct knexthop_node *
 	}
 }
 
+void
+knexthop_track(void *krn)
+{
+	struct knexthop_node	*kn;
+	struct kroute_node	*kr;
+	struct kroute6_node	*kr6;
+	struct kroute_nexthop	 n;
+
+	RB_FOREACH(kn, knexthop_tree, &knt)
+		if (kn->kroute == krn) {
+			bzero(&n, sizeof(n));
+			memcpy(&n.nexthop, &kn->nexthop, sizeof(n.nexthop));
+
+			switch (kn->nexthop.af) {
+			case AF_INET:
+				kr = krn;
+				n.valid = 1;
+				n.connected = kr->r.flags & F_CONNECTED;
+				if ((n.gateway.v4.s_addr =
+				    kr->r.nexthop.s_addr) != 0)
+					n.gateway.af = AF_INET;
+				memcpy(&n.kr.kr4, &kr->r, sizeof(n.kr.kr4));
+				break;
+			case AF_INET6:
+				kr6 = krn;
+				n.valid = 1;
+				n.connected = kr6->r.flags & F_CONNECTED;
+				if (memcmp(&kr6->r.nexthop, &in6addr_any,
+				    sizeof(struct in6_addr)) != 0) {
+					n.gateway.af = AF_INET6;
+					memcpy(&n.gateway.v6, &kr6->r.nexthop,
+					    sizeof(struct in6_addr));
+				}
+				memcpy(&n.kr.kr6, &kr6->r, sizeof(n.kr.kr6));
+				break;
+			}
+			send_nexthop_update(&n);
+		}
+}
+
 struct kroute_node *
 kroute_match(in_addr_t key, int matchall)
 {
@@ -1385,13 +1589,13 @@ kroute_match(in_addr_t key, int matchall
 
 	/* we will never match the default route */
 	for (i = 32; i > 0; i--)
-		if ((kr =
-		    kroute_find(htonl(ina & prefixlen2mask(i)), i)) != NULL)
+		if ((kr = kroute_find(htonl(ina & prefixlen2mask(i)), i,
+		    RTP_ANY)) != NULL)
 			if (matchall || bgpd_filternexthop(&kr->r, NULL) == 0)
 			    return (kr);
 
 	/* if we don't have a match yet, try to find a default route */
-	if ((kr = kroute_find(0, 0)) != NULL)
+	if ((kr = kroute_find(0, 0, RTP_ANY)) != NULL)
 		if (matchall || bgpd_filternexthop(&kr->r, NULL) == 0)
 			return (kr);
 
@@ -1408,13 +1612,13 @@ kroute6_match(struct in6_addr *key, int 
 	/* we will never match the default route */
 	for (i = 128; i > 0; i--) {
 		inet6applymask(&ina, key, i);
-		if ((kr6 = kroute6_find(&ina, i)) != NULL)
+		if ((kr6 = kroute6_find(&ina, i, RTP_ANY)) != NULL)
 			if (matchall || bgpd_filternexthop(NULL, &kr6->r) == 0)
 				return (kr6);
 	}
 
 	/* if we don't have a match yet, try to find a default route */
-	if ((kr6 = kroute6_find(&in6addr_any, 0)) != NULL)
+	if ((kr6 = kroute6_find(&in6addr_any, 0, RTP_ANY)) != NULL)
 		if (matchall || bgpd_filternexthop(NULL, &kr6->r) == 0)
 			return (kr6);
 
@@ -1456,7 +1660,6 @@ kroute_detach_nexthop(struct knexthop_no
 	kn->kroute = NULL;
 }
 
-
 /*
  * misc helpers
  */
@@ -1568,15 +1771,6 @@ mask2prefixlen6(struct sockaddr_in6 *sa_
 	return (l);
 }
 
-in_addr_t
-prefixlen2mask(u_int8_t prefixlen)
-{
-	if (prefixlen == 0)
-		return (0);
-
-	return (0xffffffff << (32 - prefixlen));
-}
-
 struct in6_addr *
 prefixlen2mask6(u_int8_t prefixlen)
 {
@@ -1593,25 +1787,8 @@ prefixlen2mask6(u_int8_t prefixlen)
 	return (&mask);
 }
 
-void
-inet6applymask(struct in6_addr *dest, const struct in6_addr *src, int prefixlen)
-{
-	struct in6_addr	mask;
-	int		i;
-
-	bzero(&mask, sizeof(mask));
-	for (i = 0; i < prefixlen / 8; i++)
-		mask.s6_addr[i] = 0xff;
-	i = prefixlen % 8;
-	if (i)
-		mask.s6_addr[prefixlen / 8] = 0xff00 >> i;
-
-	for (i = 0; i < 16; i++)
-		dest->s6_addr[i] = src->s6_addr[i] & mask.s6_addr[i];
-}
-
-#define	ROUNDUP(a, size)	\
-    (((a) & ((size) - 1)) ? (1 + ((a) | ((size) - 1))) : (a))
+#define	ROUNDUP(a)	\
+    (((a) & ((sizeof(long)) - 1)) ? (1 + ((a) | ((sizeof(long)) - 1))) : (a))
 
 void
 get_rtaddrs(int addrs, struct sockaddr *sa, struct sockaddr **rti_info)
@@ -1622,7 +1799,7 @@ get_rtaddrs(int addrs, struct sockaddr *
 		if (addrs & (1 << i)) {
 			rti_info[i] = sa;
 			sa = (struct sockaddr *)((char *)(sa) +
-			    ROUNDUP(sa->sa_len, sizeof(long)));
+			    ROUNDUP(sa->sa_len));
 		} else
 			rti_info[i] = NULL;
 	}
@@ -1747,7 +1924,9 @@ send_rtmsg(int fd, int action, struct kr
 	struct sockaddr_in	prefix;
 	struct sockaddr_in	nexthop;
 	struct sockaddr_in	mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
@@ -1757,9 +1936,13 @@ send_rtmsg(int fd, int action, struct kr
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */
 	hdr.rtm_tableid = kr_state.rtableid;
+#endif /* !defined(__FreeBSD__) */
 	hdr.rtm_flags = RTF_PROTO1;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no rtm_priority */
 	hdr.rtm_priority = RTP_BGP;
+#endif /* !defined(__FreeBSD__) */
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
 	if (kroute->flags & F_REJECT)
@@ -1809,6 +1992,7 @@ send_rtmsg(int fd, int action, struct kr
 	iov[iovcnt++].iov_len = sizeof(mask);
 
 	if (kroute->labelid) {
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
 		strlcpy(label.sr_label, rtlabel_id2name(kroute->labelid),
@@ -1819,6 +2003,7 @@ send_rtmsg(int fd, int action, struct kr
 		/* adjust iovec */
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
+#endif /* !defined(__FreeBSD__) */
 	}
 
 retry:
@@ -1857,10 +2042,13 @@ send_rt6msg(int fd, int action, struct k
 {
 	struct iovec		iov[5];
 	struct rt_msghdr	hdr;
-	struct sockaddr_in6	prefix;
-	struct sockaddr_in6	nexthop;
-	struct sockaddr_in6	mask;
+	struct pad {
+		struct sockaddr_in6	addr;
+		char			pad[sizeof(long)];
+	} prefix, nexthop, mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
@@ -1870,7 +2058,9 @@ send_rt6msg(int fd, int action, struct k
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 	hdr.rtm_tableid = kr_state.rtableid;
+#endif /* !defined(__FreeBSD__) */
 	hdr.rtm_flags = RTF_PROTO1;
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
@@ -1885,44 +2075,46 @@ send_rt6msg(int fd, int action, struct k
 	iov[iovcnt++].iov_len = sizeof(hdr);
 
 	bzero(&prefix, sizeof(prefix));
-	prefix.sin6_len = sizeof(prefix);
-	prefix.sin6_family = AF_INET6;
-	memcpy(&prefix.sin6_addr, &kroute->prefix, sizeof(struct in6_addr));
+	prefix.addr.sin6_len = sizeof(struct sockaddr_in6);
+	prefix.addr.sin6_family = AF_INET6;
+	memcpy(&prefix.addr.sin6_addr, &kroute->prefix,
+	    sizeof(struct in6_addr));
 	/* XXX scope does not matter or? */
 	/* adjust header */
 	hdr.rtm_addrs |= RTA_DST;
-	hdr.rtm_msglen += sizeof(prefix);
+	hdr.rtm_msglen += ROUNDUP(sizeof(struct sockaddr_in6));
 	/* adjust iovec */
 	iov[iovcnt].iov_base = &prefix;
-	iov[iovcnt++].iov_len = sizeof(prefix);
+	iov[iovcnt++].iov_len = ROUNDUP(sizeof(struct sockaddr_in6));
 
 	if (memcmp(&kroute->nexthop, &in6addr_any, sizeof(struct in6_addr))) {
 		bzero(&nexthop, sizeof(nexthop));
-		nexthop.sin6_len = sizeof(nexthop);
-		nexthop.sin6_family = AF_INET6;
-		memcpy(&nexthop.sin6_addr, &kroute->nexthop,
+		nexthop.addr.sin6_len = sizeof(struct sockaddr_in6);
+		nexthop.addr.sin6_family = AF_INET6;
+		memcpy(&nexthop.addr.sin6_addr, &kroute->nexthop,
 		    sizeof(struct in6_addr));
 		/* adjust header */
 		hdr.rtm_flags |= RTF_GATEWAY;
 		hdr.rtm_addrs |= RTA_GATEWAY;
-		hdr.rtm_msglen += sizeof(nexthop);
+		hdr.rtm_msglen += ROUNDUP(sizeof(struct sockaddr_in6));
 		/* adjust iovec */
 		iov[iovcnt].iov_base = &nexthop;
-		iov[iovcnt++].iov_len = sizeof(nexthop);
+		iov[iovcnt++].iov_len = ROUNDUP(sizeof(struct sockaddr_in6));
 	}
 
 	bzero(&mask, sizeof(mask));
-	mask.sin6_len = sizeof(mask);
-	mask.sin6_family = AF_INET6;
-	memcpy(&mask.sin6_addr, prefixlen2mask6(kroute->prefixlen),
+	mask.addr.sin6_len = sizeof(struct sockaddr_in6);
+	mask.addr.sin6_family = AF_INET6;
+	memcpy(&mask.addr.sin6_addr, prefixlen2mask6(kroute->prefixlen),
 	    sizeof(struct in6_addr));
 	/* adjust header */
 	hdr.rtm_addrs |= RTA_NETMASK;
-	hdr.rtm_msglen += sizeof(mask);
+	hdr.rtm_msglen += ROUNDUP(sizeof(struct sockaddr_in6));
 	/* adjust iovec */
 	iov[iovcnt].iov_base = &mask;
-	iov[iovcnt++].iov_len = sizeof(mask);
+	iov[iovcnt++].iov_len = ROUNDUP(sizeof(struct sockaddr_in6));
 
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	if (kroute->labelid) {
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
@@ -1935,6 +2127,7 @@ send_rt6msg(int fd, int action, struct k
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
 	}
+#endif /* !defined(__FreeBSD__) */
 
 retry:
 	if (writev(fd, iov, iovcnt) == -1) {
@@ -1949,7 +2142,7 @@ retry:
 				    kroute->prefixlen);
 				return (0);
 			} else {
-				log_warnx("send_rtmsg: action %u, "
+				log_warnx("send_rt6msg: action %u, "
 				    "prefix %s/%u: %s", hdr.rtm_type,
 				    log_in6addr(&kroute->prefix),
 				    kroute->prefixlen, strerror(errno));
@@ -1957,7 +2150,7 @@ retry:
 			}
 			break;
 		default:
-			log_warnx("send_rtmsg: action %u, prefix %s/%u: %s",
+			log_warnx("send_rt6msg: action %u, prefix %s/%u: %s",
 			    hdr.rtm_type, log_in6addr(&kroute->prefix),
 			    kroute->prefixlen, strerror(errno));
 			return (0);
@@ -1970,8 +2163,8 @@ retry:
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
@@ -1986,9 +2179,8 @@ fetchtable(u_int rtableid, int connected
 	mib[3] = 0;
 	mib[4] = NET_RT_DUMP;
 	mib[5] = 0;
-	mib[6] = rtableid;
 
-	if (sysctl(mib, 7, NULL, &len, NULL, 0) == -1) {
+	if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) {
 		if (rtableid != 0 && errno == EINVAL)	/* table nonexistent */
 			return (0);
 		log_warn("sysctl");
@@ -1998,7 +2190,7 @@ fetchtable(u_int rtableid, int connected
 		log_warn("fetchtable");
 		return (-1);
 	}
-	if (sysctl(mib, 7, buf, &len, NULL, 0) == -1) {
+	if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
 		log_warn("sysctl");
 		free(buf);
 		return (-1);
@@ -2007,7 +2199,13 @@ fetchtable(u_int rtableid, int connected
 	lim = buf + len;
 	for (next = buf; next < lim; next += rtm->rtm_msglen) {
 		rtm = (struct rt_msghdr *)next;
-		sa = (struct sockaddr *)(rtm + 1);
+		if (rtm->rtm_version != RTM_VERSION)
+			continue;
+#if !defined(__FreeBSD__)	/* no rtm_hdrlen on FreeBSD */
+		sa = (struct sockaddr *)(next + rtm->rtm_hdrlen);
+#else
+		sa = (struct sockaddr *)(next + sizeof(struct rt_msghdr));
+#endif
 		get_rtaddrs(rtm->rtm_addrs, sa, rti_info);
 
 		if ((sa = rti_info[RTAX_DST]) == NULL)
@@ -2016,10 +2214,6 @@ fetchtable(u_int rtableid, int connected
 		if (rtm->rtm_flags & RTF_LLINFO)	/* arp cache */
 			continue;
 
-#ifdef RTF_MPATH
-		if (rtm->rtm_flags & RTF_MPATH)		/* multipath */
-			continue;
-#endif
 		switch (sa->sa_family) {
 		case AF_INET:
 			if ((kr = calloc(1, sizeof(struct kroute_node))) ==
@@ -2030,6 +2224,9 @@ fetchtable(u_int rtableid, int connected
 			}
 
 			kr->r.flags = F_KERNEL;
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
+			kr->r.priority = RTP_BGP;
+#endif
 			kr->r.ifindex = rtm->rtm_index;
 			kr->r.prefix.s_addr =
 			    ((struct sockaddr_in *)sa)->sin_addr.s_addr;
@@ -2062,6 +2259,9 @@ fetchtable(u_int rtableid, int connected
 			}
 
 			kr6->r.flags = F_KERNEL;
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
+			kr->r.priority = RTP_BGP;
+#endif
 			kr6->r.ifindex = rtm->rtm_index;
 			memcpy(&kr6->r.prefix,
 			    &((struct sockaddr_in6 *)sa)->sin6_addr,
@@ -2113,7 +2313,12 @@ fetchtable(u_int rtableid, int connected
 			}
 
 		if (sa->sa_family == AF_INET) {
-			if (rtm->rtm_flags & RTF_PROTO1)  {
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
+			if (rtm->rtm_priority == RTP_BGP)  {
+#else
+			/* never delete route */
+			if (0) {
+#endif
 				send_rtmsg(kr_state.fd, RTM_DELETE, &kr->r);
 				free(kr);
 			} else if (connected_only &&
@@ -2122,7 +2327,12 @@ fetchtable(u_int rtableid, int connected
 			else
 				kroute_insert(kr);
 		} else if (sa->sa_family == AF_INET6) {
-			if (rtm->rtm_flags & RTF_PROTO1)  {
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
+			if (rtm->rtm_priority == RTP_BGP)  {
+#else
+			/* never delete route */
+			if (0) {
+#endif
 				send_rt6msg(kr_state.fd, RTM_DELETE, &kr6->r);
 				free(kr6);
 			} else if (connected_only &&
@@ -2234,12 +2444,18 @@ dispatch_rtmsg(void)
 	lim = buf + n;
 	for (next = buf; next < lim; next += rtm->rtm_msglen) {
 		rtm = (struct rt_msghdr *)next;
+		if (rtm->rtm_version != RTM_VERSION)
+			continue;
 
 		switch (rtm->rtm_type) {
 		case RTM_ADD:
 		case RTM_CHANGE:
 		case RTM_DELETE:
-			sa = (struct sockaddr *)(rtm + 1);
+#if !defined(__FreeBSD__)	/* no rtm_hdrlen on FreeBSD */
+			sa = (struct sockaddr *)(next + rtm->rtm_hdrlen);
+#else
+			sa = (struct sockaddr *)(next + sizeof(struct rt_msghdr));
+#endif
 			get_rtaddrs(rtm->rtm_addrs, sa, rti_info);
 
 			if (rtm->rtm_pid == kr_state.pid) /* cause by us */
@@ -2252,12 +2468,14 @@ dispatch_rtmsg(void)
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
@@ -2289,9 +2507,10 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 	struct kroute_node	*kr;
 	struct kroute6_node	*kr6;
 	struct bgpd_addr	 prefix;
-	int			 flags, oflags;
+	int			 flags, oflags, mpath = 0;
 	u_int16_t		 ifindex;
 	u_int8_t		 prefixlen;
+	u_int8_t		 prio;
 
 	flags = F_KERNEL;
 	ifindex = 0;
@@ -2309,7 +2528,16 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 		flags |= F_REJECT;
 	if (rtm->rtm_flags & RTF_DYNAMIC)
 		flags |= F_DYNAMIC;
+#ifdef RTF_MPATH
+	if (rtm->rtm_flags & RTF_MPATH)
+		mpath = 1;
+#endif
 
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
+	prio = rtm->rtm_priority;
+#else
+	prio = RTP_BGP;
+#endif
 	prefix.af = sa->sa_family;
 	switch (prefix.af) {
 	case AF_INET:
@@ -2341,22 +2569,54 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 		return (0);
 	}
 
+	if ((sa = rti_info[RTAX_GATEWAY]) != NULL)
+		switch (sa->sa_family) {
+		case AF_LINK:
+			flags |= F_CONNECTED;
+			ifindex = rtm->rtm_index;
+			sa = NULL;
+			mpath = 0;	/* link local stuff can't be mpath */
+			break;
+		}
+
 	if (rtm->rtm_type == RTM_DELETE) {
 		switch (prefix.af) {
 		case AF_INET:
+			sa_in = (struct sockaddr_in *)sa;
 			if ((kr = kroute_find(prefix.v4.s_addr,
-			    prefixlen)) == NULL)
+			    prefixlen, prio)) == NULL)
 				return (0);
 			if (!(kr->r.flags & F_KERNEL))
 				return (0);
+
+			if (mpath)
+				/* get the correct route */
+				if ((kr = kroute_matchgw(kr, sa_in)) == NULL) {
+					log_warnx("dispatch_rtmsg[delete] "
+					    "mpath route not found");
+					return (0);
+				}
+
 			if (kroute_remove(kr) == -1)
 				return (-1);
 			break;
 		case AF_INET6:
-			if ((kr6 = kroute6_find(&prefix.v6, prefixlen)) == NULL)
+			sa_in6 = (struct sockaddr_in6 *)sa;
+			if ((kr6 = kroute6_find(&prefix.v6, prefixlen,
+			    prio)) == NULL)
 				return (0);
 			if (!(kr6->r.flags & F_KERNEL))
 				return (0);
+
+			if (mpath)
+				/* get the correct route */
+				if ((kr6 = kroute6_matchgw(kr6, sa_in6)) ==
+				    NULL) {
+					log_warnx("dispatch_rtmsg[delete] "
+					    "IPv6 mpath route not found");
+					return (0);
+				}
+
 			if (kroute6_remove(kr6) == -1)
 				return (-1);
 			break;
@@ -2364,15 +2624,6 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 		return (0);
 	}
 
-	if ((sa = rti_info[RTAX_GATEWAY]) != NULL)
-		switch (sa->sa_family) {
-		case AF_LINK:
-			flags |= F_CONNECTED;
-			ifindex = rtm->rtm_index;
-			sa = NULL;
-			break;
-		}
-
 	if (connected_only && !(flags & F_CONNECTED))
 		return (0);
 
@@ -2385,8 +2636,18 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 	switch (prefix.af) {
 	case AF_INET:
 		sa_in = (struct sockaddr_in *)sa;
-		if ((kr = kroute_find(prefix.v4.s_addr, prefixlen)) != NULL) {
+		if ((kr = kroute_find(prefix.v4.s_addr, prefixlen,
+		    prio)) != NULL) {
 			if (kr->r.flags & F_KERNEL) {
+				/* get the correct route */
+				if (mpath && rtm->rtm_type == RTM_CHANGE &&
+				    (kr = kroute_matchgw(kr, sa_in)) == NULL) {
+					log_warnx("dispatch_rtmsg[change] "
+					    "mpath route not found");
+					return (-1);
+				} else if (mpath && rtm->rtm_type == RTM_ADD)
+					goto add4;
+
 				if (sa_in != NULL)
 					kr->r.nexthop.s_addr =
 					    sa_in->sin_addr.s_addr;
@@ -2409,12 +2670,15 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 					kr_redistribute(IMSG_NETWORK_ADD,
 					    &kr->r);
 				}
+				if (kr->r.flags & F_NEXTHOP)
+					knexthop_track(kr);
 			}
 		} else if (rtm->rtm_type == RTM_CHANGE) {
 			log_warnx("change req for %s/%u: not in table",
 			    log_addr(&prefix), prefixlen);
 			return (0);
 		} else {
+add4:
 			if ((kr = calloc(1,
 			    sizeof(struct kroute_node))) == NULL) {
 				log_warn("dispatch_rtmsg");
@@ -2428,14 +2692,25 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 				kr->r.nexthop.s_addr = 0;
 			kr->r.flags = flags;
 			kr->r.ifindex = ifindex;
+			kr->r.priority = prio;
 
 			kroute_insert(kr);
 		}
 		break;
 	case AF_INET6:
 		sa_in6 = (struct sockaddr_in6 *)sa;
-		if ((kr6 = kroute6_find(&prefix.v6, prefixlen)) != NULL) {
+		if ((kr6 = kroute6_find(&prefix.v6, prefixlen, prio)) != NULL) {
 			if (kr6->r.flags & F_KERNEL) {
+				/* get the correct route */
+				if (mpath && rtm->rtm_type == RTM_CHANGE &&
+				    (kr6 = kroute6_matchgw(kr6, sa_in6)) ==
+				    NULL) {
+					log_warnx("dispatch_rtmsg[change] "
+					    "mpath route not found");
+					return (-1);
+				} else if (mpath && rtm->rtm_type == RTM_ADD)
+					goto add6;
+
 				if (sa_in6 != NULL)
 					memcpy(&kr6->r.nexthop,
 					    &sa_in6->sin6_addr,
@@ -2461,12 +2736,15 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 					kr_redistribute6(IMSG_NETWORK_ADD,
 					    &kr6->r);
 				}
+				if (kr6->r.flags & F_NEXTHOP)
+					knexthop_track(kr6);
 			}
 		} else if (rtm->rtm_type == RTM_CHANGE) {
 			log_warnx("change req for %s/%u: not in table",
 			    log_addr(&prefix), prefixlen);
 			return (0);
 		} else {
+add6:
 			if ((kr6 = calloc(1,
 			    sizeof(struct kroute6_node))) == NULL) {
 				log_warn("dispatch_rtmsg");
@@ -2483,6 +2761,7 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 				    sizeof(struct in6_addr));
 			kr6->r.flags = flags;
 			kr6->r.ifindex = ifindex;
+			kr6->r.priority = prio;
 
 			kroute6_insert(kr6);
 		}
