Index: bgpd/kroute.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/kroute.c,v
retrieving revision 1.1.1.7
retrieving revision 1.15
diff -u -p -r1.1.1.7 -r1.15
--- bgpd/kroute.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/kroute.c	16 May 2014 00:36:26 -0000	1.15
@@ -1,4 +1,4 @@
-/*	$OpenBSD: kroute.c,v 1.169 2009/06/25 15:54:22 claudio Exp $ */
+/*	$OpenBSD: kroute.c,v 1.190 2012/07/13 16:57:35 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -27,6 +27,9 @@
 #include <net/if.h>
 #include <net/if_dl.h>
 #include <net/route.h>
+#if !defined(__FreeBSD__) /* FreeBSD has no mpls support. */
+#include <netmpls/mpls.h>
+#endif
 #include <err.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -37,11 +40,12 @@
 
 #include "bgpd.h"
 
+struct ktable		**krt;
+u_int			  krt_size;
+
 struct {
 	u_int32_t		rtseq;
 	pid_t			pid;
-	u_int			rtableid;
-	int			fib_sync;
 	int			fd;
 } kr_state;
 
@@ -83,32 +87,52 @@ struct kif_node {
 	struct kif_kr6_head	 kroute6_l;
 };
 
-int	kr_redistribute(int, struct kroute *);
-int	kr_redistribute6(int, struct kroute6 *);
+int	ktable_new(u_int, u_int, char *, char *, int);
+void	ktable_free(u_int);
+void	ktable_destroy(struct ktable *);
+struct ktable	*ktable_get(u_int);
+
+int	kr4_change(struct ktable *, struct kroute_full *);
+int	kr6_change(struct ktable *, struct kroute_full *);
+int	krVPN4_change(struct ktable *, struct kroute_full *);
+int	kr4_delete(struct ktable *, struct kroute_full *);
+int	kr6_delete(struct ktable *, struct kroute_full *);
+int	krVPN4_delete(struct ktable *, struct kroute_full *);
+void	kr_net_delete(struct network *);
+struct network *kr_net_match(struct ktable *, struct kroute *);
+struct network *kr_net_match6(struct ktable *, struct kroute6 *);
+struct network *kr_net_find(struct ktable *, struct network *);
+int	kr_redistribute(int, struct ktable *, struct kroute *);
+int	kr_redistribute6(int, struct ktable *, struct kroute6 *);
+struct kroute_full *kr_tofull(struct kroute *);
+struct kroute_full *kr6_tofull(struct kroute6 *);
 int	kroute_compare(struct kroute_node *, struct kroute_node *);
 int	kroute6_compare(struct kroute6_node *, struct kroute6_node *);
 int	knexthop_compare(struct knexthop_node *, struct knexthop_node *);
 int	kif_compare(struct kif_node *, struct kif_node *);
 
-struct kroute_node	*kroute_find(in_addr_t, u_int8_t, u_int8_t);
+struct kroute_node	*kroute_find(struct ktable *, in_addr_t, u_int8_t,
+			    u_int8_t);
 struct kroute_node	*kroute_matchgw(struct kroute_node *,
 			    struct sockaddr_in *);
-int			 kroute_insert(struct kroute_node *);
-int			 kroute_remove(struct kroute_node *);
-void			 kroute_clear(void);
+int			 kroute_insert(struct ktable *, struct kroute_node *);
+int			 kroute_remove(struct ktable *, struct kroute_node *);
+void			 kroute_clear(struct ktable *);
 
-struct kroute6_node	*kroute6_find(const struct in6_addr *, u_int8_t,
-			     u_int8_t);
+struct kroute6_node	*kroute6_find(struct ktable *, const struct in6_addr *,
+			    u_int8_t, u_int8_t);
 struct kroute6_node	*kroute6_matchgw(struct kroute6_node *,
 			    struct sockaddr_in6 *);
-int			 kroute6_insert(struct kroute6_node *);
-int			 kroute6_remove(struct kroute6_node *);
-void			 kroute6_clear(void);
-
-struct knexthop_node	*knexthop_find(struct bgpd_addr *);
-int			 knexthop_insert(struct knexthop_node *);
-int			 knexthop_remove(struct knexthop_node *);
-void			 knexthop_clear(void);
+int			 kroute6_insert(struct ktable *, struct kroute6_node *);
+int			 kroute6_remove(struct ktable *, struct kroute6_node *);
+void			 kroute6_clear(struct ktable *);
+
+struct knexthop_node	*knexthop_find(struct ktable *, struct bgpd_addr *);
+int			 knexthop_insert(struct ktable *,
+			    struct knexthop_node *);
+int			 knexthop_remove(struct ktable *,
+			    struct knexthop_node *);
+void			 knexthop_clear(struct ktable *);
 
 struct kif_node		*kif_find(int);
 int			 kif_insert(struct kif_node *);
@@ -124,13 +148,16 @@ int			 kif_kr6_remove(struct kroute6_nod
 int			 kif_validate(struct kif *);
 int			 kroute_validate(struct kroute *);
 int			 kroute6_validate(struct kroute6 *);
-void			 knexthop_validate(struct knexthop_node *);
-void			 knexthop_track(void *);
-struct kroute_node	*kroute_match(in_addr_t, int);
-struct kroute6_node	*kroute6_match(struct in6_addr *, int);
-void			 kroute_detach_nexthop(struct knexthop_node *);
+void			 knexthop_validate(struct ktable *,
+			    struct knexthop_node *);
+void			 knexthop_track(struct ktable *, void *);
+void			 knexthop_send_update(struct knexthop_node *);
+struct kroute_node	*kroute_match(struct ktable *, in_addr_t, int);
+struct kroute6_node	*kroute6_match(struct ktable *, struct in6_addr *, int);
+void			 kroute_detach_nexthop(struct ktable *,
+			    struct knexthop_node *);
 
-int		protect_lo(void);
+int		protect_lo(struct ktable *);
 u_int8_t	prefixlen_classful(in_addr_t);
 u_int8_t	mask2prefixlen(in_addr_t);
 u_int8_t	mask2prefixlen6(struct sockaddr_in6 *);
@@ -138,23 +165,20 @@ void		get_rtaddrs(int, struct sockaddr *
 void		if_change(u_short, int, struct if_data *);
 void		if_announce(void *);
 
-int		send_rtmsg(int, int, struct kroute *);
-int		send_rt6msg(int, int, struct kroute6 *);
+int		send_rtmsg(int, int, struct ktable *, struct kroute *);
+int		send_rt6msg(int, int, struct ktable *, struct kroute6 *);
 int		dispatch_rtmsg(void);
-int		fetchtable(u_int, int);
+int		fetchtable(struct ktable *);
 int		fetchifs(int);
 int		dispatch_rtmsg_addr(struct rt_msghdr *,
-		    struct sockaddr *[RTAX_MAX], int);
+		    struct sockaddr *[RTAX_MAX], struct ktable *);
 
-RB_HEAD(kroute_tree, kroute_node)	krt;
 RB_PROTOTYPE(kroute_tree, kroute_node, entry, kroute_compare)
 RB_GENERATE(kroute_tree, kroute_node, entry, kroute_compare)
 
-RB_HEAD(kroute6_tree, kroute6_node)	krt6;
 RB_PROTOTYPE(kroute6_tree, kroute6_node, entry, kroute6_compare)
 RB_GENERATE(kroute6_tree, kroute6_node, entry, kroute6_compare)
 
-RB_HEAD(knexthop_tree, knexthop_node)	knt;
 RB_PROTOTYPE(knexthop_tree, knexthop_node, entry, knexthop_compare)
 RB_GENERATE(knexthop_tree, knexthop_node, entry, knexthop_compare)
 
@@ -162,19 +186,21 @@ RB_HEAD(kif_tree, kif_node)		kit;
 RB_PROTOTYPE(kif_tree, kif_node, entry, kif_compare)
 RB_GENERATE(kif_tree, kif_node, entry, kif_compare)
 
+#define KT2KNT(x)	(&(ktable_get((x)->nhtableid)->knt))
+
 /*
  * exported functions
  */
 
 int
-kr_init(int fs, u_int rtableid)
+kr_init(void)
 {
 	int		opt = 0, rcvbuf, default_rcvbuf;
+#if !defined(__FreeBSD__) /* FreeBSD does not have ROUTE_TABLEFILTER. */
+	unsigned int	tid = RTABLE_ANY;
+#endif
 	socklen_t	optlen;
 
-	kr_state.rtableid = rtableid;
-	kr_state.fib_sync = fs;
-
 	if ((kr_state.fd = socket(AF_ROUTE, SOCK_RAW, 0)) == -1) {
 		log_warn("kr_init: socket");
 		return (-1);
@@ -198,194 +224,533 @@ kr_init(int fs, u_int rtableid)
 		    rcvbuf /= 2)
 			;	/* nothing */
 
+#if !defined(__FreeBSD__) /* FreeBSD does not have ROUTE_TABLEFILTER. */
+	if (setsockopt(kr_state.fd, AF_ROUTE, ROUTE_TABLEFILTER, &tid,
+	    sizeof(tid)) == -1) {
+		log_warn("kr_init: setsockopt AF_ROUTE ROUTE_TABLEFILTER");
+		return (-1);
+	}
+#endif
+
 	kr_state.pid = getpid();
 	kr_state.rtseq = 1;
 
-	RB_INIT(&krt);
-	RB_INIT(&krt6);
-	RB_INIT(&knt);
 	RB_INIT(&kit);
 
 	if (fetchifs(0) == -1)
 		return (-1);
 
-	if (fetchtable(kr_state.rtableid, 0) == -1)
-		return (-1);
-	if (kr_state.rtableid != 0)
-		if (fetchtable(0, 1) == -1)
+	return (kr_state.fd);
+}
+
+int
+ktable_new(u_int rtableid, u_int rdomid, char *name, char *ifname, int fs)
+{
+	struct ktable	**xkrt;
+	struct ktable	 *kt;
+	size_t		  newsize, oldsize;
+
+	/* resize index table if needed */
+	if (rtableid >= krt_size) {
+		oldsize = sizeof(struct ktable *) * krt_size;
+		newsize = sizeof(struct ktable *) * (rtableid + 1);
+		if ((xkrt = realloc(krt, newsize)) == NULL) {
+			log_warn("ktable_new");
 			return (-1);
+		}
+		krt = xkrt;
+		krt_size = rtableid + 1;
+		bzero((char *)krt + oldsize, newsize - oldsize);
+	}
+
+	if (krt[rtableid])
+		fatalx("ktable_new: table already exists.");
 
-	if (protect_lo() == -1)
+	/* allocate new element */
+	kt = krt[rtableid] = calloc(1, sizeof(struct ktable));
+	if (kt == NULL) {
+		log_warn("ktable_new");
 		return (-1);
+	}
 
-	return (kr_state.fd);
+	/* initialize structure ... */
+	strlcpy(kt->descr, name, sizeof(kt->descr));
+	RB_INIT(&kt->krt);
+	RB_INIT(&kt->krt6);
+	RB_INIT(&kt->knt);
+	TAILQ_INIT(&kt->krn);
+	kt->fib_conf = kt->fib_sync = fs;
+	kt->rtableid = rtableid;
+	kt->nhtableid = rdomid;
+	/* bump refcount of rdomain table for the nexthop lookups */
+	ktable_get(kt->nhtableid)->nhrefcnt++;
+	if (ifname) {
+		strlcpy(kt->ifmpe, ifname, IFNAMSIZ);
+		kt->ifindex = if_nametoindex(ifname);
+	}
+
+	/* ... and load it */
+	if (fetchtable(kt) == -1)
+		return (-1);
+	if (protect_lo(kt) == -1)
+		return (-1);
+
+	/* everything is up and running */
+	kt->state = RECONF_REINIT;
+	log_debug("new ktable %s for rtableid %d", name, rtableid);
+	return (0);
+}
+
+void
+ktable_free(u_int rtableid)
+{
+	struct ktable	*kt, *nkt;
+
+	if ((kt = ktable_get(rtableid)) == NULL)
+		return;
+
+	/* decouple from kernel, no new routes will be entered from here */
+	kr_fib_decouple(kt->rtableid);
+
+	/* first unhook from the nexthop table */
+	nkt = ktable_get(kt->nhtableid);
+	nkt->nhrefcnt--;
+
+	/*
+	 * Evil little details:
+	 *   If kt->nhrefcnt > 0 then kt == nkt and nothing needs to be done.
+	 *   If kt != nkt then kt->nhrefcnt must be 0 and kt must be killed.
+	 *   If nkt is no longer referenced it must be killed (possible double
+	 *   free so check that kt != nkt).
+	 */
+	if (kt != nkt && nkt->nhrefcnt <= 0)
+		ktable_destroy(nkt);
+	if (kt->nhrefcnt <= 0)
+		ktable_destroy(kt);
+}
+
+void
+ktable_destroy(struct ktable *kt)
+{
+	/* decouple just to be sure, does not hurt */
+	kr_fib_decouple(kt->rtableid);
+
+	log_debug("freeing ktable %s rtableid %u", kt->descr, kt->rtableid);
+	knexthop_clear(kt);
+	kroute_clear(kt);
+	kroute6_clear(kt);
+
+	krt[kt->rtableid] = NULL;
+	free(kt);
+}
+
+struct ktable *
+ktable_get(u_int rtableid)
+{
+	if (rtableid >= krt_size)
+		return (NULL);
+	return (krt[rtableid]);
+}
+
+int
+ktable_update(u_int rtableid, char *name, char *ifname, int flags)
+{
+	struct ktable	*kt, *rkt;
+	u_int		 rdomid;
+
+	if (!ktable_exists(rtableid, &rdomid))
+		fatalx("King Bula lost a table");	/* may not happen */
+
+	if (rdomid != rtableid || flags & F_RIB_NOFIB) {
+		rkt = ktable_get(rdomid);
+		if (rkt == NULL) {
+			char buf[32];
+			snprintf(buf, sizeof(buf), "rdomain_%d", rdomid);
+			if (ktable_new(rdomid, rdomid, buf, NULL, 0))
+				return (-1);
+		} else {
+			/* there is no need for full fib synchronisation if
+			 * the table is only used for nexthop lookups.
+			 */
+			if (rkt->state == RECONF_DELETE) {
+				rkt->fib_conf = 0;
+				rkt->state = RECONF_KEEP;
+			}
+		}
+	}
+
+	if (flags & (F_RIB_NOEVALUATE | F_RIB_NOFIB))
+		/* only rdomain table must exist */
+		return (0);
+
+	kt = ktable_get(rtableid);
+	if (kt == NULL) {
+		if (ktable_new(rtableid, rdomid, name, ifname,
+		    !(flags & F_RIB_NOFIBSYNC)))
+			return (-1);
+	} else {
+		/* fib sync has higher preference then no sync */
+		if (kt->state == RECONF_DELETE) {
+			kt->fib_conf = !(flags & F_RIB_NOFIBSYNC);
+			kt->state = RECONF_KEEP;
+		} else if (!kt->fib_conf)
+			kt->fib_conf = !(flags & F_RIB_NOFIBSYNC);
+
+		strlcpy(kt->descr, name, sizeof(kt->descr));
+	}
+	return (0);
+}
+
+void
+ktable_preload(void)
+{
+	struct ktable 	*kt;
+	u_int		 i;
+
+	for (i = 0; i < krt_size; i++) {
+		if ((kt = ktable_get(i)) == NULL)
+			continue;
+		kt->state = RECONF_DELETE;
+	}
+}
+
+void
+ktable_postload(void)
+{
+	struct ktable 	*kt;
+	u_int		 i;
+
+	for (i = krt_size; i > 0; i--) {
+		if ((kt = ktable_get(i - 1)) == NULL)
+			continue;
+		if (kt->state == RECONF_DELETE)
+			ktable_free(i - 1);
+		else if (kt->state == RECONF_REINIT)
+			kt->fib_sync = kt->fib_conf;
+	}
+}
+
+int
+ktable_exists(u_int rtableid, u_int *rdomid)
+{
+#if !defined(__FreeBSD__) /* FreeBSD does not have NET_RT_TABLE. */
+	size_t			 len;
+	struct rt_tableinfo	 info;
+	int			 mib[6];
+
+	mib[0] = CTL_NET;
+	mib[1] = AF_ROUTE;
+	mib[2] = 0;
+	mib[3] = 0;
+	mib[4] = NET_RT_TABLE;
+	mib[5] = rtableid;
+
+	len = sizeof(info);
+	if (sysctl(mib, 6, &info, &len, NULL, 0) == -1) {
+		if (errno == ENOENT)
+			/* table nonexistent */
+			return (0);
+		log_warn("sysctl");
+		/* must return 0 so that the table is considered non-existent */
+		return (0);
+	}
+	if (rdomid)
+		*rdomid = info.rti_domainid;
+#else
+	*rdomid = 0;
+#endif
+	return (1);
 }
 
 int
-kr_change(struct kroute_label *kl)
+kr_change(u_int rtableid, struct kroute_full *kl)
+{
+	struct ktable		*kt;
+
+	if ((kt = ktable_get(rtableid)) == NULL)
+		/* too noisy during reloads, just ignore */
+		return (0);
+	switch (kl->prefix.aid) {
+	case AID_INET:
+		return (kr4_change(kt, kl));
+	case AID_INET6:
+		return (kr6_change(kt, kl));
+	case AID_VPN_IPv4:
+		return (krVPN4_change(kt, kl));
+	}
+	log_warnx("kr_change: not handled AID");
+	return (-1);
+}
+
+int
+kr4_change(struct ktable *kt, struct kroute_full *kl)
 {
 	struct kroute_node	*kr;
 	int			 action = RTM_ADD;
+	u_int16_t		 labelid;
 
-	if ((kr = kroute_find(kl->kr.prefix.s_addr, kl->kr.prefixlen, RTP_BGP))
-	    != NULL)
+	if ((kr = kroute_find(kt, kl->prefix.v4.s_addr, kl->prefixlen,
+	    RTP_BGP)) != NULL)
 		action = RTM_CHANGE;
 
 	/* nexthop within 127/8 -> ignore silently */
-	if ((kl->kr.nexthop.s_addr & htonl(IN_CLASSA_NET)) ==
+	if ((kl->nexthop.v4.s_addr & htonl(IN_CLASSA_NET)) ==
 	    htonl(INADDR_LOOPBACK & IN_CLASSA_NET))
 		return (0);
 
-	if (kr)
-		rtlabel_unref(kr->r.labelid);
-	kl->kr.labelid = rtlabel_name2id(kl->label);
+	labelid = rtlabel_name2id(kl->label);
 
 	/* for blackhole and reject routes nexthop needs to be 127.0.0.1 */
-	if (kl->kr.flags & (F_BLACKHOLE|F_REJECT))
-		kl->kr.nexthop.s_addr = htonl(INADDR_LOOPBACK);
-
-	if (send_rtmsg(kr_state.fd, action, &kl->kr) == -1)
-		return (-1);
+	if (kl->flags & (F_BLACKHOLE|F_REJECT))
+		kl->nexthop.v4.s_addr = htonl(INADDR_LOOPBACK);
 
 	if (action == RTM_ADD) {
 		if ((kr = calloc(1, sizeof(struct kroute_node))) == NULL) {
 			log_warn("kr_change");
 			return (-1);
 		}
-		kr->r.prefix.s_addr = kl->kr.prefix.s_addr;
-		kr->r.prefixlen = kl->kr.prefixlen;
-		kr->r.nexthop.s_addr = kl->kr.nexthop.s_addr;
-		kr->r.flags = kl->kr.flags | F_BGPD_INSERTED;
+		kr->r.prefix.s_addr = kl->prefix.v4.s_addr;
+		kr->r.prefixlen = kl->prefixlen;
+		kr->r.nexthop.s_addr = kl->nexthop.v4.s_addr;
+		kr->r.flags = kl->flags | F_BGPD_INSERTED;
 		kr->r.priority = RTP_BGP;
-		kr->r.labelid = kl->kr.labelid;
+		kr->r.labelid = labelid;
 
-		if (kroute_insert(kr) == -1)
+		if (kroute_insert(kt, kr) == -1)
 			free(kr);
 	} else {
-		kr->r.nexthop.s_addr = kl->kr.nexthop.s_addr;
-		kr->r.labelid = kl->kr.labelid;
-		if (kl->kr.flags & F_BLACKHOLE)
+		kr->r.nexthop.s_addr = kl->nexthop.v4.s_addr;
+		rtlabel_unref(kr->r.labelid);
+		kr->r.labelid = labelid;
+		if (kl->flags & F_BLACKHOLE)
 			kr->r.flags |= F_BLACKHOLE;
 		else
 			kr->r.flags &= ~F_BLACKHOLE;
-		if (kl->kr.flags & F_REJECT)
+		if (kl->flags & F_REJECT)
 			kr->r.flags |= F_REJECT;
 		else
 			kr->r.flags &= ~F_REJECT;
 	}
 
+	if (send_rtmsg(kr_state.fd, action, kt, &kr->r) == -1)
+		return (-1);
+
 	return (0);
 }
 
 int
-kr_delete(struct kroute_label *kl)
+kr6_change(struct ktable *kt, struct kroute_full *kl)
 {
-	struct kroute_node	*kr;
+	struct kroute6_node	*kr6;
+	struct in6_addr		 lo6 = IN6ADDR_LOOPBACK_INIT;
+	int			 action = RTM_ADD;
+	u_int16_t		 labelid;
 
-	if ((kr = kroute_find(kl->kr.prefix.s_addr, kl->kr.prefixlen, RTP_BGP))
-	    == NULL)
-		return (0);
+	if ((kr6 = kroute6_find(kt, &kl->prefix.v6, kl->prefixlen, RTP_BGP)) !=
+	    NULL)
+		action = RTM_CHANGE;
 
-	if (!(kr->r.flags & F_BGPD_INSERTED))
+	/* nexthop to loopback -> ignore silently */
+	if (IN6_IS_ADDR_LOOPBACK(&kl->nexthop.v6))
 		return (0);
 
-	/* nexthop within 127/8 -> ignore silently */
-	if ((kl->kr.nexthop.s_addr & htonl(IN_CLASSA_NET)) ==
-	    htonl(INADDR_LOOPBACK & IN_CLASSA_NET))
-		return (0);
+	labelid = rtlabel_name2id(kl->label);
 
-	if (send_rtmsg(kr_state.fd, RTM_DELETE, &kl->kr) == -1)
-		return (-1);
+	/* for blackhole and reject routes nexthop needs to be ::1 */
+	if (kl->flags & (F_BLACKHOLE|F_REJECT))
+		bcopy(&lo6, &kl->nexthop.v6, sizeof(kl->nexthop.v6));
 
-	rtlabel_unref(kl->kr.labelid);
+	if (action == RTM_ADD) {
+		if ((kr6 = calloc(1, sizeof(struct kroute6_node))) == NULL) {
+			log_warn("kr_change");
+			return (-1);
+		}
+		memcpy(&kr6->r.prefix, &kl->prefix.v6, sizeof(struct in6_addr));
+		kr6->r.prefixlen = kl->prefixlen;
+		memcpy(&kr6->r.nexthop, &kl->nexthop.v6,
+		    sizeof(struct in6_addr));
+		kr6->r.flags = kl->flags | F_BGPD_INSERTED;
+		kr6->r.priority = RTP_BGP;
+		kr6->r.labelid = labelid;
 
-	if (kroute_remove(kr) == -1)
+		if (kroute6_insert(kt, kr6) == -1)
+			free(kr6);
+	} else {
+		memcpy(&kr6->r.nexthop, &kl->nexthop.v6,
+		    sizeof(struct in6_addr));
+		rtlabel_unref(kr6->r.labelid);
+		kr6->r.labelid = labelid;
+		if (kl->flags & F_BLACKHOLE)
+			kr6->r.flags |= F_BLACKHOLE;
+		else
+			kr6->r.flags &= ~F_BLACKHOLE;
+		if (kl->flags & F_REJECT)
+			kr6->r.flags |= F_REJECT;
+		else
+			kr6->r.flags &= ~F_REJECT;
+	}
+
+	if (send_rt6msg(kr_state.fd, action, kt, &kr6->r) == -1)
 		return (-1);
 
 	return (0);
 }
 
 int
-kr6_change(struct kroute6_label *kl)
+krVPN4_change(struct ktable *kt, struct kroute_full *kl)
 {
-	struct kroute6_node	*kr6;
+	struct kroute_node	*kr;
 	int			 action = RTM_ADD;
-	struct in6_addr		 lo6 = IN6ADDR_LOOPBACK_INIT;
+	u_int32_t		 mplslabel = 0;
+	u_int16_t		 labelid;
 
-	if ((kr6 = kroute6_find(&kl->kr.prefix, kl->kr.prefixlen, RTP_BGP))
-	     != NULL)
+	if ((kr = kroute_find(kt, kl->prefix.vpn4.addr.s_addr, kl->prefixlen,
+	    RTP_BGP)) != NULL)
 		action = RTM_CHANGE;
 
-	/* nexthop to loopback -> ignore silently */
-	if (IN6_IS_ADDR_LOOPBACK(&kl->kr.nexthop))
+	/* nexthop within 127/8 -> ignore silently */
+	if ((kl->nexthop.v4.s_addr & htonl(IN_CLASSA_NET)) ==
+	    htonl(INADDR_LOOPBACK & IN_CLASSA_NET))
 		return (0);
 
-	if (kr6)
-		rtlabel_unref(kr6->r.labelid);
-	kl->kr.labelid = rtlabel_name2id(kl->label);
+	/* only single MPLS label are supported for now */
+	if (kl->prefix.vpn4.labellen != 3) {
+		log_warnx("krVPN4_change: %s/%u has not a single label",
+		    log_addr(&kl->prefix), kl->prefixlen);
+		return (0);
+	}
+	mplslabel = (kl->prefix.vpn4.labelstack[0] << 24) |
+	    (kl->prefix.vpn4.labelstack[1] << 16) |
+	    (kl->prefix.vpn4.labelstack[2] << 8);
+	mplslabel = htonl(mplslabel);
 
-	/* for blackhole and reject routes nexthop needs to be ::1 */
-	if (kl->kr.flags & (F_BLACKHOLE|F_REJECT))
-		bcopy(&lo6, &kl->kr.nexthop, sizeof(kl->kr.nexthop));
+	labelid = rtlabel_name2id(kl->label);
 
-	if (send_rt6msg(kr_state.fd, action, &kl->kr) == -1)
-		return (-1);
+	/* for blackhole and reject routes nexthop needs to be 127.0.0.1 */
+	if (kl->flags & (F_BLACKHOLE|F_REJECT))
+		kl->nexthop.v4.s_addr = htonl(INADDR_LOOPBACK);
 
 	if (action == RTM_ADD) {
-		if ((kr6 = calloc(1, sizeof(struct kroute6_node))) == NULL) {
+		if ((kr = calloc(1, sizeof(struct kroute_node))) == NULL) {
 			log_warn("kr_change");
 			return (-1);
 		}
-		memcpy(&kr6->r.prefix, &kl->kr.prefix,
-		    sizeof(struct in6_addr));
-		kr6->r.prefixlen = kl->kr.prefixlen;
-		memcpy(&kr6->r.nexthop, &kl->kr.nexthop,
-		    sizeof(struct in6_addr));
-		kr6->r.flags = kl->kr.flags | F_BGPD_INSERTED;
-		kr6->r.priority = RTP_BGP;
-		kr6->r.labelid = kl->kr.labelid;
+		kr->r.prefix.s_addr = kl->prefix.vpn4.addr.s_addr;
+		kr->r.prefixlen = kl->prefixlen;
+		kr->r.nexthop.s_addr = kl->nexthop.v4.s_addr;
+		kr->r.flags = kl->flags | F_BGPD_INSERTED | F_MPLS;
+		kr->r.priority = RTP_BGP;
+		kr->r.labelid = labelid;
+		kr->r.mplslabel = mplslabel;
 
-		if (kroute6_insert(kr6) == -1)
-			free(kr6);
+		if (kroute_insert(kt, kr) == -1)
+			free(kr);
 	} else {
-		memcpy(&kr6->r.nexthop, &kl->kr.nexthop,
-		    sizeof(struct in6_addr));
-		kr6->r.labelid = kl->kr.labelid;
-		if (kl->kr.flags & F_BLACKHOLE)
-			kr6->r.flags |= F_BLACKHOLE;
+		kr->r.mplslabel = mplslabel;
+		kr->r.nexthop.s_addr = kl->nexthop.v4.s_addr;
+		rtlabel_unref(kr->r.labelid);
+		kr->r.labelid = labelid;
+		if (kl->flags & F_BLACKHOLE)
+			kr->r.flags |= F_BLACKHOLE;
 		else
-			kr6->r.flags &= ~F_BLACKHOLE;
-		if (kl->kr.flags & F_REJECT)
-			kr6->r.flags |= F_REJECT;
+			kr->r.flags &= ~F_BLACKHOLE;
+		if (kl->flags & F_REJECT)
+			kr->r.flags |= F_REJECT;
 		else
-			kr6->r.flags &= ~F_REJECT;
+			kr->r.flags &= ~F_REJECT;
 	}
 
+	if (send_rtmsg(kr_state.fd, action, kt, &kr->r) == -1)
+		return (-1);
+
 	return (0);
 }
 
 int
-kr6_delete(struct kroute6_label *kl)
+kr_delete(u_int rtableid, struct kroute_full *kl)
+{
+	struct ktable		*kt;
+
+	if ((kt = ktable_get(rtableid)) == NULL)
+		/* too noisy during reloads, just ignore */
+		return (0);
+
+	switch (kl->prefix.aid) {
+	case AID_INET:
+		return (kr4_delete(kt, kl));
+	case AID_INET6:
+		return (kr6_delete(kt, kl));
+	case AID_VPN_IPv4:
+		return (krVPN4_delete(kt, kl));
+	}
+	log_warnx("kr_change: not handled AID");
+	return (-1);
+}
+
+int
+kr4_delete(struct ktable *kt, struct kroute_full *kl)
+{
+	struct kroute_node	*kr;
+
+	if ((kr = kroute_find(kt, kl->prefix.v4.s_addr, kl->prefixlen,
+	    RTP_BGP)) == NULL)
+		return (0);
+
+	if (!(kr->r.flags & F_BGPD_INSERTED))
+		return (0);
+
+	if (send_rtmsg(kr_state.fd, RTM_DELETE, kt, &kr->r) == -1)
+		return (-1);
+
+	rtlabel_unref(kr->r.labelid);
+
+	if (kroute_remove(kt, kr) == -1)
+		return (-1);
+
+	return (0);
+}
+
+int
+kr6_delete(struct ktable *kt, struct kroute_full *kl)
 {
 	struct kroute6_node	*kr6;
 
-	if ((kr6 = kroute6_find(&kl->kr.prefix, kl->kr.prefixlen, RTP_BGP))
-	    == NULL)
+	if ((kr6 = kroute6_find(kt, &kl->prefix.v6, kl->prefixlen, RTP_BGP)) ==
+	    NULL)
 		return (0);
 
 	if (!(kr6->r.flags & F_BGPD_INSERTED))
 		return (0);
 
-	/* nexthop to loopback -> ignore silently */
-	if (IN6_IS_ADDR_LOOPBACK(&kl->kr.nexthop))
+	if (send_rt6msg(kr_state.fd, RTM_DELETE, kt, &kr6->r) == -1)
+		return (-1);
+
+	rtlabel_unref(kr6->r.labelid);
+
+	if (kroute6_remove(kt, kr6) == -1)
+		return (-1);
+
+	return (0);
+}
+
+int
+krVPN4_delete(struct ktable *kt, struct kroute_full *kl)
+{
+	struct kroute_node	*kr;
+
+	if ((kr = kroute_find(kt, kl->prefix.vpn4.addr.s_addr, kl->prefixlen,
+	    RTP_BGP)) == NULL)
 		return (0);
 
-	if (send_rt6msg(kr_state.fd, RTM_DELETE, &kl->kr) == -1)
+	if (!(kr->r.flags & F_BGPD_INSERTED))
+		return (0);
+
+	if (send_rtmsg(kr_state.fd, RTM_DELETE, kt, &kr->r) == -1)
 		return (-1);
 
-	rtlabel_unref(kl->kr.labelid);
+	rtlabel_unref(kr->r.labelid);
 
-	if (kroute6_remove(kr6) == -1)
+	if (kroute_remove(kt, kr) == -1)
 		return (-1);
 
 	return (0);
@@ -394,53 +759,63 @@ kr6_delete(struct kroute6_label *kl)
 void
 kr_shutdown(void)
 {
-	kr_fib_decouple();
-	knexthop_clear();
-	kroute_clear();
-	kroute6_clear();
+	u_int	i;
+
+	for (i = krt_size; i > 0; i--)
+		ktable_free(i - 1);
 	kif_clear();
 }
 
 void
-kr_fib_couple(void)
+kr_fib_couple(u_int rtableid)
 {
+	struct ktable		*kt;
 	struct kroute_node	*kr;
 	struct kroute6_node	*kr6;
 
-	if (kr_state.fib_sync == 1)	/* already coupled */
+	if ((kt = ktable_get(rtableid)) == NULL)  /* table does not exist */
 		return;
 
-	kr_state.fib_sync = 1;
+	if (kt->fib_sync)	/* already coupled */
+		return;
 
-	RB_FOREACH(kr, kroute_tree, &krt)
+	kt->fib_sync = 1;
+
+	RB_FOREACH(kr, kroute_tree, &kt->krt)
 		if ((kr->r.flags & F_BGPD_INSERTED))
-			send_rtmsg(kr_state.fd, RTM_ADD, &kr->r);
-	RB_FOREACH(kr6, kroute6_tree, &krt6)
+			send_rtmsg(kr_state.fd, RTM_ADD, kt, &kr->r);
+	RB_FOREACH(kr6, kroute6_tree, &kt->krt6)
 		if ((kr6->r.flags & F_BGPD_INSERTED))
-			send_rt6msg(kr_state.fd, RTM_ADD, &kr6->r);
+			send_rt6msg(kr_state.fd, RTM_ADD, kt, &kr6->r);
 
-	log_info("kernel routing table coupled");
+	log_info("kernel routing table %u (%s) coupled", kt->rtableid,
+	    kt->descr);
 }
 
 void
-kr_fib_decouple(void)
+kr_fib_decouple(u_int rtableid)
 {
+	struct ktable		*kt;
 	struct kroute_node	*kr;
 	struct kroute6_node	*kr6;
 
-	if (kr_state.fib_sync == 0)	/* already decoupled */
+	if ((kt = ktable_get(rtableid)) == NULL)  /* table does not exist */
+		return;
+
+	if (!kt->fib_sync)	/* already decoupled */
 		return;
 
-	RB_FOREACH(kr, kroute_tree, &krt)
+	RB_FOREACH(kr, kroute_tree, &kt->krt)
 		if ((kr->r.flags & F_BGPD_INSERTED))
-			send_rtmsg(kr_state.fd, RTM_DELETE, &kr->r);
-	RB_FOREACH(kr6, kroute6_tree, &krt6)
+			send_rtmsg(kr_state.fd, RTM_DELETE, kt, &kr->r);
+	RB_FOREACH(kr6, kroute6_tree, &kt->krt6)
 		if ((kr6->r.flags & F_BGPD_INSERTED))
-			send_rt6msg(kr_state.fd, RTM_DELETE, &kr6->r);
+			send_rt6msg(kr_state.fd, RTM_DELETE, kt, &kr6->r);
 
-	kr_state.fib_sync = 0;
+	kt->fib_sync = 0;
 
-	log_info("kernel routing table decoupled");
+	log_info("kernel routing table %u (%s) decoupled", kt->rtableid,
+	    kt->descr);
 }
 
 int
@@ -450,41 +825,18 @@ kr_dispatch_msg(void)
 }
 
 int
-kr_nexthop_add(struct bgpd_addr *addr)
+kr_nexthop_add(u_int rtableid, struct bgpd_addr *addr)
 {
+	struct ktable		*kt;
 	struct knexthop_node	*h;
 
-	if ((h = knexthop_find(addr)) != NULL) {
+	if ((kt = ktable_get(rtableid)) == NULL) {
+		log_warnx("kr_nexthop_add: non-existent rtableid %d", rtableid);
+		return (0);
+	}
+	if ((h = knexthop_find(kt, addr)) != NULL) {
 		/* should not happen... this is actually an error path */
-		struct kroute_nexthop	 nh;
-		struct kroute_node	*k;
-		struct kroute6_node	*k6;
-
-		bzero(&nh, sizeof(nh));
-		memcpy(&nh.nexthop, addr, sizeof(nh.nexthop));
-		nh.valid = 1;
-		if (h->kroute != NULL && addr->af == AF_INET) {
-			k = h->kroute;
-			nh.connected = k->r.flags & F_CONNECTED;
-			if (k->r.nexthop.s_addr != 0) {
-				nh.gateway.af = AF_INET;
-				nh.gateway.v4.s_addr =
-				    k->r.nexthop.s_addr;
-			}
-			memcpy(&nh.kr.kr4, &k->r, sizeof(nh.kr.kr4));
-		} else if (h->kroute != NULL && addr->af == AF_INET6) {
-			k6 = h->kroute;
-			nh.connected = k6->r.flags & F_CONNECTED;
-			if (memcmp(&k6->r.nexthop, &in6addr_any,
-			    sizeof(struct in6_addr)) != 0) {
-				nh.gateway.af = AF_INET6;
-				memcpy(&nh.gateway.v6, &k6->r.nexthop,
-				    sizeof(struct in6_addr));
-			}
-			memcpy(&nh.kr.kr6, &k6->r, sizeof(nh.kr.kr6));
-		}
-
-		send_nexthop_update(&nh);
+		knexthop_send_update(h);
 	} else {
 		if ((h = calloc(1, sizeof(struct knexthop_node))) == NULL) {
 			log_warn("kr_nexthop_add");
@@ -492,7 +844,7 @@ kr_nexthop_add(struct bgpd_addr *addr)
 		}
 		memcpy(&h->nexthop, addr, sizeof(h->nexthop));
 
-		if (knexthop_insert(h) == -1)
+		if (knexthop_insert(kt, h) == -1)
 			return (-1);
 	}
 
@@ -500,19 +852,26 @@ kr_nexthop_add(struct bgpd_addr *addr)
 }
 
 void
-kr_nexthop_delete(struct bgpd_addr *addr)
+kr_nexthop_delete(u_int rtableid, struct bgpd_addr *addr)
 {
+	struct ktable		*kt;
 	struct knexthop_node	*kn;
 
-	if ((kn = knexthop_find(addr)) == NULL)
+	if ((kt = ktable_get(rtableid)) == NULL) {
+		log_warnx("kr_nexthop_delete: non-existent rtableid %d",
+		    rtableid);
+		return;
+	}
+	if ((kn = knexthop_find(kt, addr)) == NULL)
 		return;
 
-	knexthop_remove(kn);
+	knexthop_remove(kt, kn);
 }
 
 void
 kr_show_route(struct imsg *imsg)
 {
+	struct ktable		*kt;
 	struct kroute_node	*kr, *kn;
 	struct kroute6_node	*kr6, *kn6;
 	struct bgpd_addr	*addr;
@@ -521,6 +880,7 @@ kr_show_route(struct imsg *imsg)
 	struct ctl_show_nexthop	 snh;
 	struct knexthop_node	*h;
 	struct kif_node		*kif;
+	u_int			 i;
 	u_short			 ifindex = 0;
 
 	switch (imsg->hdr.type) {
@@ -528,70 +888,96 @@ kr_show_route(struct imsg *imsg)
 		if (imsg->hdr.len != IMSG_HEADER_SIZE + sizeof(flags) +
 		    sizeof(af)) {
 			log_warnx("kr_show_route: wrong imsg len");
-			return;
+			break;
+		}
+		kt = ktable_get(imsg->hdr.peerid);
+		if (kt == NULL) {
+			log_warnx("kr_show_route: table %u does not exist",
+			    imsg->hdr.peerid);
+			break;
 		}
 		memcpy(&flags, imsg->data, sizeof(flags));
 		memcpy(&af, (char *)imsg->data + sizeof(flags), sizeof(af));
 		if (!af || af == AF_INET)
-			RB_FOREACH(kr, kroute_tree, &krt)
-				if (!flags || kr->r.flags & flags) {
-					kn = kr;
-					do {
-						send_imsg_session(
-						    IMSG_CTL_KROUTE,
-						    imsg->hdr.pid, &kn->r,
-						    sizeof(kn->r));
-					} while ((kn = kn->next) != NULL);
-				}
+			RB_FOREACH(kr, kroute_tree, &kt->krt) {
+				if (flags && (kr->r.flags & flags) == 0)
+					continue;
+				kn = kr;
+				do {
+					send_imsg_session(IMSG_CTL_KROUTE,
+					    imsg->hdr.pid, kr_tofull(&kn->r),
+					    sizeof(struct kroute_full));
+				} while ((kn = kn->next) != NULL);
+			}
 		if (!af || af == AF_INET6)
-			RB_FOREACH(kr6, kroute6_tree, &krt6)
-				if (!flags || kr6->r.flags & flags) {
-					kn6 = kr6;
-					do {
-						send_imsg_session(
-						    IMSG_CTL_KROUTE6,
-						    imsg->hdr.pid, &kn6->r,
-						    sizeof(kn6->r));
-					} while ((kn6 = kn6->next) != NULL);
-				}
+			RB_FOREACH(kr6, kroute6_tree, &kt->krt6) {
+				if (flags && (kr6->r.flags & flags) == 0)
+					continue;
+				kn6 = kr6;
+				do {
+					send_imsg_session(IMSG_CTL_KROUTE,
+					    imsg->hdr.pid, kr6_tofull(&kn6->r),
+					    sizeof(struct kroute_full));
+				} while ((kn6 = kn6->next) != NULL);
+			}
 		break;
 	case IMSG_CTL_KROUTE_ADDR:
 		if (imsg->hdr.len != IMSG_HEADER_SIZE +
 		    sizeof(struct bgpd_addr)) {
 			log_warnx("kr_show_route: wrong imsg len");
-			return;
+			break;
+		}
+		kt = ktable_get(imsg->hdr.peerid);
+		if (kt == NULL) {
+			log_warnx("kr_show_route: table %u does not exist",
+			    imsg->hdr.peerid);
+			break;
 		}
 		addr = imsg->data;
 		kr = NULL;
-		switch (addr->af) {
-		case AF_INET:
-			kr = kroute_match(addr->v4.s_addr, 1);
+		switch (addr->aid) {
+		case AID_INET:
+			kr = kroute_match(kt, addr->v4.s_addr, 1);
 			if (kr != NULL)
 				send_imsg_session(IMSG_CTL_KROUTE,
-				    imsg->hdr.pid, &kr->r, sizeof(kr->r));
+				    imsg->hdr.pid, kr_tofull(&kr->r),
+				    sizeof(struct kroute_full));
 			break;
-		case AF_INET6:
-			kr6 = kroute6_match(&addr->v6, 1);
+		case AID_INET6:
+			kr6 = kroute6_match(kt, &addr->v6, 1);
 			if (kr6 != NULL)
-				send_imsg_session(IMSG_CTL_KROUTE6,
-				    imsg->hdr.pid, &kr6->r, sizeof(kr6->r));
+				send_imsg_session(IMSG_CTL_KROUTE,
+				    imsg->hdr.pid, kr6_tofull(&kr6->r),
+				    sizeof(struct kroute_full));
 			break;
 		}
 		break;
 	case IMSG_CTL_SHOW_NEXTHOP:
-		RB_FOREACH(h, knexthop_tree, &knt) {
+		kt = ktable_get(imsg->hdr.peerid);
+		if (kt == NULL) {
+			log_warnx("kr_show_route: table %u does not exist",
+			    imsg->hdr.peerid);
+			break;
+		}
+		RB_FOREACH(h, knexthop_tree, KT2KNT(kt)) {
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
@@ -608,41 +994,190 @@ kr_show_route(struct imsg *imsg)
 			send_imsg_session(IMSG_CTL_SHOW_INTERFACE,
 			    imsg->hdr.pid, &kif->k, sizeof(kif->k));
 		break;
+	case IMSG_CTL_SHOW_FIB_TABLES:
+		for (i = 0; i < krt_size; i++) {
+			struct ktable	ktab;
+
+			if ((kt = ktable_get(i)) == NULL)
+				continue;
+
+			ktab = *kt;
+			/* do not leak internal information */
+			RB_INIT(&ktab.krt);
+			RB_INIT(&ktab.krt6);
+			RB_INIT(&ktab.knt);
+			TAILQ_INIT(&ktab.krn);
+
+			send_imsg_session(IMSG_CTL_SHOW_FIB_TABLES,
+			    imsg->hdr.pid, &ktab, sizeof(ktab));
+		}
+		break;
 	default:	/* nada */
 		break;
 	}
-
-	send_imsg_session(IMSG_CTL_END, imsg->hdr.pid, NULL, 0);
+
+	send_imsg_session(IMSG_CTL_END, imsg->hdr.pid, NULL, 0);
+}
+
+void
+kr_ifinfo(char *ifname)
+{
+	struct kif_node	*kif;
+
+	RB_FOREACH(kif, kif_tree, &kit)
+		if (!strcmp(ifname, kif->k.ifname)) {
+			send_imsg_session(IMSG_IFINFO, 0,
+			    &kif->k, sizeof(kif->k));
+			return;
+		}
+}
+
+void
+kr_net_delete(struct network *n)
+{
+	filterset_free(&n->net.attrset);
+	free(n);
+}
+
+struct network *
+kr_net_match(struct ktable *kt, struct kroute *kr)
+{
+	struct network		*xn;
+
+	TAILQ_FOREACH(xn, &kt->krn, entry) {
+		if (xn->net.prefix.aid != AID_INET)
+			continue;
+		switch (xn->net.type) {
+		case NETWORK_DEFAULT:
+			if (xn->net.prefixlen == kr->prefixlen &&
+			    xn->net.prefix.v4.s_addr == kr->prefix.s_addr)
+				/* static match already redistributed */
+				return (NULL);
+			break;
+		case NETWORK_STATIC:
+			if (kr->flags & F_STATIC)
+				return (xn);
+			break;
+		case NETWORK_CONNECTED:
+			if (kr->flags & F_CONNECTED)
+				return (xn);
+			break;
+		case NETWORK_MRTCLONE:
+			/* can not happen */
+			break;
+		}
+	}
+	return (NULL);
 }
 
-void
-kr_ifinfo(char *ifname)
+struct network *
+kr_net_match6(struct ktable *kt, struct kroute6 *kr6)
 {
-	struct kif_node	*kif;
+	struct network		*xn;
 
-	RB_FOREACH(kif, kif_tree, &kit)
-		if (!strcmp(ifname, kif->k.ifname)) {
-			send_imsg_session(IMSG_IFINFO, 0,
-			    &kif->k, sizeof(kif->k));
-			return;
+	TAILQ_FOREACH(xn, &kt->krn, entry) {
+		if (xn->net.prefix.aid != AID_INET6)
+			continue;
+		switch (xn->net.type) {
+		case NETWORK_DEFAULT:
+			if (xn->net.prefixlen == kr6->prefixlen &&
+			    memcmp(&xn->net.prefix.v6, &kr6->prefix,
+			    sizeof(struct in6_addr)) == 0)
+				/* static match already redistributed */
+				return (NULL);
+			break;
+		case NETWORK_STATIC:
+			if (kr6->flags & F_STATIC)
+				return (xn);
+			break;
+		case NETWORK_CONNECTED:
+			if (kr6->flags & F_CONNECTED)
+				return (xn);
+			break;
+		case NETWORK_MRTCLONE:
+			/* can not happen */
+			break;
 		}
+	}
+	return (NULL);
 }
 
-struct redist_node {
-	LIST_ENTRY(redist_node)	 entry;
-	struct kroute		*kr;
-	struct kroute6		*kr6;
-};
+struct network *
+kr_net_find(struct ktable *kt, struct network *n)
+{
+	struct network		*xn;
+
+	TAILQ_FOREACH(xn, &kt->krn, entry) {
+		if (n->net.type != xn->net.type ||
+		    n->net.prefixlen != xn->net.prefixlen ||
+		    n->net.rtableid != xn->net.rtableid)
+			continue;
+		if (memcmp(&n->net.prefix, &xn->net.prefix,
+		    sizeof(n->net.prefix)) == 0)
+			return (xn);
+	}
+	return (NULL);
+}
+
+int
+kr_net_reload(u_int rtableid, struct network_head *nh)
+{
+	struct network		*n, *xn;
+	struct ktable		*kt;
+
+	if ((kt = ktable_get(rtableid)) == NULL) {
+		log_warnx("kr_net_reload: non-existent rtableid %d", rtableid);
+		return (-1);
+	}
+
+	TAILQ_FOREACH(n, &kt->krn, entry)
+		n->net.old = 1;
+
+	while ((n = TAILQ_FIRST(nh)) != NULL) {
+		TAILQ_REMOVE(nh, n, entry);
+		n->net.old = 0;
+		n->net.rtableid = rtableid;
+		xn = kr_net_find(kt, n);
+		if (xn) {
+			xn->net.old = 0;
+			filterset_free(&xn->net.attrset);
+			filterset_move(&n->net.attrset, &xn->net.attrset);
+			kr_net_delete(n);
+		} else
+			TAILQ_INSERT_TAIL(&kt->krn, n, entry);
+	}
 
+	for (n = TAILQ_FIRST(&kt->krn); n != NULL; n = xn) {
+		xn = TAILQ_NEXT(n, entry);
+		if (n->net.old) {
+			if (n->net.type == NETWORK_DEFAULT)
+				if (send_network(IMSG_NETWORK_REMOVE, &n->net,
+				    NULL))
+					return (-1);
+			TAILQ_REMOVE(&kt->krn, n, entry);
+			kr_net_delete(n);
+		}
+	}
 
-LIST_HEAD(, redist_node) redistlist;
+	return (0);
+}
 
 int
-kr_redistribute(int type, struct kroute *kr)
+kr_redistribute(int type, struct ktable *kt, struct kroute *kr)
 {
-	struct redist_node	*rn;
+	struct network		*match;
+	struct network_config	 net;
 	u_int32_t		 a;
 
+	/* shortcut for removals */
+	if (type == IMSG_NETWORK_REMOVE) {
+		if (!(kr->flags & F_REDISTRIBUTED))
+			return (0);	/* no match, don't redistribute */
+		kr->flags &= ~F_REDISTRIBUTED;
+		match = NULL;
+		goto sendit;
+	}
+
 	if (!(kr->flags & F_KERNEL))
 		return (0);
 
@@ -670,41 +1205,40 @@ kr_redistribute(int type, struct kroute 
 	if (kr->prefix.s_addr == INADDR_ANY && kr->prefixlen == 0)
 		return (0);
 
-	/* Add or delete kr from list ... */
-	LIST_FOREACH(rn, &redistlist, entry)
-	    if (rn->kr == kr)
-		    break;
-
-	switch (type) {
-	case IMSG_NETWORK_ADD:
-		if (rn == NULL) {
-			if ((rn = calloc(1, sizeof(struct redist_node))) ==
-			    NULL) {
-				log_warn("kr_redistribute");
-				return (-1);
-			}
-			rn->kr = kr;
-			LIST_INSERT_HEAD(&redistlist, rn, entry);
-		}
-		break;
-	case IMSG_NETWORK_REMOVE:
-		if (rn != NULL) {
-			LIST_REMOVE(rn, entry);
-			free(rn);
-		}
-		break;
-	default:
-		errno = EINVAL;
-		return (-1);
-	}
-
-	return (bgpd_redistribute(type, kr, NULL));
+	match = kr_net_match(kt, kr);
+	if (match == NULL) {
+		if (!(kr->flags & F_REDISTRIBUTED))
+			return (0);	/* no match, don't redistribute */
+		/* route no longer matches but is redistributed, so remove */
+		kr->flags &= ~F_REDISTRIBUTED;
+		type = IMSG_NETWORK_REMOVE;
+	} else
+		kr->flags |= F_REDISTRIBUTED;
+
+sendit:
+	bzero(&net, sizeof(net));
+	net.prefix.aid = AID_INET;
+	net.prefix.v4.s_addr = kr->prefix.s_addr;
+	net.prefixlen = kr->prefixlen;
+	net.rtableid = kt->rtableid;
+
+	return (send_network(type, &net, match ? &match->net.attrset : NULL));
 }
 
 int
-kr_redistribute6(int type, struct kroute6 *kr6)
-{
-	struct redist_node	*rn;
+kr_redistribute6(int type, struct ktable *kt, struct kroute6 *kr6)
+{
+	struct network		*match;
+	struct network_config	 net;
+
+	/* shortcut for removals */
+	if (type == IMSG_NETWORK_REMOVE) {
+		if (!(kr6->flags & F_REDISTRIBUTED))
+			return (0);	/* no match, don't redistribute */
+		kr6->flags &= ~F_REDISTRIBUTED;
+		match = NULL;
+		goto sendit;
+	}
 
 	if (!(kr6->flags & F_KERNEL))
 		return (0);
@@ -736,60 +1270,107 @@ kr_redistribute6(int type, struct kroute
 	 * never allow ::/0 the default route can only be redistributed
 	 * with announce default.
 	 */
-	if (memcmp(&kr6->prefix, &in6addr_any, sizeof(struct in6_addr)) == 0 &&
-	    kr6->prefixlen == 0)
+	if (kr6->prefixlen == 0 &&
+	    memcmp(&kr6->prefix, &in6addr_any, sizeof(struct in6_addr)) == 0)
 		return (0);
 
-	/* Add or delete kr from list ...
-	 * using a linear list to store the redistributed networks will hurt
-	 * as soon as redistribute ospf comes but until then keep it simple.
-	 */
-	LIST_FOREACH(rn, &redistlist, entry)
-	    if (rn->kr6 == kr6)
-		    break;
-
-	switch (type) {
-	case IMSG_NETWORK_ADD:
-		if (rn == NULL) {
-			if ((rn = calloc(1, sizeof(struct redist_node))) ==
-			    NULL) {
-				log_warn("kr_redistribute");
-				return (-1);
-			}
-			rn->kr6 = kr6;
-			LIST_INSERT_HEAD(&redistlist, rn, entry);
-		}
-		break;
-	case IMSG_NETWORK_REMOVE:
-		if (rn != NULL) {
-			LIST_REMOVE(rn, entry);
-			free(rn);
-		}
-		break;
-	default:
-		errno = EINVAL;
-		return (-1);
-	}
+	match = kr_net_match6(kt, kr6);
+	if (match == NULL) {
+		if (!(kr6->flags & F_REDISTRIBUTED))
+			return (0);	/* no match, don't redistribute */
+		/* route no longer matches but is redistributed, so remove */
+		kr6->flags &= ~F_REDISTRIBUTED;
+		type = IMSG_NETWORK_REMOVE;
+	} else
+		kr6->flags |= F_REDISTRIBUTED;
+sendit:
+	bzero(&net, sizeof(net));
+	net.prefix.aid = AID_INET6;
+	memcpy(&net.prefix.v6, &kr6->prefix, sizeof(struct in6_addr));
+	net.prefixlen = kr6->prefixlen;
+	net.rtableid = kt->rtableid;
 
-	return (bgpd_redistribute(type, NULL, kr6));
+	return (send_network(type, &net, match ? &match->net.attrset : NULL));
 }
 
 int
 kr_reload(void)
 {
-	struct redist_node	*rn;
+	struct ktable		*kt;
+	struct kroute_node	*kr;
+	struct kroute6_node	*kr6;
 	struct knexthop_node	*nh;
+	struct network		*n;
+	u_int			 rid;
+	int			 hasdyn = 0;
 
-	LIST_FOREACH(rn, &redistlist, entry)
-		if (bgpd_redistribute(IMSG_NETWORK_ADD, rn->kr, rn->kr6) == -1)
-			return (-1);
+	for (rid = 0; rid < krt_size; rid++) {
+		if ((kt = ktable_get(rid)) == NULL)
+			continue;
 
-	RB_FOREACH(nh, knexthop_tree, &knt)
-		knexthop_validate(nh);
+		RB_FOREACH(nh, knexthop_tree, KT2KNT(kt))
+			knexthop_validate(kt, nh);
+
+		TAILQ_FOREACH(n, &kt->krn, entry)
+			if (n->net.type == NETWORK_DEFAULT) {
+				if (send_network(IMSG_NETWORK_ADD, &n->net,
+				    &n->net.attrset))
+					return (-1);
+			} else
+				hasdyn = 1;
+
+		if (hasdyn) {
+			/* only evaluate the full tree if we need */
+			RB_FOREACH(kr, kroute_tree, &kt->krt)
+				kr_redistribute(IMSG_NETWORK_ADD, kt, &kr->r);
+			RB_FOREACH(kr6, kroute6_tree, &kt->krt6)
+				kr_redistribute6(IMSG_NETWORK_ADD, kt, &kr6->r);
+		}
+	}
 
 	return (0);
 }
 
+struct kroute_full *
+kr_tofull(struct kroute *kr)
+{
+	static struct kroute_full	kf;
+
+	bzero(&kf, sizeof(kf));
+
+	kf.prefix.aid = AID_INET;
+	kf.prefix.v4.s_addr = kr->prefix.s_addr;
+	kf.nexthop.aid = AID_INET;
+	kf.nexthop.v4.s_addr = kr->nexthop.s_addr;
+	strlcpy(kf.label, rtlabel_id2name(kr->labelid), sizeof(kf.label));
+	kf.flags = kr->flags;
+	kf.ifindex = kr->ifindex;
+	kf.prefixlen = kr->prefixlen;
+	kf.priority = kr->priority;
+
+	return (&kf);
+}
+
+struct kroute_full *
+kr6_tofull(struct kroute6 *kr6)
+{
+	static struct kroute_full	kf;
+
+	bzero(&kf, sizeof(kf));
+
+	kf.prefix.aid = AID_INET6;
+	memcpy(&kf.prefix.v6, &kr6->prefix, sizeof(struct in6_addr));
+	kf.nexthop.aid = AID_INET6;
+	memcpy(&kf.nexthop.v6, &kr6->nexthop, sizeof(struct in6_addr));
+	strlcpy(kf.label, rtlabel_id2name(kr6->labelid), sizeof(kf.label));
+	kf.flags = kr6->flags;
+	kf.ifindex = kr6->ifindex;
+	kf.prefixlen = kr6->prefixlen;
+	kf.priority = kr6->priority;
+
+	return (&kf);
+}
+
 /*
  * RB-tree compare functions
  */
@@ -846,26 +1427,28 @@ kroute6_compare(struct kroute6_node *a, 
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
@@ -883,7 +1466,8 @@ kif_compare(struct kif_node *a, struct k
  */
 
 struct kroute_node *
-kroute_find(in_addr_t prefix, u_int8_t prefixlen, u_int8_t prio)
+kroute_find(struct ktable *kt, in_addr_t prefix, u_int8_t prefixlen,
+    u_int8_t prio)
 {
 	struct kroute_node	s;
 	struct kroute_node	*kn, *tmp;
@@ -892,15 +1476,15 @@ kroute_find(in_addr_t prefix, u_int8_t p
 	s.r.prefixlen = prefixlen;
 	s.r.priority = prio;
 
-	kn = RB_FIND(kroute_tree, &krt, &s);
+	kn = RB_FIND(kroute_tree, &kt->krt, &s);
 	if (kn && prio == RTP_ANY) {
-		tmp = RB_PREV(kroute_tree, &krt, kn);
+		tmp = RB_PREV(kroute_tree, &kt->krt, kn);
 		while (tmp) {
 			if (kroute_compare(&s, tmp) == 0)
 				kn = tmp;
 			else
 				break;
-			tmp = RB_PREV(kroute_tree, &krt, kn);
+			tmp = RB_PREV(kroute_tree, &kt->krt, kn);
 		}
 	}
 	return (kn);
@@ -927,13 +1511,13 @@ kroute_matchgw(struct kroute_node *kr, s
 }
 
 int
-kroute_insert(struct kroute_node *kr)
+kroute_insert(struct ktable *kt, struct kroute_node *kr)
 {
 	struct kroute_node	*krm;
 	struct knexthop_node	*h;
 	in_addr_t		 mask, ina;
 
-	if ((krm = RB_INSERT(kroute_tree, &krt, kr)) != NULL) {
+	if ((krm = RB_INSERT(kroute_tree, &kt->krt, kr)) != NULL) {
 		/* multipath route, add at end of list */
 		while (krm->next != NULL)
 			krm = krm->next;
@@ -941,13 +1525,14 @@ kroute_insert(struct kroute_node *kr)
 		kr->next = NULL; /* to be sure */
 	}
 
+	/* XXX this is wrong for nexthop validated via BGP */
 	if (kr->r.flags & F_KERNEL) {
 		mask = prefixlen2mask(kr->r.prefixlen);
 		ina = ntohl(kr->r.prefix.s_addr);
-		RB_FOREACH(h, knexthop_tree, &knt)
-			if (h->nexthop.af == AF_INET &&
+		RB_FOREACH(h, knexthop_tree, KT2KNT(kt))
+			if (h->nexthop.aid == AID_INET &&
 			    (ntohl(h->nexthop.v4.s_addr) & mask) == ina)
-				knexthop_validate(h);
+				knexthop_validate(kt, h);
 
 		if (kr->r.flags & F_CONNECTED)
 			if (kif_kr_insert(kr) == -1)
@@ -955,19 +1540,19 @@ kroute_insert(struct kroute_node *kr)
 
 		if (krm == NULL)
 			/* redistribute multipath routes only once */
-			kr_redistribute(IMSG_NETWORK_ADD, &kr->r);
+			kr_redistribute(IMSG_NETWORK_ADD, kt, &kr->r);
 	}
 	return (0);
 }
 
 
 int
-kroute_remove(struct kroute_node *kr)
+kroute_remove(struct ktable *kt, struct kroute_node *kr)
 {
 	struct kroute_node	*krm;
 	struct knexthop_node	*s;
 
-	if ((krm = RB_FIND(kroute_tree, &krt, kr)) == NULL) {
+	if ((krm = RB_FIND(kroute_tree, &kt->krt, kr)) == NULL) {
 		log_warnx("kroute_remove failed to find %s/%u",
 		    inet_ntoa(kr->r.prefix), kr->r.prefixlen);
 		return (-1);
@@ -975,13 +1560,14 @@ kroute_remove(struct kroute_node *kr)
 
 	if (krm == kr) {
 		/* head element */
-		if (RB_REMOVE(kroute_tree, &krt, kr) == NULL) {
+		if (RB_REMOVE(kroute_tree, &kt->krt, kr) == NULL) {
 			log_warnx("kroute_remove failed for %s/%u",
 			    inet_ntoa(kr->r.prefix), kr->r.prefixlen);
 			return (-1);
 		}
 	       	if (kr->next != NULL) {
-			if (RB_INSERT(kroute_tree, &krt, kr->next) != NULL) {
+			if (RB_INSERT(kroute_tree, &kt->krt, kr->next) !=
+			    NULL) {
 				log_warnx("kroute_remove failed to add %s/%u",
 				    inet_ntoa(kr->r.prefix), kr->r.prefixlen);
 				return (-1);
@@ -1001,14 +1587,14 @@ kroute_remove(struct kroute_node *kr)
 	}
 
 	/* check whether a nexthop depends on this kroute */
-	if ((kr->r.flags & F_KERNEL) && (kr->r.flags & F_NEXTHOP))
-		RB_FOREACH(s, knexthop_tree, &knt)
+	if (kr->r.flags & F_NEXTHOP)
+		RB_FOREACH(s, knexthop_tree, KT2KNT(kt))
 			if (s->kroute == kr)
-				knexthop_validate(s);
+				knexthop_validate(kt, s);
 
 	if (kr->r.flags & F_KERNEL && kr == krm && kr->next == NULL)
 		/* again remove only once */
-		kr_redistribute(IMSG_NETWORK_REMOVE, &kr->r);
+		kr_redistribute(IMSG_NETWORK_REMOVE, kt, &kr->r);
 
 	if (kr->r.flags & F_CONNECTED)
 		if (kif_kr_remove(kr) == -1) {
@@ -1021,16 +1607,17 @@ kroute_remove(struct kroute_node *kr)
 }
 
 void
-kroute_clear(void)
+kroute_clear(struct ktable *kt)
 {
 	struct kroute_node	*kr;
 
-	while ((kr = RB_MIN(kroute_tree, &krt)) != NULL)
-		kroute_remove(kr);
+	while ((kr = RB_MIN(kroute_tree, &kt->krt)) != NULL)
+		kroute_remove(kt, kr);
 }
 
 struct kroute6_node *
-kroute6_find(const struct in6_addr *prefix, u_int8_t prefixlen, u_int8_t prio)
+kroute6_find(struct ktable *kt, const struct in6_addr *prefix,
+    u_int8_t prefixlen, u_int8_t prio)
 {
 	struct kroute6_node	s;
 	struct kroute6_node	*kn6, *tmp;
@@ -1039,15 +1626,15 @@ kroute6_find(const struct in6_addr *pref
 	s.r.prefixlen = prefixlen;
 	s.r.priority = prio;
 
-	kn6 = RB_FIND(kroute6_tree, &krt6, &s);
+	kn6 = RB_FIND(kroute6_tree, &kt->krt6, &s);
 	if (kn6 && prio == RTP_ANY) {
-		tmp = RB_PREV(kroute6_tree, &krt6, kn6);
+		tmp = RB_PREV(kroute6_tree, &kt->krt6, kn6);
 		while (tmp) {
 			if (kroute6_compare(&s, tmp) == 0)
 				kn6 = tmp;
-			else 
+			else
 				break;
-			tmp = RB_PREV(kroute6_tree, &krt6, kn6);
+			tmp = RB_PREV(kroute6_tree, &kt->krt6, kn6);
 		}
 	}
 	return (kn6);
@@ -1056,17 +1643,29 @@ kroute6_find(const struct in6_addr *pref
 struct kroute6_node *
 kroute6_matchgw(struct kroute6_node *kr, struct sockaddr_in6 *sa_in6)
 {
-	struct in6_addr	nexthop;
+	struct sockaddr_in6	nexthop;
 
 	if (sa_in6 == NULL) {
 		log_warnx("kroute6_matchgw: no nexthop defined");
 		return (NULL);
 	}
-	memcpy(&nexthop, &sa_in6->sin6_addr, sizeof(nexthop));
+	memcpy(&nexthop, sa_in6, sizeof(nexthop));
+#if defined(__KAME__) && defined(IPV6_LINKLOCAL_PEER)
+	if (IN6_IS_ADDR_LINKLOCAL(&nexthop.sin6_addr)) {
+		/* Embed scope id and set sin6_scope_id. */
+		if (nexthop.sin6_scope_id == 0)
+			nexthop.sin6_scope_id =
+			    IN6_LINKLOCAL_IFINDEX(nexthop.sin6_addr);
+		else
+			SET_IN6_LINKLOCAL_IFINDEX(nexthop.sin6_addr,
+			    nexthop.sin6_scope_id);
+	}
+#endif
 
 	while (kr) {
-		if (memcmp(&kr->r.nexthop, &nexthop, sizeof(nexthop)) == NULL)
-			return (kr);
+		if (memcmp(&kr->r.nexthop, &nexthop.sin6_addr,
+		    sizeof(nexthop.sin6_addr)) == 0)
+				return (kr);
 		kr = kr->next;
 	}
 
@@ -1074,13 +1673,13 @@ kroute6_matchgw(struct kroute6_node *kr,
 }
 
 int
-kroute6_insert(struct kroute6_node *kr)
+kroute6_insert(struct ktable *kt, struct kroute6_node *kr)
 {
 	struct kroute6_node	*krm;
 	struct knexthop_node	*h;
 	struct in6_addr		 ina, inb;
 
-	if ((krm = RB_INSERT(kroute6_tree, &krt6, kr)) != NULL) {
+	if ((krm = RB_INSERT(kroute6_tree, &kt->krt6, kr)) != NULL) {
 		/* multipath route, add at end of list */
 		while (krm->next != NULL)
 			krm = krm->next;
@@ -1088,14 +1687,15 @@ kroute6_insert(struct kroute6_node *kr)
 		kr->next = NULL; /* to be sure */
 	}
 
+	/* XXX this is wrong for nexthop validated via BGP */
 	if (kr->r.flags & F_KERNEL) {
 		inet6applymask(&ina, &kr->r.prefix, kr->r.prefixlen);
-		RB_FOREACH(h, knexthop_tree, &knt)
-			if (h->nexthop.af == AF_INET6) {
+		RB_FOREACH(h, knexthop_tree, KT2KNT(kt))
+			if (h->nexthop.aid == AID_INET6) {
 				inet6applymask(&inb, &h->nexthop.v6,
 				    kr->r.prefixlen);
 				if (memcmp(&ina, &inb, sizeof(ina)) == 0)
-					knexthop_validate(h);
+					knexthop_validate(kt, h);
 			}
 
 		if (kr->r.flags & F_CONNECTED)
@@ -1104,19 +1704,19 @@ kroute6_insert(struct kroute6_node *kr)
 
 		if (krm == NULL)
 			/* redistribute multipath routes only once */
-			kr_redistribute6(IMSG_NETWORK_ADD, &kr->r);
+			kr_redistribute6(IMSG_NETWORK_ADD, kt, &kr->r);
 	}
 
 	return (0);
 }
 
 int
-kroute6_remove(struct kroute6_node *kr)
+kroute6_remove(struct ktable *kt, struct kroute6_node *kr)
 {
 	struct kroute6_node	*krm;
 	struct knexthop_node	*s;
 
-	if ((krm = RB_FIND(kroute6_tree, &krt6, kr)) == NULL) {
+	if ((krm = RB_FIND(kroute6_tree, &kt->krt6, kr)) == NULL) {
 		log_warnx("kroute6_remove failed for %s/%u",
 		    log_in6addr(&kr->r.prefix), kr->r.prefixlen);
 		return (-1);
@@ -1124,13 +1724,14 @@ kroute6_remove(struct kroute6_node *kr)
 
 	if (krm == kr) {
 		/* head element */
-		if (RB_REMOVE(kroute6_tree, &krt6, kr) == NULL) {
+		if (RB_REMOVE(kroute6_tree, &kt->krt6, kr) == NULL) {
 			log_warnx("kroute6_remove failed for %s/%u",
 			    log_in6addr(&kr->r.prefix), kr->r.prefixlen);
 			return (-1);
 		}
 	       	if (kr->next != NULL) {
-			if (RB_INSERT(kroute6_tree, &krt6, kr->next) != NULL) {
+			if (RB_INSERT(kroute6_tree, &kt->krt6, kr->next) !=
+			    NULL) {
 				log_warnx("kroute6_remove failed to add %s/%u",
 				    log_in6addr(&kr->r.prefix),
 				    kr->r.prefixlen);
@@ -1151,14 +1752,14 @@ kroute6_remove(struct kroute6_node *kr)
 	}
 
 	/* check whether a nexthop depends on this kroute */
-	if ((kr->r.flags & F_KERNEL) && (kr->r.flags & F_NEXTHOP))
-		RB_FOREACH(s, knexthop_tree, &knt)
+	if (kr->r.flags & F_NEXTHOP)
+		RB_FOREACH(s, knexthop_tree, KT2KNT(kt))
 			if (s->kroute == kr)
-				knexthop_validate(s);
+				knexthop_validate(kt, s);
 
 	if (kr->r.flags & F_KERNEL && kr == krm && kr->next == NULL)
 		/* again remove only once */
-		kr_redistribute6(IMSG_NETWORK_REMOVE, &kr->r);
+		kr_redistribute6(IMSG_NETWORK_REMOVE, kt, &kr->r);
 
 	if (kr->r.flags & F_CONNECTED)
 		if (kif_kr6_remove(kr) == -1) {
@@ -1171,45 +1772,46 @@ kroute6_remove(struct kroute6_node *kr)
 }
 
 void
-kroute6_clear(void)
+kroute6_clear(struct ktable *kt)
 {
 	struct kroute6_node	*kr;
 
-	while ((kr = RB_MIN(kroute6_tree, &krt6)) != NULL)
-		kroute6_remove(kr);
+	while ((kr = RB_MIN(kroute6_tree, &kt->krt6)) != NULL)
+		kroute6_remove(kt, kr);
 }
 
 struct knexthop_node *
-knexthop_find(struct bgpd_addr *addr)
+knexthop_find(struct ktable *kt, struct bgpd_addr *addr)
 {
 	struct knexthop_node	s;
 
+	bzero(&s, sizeof(s));
 	memcpy(&s.nexthop, addr, sizeof(s.nexthop));
 
-	return (RB_FIND(knexthop_tree, &knt, &s));
+	return (RB_FIND(knexthop_tree, KT2KNT(kt), &s));
 }
 
 int
-knexthop_insert(struct knexthop_node *kn)
+knexthop_insert(struct ktable *kt, struct knexthop_node *kn)
 {
-	if (RB_INSERT(knexthop_tree, &knt, kn) != NULL) {
+	if (RB_INSERT(knexthop_tree, KT2KNT(kt), kn) != NULL) {
 		log_warnx("knexthop_tree insert failed for %s",
 			    log_addr(&kn->nexthop));
 		free(kn);
 		return (-1);
 	}
 
-	knexthop_validate(kn);
+	knexthop_validate(kt, kn);
 
 	return (0);
 }
 
 int
-knexthop_remove(struct knexthop_node *kn)
+knexthop_remove(struct ktable *kt, struct knexthop_node *kn)
 {
-	kroute_detach_nexthop(kn);
+	kroute_detach_nexthop(kt, kn);
 
-	if (RB_REMOVE(knexthop_tree, &knt, kn) == NULL) {
+	if (RB_REMOVE(knexthop_tree, KT2KNT(kt), kn) == NULL) {
 		log_warnx("knexthop_remove failed for %s",
 		    log_addr(&kn->nexthop));
 		return (-1);
@@ -1220,12 +1822,12 @@ knexthop_remove(struct knexthop_node *kn
 }
 
 void
-knexthop_clear(void)
+knexthop_clear(struct ktable *kt)
 {
 	struct knexthop_node	*kn;
 
-	while ((kn = RB_MIN(knexthop_tree, &knt)) != NULL)
-		knexthop_remove(kn);
+	while ((kn = RB_MIN(knexthop_tree, KT2KNT(kt))) != NULL)
+		knexthop_remove(kt, kn);
 }
 
 struct kif_node *
@@ -1257,6 +1859,7 @@ kif_insert(struct kif_node *kif)
 int
 kif_remove(struct kif_node *kif)
 {
+	struct ktable	*kt;
 	struct kif_kr	*kkr;
 	struct kif_kr6	*kkr6;
 
@@ -1265,20 +1868,23 @@ kif_remove(struct kif_node *kif)
 		return (-1);
 	}
 
+	if ((kt = ktable_get(/* XXX */ 0)) == NULL)
+		goto done;
+
 	while ((kkr = LIST_FIRST(&kif->kroute_l)) != NULL) {
 		LIST_REMOVE(kkr, entry);
 		kkr->kr->r.flags &= ~F_NEXTHOP;
-		kroute_remove(kkr->kr);
+		kroute_remove(kt, kkr->kr);
 		free(kkr);
 	}
 
 	while ((kkr6 = LIST_FIRST(&kif->kroute6_l)) != NULL) {
 		LIST_REMOVE(kkr6, entry);
 		kkr6->kr->r.flags &= ~F_NEXTHOP;
-		kroute6_remove(kkr6->kr);
+		kroute6_remove(kt, kkr6->kr);
 		free(kkr6);
 	}
-
+done:
 	free(kif);
 	return (0);
 }
@@ -1473,113 +2079,109 @@ kroute6_validate(struct kroute6 *kr)
 }
 
 void
-knexthop_validate(struct knexthop_node *kn)
+knexthop_validate(struct ktable *kt, struct knexthop_node *kn)
 {
+	void			*oldk;
 	struct kroute_node	*kr;
 	struct kroute6_node	*kr6;
-	struct kroute_nexthop	 n;
-	int			 was_valid = 0;
 
-	if (kn->nexthop.af == AF_INET && (kr = kn->kroute) != NULL)
-		was_valid = kroute_validate(&kr->r);
-	if (kn->nexthop.af == AF_INET6 && (kr6 = kn->kroute) != NULL)
-		was_valid = kroute6_validate(&kr6->r);
+	oldk = kn->kroute;
+	kroute_detach_nexthop(kt, kn);
 
-	bzero(&n, sizeof(n));
-	memcpy(&n.nexthop, &kn->nexthop, sizeof(n.nexthop));
-	kroute_detach_nexthop(kn);
-
-	switch (kn->nexthop.af) {
-	case AF_INET:
-		if ((kr = kroute_match(kn->nexthop.v4.s_addr, 0)) == NULL) {
-			if (was_valid)
-				send_nexthop_update(&n);
-		} else {					/* match */
-			if (kroute_validate(&kr->r)) {		/* valid */
-				n.valid = 1;
-				n.connected = kr->r.flags & F_CONNECTED;
-				if ((n.gateway.v4.s_addr =
-				    kr->r.nexthop.s_addr) != 0)
-					n.gateway.af = AF_INET;
-				memcpy(&n.kr.kr4, &kr->r, sizeof(n.kr.kr4));
-				send_nexthop_update(&n);
-			} else					/* down */
-				if (was_valid)
-					send_nexthop_update(&n);
+	switch (kn->nexthop.aid) {
+	case AID_INET:
+		kr = kroute_match(kt, kn->nexthop.v4.s_addr, 0);
 
+		if (kr) {
 			kn->kroute = kr;
 			kr->r.flags |= F_NEXTHOP;
 		}
+
+		/*
+		 * Send update if nexthop route changed under us if
+		 * the route remains the same then the NH state has not
+		 * changed. State changes are tracked by knexthop_track().
+		 */
+		if (kr != oldk)
+			knexthop_send_update(kn);
 		break;
-	case AF_INET6:
-		if ((kr6 = kroute6_match(&kn->nexthop.v6, 0)) == NULL) {
-			if (was_valid)
-				send_nexthop_update(&n);
-		} else {					/* match */
-			if (kroute6_validate(&kr6->r)) {	/* valid */
-				n.valid = 1;
-				n.connected = kr6->r.flags & F_CONNECTED;
-				if (memcmp(&kr6->r.nexthop, &in6addr_any,
-				    sizeof(struct in6_addr)) != 0) {
-					n.gateway.af = AF_INET6;
-					memcpy(&n.gateway.v6, &kr6->r.nexthop,
-					    sizeof(struct in6_addr));
-				}
-				memcpy(&n.kr.kr6, &kr6->r, sizeof(n.kr.kr6));
-				send_nexthop_update(&n);
-			} else					/* down */
-				if (was_valid)
-					send_nexthop_update(&n);
+	case AID_INET6:
+		kr6 = kroute6_match(kt, &kn->nexthop.v6, 0);
 
+		if (kr6) {
 			kn->kroute = kr6;
 			kr6->r.flags |= F_NEXTHOP;
 		}
+
+		if (kr6 != oldk)
+			knexthop_send_update(kn);
 		break;
 	}
 }
 
 void
-knexthop_track(void *krn)
+knexthop_track(struct ktable *kt, void *krp)
 {
 	struct knexthop_node	*kn;
+
+	RB_FOREACH(kn, knexthop_tree, KT2KNT(kt))
+		if (kn->kroute == krp)
+			knexthop_send_update(kn);
+}
+
+void
+knexthop_send_update(struct knexthop_node *kn)
+{
+	struct kroute_nexthop	 n;
 	struct kroute_node	*kr;
 	struct kroute6_node	*kr6;
-	struct kroute_nexthop	 n;
 
-	RB_FOREACH(kn, knexthop_tree, &knt)
-		if (kn->kroute == krn) {
-			bzero(&n, sizeof(n));
-			memcpy(&n.nexthop, &kn->nexthop, sizeof(n.nexthop));
+	bzero(&n, sizeof(n));
+	memcpy(&n.nexthop, &kn->nexthop, sizeof(n.nexthop));
 
-			switch (kn->nexthop.af) {
-			case AF_INET:
-				kr = krn;
-				n.valid = 1;
-				n.connected = kr->r.flags & F_CONNECTED;
-				if ((n.gateway.v4.s_addr =
-				    kr->r.nexthop.s_addr) != 0)
-					n.gateway.af = AF_INET;
-				memcpy(&n.kr.kr4, &kr->r, sizeof(n.kr.kr4));
-				break;
-			case AF_INET6:
-				kr6 = krn;
-				n.valid = 1;
-				n.connected = kr6->r.flags & F_CONNECTED;
-				if (memcmp(&kr6->r.nexthop, &in6addr_any,
-				    sizeof(struct in6_addr)) != 0) {
-					n.gateway.af = AF_INET6;
-					memcpy(&n.gateway.v6, &kr6->r.nexthop,
-					    sizeof(struct in6_addr));
-				}
-				memcpy(&n.kr.kr6, &kr6->r, sizeof(n.kr.kr6));
-				break;
-			}
-			send_nexthop_update(&n);
+	if (kn->kroute == NULL) {
+		n.valid = 0;	/* NH is not valid */
+		send_nexthop_update(&n);
+		return;
+	}
+
+	switch (kn->nexthop.aid) {
+	case AID_INET:
+		kr = kn->kroute;
+		n.valid = kroute_validate(&kr->r);
+		n.connected = kr->r.flags & F_CONNECTED;
+		if ((n.gateway.v4.s_addr =
+		    kr->r.nexthop.s_addr) != 0)
+			n.gateway.aid = AID_INET;
+		if (n.connected) {
+			n.net.aid = AID_INET;
+			n.net.v4.s_addr = kr->r.prefix.s_addr;
+			n.netlen = kr->r.prefixlen;
 		}
+		break;
+	case AID_INET6:
+		kr6 = kn->kroute;
+		n.valid = kroute6_validate(&kr6->r);
+		n.connected = kr6->r.flags & F_CONNECTED;
+		if (memcmp(&kr6->r.nexthop, &in6addr_any,
+		    sizeof(struct in6_addr)) != 0) {
+			n.gateway.aid = AID_INET6;
+			memcpy(&n.gateway.v6, &kr6->r.nexthop,
+			    sizeof(struct in6_addr));
+		}
+		if (n.connected) {
+			n.net.aid = AID_INET6;
+			memcpy(&n.net.v6, &kr6->r.nexthop,
+			    sizeof(struct in6_addr));
+			n.netlen = kr6->r.prefixlen;
+		}
+		break;
+	}
+	send_nexthop_update(&n);
 }
 
 struct kroute_node *
-kroute_match(in_addr_t key, int matchall)
+kroute_match(struct ktable *kt, in_addr_t key, int matchall)
 {
 	int			 i;
 	struct kroute_node	*kr;
@@ -1589,13 +2191,13 @@ kroute_match(in_addr_t key, int matchall
 
 	/* we will never match the default route */
 	for (i = 32; i > 0; i--)
-		if ((kr = kroute_find(htonl(ina & prefixlen2mask(i)), i,
+		if ((kr = kroute_find(kt, htonl(ina & prefixlen2mask(i)), i,
 		    RTP_ANY)) != NULL)
 			if (matchall || bgpd_filternexthop(&kr->r, NULL) == 0)
 			    return (kr);
 
 	/* if we don't have a match yet, try to find a default route */
-	if ((kr = kroute_find(0, 0, RTP_ANY)) != NULL)
+	if ((kr = kroute_find(kt, 0, 0, RTP_ANY)) != NULL)
 		if (matchall || bgpd_filternexthop(&kr->r, NULL) == 0)
 			return (kr);
 
@@ -1603,7 +2205,7 @@ kroute_match(in_addr_t key, int matchall
 }
 
 struct kroute6_node *
-kroute6_match(struct in6_addr *key, int matchall)
+kroute6_match(struct ktable *kt, struct in6_addr *key, int matchall)
 {
 	int			 i;
 	struct kroute6_node	*kr6;
@@ -1612,13 +2214,13 @@ kroute6_match(struct in6_addr *key, int 
 	/* we will never match the default route */
 	for (i = 128; i > 0; i--) {
 		inet6applymask(&ina, key, i);
-		if ((kr6 = kroute6_find(&ina, i, RTP_ANY)) != NULL)
+		if ((kr6 = kroute6_find(kt, &ina, i, RTP_ANY)) != NULL)
 			if (matchall || bgpd_filternexthop(NULL, &kr6->r) == 0)
 				return (kr6);
 	}
 
 	/* if we don't have a match yet, try to find a default route */
-	if ((kr6 = kroute6_find(&in6addr_any, 0, RTP_ANY)) != NULL)
+	if ((kr6 = kroute6_find(kt, &in6addr_any, 0, RTP_ANY)) != NULL)
 		if (matchall || bgpd_filternexthop(NULL, &kr6->r) == 0)
 			return (kr6);
 
@@ -1626,31 +2228,30 @@ kroute6_match(struct in6_addr *key, int 
 }
 
 void
-kroute_detach_nexthop(struct knexthop_node *kn)
+kroute_detach_nexthop(struct ktable *kt, struct knexthop_node *kn)
 {
 	struct knexthop_node	*s;
 	struct kroute_node	*k;
 	struct kroute6_node	*k6;
 
+	if (kn->kroute == NULL)
+		return;
+
 	/*
 	 * check whether there's another nexthop depending on this kroute
 	 * if not remove the flag
 	 */
-
-	if (kn->kroute == NULL)
-		return;
-
-	for (s = RB_MIN(knexthop_tree, &knt); s != NULL &&
-	    s->kroute != kn->kroute; s = RB_NEXT(knexthop_tree, &knt, s))
-		;	/* nothing */
+	RB_FOREACH(s, knexthop_tree, KT2KNT(kt))
+		if (s->kroute == kn->kroute && s != kn)
+			break;
 
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
@@ -1665,7 +2266,7 @@ kroute_detach_nexthop(struct knexthop_no
  */
 
 int
-protect_lo(void)
+protect_lo(struct ktable *kt)
 {
 	struct kroute_node	*kr;
 	struct kroute6_node	*kr6;
@@ -1675,11 +2276,11 @@ protect_lo(void)
 		log_warn("protect_lo");
 		return (-1);
 	}
-	kr->r.prefix.s_addr = htonl(INADDR_LOOPBACK);
+	kr->r.prefix.s_addr = htonl(INADDR_LOOPBACK & IN_CLASSA_NET);
 	kr->r.prefixlen = 8;
 	kr->r.flags = F_KERNEL|F_CONNECTED;
 
-	if (RB_INSERT(kroute_tree, &krt, kr) != NULL)
+	if (RB_INSERT(kroute_tree, &kt->krt, kr) != NULL)
 		free(kr);	/* kernel route already there, no problem */
 
 	/* special protection for loopback */
@@ -1689,9 +2290,9 @@ protect_lo(void)
 	}
 	memcpy(&kr6->r.prefix, &in6addr_loopback, sizeof(kr6->r.prefix));
 	kr6->r.prefixlen = 128;
-	kr->r.flags = F_KERNEL|F_CONNECTED;
+	kr6->r.flags = F_KERNEL|F_CONNECTED;
 
-	if (RB_INSERT(kroute6_tree, &krt6, kr6) != NULL)
+	if (RB_INSERT(kroute6_tree, &kt->krt6, kr6) != NULL)
 		free(kr6);	/* kernel route already there, no problem */
 
 	return (0);
@@ -1726,17 +2327,17 @@ mask2prefixlen(in_addr_t ina)
 u_int8_t
 mask2prefixlen6(struct sockaddr_in6 *sa_in6)
 {
-	u_int8_t	 l = 0, i, len;
+	u_int8_t	 l = 0, *ap, *ep;
 
 	/*
 	 * sin6_len is the size of the sockaddr so substract the offset of
 	 * the possibly truncated sin6_addr struct.
 	 */
-	len = sa_in6->sin6_len -
-	    (u_int8_t)(&((struct sockaddr_in6 *)NULL)->sin6_addr);
-	for (i = 0; i < len; i++) {
+	ap = (u_int8_t *)&sa_in6->sin6_addr;
+	ep = (u_int8_t *)sa_in6 + sa_in6->sin6_len;
+	for (; ap < ep; ap++) {
 		/* this "beauty" is adopted from sbin/route/show.c ... */
-		switch (sa_in6->sin6_addr.s6_addr[i]) {
+		switch (*ap) {
 		case 0xff:
 			l += 8;
 			break;
@@ -1764,7 +2365,7 @@ mask2prefixlen6(struct sockaddr_in6 *sa_
 		case 0x00:
 			return (l);
 		default:
-			fatalx("non continguous inet6 netmask");
+			fatalx("non contiguous inet6 netmask");
 		}
 	}
 
@@ -1788,7 +2389,7 @@ prefixlen2mask6(u_int8_t prefixlen)
 }
 
 #define	ROUNDUP(a)	\
-    (((a) & ((sizeof(long)) - 1)) ? (1 + ((a) | ((sizeof(long)) - 1))) : (a))
+    (((a) & (sizeof(long) - 1)) ? (1 + ((a) | (sizeof(long) - 1))) : (a))
 
 void
 get_rtaddrs(int addrs, struct sockaddr *sa, struct sockaddr **rti_info)
@@ -1808,11 +2409,10 @@ get_rtaddrs(int addrs, struct sockaddr *
 void
 if_change(u_short ifindex, int flags, struct if_data *ifd)
 {
+	struct ktable		*kt;
 	struct kif_node		*kif;
 	struct kif_kr		*kkr;
 	struct kif_kr6		*kkr6;
-	struct kroute_nexthop	 nh;
-	struct knexthop_node	*n;
 	u_int8_t		 reachable;
 
 	if ((kif = kif_find(ifindex)) == NULL) {
@@ -1833,28 +2433,18 @@ if_change(u_short ifindex, int flags, st
 
 	kif->k.nh_reachable = reachable;
 
+	kt = ktable_get(/* XXX */ 0);
+
 	LIST_FOREACH(kkr, &kif->kroute_l, entry) {
 		if (reachable)
 			kkr->kr->r.flags &= ~F_DOWN;
 		else
 			kkr->kr->r.flags |= F_DOWN;
 
-		RB_FOREACH(n, knexthop_tree, &knt)
-			if (n->kroute == kkr->kr) {
-				bzero(&nh, sizeof(nh));
-				memcpy(&nh.nexthop, &n->nexthop,
-				    sizeof(nh.nexthop));
-				if (kroute_validate(&kkr->kr->r)) {
-					nh.valid = 1;
-					nh.connected = 1;
-					if ((nh.gateway.v4.s_addr =
-					    kkr->kr->r.nexthop.s_addr) != 0)
-						nh.gateway.af = AF_INET;
-				}
-				memcpy(&nh.kr.kr4, &kkr->kr->r,
-				    sizeof(nh.kr.kr4));
-				send_nexthop_update(&nh);
-			}
+		if (kt == NULL)
+			continue;
+
+		knexthop_track(kt, kkr->kr);
 	}
 	LIST_FOREACH(kkr6, &kif->kroute6_l, entry) {
 		if (reachable)
@@ -1862,27 +2452,10 @@ if_change(u_short ifindex, int flags, st
 		else
 			kkr6->kr->r.flags |= F_DOWN;
 
-		RB_FOREACH(n, knexthop_tree, &knt)
-			if (n->kroute == kkr6->kr) {
-				bzero(&nh, sizeof(nh));
-				memcpy(&nh.nexthop, &n->nexthop,
-				    sizeof(nh.nexthop));
-				if (kroute6_validate(&kkr6->kr->r)) {
-					nh.valid = 1;
-					nh.connected = 1;
-					if (memcmp(&kkr6->kr->r.nexthop,
-					    &in6addr_any, sizeof(struct
-					    in6_addr))) {
-						nh.gateway.af = AF_INET6;
-						memcpy(&nh.gateway.v6,
-						    &kkr6->kr->r.nexthop,
-						    sizeof(struct in6_addr));
-					}
-				}
-				memcpy(&nh.kr.kr6, &kkr6->kr->r,
-				    sizeof(nh.kr.kr6));
-				send_nexthop_update(&nh);
-			}
+		if (kt == NULL)
+			continue;
+
+		knexthop_track(kt, kkr6->kr);
 	}
 }
 
@@ -1917,25 +2490,38 @@ if_announce(void *msg)
  */
 
 int
-send_rtmsg(int fd, int action, struct kroute *kroute)
+send_rtmsg(int fd, int action, struct ktable *kt, struct kroute *kroute)
 {
-	struct iovec		iov[5];
+	struct iovec		iov[7];
 	struct rt_msghdr	hdr;
 	struct sockaddr_in	prefix;
 	struct sockaddr_in	nexthop;
 	struct sockaddr_in	mask;
+	struct {
+		struct sockaddr_dl	dl;
+		char			pad[sizeof(long)];
+	}			ifp;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
+	struct sockaddr_mpls	mpls;
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
-	if (kr_state.fib_sync == 0)
+	if (!kt->fib_sync)
 		return (0);
 
 	/* initialize header */
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
-	hdr.rtm_tableid = kr_state.rtableid;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */
+	hdr.rtm_tableid = kt->rtableid;
+#endif /* !defined(__FreeBSD__) */
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no rtm_priority */
 	hdr.rtm_priority = RTP_BGP;
+#else
+	hdr.rtm_flags = RTF_PROTO1;
+#endif /* !defined(__FreeBSD__) */
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
 	if (kroute->flags & F_REJECT)
@@ -1984,6 +2570,37 @@ send_rtmsg(int fd, int action, struct kr
 	iov[iovcnt].iov_base = &mask;
 	iov[iovcnt++].iov_len = sizeof(mask);
 
+	if (kt->ifindex) {
+		bzero(&ifp, sizeof(ifp));
+		ifp.dl.sdl_len = sizeof(struct sockaddr_dl);
+		ifp.dl.sdl_family = AF_LINK;
+		ifp.dl.sdl_index = kt->ifindex;
+		/* adjust header */
+		hdr.rtm_addrs |= RTA_IFP;
+		hdr.rtm_msglen += ROUNDUP(sizeof(struct sockaddr_dl));
+		/* adjust iovec */
+		iov[iovcnt].iov_base = &ifp;
+		iov[iovcnt++].iov_len = ROUNDUP(sizeof(struct sockaddr_dl));
+	}
+
+#if !defined(__FreeBSD__) /* FreeBSD has no mpls support. */
+	if (kroute->flags & F_MPLS) {
+		bzero(&mpls, sizeof(mpls));
+		mpls.smpls_len = sizeof(mpls);
+		mpls.smpls_family = AF_MPLS;
+		mpls.smpls_label = kroute->mplslabel;
+		/* adjust header */
+		hdr.rtm_flags |= RTF_MPLS;
+		hdr.rtm_mpls = MPLS_OP_PUSH;
+		hdr.rtm_addrs |= RTA_SRC;
+		hdr.rtm_msglen += sizeof(mpls);
+		/* adjust iovec */
+		iov[iovcnt].iov_base = &mpls;
+		iov[iovcnt++].iov_len = sizeof(mpls);
+	}
+#endif
+
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	if (kroute->labelid) {
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
@@ -1996,11 +2613,11 @@ send_rtmsg(int fd, int action, struct kr
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
 	}
+#endif /* !defined(__FreeBSD__) */
 
 retry:
 	if (writev(fd, iov, iovcnt) == -1) {
-		switch (errno) {
-		case ESRCH:
+		if (errno == ESRCH) {
 			if (hdr.rtm_type == RTM_CHANGE) {
 				hdr.rtm_type = RTM_ADD;
 				goto retry;
@@ -2009,27 +2626,18 @@ retry:
 				    inet_ntoa(kroute->prefix),
 				    kroute->prefixlen);
 				return (0);
-			} else {
-				log_warnx("send_rtmsg: action %u, "
-				    "prefix %s/%u: %s", hdr.rtm_type,
-				    inet_ntoa(kroute->prefix),
-				    kroute->prefixlen, strerror(errno));
-				return (0);
 			}
-			break;
-		default:
-			log_warnx("send_rtmsg: action %u, prefix %s/%u: %s",
-			    hdr.rtm_type, inet_ntoa(kroute->prefix),
-			    kroute->prefixlen, strerror(errno));
-			return (0);
 		}
+		log_warn("send_rtmsg: action %u, prefix %s/%u", hdr.rtm_type,
+		    inet_ntoa(kroute->prefix), kroute->prefixlen);
+		return (0);
 	}
 
 	return (0);
 }
 
 int
-send_rt6msg(int fd, int action, struct kroute6 *kroute)
+send_rt6msg(int fd, int action, struct ktable *kt, struct kroute6 *kroute)
 {
 	struct iovec		iov[5];
 	struct rt_msghdr	hdr;
@@ -2037,17 +2645,23 @@ send_rt6msg(int fd, int action, struct k
 		struct sockaddr_in6	addr;
 		char			pad[sizeof(long)];
 	} prefix, nexthop, mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
-	if (kr_state.fib_sync == 0)
+	if (!kt->fib_sync)
 		return (0);
 
 	/* initialize header */
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 	hdr.rtm_tableid = kr_state.rtableid;
+#else
+	hdr.rtm_flags = RTF_PROTO1;
+#endif /* !defined(__FreeBSD__) */
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
 	if (kroute->flags & F_REJECT)
@@ -2100,6 +2714,7 @@ send_rt6msg(int fd, int action, struct k
 	iov[iovcnt].iov_base = &mask;
 	iov[iovcnt++].iov_len = ROUNDUP(sizeof(struct sockaddr_in6));
 
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	if (kroute->labelid) {
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
@@ -2112,11 +2727,11 @@ send_rt6msg(int fd, int action, struct k
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
 	}
+#endif /* !defined(__FreeBSD__) */
 
 retry:
 	if (writev(fd, iov, iovcnt) == -1) {
-		switch (errno) {
-		case ESRCH:
+		if (errno == ESRCH) {
 			if (hdr.rtm_type == RTM_CHANGE) {
 				hdr.rtm_type = RTM_ADD;
 				goto retry;
@@ -2125,31 +2740,26 @@ retry:
 				    log_in6addr(&kroute->prefix),
 				    kroute->prefixlen);
 				return (0);
-			} else {
-				log_warnx("send_rt6msg: action %u, "
-				    "prefix %s/%u: %s", hdr.rtm_type,
-				    log_in6addr(&kroute->prefix),
-				    kroute->prefixlen, strerror(errno));
-				return (0);
 			}
-			break;
-		default:
-			log_warnx("send_rt6msg: action %u, prefix %s/%u: %s",
-			    hdr.rtm_type, log_in6addr(&kroute->prefix),
-			    kroute->prefixlen, strerror(errno));
-			return (0);
 		}
+		log_warn("send_rt6msg: action %u, prefix %s/%u", hdr.rtm_type,
+		    log_in6addr(&kroute->prefix), kroute->prefixlen);
+		return (0);
 	}
 
 	return (0);
 }
 
 int
-fetchtable(u_int rtableid, int connected_only)
+fetchtable(struct ktable *kt)
 {
 	size_t			 len;
+#if !defined(__FreeBSD__) /* FreeBSD has no table id. */
 	int			 mib[7];
-	char			*buf, *next, *lim;
+#else
+	int			mib[6];
+#endif
+	char			*buf = NULL, *next, *lim;
 	struct rt_msghdr	*rtm;
 	struct sockaddr		*sa, *gw, *rti_info[RTAX_MAX];
 	struct sockaddr_in	*sa_in;
@@ -2163,22 +2773,35 @@ fetchtable(u_int rtableid, int connected
 	mib[3] = 0;
 	mib[4] = NET_RT_DUMP;
 	mib[5] = 0;
-	mib[6] = rtableid;
+#if !defined(__FreeBSD__) /* FreeBSD has no table id. */
+	mib[6] = kt->rtableid;
+#endif
 
+#if !defined(__FreeBSD__) /* FreeBSD has no table id. */
 	if (sysctl(mib, 7, NULL, &len, NULL, 0) == -1) {
-		if (rtableid != 0 && errno == EINVAL)	/* table nonexistent */
+#else
+	if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) {
+#endif
+		if (kt->rtableid != 0 && errno == EINVAL)
+			/* table nonexistent */
 			return (0);
 		log_warn("sysctl");
 		return (-1);
 	}
-	if ((buf = malloc(len)) == NULL) {
-		log_warn("fetchtable");
-		return (-1);
-	}
-	if (sysctl(mib, 7, buf, &len, NULL, 0) == -1) {
-		log_warn("sysctl");
-		free(buf);
-		return (-1);
+	if (len > 0) {
+		if ((buf = malloc(len)) == NULL) {
+			log_warn("fetchtable");
+			return (-1);
+		}
+#if !defined(__FreeBSD__) /* FreeBSD has no table id. */
+		if (sysctl(mib, 7, buf, &len, NULL, 0) == -1) {
+#else
+		if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
+#endif
+			log_warn("sysctl2");
+			free(buf);
+			return (-1);
+		}
 	}
 
 	lim = buf + len;
@@ -2186,7 +2809,11 @@ fetchtable(u_int rtableid, int connected
 		rtm = (struct rt_msghdr *)next;
 		if (rtm->rtm_version != RTM_VERSION)
 			continue;
+#if !defined(__FreeBSD__)
 		sa = (struct sockaddr *)(next + rtm->rtm_hdrlen);
+#else
+		sa = (struct sockaddr *)(next + sizeof(struct rt_msghdr));
+#endif
 		get_rtaddrs(rtm->rtm_addrs, sa, rti_info);
 
 		if ((sa = rti_info[RTAX_DST]) == NULL)
@@ -2205,7 +2832,11 @@ fetchtable(u_int rtableid, int connected
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
@@ -2223,8 +2854,12 @@ fetchtable(u_int rtableid, int connected
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
@@ -2238,11 +2873,25 @@ fetchtable(u_int rtableid, int connected
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
 			    sizeof(kr6->r.prefix));
+#if defined(__KAME__) && defined(IPV6_LINKLOCAL_PEER)
+			if (IN6_IS_ADDR_LINKLOCAL(&kr6->r.prefix)) {
+				if (((struct sockaddr_in6 *)sa)->sin6_scope_id !=0)
+					SET_IN6_LINKLOCAL_IFINDEX(kr6->r.prefix,
+					    ((struct sockaddr_in6 *)sa)->sin6_scope_id);
+				else
+					SET_IN6_LINKLOCAL_IFINDEX(kr6->r.prefix,
+					    rtm->rtm_index);
+			}
+#endif
 
 			sa_in6 = (struct sockaddr_in6 *)rti_info[RTAX_NETMASK];
 			if (rtm->rtm_flags & RTF_STATIC)
@@ -2257,8 +2906,12 @@ fetchtable(u_int rtableid, int connected
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
@@ -2280,6 +2933,13 @@ fetchtable(u_int rtableid, int connected
 				memcpy(&kr6->r.nexthop,
 				    &((struct sockaddr_in6 *)gw)->sin6_addr,
 				    sizeof(kr6->r.nexthop));
+#if defined(__KAME__) && defined(IPV6_LINKLOCAL_PEER)
+				if (IN6_IS_ADDR_LINKLOCAL(&kr6->r.nexthop) &&
+				    ((struct sockaddr_in6 *)gw)->sin6_scope_id != 0) {
+					SET_IN6_LINKLOCAL_IFINDEX(kr6->r.nexthop,
+					    ((struct sockaddr_in6 *)gw)->sin6_scope_id);
+				}
+#endif
 				break;
 			case AF_LINK:
 				if (sa->sa_family == AF_INET)
@@ -2290,23 +2950,28 @@ fetchtable(u_int rtableid, int connected
 			}
 
 		if (sa->sa_family == AF_INET) {
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
 			if (rtm->rtm_priority == RTP_BGP)  {
-				send_rtmsg(kr_state.fd, RTM_DELETE, &kr->r);
-				free(kr);
-			} else if (connected_only &&
-			    !(kr->r.flags & F_CONNECTED))
+#else
+			/* never delete route */
+			if (0) {
+#endif
+				send_rtmsg(kr_state.fd, RTM_DELETE, kt, &kr->r);
 				free(kr);
-			else
-				kroute_insert(kr);
+			} else
+				kroute_insert(kt, kr);
 		} else if (sa->sa_family == AF_INET6) {
+#if !defined(__FreeBSD__)	/* no rtm_priority on FreeBSD */
 			if (rtm->rtm_priority == RTP_BGP)  {
-				send_rt6msg(kr_state.fd, RTM_DELETE, &kr6->r);
-				free(kr6);
-			} else if (connected_only &&
-			    !(kr6->r.flags & F_CONNECTED))
+#else
+			/* never delete route */
+			if (0) {
+#endif
+				send_rt6msg(kr_state.fd, RTM_DELETE, kt,
+				    &kr6->r);
 				free(kr6);
-			else
-				kroute6_insert(kr6);
+			} else
+				kroute6_insert(kt, kr6);
 		}
 	}
 	free(buf);
@@ -2327,7 +2992,7 @@ fetchifs(int ifindex)
 	mib[0] = CTL_NET;
 	mib[1] = AF_ROUTE;
 	mib[2] = 0;
-	mib[3] = AF_INET;
+	mib[3] = AF_INET;	/* AF does not matter but AF_INET is shorter */
 	mib[4] = NET_RT_IFLIST;
 	mib[5] = ifindex;
 
@@ -2396,7 +3061,7 @@ dispatch_rtmsg(void)
 	struct rt_msghdr	*rtm;
 	struct if_msghdr	 ifm;
 	struct sockaddr		*sa, *rti_info[RTAX_MAX];
-	int			 connected_only;
+	struct ktable		*kt;
 
 	if ((n = read(kr_state.fd, &buf, sizeof(buf))) == -1) {
 		log_warn("dispatch_rtmsg: read error");
@@ -2418,7 +3083,11 @@ dispatch_rtmsg(void)
 		case RTM_ADD:
 		case RTM_CHANGE:
 		case RTM_DELETE:
+#if !defined(__FreeBSD__)
 			sa = (struct sockaddr *)(next + rtm->rtm_hdrlen);
+#else
+			sa = (struct sockaddr *)(next + sizeof(struct rt_msghdr));
+#endif
 			get_rtaddrs(rtm->rtm_addrs, sa, rti_info);
 
 			if (rtm->rtm_pid == kr_state.pid) /* cause by us */
@@ -2430,16 +3099,14 @@ dispatch_rtmsg(void)
 			if (rtm->rtm_flags & RTF_LLINFO) /* arp cache */
 				continue;
 
-			connected_only = 0;
-			if (rtm->rtm_tableid != kr_state.rtableid) {
-				if (rtm->rtm_tableid == 0)
-					connected_only = 1;
-				else
-					continue;
-			}
+#if !defined(__FreeBSD__) /* FreeBSD has no rtm_tableid. */
+			if ((kt = ktable_get(rtm->rtm_tableid)) == NULL)
+#else
+			if ((kt = ktable_get(0)) == NULL)
+#endif
+				continue;
 
-			if (dispatch_rtmsg_addr(rtm, rti_info,
-			    connected_only) == -1)
+			if (dispatch_rtmsg_addr(rtm, rti_info, kt) == -1)
 				return (-1);
 			break;
 		case RTM_IFINFO:
@@ -2460,7 +3127,7 @@ dispatch_rtmsg(void)
 
 int
 dispatch_rtmsg_addr(struct rt_msghdr *rtm, struct sockaddr *rti_info[RTAX_MAX],
-    int connected_only)
+    struct ktable *kt)
 {
 	struct sockaddr		*sa;
 	struct sockaddr_in	*sa_in;
@@ -2468,7 +3135,7 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 	struct kroute_node	*kr;
 	struct kroute6_node	*kr6;
 	struct bgpd_addr	 prefix;
-	int			 flags, oflags, mpath = 0;
+	int			 flags, oflags, mpath = 0, changed = 0;
 	u_int16_t		 ifindex;
 	u_int8_t		 prefixlen;
 	u_int8_t		 prio;
@@ -2494,31 +3161,54 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
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
+#if defined(__KAME__) && defined(IPV6_LINKLOCAL_PEER)
+		if (IN6_IS_ADDR_LINKLOCAL(&prefix.v6) != 0) {
+			if (((struct sockaddr_in6 *)sa)->sin6_scope_id !=0)
+				SET_IN6_LINKLOCAL_IFINDEX(prefix.v6,
+				    ((struct sockaddr_in6 *)sa)->sin6_scope_id);
+			else
+				SET_IN6_LINKLOCAL_IFINDEX(prefix.v6,
+				    rtm->rtm_index);
+		}
+#endif              
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
@@ -2537,10 +3227,10 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 		}
 
 	if (rtm->rtm_type == RTM_DELETE) {
-		switch (prefix.af) {
-		case AF_INET:
+		switch (prefix.aid) {
+		case AID_INET:
 			sa_in = (struct sockaddr_in *)sa;
-			if ((kr = kroute_find(prefix.v4.s_addr,
+			if ((kr = kroute_find(kt, prefix.v4.s_addr,
 			    prefixlen, prio)) == NULL)
 				return (0);
 			if (!(kr->r.flags & F_KERNEL))
@@ -2554,12 +3244,12 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 					return (0);
 				}
 
-			if (kroute_remove(kr) == -1)
+			if (kroute_remove(kt, kr) == -1)
 				return (-1);
 			break;
-		case AF_INET6:
+		case AID_INET6:
 			sa_in6 = (struct sockaddr_in6 *)sa;
-			if ((kr6 = kroute6_find(&prefix.v6, prefixlen,
+			if ((kr6 = kroute6_find(kt, &prefix.v6, prefixlen,
 			    prio)) == NULL)
 				return (0);
 			if (!(kr6->r.flags & F_KERNEL))
@@ -2574,26 +3264,23 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 					return (0);
 				}
 
-			if (kroute6_remove(kr6) == -1)
+			if (kroute6_remove(kt, kr6) == -1)
 				return (-1);
 			break;
 		}
 		return (0);
 	}
 
-	if (connected_only && !(flags & F_CONNECTED))
-		return (0);
-
 	if (sa == NULL && !(flags & F_CONNECTED)) {
 		log_warnx("dispatch_rtmsg no nexthop for %s/%u",
 		    log_addr(&prefix), prefixlen);
 		return (0);
 	}
 
-	switch (prefix.af) {
-	case AF_INET:
+	switch (prefix.aid) {
+	case AID_INET:
 		sa_in = (struct sockaddr_in *)sa;
-		if ((kr = kroute_find(prefix.v4.s_addr, prefixlen,
+		if ((kr = kroute_find(kt, prefix.v4.s_addr, prefixlen,
 		    prio)) != NULL) {
 			if (kr->r.flags & F_KERNEL) {
 				/* get the correct route */
@@ -2605,30 +3292,38 @@ dispatch_rtmsg_addr(struct rt_msghdr *rt
 				} else if (mpath && rtm->rtm_type == RTM_ADD)
 					goto add4;
 
-				if (sa_in != NULL)
+				if (sa_in != NULL) {
+					if (kr->r.nexthop.s_addr !=
+					    sa_in->sin_addr.s_addr)
+						changed = 1;
 					kr->r.nexthop.s_addr =
 					    sa_in->sin_addr.s_addr;
-				else
+				} else {
+					if (kr->r.nexthop.s_addr != 0)
+						changed = 1;
 					kr->r.nexthop.s_addr = 0;
+				}
 
 				if (kr->r.flags & F_NEXTHOP)
 					flags |= F_NEXTHOP;
 				oflags = kr->r.flags;
+				if (flags != oflags)
+					changed = 1;
 				kr->r.flags = flags;
 				if ((oflags & F_CONNECTED) &&
 				    !(flags & F_CONNECTED)) {
 					kif_kr_remove(kr);
 					kr_redistribute(IMSG_NETWORK_REMOVE,
-					    &kr->r);
+					    kt, &kr->r);
 				}
 				if ((flags & F_CONNECTED) &&
 				    !(oflags & F_CONNECTED)) {
 					kif_kr_insert(kr);
 					kr_redistribute(IMSG_NETWORK_ADD,
-					    &kr->r);
+					    kt, &kr->r);
 				}
-				if (kr->r.flags & F_NEXTHOP)
-					knexthop_track(kr);
+				if (kr->r.flags & F_NEXTHOP && changed)
+					knexthop_track(kt, kr);
 			}
 		} else if (rtm->rtm_type == RTM_CHANGE) {
 			log_warnx("change req for %s/%u: not in table",
@@ -2651,50 +3346,62 @@ add4:
 			kr->r.ifindex = ifindex;
 			kr->r.priority = prio;
 
-			kroute_insert(kr);
+			kroute_insert(kt, kr);
 		}
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		sa_in6 = (struct sockaddr_in6 *)sa;
-		if ((kr6 = kroute6_find(&prefix.v6, prefixlen, prio)) != NULL) {
+		if ((kr6 = kroute6_find(kt, &prefix.v6, prefixlen, prio)) !=
+		    NULL) {
 			if (kr6->r.flags & F_KERNEL) {
 				/* get the correct route */
 				if (mpath && rtm->rtm_type == RTM_CHANGE &&
 				    (kr6 = kroute6_matchgw(kr6, sa_in6)) ==
 				    NULL) {
 					log_warnx("dispatch_rtmsg[change] "
-					    "mpath route not found");
+					    "IPv6 mpath route not found");
 					return (-1);
 				} else if (mpath && rtm->rtm_type == RTM_ADD)
 					goto add6;
 
-				if (sa_in6 != NULL)
+				if (sa_in6 != NULL) {
+					if (memcmp(&kr6->r.nexthop,
+					    &sa_in6->sin6_addr,
+					    sizeof(struct in6_addr)))
+						changed = 1;
 					memcpy(&kr6->r.nexthop,
 					    &sa_in6->sin6_addr,
 					    sizeof(struct in6_addr));
-				else
+				} else {
+					if (memcmp(&kr6->r.nexthop,
+					    &in6addr_any,
+					    sizeof(struct in6_addr)))
+						changed = 1;
 					memcpy(&kr6->r.nexthop,
 					    &in6addr_any,
 					    sizeof(struct in6_addr));
+				}
 
 				if (kr6->r.flags & F_NEXTHOP)
 					flags |= F_NEXTHOP;
 				oflags = kr6->r.flags;
+				if (flags != oflags)
+					changed = 1;
 				kr6->r.flags = flags;
 				if ((oflags & F_CONNECTED) &&
 				    !(flags & F_CONNECTED)) {
 					kif_kr6_remove(kr6);
 					kr_redistribute6(IMSG_NETWORK_REMOVE,
-					    &kr6->r);
+					    kt, &kr6->r);
 				}
 				if ((flags & F_CONNECTED) &&
 				    !(oflags & F_CONNECTED)) {
 					kif_kr6_insert(kr6);
 					kr_redistribute6(IMSG_NETWORK_ADD,
-					    &kr6->r);
+					    kt, &kr6->r);
 				}
-				if (kr6->r.flags & F_NEXTHOP)
-					knexthop_track(kr6);
+				if (kr6->r.flags & F_NEXTHOP && changed)
+					knexthop_track(kt, kr6);
 			}
 		} else if (rtm->rtm_type == RTM_CHANGE) {
 			log_warnx("change req for %s/%u: not in table",
@@ -2719,8 +3426,12 @@ add6:
 			kr6->r.flags = flags;
 			kr6->r.ifindex = ifindex;
 			kr6->r.priority = prio;
-
-			kroute6_insert(kr6);
+#if defined(__KAME__) && defined(IPV6_LINKLOCAL_PEER)
+			if (IN6_IS_ADDR_LINKLOCAL(&kr6->r.nexthop))
+				SET_IN6_LINKLOCAL_IFINDEX(kr6->r.nexthop,
+				    ifindex);
+#endif
+			kroute6_insert(kt, kr6);
 		}
 		break;
 	}
