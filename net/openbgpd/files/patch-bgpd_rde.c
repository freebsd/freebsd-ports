Index: bgpd/rde.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde.c,v
retrieving revision 1.1.1.8
retrieving revision 1.12
diff -u -p -r1.1.1.8 -r1.12
--- bgpd/rde.c	14 Feb 2010 20:19:57 -0000	1.1.1.8
+++ bgpd/rde.c	16 May 2014 00:36:26 -0000	1.12
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde.c,v 1.264 2009/06/29 12:22:16 claudio Exp $ */
+/*	$OpenBSD: rde.c,v 1.320 2012/09/18 09:45:51 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -18,10 +18,11 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 
 #include <errno.h>
 #include <ifaddrs.h>
-#include <limits.h>
 #include <pwd.h>
 #include <poll.h>
 #include <signal.h>
@@ -50,13 +51,18 @@ void		 rde_update_withdraw(struct rde_pe
 		     u_int8_t);
 int		 rde_attr_parse(u_char *, u_int16_t, struct rde_peer *,
 		     struct rde_aspath *, struct mpattr *);
+int		 rde_attr_add(struct rde_aspath *, u_char *, u_int16_t);
 u_int8_t	 rde_attr_missing(struct rde_aspath *, int, u_int16_t);
-int		 rde_get_mp_nexthop(u_char *, u_int16_t, u_int16_t,
-		     struct rde_aspath *);
+int		 rde_get_mp_nexthop(u_char *, u_int16_t, u_int8_t,
+		     struct rde_aspath *, struct rde_peer *);
+int		 rde_update_extract_prefix(u_char *, u_int16_t, void *,
+		     u_int8_t, u_int8_t);
 int		 rde_update_get_prefix(u_char *, u_int16_t, struct bgpd_addr *,
 		     u_int8_t *);
 int		 rde_update_get_prefix6(u_char *, u_int16_t, struct bgpd_addr *,
 		     u_int8_t *);
+int		 rde_update_get_vpn4(u_char *, u_int16_t, struct bgpd_addr *,
+		     u_int8_t *);
 void		 rde_update_err(struct rde_peer *, u_int8_t , u_int8_t,
 		     void *, u_int16_t);
 void		 rde_update_log(const char *, u_int16_t,
@@ -78,11 +84,15 @@ void		 rde_dump_ctx_new(struct ctl_show_
 void		 rde_dump_mrt_new(struct mrt *, pid_t, int);
 void		 rde_dump_done(void *);
 
+int		 rde_rdomain_import(struct rde_aspath *, struct rdomain *);
 void		 rde_up_dump_upcall(struct rib_entry *, void *);
 void		 rde_softreconfig_out(struct rib_entry *, void *);
 void		 rde_softreconfig_in(struct rib_entry *, void *);
+void		 rde_softreconfig_load(struct rib_entry *, void *);
+void		 rde_softreconfig_load_peer(struct rib_entry *, void *);
+void		 rde_softreconfig_unload_peer(struct rib_entry *, void *);
 void		 rde_update_queue_runner(void);
-void		 rde_update6_queue_runner(void);
+void		 rde_update6_queue_runner(u_int8_t);
 
 void		 peer_init(u_int32_t);
 void		 peer_shutdown(void);
@@ -91,10 +101,12 @@ struct rde_peer	*peer_add(u_int32_t, str
 struct rde_peer	*peer_get(u_int32_t);
 void		 peer_up(u_int32_t, struct session_up *);
 void		 peer_down(u_int32_t);
-void		 peer_dump(u_int32_t, u_int16_t, u_int8_t);
-void		 peer_send_eor(struct rde_peer *, u_int16_t, u_int16_t);
+void		 peer_flush(struct rde_peer *, u_int8_t);
+void		 peer_stale(u_int32_t, u_int8_t);
+void		 peer_recv_eor(struct rde_peer *, u_int8_t);
+void		 peer_dump(u_int32_t, u_int8_t);
+void		 peer_send_eor(struct rde_peer *, u_int8_t);
 
-void		 network_init(struct network_head *);
 void		 network_add(struct network_config *, int);
 void		 network_delete(struct network_config *, int);
 void		 network_dump_upcall(struct rib_entry *, void *);
@@ -108,6 +120,7 @@ time_t			 reloadtime;
 struct rde_peer_head	 peerlist;
 struct rde_peer		*peerself;
 struct filter_head	*rules_l, *newrules;
+struct rdomain_head	*rdomains_l, *newdomains;
 struct imsgbuf		*ibuf_se;
 struct imsgbuf		*ibuf_se_ctl;
 struct imsgbuf		*ibuf_main;
@@ -120,11 +133,12 @@ struct rde_dump_ctx {
 };
 
 struct rde_mrt_ctx {
-	struct mrt		 mrt;
-	struct rib_context	 ribctx;
+	struct mrt		mrt;
+	struct rib_context	ribctx;
+	LIST_ENTRY(rde_mrt_ctx)	entry;
 };
 
-struct mrt_head rde_mrts = LIST_HEAD_INITIALIZER(rde_mrts);
+LIST_HEAD(, rde_mrt_ctx) rde_mrts = LIST_HEAD_INITIALIZER(rde_mrts);
 u_int rde_mrt_cnt;
 
 void
@@ -144,24 +158,17 @@ u_int32_t	attrhashsize = 512;
 u_int32_t	nexthophashsize = 64;
 
 pid_t
-rde_main(struct bgpd_config *config, struct peer *peer_l,
-    struct network_head *net_l, struct filter_head *rules,
-    struct mrt_head *mrt_l, struct rib_names *rib_n, int pipe_m2r[2],
-    int pipe_s2r[2], int pipe_m2s[2], int pipe_s2rctl[2], int debug)
+rde_main(int pipe_m2r[2], int pipe_s2r[2], int pipe_m2s[2], int pipe_s2rctl[2],
+    int debug)
 {
 	pid_t			 pid;
 	struct passwd		*pw;
-	struct peer		*p;
-	struct listen_addr	*la;
 	struct pollfd		*pfd = NULL;
-	struct filter_rule	*f;
-	struct filter_set	*set;
-	struct nexthop		*nh;
-	struct rde_rib		*rr;
-	struct mrt		*mrt, *xmrt;
+	struct rde_mrt_ctx	*mctx, *xmctx;
 	void			*newp;
 	u_int			 pfd_elms = 0, i, j;
 	int			 timeout;
+	u_int8_t		 aid;
 
 	switch (pid = fork()) {
 	case -1:
@@ -172,8 +179,6 @@ rde_main(struct bgpd_config *config, str
 		return (pid);
 	}
 
-	conf = config;
-
 	if ((pw = getpwnam(BGPD_USER)) == NULL)
 		fatal("getpwnam");
 
@@ -194,6 +199,8 @@ rde_main(struct bgpd_config *config, str
 	signal(SIGINT, rde_sighdlr);
 	signal(SIGPIPE, SIG_IGN);
 	signal(SIGHUP, SIG_IGN);
+	signal(SIGALRM, SIG_IGN);
+	signal(SIGUSR1, SIG_IGN);
 
 	close(pipe_s2r[0]);
 	close(pipe_s2rctl[0]);
@@ -210,50 +217,25 @@ rde_main(struct bgpd_config *config, str
 	imsg_init(ibuf_se_ctl, pipe_s2rctl[1]);
 	imsg_init(ibuf_main, pipe_m2r[1]);
 
-	/* peer list, mrt list and listener list are not used in the RDE */
-	while ((p = peer_l) != NULL) {
-		peer_l = p->next;
-		free(p);
-	}
-
-	while ((mrt = LIST_FIRST(mrt_l)) != NULL) {
-		LIST_REMOVE(mrt, entry);
-		free(mrt);
-	}
-
-	while ((la = TAILQ_FIRST(config->listen_addrs)) != NULL) {
-		TAILQ_REMOVE(config->listen_addrs, la, entry);
-		close(la->fd);
-		free(la);
-	}
-	free(config->listen_addrs);
-
 	pt_init();
-	while ((rr = SIMPLEQ_FIRST(&ribnames))) {
-		SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
-		rib_new(-1, rr->name, rr->flags);
-		free(rr);
-	}
 	path_init(pathhashsize);
 	aspath_init(pathhashsize);
 	attr_init(attrhashsize);
 	nexthop_init(nexthophashsize);
 	peer_init(peerhashsize);
-	rules_l = rules;
-	network_init(net_l);
 
+	rules_l = calloc(1, sizeof(struct filter_head));
+	if (rules_l == NULL)
+		fatal(NULL);
+	TAILQ_INIT(rules_l);
+	rdomains_l = calloc(1, sizeof(struct rdomain_head));
+	if (rdomains_l == NULL)
+		fatal(NULL);
+	SIMPLEQ_INIT(rdomains_l);
+	if ((conf = calloc(1, sizeof(struct bgpd_config))) == NULL)
+		fatal(NULL);
 	log_info("route decision engine ready");
 
-	TAILQ_FOREACH(f, rules, entry) {
-		f->peer.ribid = rib_find(f->rib);
-		TAILQ_FOREACH(set, &f->set, entry) {
-			if (set->type == ACTION_SET_NEXTHOP) {
-				nh = nexthop_get(&set->action.nexthop);
-				nh->refcnt++;
-			}
-		}
-	}
-
 	while (rde_quit == 0) {
 		if (pfd_elms < PFD_PIPE_COUNT + rde_mrt_cnt) {
 			if ((newp = realloc(pfd, sizeof(struct pollfd) *
@@ -287,11 +269,18 @@ rde_main(struct bgpd_config *config, str
 			timeout = 0;
 
 		i = PFD_PIPE_COUNT;
-		LIST_FOREACH(mrt, &rde_mrts, entry) {
-			if (mrt->wbuf.queued) {
-				pfd[i].fd = mrt->wbuf.fd;
+		for (mctx = LIST_FIRST(&rde_mrts); mctx != 0; mctx = xmctx) {
+			xmctx = LIST_NEXT(mctx, entry);
+			if (mctx->mrt.wbuf.queued) {
+				pfd[i].fd = mctx->mrt.wbuf.fd;
 				pfd[i].events = POLLOUT;
 				i++;
+			} else if (mctx->mrt.state == MRT_STATE_REMOVE) {
+				close(mctx->mrt.wbuf.fd);
+				LIST_REMOVE(&mctx->ribctx, entry);
+				LIST_REMOVE(mctx, entry);
+				free(mctx);
+				rde_mrt_cnt--;
 			}
 		}
 
@@ -325,24 +314,17 @@ rde_main(struct bgpd_config *config, str
 		if (pfd[PFD_PIPE_SESSION_CTL].revents & POLLIN)
 			rde_dispatch_imsg_session(ibuf_se_ctl);
 
-		for (j = PFD_PIPE_COUNT, mrt = LIST_FIRST(&rde_mrts);
-		    j < i && mrt != 0; j++) {
-			xmrt = LIST_NEXT(mrt, entry);
-			if (pfd[j].fd == mrt->wbuf.fd &&
+		for (j = PFD_PIPE_COUNT, mctx = LIST_FIRST(&rde_mrts);
+		    j < i && mctx != 0; j++) {
+			if (pfd[j].fd == mctx->mrt.wbuf.fd &&
 			    pfd[j].revents & POLLOUT)
-				mrt_write(mrt);
-			if (mrt->wbuf.queued == 0 && 
-			    mrt->state == MRT_STATE_REMOVE) {
-				close(mrt->wbuf.fd);
-				LIST_REMOVE(mrt, entry);
-				free(mrt);
-				rde_mrt_cnt--;
-			}
-			mrt = xmrt;
+				mrt_write(&mctx->mrt);
+			mctx = LIST_NEXT(mctx, entry);
 		}
 
 		rde_update_queue_runner();
-		rde_update6_queue_runner();
+		for (aid = AID_INET6; aid < AID_MAX; aid++)
+			rde_update6_queue_runner(aid);
 		if (ibuf_se_ctl->w.queued <= 0)
 			rib_dump_runner();
 	}
@@ -351,11 +333,12 @@ rde_main(struct bgpd_config *config, str
 	if (debug)
 		rde_shutdown();
 
-	while ((mrt = LIST_FIRST(&rde_mrts)) != NULL) {
-		msgbuf_clear(&mrt->wbuf);
-		close(mrt->wbuf.fd);
-		LIST_REMOVE(mrt, entry);
-		free(mrt);
+	while ((mctx = LIST_FIRST(&rde_mrts)) != NULL) {
+		msgbuf_clear(&mctx->mrt.wbuf);
+		close(mctx->mrt.wbuf.fd);
+		LIST_REMOVE(&mctx->ribctx, entry);
+		LIST_REMOVE(mctx, entry);
+		free(mctx);
 	}
 
 	msgbuf_clear(&ibuf_se->w);
@@ -378,13 +361,18 @@ rde_dispatch_imsg_session(struct imsgbuf
 	struct imsg		 imsg;
 	struct peer		 p;
 	struct peer_config	 pconf;
-	struct rrefresh		 r;
-	struct rde_peer		*peer;
 	struct session_up	 sup;
+	struct ctl_show_rib	 csr;
 	struct ctl_show_rib_request	req;
+	struct rde_peer		*peer;
+	struct rde_aspath	*asp;
 	struct filter_set	*s;
 	struct nexthop		*nh;
-	int			 n;
+	u_int8_t		*asdata;
+	ssize_t			 n;
+	int			 verbose;
+	u_int16_t		 len;
+	u_int8_t		 aid;
 
 	if ((n = imsg_read(ibuf)) == -1)
 		fatal("rde_dispatch_imsg_session: imsg_read error");
@@ -422,13 +410,56 @@ rde_dispatch_imsg_session(struct imsgbuf
 		case IMSG_SESSION_DOWN:
 			peer_down(imsg.hdr.peerid);
 			break;
+		case IMSG_SESSION_STALE:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE != sizeof(aid)) {
+				log_warnx("rde_dispatch: wrong imsg len");
+				break;
+			}
+			memcpy(&aid, imsg.data, sizeof(aid));
+			if (aid >= AID_MAX)
+				fatalx("IMSG_SESSION_STALE: bad AID");
+			peer_stale(imsg.hdr.peerid, aid);
+			break;
+		case IMSG_SESSION_FLUSH:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE != sizeof(aid)) {
+				log_warnx("rde_dispatch: wrong imsg len");
+				break;
+			}
+			memcpy(&aid, imsg.data, sizeof(aid));
+			if (aid >= AID_MAX)
+				fatalx("IMSG_SESSION_FLUSH: bad AID");
+			if ((peer = peer_get(imsg.hdr.peerid)) == NULL) {
+				log_warnx("rde_dispatch: unknown peer id %d",
+				    imsg.hdr.peerid);
+				break;
+			}
+			peer_flush(peer, aid);
+			break;
+		case IMSG_SESSION_RESTARTED:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE != sizeof(aid)) {
+				log_warnx("rde_dispatch: wrong imsg len");
+				break;
+			}
+			memcpy(&aid, imsg.data, sizeof(aid));
+			if (aid >= AID_MAX)
+				fatalx("IMSG_SESSION_RESTARTED: bad AID");
+			if ((peer = peer_get(imsg.hdr.peerid)) == NULL) {
+				log_warnx("rde_dispatch: unknown peer id %d",
+				    imsg.hdr.peerid);
+				break;
+			}
+			if (peer->staletime[aid])
+				peer_flush(peer, aid);
+			break;
 		case IMSG_REFRESH:
-			if (imsg.hdr.len - IMSG_HEADER_SIZE != sizeof(r)) {
+			if (imsg.hdr.len - IMSG_HEADER_SIZE != sizeof(aid)) {
 				log_warnx("rde_dispatch: wrong imsg len");
 				break;
 			}
-			memcpy(&r, imsg.data, sizeof(r));
-			peer_dump(imsg.hdr.peerid, r.afi, r.safi);
+			memcpy(&aid, imsg.data, sizeof(aid));
+			if (aid >= AID_MAX)
+				fatalx("IMSG_REFRESH: bad AID");
+			peer_dump(imsg.hdr.peerid, aid);
 			break;
 		case IMSG_NETWORK_ADD:
 			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
@@ -440,23 +471,68 @@ rde_dispatch_imsg_session(struct imsgbuf
 			TAILQ_INIT(&netconf_s.attrset);
 			session_set = &netconf_s.attrset;
 			break;
+		case IMSG_NETWORK_ASPATH:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE <
+			    sizeof(struct ctl_show_rib)) {
+				log_warnx("rde_dispatch: wrong imsg len");
+				bzero(&netconf_s, sizeof(netconf_s));
+				break;
+			}
+			asdata = imsg.data;
+			asdata += sizeof(struct ctl_show_rib);
+			memcpy(&csr, imsg.data, sizeof(csr));
+			if (csr.aspath_len + sizeof(csr) > imsg.hdr.len -
+			    IMSG_HEADER_SIZE) {
+				log_warnx("rde_dispatch: wrong aspath len");
+				bzero(&netconf_s, sizeof(netconf_s));
+				break;
+			}
+			asp = path_get();
+			asp->lpref = csr.local_pref;
+			asp->med = csr.med;
+			asp->weight = csr.weight;
+			asp->flags = csr.flags;
+			asp->origin = csr.origin;
+			asp->flags |= F_PREFIX_ANNOUNCED | F_ANN_DYNAMIC;
+			asp->aspath = aspath_get(asdata, csr.aspath_len);
+			netconf_s.asp = asp;
+			break;
+		case IMSG_NETWORK_ATTR:
+			if (imsg.hdr.len <= IMSG_HEADER_SIZE) {
+				log_warnx("rde_dispatch: wrong imsg len");
+				break;
+			}
+			/* parse path attributes */
+			len = imsg.hdr.len - IMSG_HEADER_SIZE;
+			asp = netconf_s.asp;
+			if (rde_attr_add(asp, imsg.data, len) == -1) {
+				log_warnx("rde_dispatch: bad network "
+				    "attribute");
+				path_put(asp);
+				bzero(&netconf_s, sizeof(netconf_s));
+				break;
+			}
+			break;
 		case IMSG_NETWORK_DONE:
 			if (imsg.hdr.len != IMSG_HEADER_SIZE) {
 				log_warnx("rde_dispatch: wrong imsg len");
 				break;
 			}
 			session_set = NULL;
-			switch (netconf_s.prefix.af) {
-			case AF_INET:
+			switch (netconf_s.prefix.aid) {
+			case AID_INET:
 				if (netconf_s.prefixlen > 32)
 					goto badnet;
 				network_add(&netconf_s, 0);
 				break;
-			case AF_INET6:
+			case AID_INET6:
 				if (netconf_s.prefixlen > 128)
 					goto badnet;
 				network_add(&netconf_s, 0);
 				break;
+			case 0:
+				/* something failed beforehands */
+				break;
 			default:
 badnet:
 				log_warnx("rde_dispatch: bad network");
@@ -528,10 +604,14 @@ badnet:
 				    peer->prefix_rcvd_update;
 				p.stats.prefix_rcvd_withdraw =
 				    peer->prefix_rcvd_withdraw;
+				p.stats.prefix_rcvd_eor =
+				    peer->prefix_rcvd_eor;
 				p.stats.prefix_sent_update =
 				    peer->prefix_sent_update;
 				p.stats.prefix_sent_withdraw =
 				    peer->prefix_sent_withdraw;
+				p.stats.prefix_sent_eor =
+				    peer->prefix_sent_eor;
 			}
 			imsg_compose(ibuf_se_ctl, IMSG_CTL_SHOW_NEIGHBOR, 0,
 			    imsg.hdr.pid, -1, &p, sizeof(struct peer));
@@ -544,6 +624,11 @@ badnet:
 			imsg_compose(ibuf_se_ctl, IMSG_CTL_SHOW_RIB_MEM, 0,
 			    imsg.hdr.pid, -1, &rdemem, sizeof(rdemem));
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			/* already checked by SE */
+			memcpy(&verbose, imsg.data, sizeof(verbose));
+			log_verbose(verbose);
+			break;
 		default:
 			break;
 		}
@@ -554,14 +639,17 @@ badnet:
 void
 rde_dispatch_imsg_parent(struct imsgbuf *ibuf)
 {
+	static struct rdomain	*rd;
 	struct imsg		 imsg;
 	struct mrt		 xmrt;
 	struct rde_rib		 rn;
 	struct rde_peer		*peer;
+	struct peer_config	*pconf;
 	struct filter_rule	*r;
 	struct filter_set	*s;
 	struct nexthop		*nh;
-	int			 n, fd, reconf_in = 0, reconf_out = 0;
+	int			 n, fd, reconf_in = 0, reconf_out = 0,
+				 reconf_rib = 0;
 	u_int16_t		 rid;
 
 	if ((n = imsg_read(ibuf)) == -1)
@@ -576,20 +664,12 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			break;
 
 		switch (imsg.hdr.type) {
-		case IMSG_RECONF_CONF:
-			reloadtime = time(NULL);
-			newrules = calloc(1, sizeof(struct filter_head));
-			if (newrules == NULL)
-				fatal(NULL);
-			TAILQ_INIT(newrules);
-			if ((nconf = malloc(sizeof(struct bgpd_config))) ==
-			    NULL)
-				fatal(NULL);
-			memcpy(nconf, imsg.data, sizeof(struct bgpd_config));
-			for (rid = 0; rid < rib_size; rid++)
-				ribs[rid].state = RIB_DELETE;
-			break;
 		case IMSG_NETWORK_ADD:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
+			    sizeof(struct network_config)) {
+				log_warnx("rde_dispatch: wrong imsg len");
+				break;
+			}
 			memcpy(&netconf_p, imsg.data, sizeof(netconf_p));
 			TAILQ_INIT(&netconf_p.attrset);
 			parent_set = &netconf_p.attrset;
@@ -608,6 +688,26 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			TAILQ_INIT(&netconf_p.attrset);
 			network_delete(&netconf_p, 1);
 			break;
+		case IMSG_RECONF_CONF:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
+			    sizeof(struct bgpd_config))
+				fatalx("IMSG_RECONF_CONF bad len");
+			reloadtime = time(NULL);
+			newrules = calloc(1, sizeof(struct filter_head));
+			if (newrules == NULL)
+				fatal(NULL);
+			TAILQ_INIT(newrules);
+			newdomains = calloc(1, sizeof(struct rdomain_head));
+			if (newdomains == NULL)
+				fatal(NULL);
+			SIMPLEQ_INIT(newdomains);
+			if ((nconf = malloc(sizeof(struct bgpd_config))) ==
+			    NULL)
+				fatal(NULL);
+			memcpy(nconf, imsg.data, sizeof(struct bgpd_config));
+			for (rid = 0; rid < rib_size; rid++)
+				ribs[rid].state = RECONF_DELETE;
+			break;
 		case IMSG_RECONF_RIB:
 			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
 			    sizeof(struct rde_rib))
@@ -615,9 +715,26 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			memcpy(&rn, imsg.data, sizeof(rn));
 			rid = rib_find(rn.name);
 			if (rid == RIB_FAILED)
-				rib_new(-1, rn.name, rn.flags);
-			else
-				ribs[rid].state = RIB_ACTIVE;
+				rib_new(rn.name, rn.rtableid, rn.flags);
+			else if (ribs[rid].rtableid != rn.rtableid ||
+			    (ribs[rid].flags & F_RIB_HASNOFIB) !=
+			    (rn.flags & F_RIB_HASNOFIB)) {
+				/* Big hammer in the F_RIB_NOFIB case but
+				 * not often enough used to optimise it more. */
+				rib_free(&ribs[rid]);
+				rib_new(rn.name, rn.rtableid, rn.flags);
+			} else
+				ribs[rid].state = RECONF_KEEP;
+			break;
+		case IMSG_RECONF_PEER:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
+			    sizeof(struct peer_config))
+				fatalx("IMSG_RECONF_PEER bad len");
+			if ((peer = peer_get(imsg.hdr.peerid)) == NULL)
+				break;
+			pconf = imsg.data;
+			strlcpy(peer->conf.rib, pconf->rib,
+			    sizeof(peer->conf.rib));
 			break;
 		case IMSG_RECONF_FILTER:
 			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
@@ -631,12 +748,42 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			parent_set = &r->set;
 			TAILQ_INSERT_TAIL(newrules, r, entry);
 			break;
+		case IMSG_RECONF_RDOMAIN:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
+			    sizeof(struct rdomain))
+				fatalx("IMSG_RECONF_RDOMAIN bad len");
+			if ((rd = malloc(sizeof(struct rdomain))) == NULL)
+				fatal(NULL);
+			memcpy(rd, imsg.data, sizeof(struct rdomain));
+			TAILQ_INIT(&rd->import);
+			TAILQ_INIT(&rd->export);
+			SIMPLEQ_INSERT_TAIL(newdomains, rd, entry);
+			break;
+		case IMSG_RECONF_RDOMAIN_EXPORT:
+			if (rd == NULL) {
+				log_warnx("rde_dispatch_imsg_parent: "
+				    "IMSG_RECONF_RDOMAIN_EXPORT unexpected");
+				break;
+			}
+			parent_set = &rd->export;
+			break;
+		case IMSG_RECONF_RDOMAIN_IMPORT:
+			if (rd == NULL) {
+				log_warnx("rde_dispatch_imsg_parent: "
+				    "IMSG_RECONF_RDOMAIN_IMPORT unexpected");
+				break;
+			}
+			parent_set = &rd->import;
+			break;
+		case IMSG_RECONF_RDOMAIN_DONE:
+			parent_set = NULL;
+			break;
 		case IMSG_RECONF_DONE:
 			if (nconf == NULL)
 				fatalx("got IMSG_RECONF_DONE but no config");
 			if ((nconf->flags & BGPD_FLAG_NO_EVALUATE)
 			    != (conf->flags & BGPD_FLAG_NO_EVALUATE)) {
-				log_warnx( "change to/from route-collector "
+				log_warnx("change to/from route-collector "
 				    "mode ignored");
 				if (conf->flags & BGPD_FLAG_NO_EVALUATE)
 					nconf->flags |= BGPD_FLAG_NO_EVALUATE;
@@ -644,10 +791,27 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 					nconf->flags &= ~BGPD_FLAG_NO_EVALUATE;
 			}
 			memcpy(conf, nconf, sizeof(struct bgpd_config));
+			conf->listen_addrs = NULL;
+			conf->csock = NULL;
+			conf->rcsock = NULL;
 			free(nconf);
 			nconf = NULL;
 			parent_set = NULL;
-			prefix_network_clean(peerself, reloadtime, 0);
+			/* sync peerself with conf */
+			peerself->remote_bgpid = ntohl(conf->bgpid);
+			peerself->conf.local_as = conf->as;
+			peerself->conf.remote_as = conf->as;
+			peerself->short_as = conf->short_as;
+
+			/* apply new set of rdomain, sync will be done later */
+			while ((rd = SIMPLEQ_FIRST(rdomains_l)) != NULL) {
+				SIMPLEQ_REMOVE_HEAD(rdomains_l, entry);
+				filterset_free(&rd->import);
+				filterset_free(&rd->export);
+				free(rd);
+			}
+			free(rdomains_l);
+			rdomains_l = newdomains;
 
 			/* check if filter changed */
 			LIST_FOREACH(peer, &peerlist, peer_l) {
@@ -655,30 +819,59 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 					continue;
 				peer->reconf_out = 0;
 				peer->reconf_in = 0;
-				if (peer->conf.softreconfig_out &&
-				    !rde_filter_equal(rules_l, newrules, peer,
-				    DIR_OUT)) {
-					peer->reconf_out = 1;
-					reconf_out = 1;
-				}
+				peer->reconf_rib = 0;
 				if (peer->conf.softreconfig_in &&
 				    !rde_filter_equal(rules_l, newrules, peer,
 				    DIR_IN)) {
 					peer->reconf_in = 1;
 					reconf_in = 1;
 				}
+				if (peer->ribid != rib_find(peer->conf.rib)) {
+					rib_dump(&ribs[peer->ribid],
+					    rde_softreconfig_unload_peer, peer,
+					    AID_UNSPEC);
+					peer->ribid = rib_find(peer->conf.rib);
+					peer->reconf_rib = 1;
+					reconf_rib = 1;
+					continue;
+				}
+				if (peer->conf.softreconfig_out &&
+				    !rde_filter_equal(rules_l, newrules, peer,
+				    DIR_OUT)) {
+					peer->reconf_out = 1;
+					reconf_out = 1;
+				}
 			}
-			/* XXX this needs rework anyway */
-			/* sync local-RIB first */
+			/* bring ribs in sync before softreconfig dance */
+			for (rid = 0; rid < rib_size; rid++) {
+				if (ribs[rid].state == RECONF_DELETE)
+					rib_free(&ribs[rid]);
+				else if (ribs[rid].state == RECONF_REINIT)
+					rib_dump(&ribs[0],
+					    rde_softreconfig_load, &ribs[rid],
+					    AID_UNSPEC);
+			}
+			/* sync local-RIBs first */
 			if (reconf_in)
 				rib_dump(&ribs[0], rde_softreconfig_in, NULL,
-				    AF_UNSPEC);
+				    AID_UNSPEC);
 			/* then sync peers */
 			if (reconf_out) {
 				int i;
-				for (i = 1; i < rib_size; i++)
+				for (i = 1; i < rib_size; i++) {
+					if (ribs[i].state == RECONF_REINIT)
+						/* already synced by _load */
+						continue;
 					rib_dump(&ribs[i], rde_softreconfig_out,
-					    NULL, AF_UNSPEC);
+					    NULL, AID_UNSPEC);
+				}
+			}
+			if (reconf_rib) {
+				LIST_FOREACH(peer, &peerlist, peer_l) {
+					rib_dump(&ribs[peer->ribid],
+						rde_softreconfig_load_peer,
+						peer, AID_UNSPEC);
+				}
 			}
 
 			while ((r = TAILQ_FIRST(rules_l)) != NULL) {
@@ -688,16 +881,18 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			}
 			free(rules_l);
 			rules_l = newrules;
-			for (rid = 0; rid < rib_size; rid++) {
-				if (ribs[rid].state == RIB_DELETE)
-					rib_free(&ribs[rid]);
-			}
+
 			log_info("RDE reconfigured");
+			imsg_compose(ibuf_main, IMSG_RECONF_DONE, 0, 0,
+			    -1, NULL, 0);
 			break;
 		case IMSG_NEXTHOP_UPDATE:
 			nexthop_update(imsg.data);
 			break;
 		case IMSG_FILTER_SET:
+			if (imsg.hdr.len > IMSG_HEADER_SIZE +
+			    sizeof(struct filter_set))
+				fatalx("IMSG_RECONF_CONF bad len");
 			if (parent_set == NULL) {
 				log_warnx("rde_dispatch_imsg_parent: "
 				    "IMSG_FILTER_SET unexpected");
@@ -725,7 +920,8 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 				log_warnx("expected to receive fd for mrt dump "
 				    "but didn't receive any");
 			else if (xmrt.type == MRT_TABLE_DUMP ||
-			    xmrt.type == MRT_TABLE_DUMP_MP) {
+			    xmrt.type == MRT_TABLE_DUMP_MP ||
+			    xmrt.type == MRT_TABLE_DUMP_V2) {
 				rde_dump_mrt_new(&xmrt, imsg.hdr.pid, fd);
 			} else
 				close(fd);
@@ -744,6 +940,8 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 int
 rde_update_dispatch(struct imsg *imsg)
 {
+	struct bgpd_addr	 prefix;
+	struct mpattr		 mpa;
 	struct rde_peer		*peer;
 	struct rde_aspath	*asp = NULL;
 	u_char			*p, *mpp = NULL;
@@ -752,9 +950,8 @@ rde_update_dispatch(struct imsg *imsg)
 	u_int16_t		 withdrawn_len;
 	u_int16_t		 attrpath_len;
 	u_int16_t		 nlri_len;
-	u_int8_t		 prefixlen, safi, subtype;
-	struct bgpd_addr	 prefix;
-	struct mpattr		 mpa;
+	u_int8_t		 aid, prefixlen, safi, subtype;
+	u_int32_t		 fas;
 
 	peer = peer_get(imsg->hdr.peerid);
 	if (peer == NULL)	/* unknown peer, cannot happen */
@@ -810,26 +1007,21 @@ rde_update_dispatch(struct imsg *imsg)
 			goto done;
 		}
 
-		/*
-		 * if either ATTR_AS4_AGGREGATOR or ATTR_AS4_PATH is present
-		 * try to fixup the attributes.
-		 * XXX do not fixup if F_ATTR_LOOP is set.
-		 */
-		if (asp->flags & F_ATTR_AS4BYTE_NEW &&
-		    !(asp->flags & F_ATTR_LOOP))
-			rde_as4byte_fixup(peer, asp);
+		rde_as4byte_fixup(peer, asp);
 
 		/* enforce remote AS if requested */
 		if (asp->flags & F_ATTR_ASPATH &&
-		    peer->conf.enforce_as == ENFORCE_AS_ON)
-			if (peer->conf.remote_as !=
-			    aspath_neighbor(asp->aspath)) {
-				log_peer_warnx(&peer->conf, "bad path, "
-				    "enforce remote-as enabled");
-				rde_update_err(peer, ERR_UPDATE, ERR_UPD_ASPATH,
+		    peer->conf.enforce_as == ENFORCE_AS_ON) {
+			fas = aspath_neighbor(asp->aspath);
+			if (peer->conf.remote_as != fas) {
+			    log_peer_warnx(&peer->conf, "bad path, "
+				"starting with %s, "
+				"enforce neighbor-as enabled", log_as(fas));
+			    rde_update_err(peer, ERR_UPDATE, ERR_UPD_ASPATH,
 				    NULL, 0);
-				goto done;
+			    goto done;
 			}
+		}
 
 		rde_reflector(peer, asp);
 	}
@@ -860,9 +1052,9 @@ rde_update_dispatch(struct imsg *imsg)
 		p += pos;
 		len -= pos;
 
-		if (peer->capa_received.mp_v4 == SAFI_NONE &&
-		    peer->capa_received.mp_v6 != SAFI_NONE) {
-			log_peer_warnx(&peer->conf, "bad AFI, IPv4 disabled");
+		if (peer->capa.mp[AID_INET] == 0) {
+			log_peer_warnx(&peer->conf,
+			    "bad withdraw, %s disabled", aid2str(AID_INET));
 			rde_update_err(peer, ERR_UPDATE, ERR_UPD_OPTATTR,
 			    NULL, 0);
 			goto done;
@@ -879,6 +1071,10 @@ rde_update_dispatch(struct imsg *imsg)
 			    ERR_UPD_ATTRLIST, NULL, 0);
 			return (-1);
 		}
+		if (withdrawn_len == 0) {
+			/* EoR marker */
+			peer_recv_eor(peer, AID_INET);
+		}
 		return (0);
 	}
 
@@ -892,15 +1088,30 @@ rde_update_dispatch(struct imsg *imsg)
 		afi = ntohs(afi);
 		safi = *mpp++;
 		mplen--;
-		switch (afi) {
-		case AFI_IPv6:
-			if (peer->capa_received.mp_v6 == SAFI_NONE) {
-				log_peer_warnx(&peer->conf, "bad AFI, "
-				    "IPv6 disabled");
-				rde_update_err(peer, ERR_UPDATE,
-				    ERR_UPD_OPTATTR, NULL, 0);
-				goto done;
-			}
+
+		if (afi2aid(afi, safi, &aid) == -1) {
+			log_peer_warnx(&peer->conf,
+			    "bad AFI/SAFI pair in withdraw");
+			rde_update_err(peer, ERR_UPDATE, ERR_UPD_OPTATTR,
+			    NULL, 0);
+			goto done;
+		}
+
+		if (peer->capa.mp[aid] == 0) {
+			log_peer_warnx(&peer->conf,
+			    "bad withdraw, %s disabled", aid2str(aid));
+			rde_update_err(peer, ERR_UPDATE, ERR_UPD_OPTATTR,
+			    NULL, 0);
+			goto done;
+		}
+
+		if ((asp->flags & ~F_ATTR_MP_UNREACH) == 0 && mplen == 0) {
+			/* EoR marker */
+			peer_recv_eor(peer, aid);
+		}
+
+		switch (aid) {
+		case AID_INET6:
 			while (mplen > 0) {
 				if ((pos = rde_update_get_prefix6(mpp, mplen,
 				    &prefix, &prefixlen)) == -1) {
@@ -926,6 +1137,32 @@ rde_update_dispatch(struct imsg *imsg)
 				rde_update_withdraw(peer, &prefix, prefixlen);
 			}
 			break;
+		case AID_VPN_IPv4:
+			while (mplen > 0) {
+				if ((pos = rde_update_get_vpn4(mpp, mplen,
+				    &prefix, &prefixlen)) == -1) {
+					log_peer_warnx(&peer->conf,
+					    "bad VPNv4 withdraw prefix");
+					rde_update_err(peer, ERR_UPDATE,
+					    ERR_UPD_OPTATTR,
+					    mpa.unreach, mpa.unreach_len);
+					goto done;
+				}
+				if (prefixlen > 32) {
+					log_peer_warnx(&peer->conf,
+					    "bad VPNv4 withdraw prefix");
+					rde_update_err(peer, ERR_UPDATE,
+					    ERR_UPD_OPTATTR,
+					    mpa.unreach, mpa.unreach_len);
+					goto done;
+				}
+
+				mpp += pos;
+				mplen -= pos;
+
+				rde_update_withdraw(peer, &prefix, prefixlen);
+			}
+			break;
 		default:
 			/* silently ignore unsupported multiprotocol AF */
 			break;
@@ -963,9 +1200,9 @@ rde_update_dispatch(struct imsg *imsg)
 		p += pos;
 		nlri_len -= pos;
 
-		if (peer->capa_received.mp_v4 == SAFI_NONE &&
-		    peer->capa_received.mp_v6 != SAFI_NONE) {
-			log_peer_warnx(&peer->conf, "bad AFI, IPv4 disabled");
+		if (peer->capa.mp[AID_INET] == 0) {
+			log_peer_warnx(&peer->conf,
+			    "bad update, %s disabled", aid2str(AID_INET));
 			rde_update_err(peer, ERR_UPDATE, ERR_UPD_OPTATTR,
 			    NULL, 0);
 			goto done;
@@ -995,6 +1232,22 @@ rde_update_dispatch(struct imsg *imsg)
 		safi = *mpp++;
 		mplen--;
 
+		if (afi2aid(afi, safi, &aid) == -1) {
+			log_peer_warnx(&peer->conf,
+			    "bad AFI/SAFI pair in update");
+			rde_update_err(peer, ERR_UPDATE, ERR_UPD_OPTATTR,
+			    NULL, 0);
+			goto done;
+		}
+
+		if (peer->capa.mp[aid] == 0) {
+			log_peer_warnx(&peer->conf,
+			    "bad update, %s disabled", aid2str(aid));
+			rde_update_err(peer, ERR_UPDATE, ERR_UPD_OPTATTR,
+			    NULL, 0);
+			goto done;
+		}
+
 		/*
 		 * this works because asp is not linked.
 		 * But first unlock the previously locked nexthop.
@@ -1004,8 +1257,8 @@ rde_update_dispatch(struct imsg *imsg)
 			(void)nexthop_delete(asp->nexthop);
 			asp->nexthop = NULL;
 		}
-		if ((pos = rde_get_mp_nexthop(mpp, mplen, afi, asp)) == -1) {
-			log_peer_warnx(&peer->conf, "bad IPv6 nlri prefix");
+		if ((pos = rde_get_mp_nexthop(mpp, mplen, aid, asp, peer)) == -1) {
+			log_peer_warnx(&peer->conf, "bad nlri prefix");
 			rde_update_err(peer, ERR_UPDATE, ERR_UPD_OPTATTR,
 			    mpa.reach, mpa.reach_len);
 			goto done;
@@ -1013,16 +1266,8 @@ rde_update_dispatch(struct imsg *imsg)
 		mpp += pos;
 		mplen -= pos;
 
-		switch (afi) {
-		case AFI_IPv6:
-			if (peer->capa_received.mp_v6 == SAFI_NONE) {
-				log_peer_warnx(&peer->conf, "bad AFI, "
-				    "IPv6 disabled");
-				rde_update_err(peer, ERR_UPDATE,
-				    ERR_UPD_OPTATTR, NULL, 0);
-				goto done;
-			}
-
+		switch (aid) {
+		case AID_INET6:
 			while (mplen > 0) {
 				if ((pos = rde_update_get_prefix6(mpp, mplen,
 				    &prefix, &prefixlen)) == -1) {
@@ -1058,6 +1303,42 @@ rde_update_dispatch(struct imsg *imsg)
 
 			}
 			break;
+		case AID_VPN_IPv4:
+			while (mplen > 0) {
+				if ((pos = rde_update_get_vpn4(mpp, mplen,
+				    &prefix, &prefixlen)) == -1) {
+					log_peer_warnx(&peer->conf,
+					    "bad VPNv4 nlri prefix");
+					rde_update_err(peer, ERR_UPDATE,
+					    ERR_UPD_OPTATTR,
+					    mpa.reach, mpa.reach_len);
+					goto done;
+				}
+				if (prefixlen > 32) {
+					rde_update_err(peer, ERR_UPDATE,
+					    ERR_UPD_OPTATTR,
+					    mpa.reach, mpa.reach_len);
+					goto done;
+				}
+
+				mpp += pos;
+				mplen -= pos;
+
+				rde_update_update(peer, asp, &prefix,
+				    prefixlen);
+
+				/* max prefix checker */
+				if (peer->conf.max_prefix &&
+				    peer->prefix_cnt >= peer->conf.max_prefix) {
+					log_peer_warnx(&peer->conf,
+					    "prefix limit reached");
+					rde_update_err(peer, ERR_CEASE,
+					    ERR_CEASE_MAX_PREFIX, NULL, 0);
+					goto done;
+				}
+
+			}
+			break;
 		default:
 			/* silently ignore unsupported multiprotocol AF */
 			break;
@@ -1085,7 +1366,8 @@ rde_update_update(struct rde_peer *peer,
     struct bgpd_addr *prefix, u_int8_t prefixlen)
 {
 	struct rde_aspath	*fasp;
-	int			 r = 0;
+	enum filter_actions	 action;
+	int			 r = 0, f = 0;
 	u_int16_t		 i;
 
 	peer->prefix_rcvd_update++;
@@ -1095,18 +1377,24 @@ rde_update_update(struct rde_peer *peer,
 
 	for (i = 1; i < rib_size; i++) {
 		/* input filter */
-		if (rde_filter(i, &fasp, rules_l, peer, asp, prefix, prefixlen,
-		    peer, DIR_IN) == ACTION_DENY)
-			goto done;
+		action = rde_filter(i, &fasp, rules_l, peer, asp, prefix,
+		    prefixlen, peer, DIR_IN);
 
 		if (fasp == NULL)
 			fasp = asp;
 
-		rde_update_log("update", i, peer, &fasp->nexthop->exit_nexthop,
-		    prefix, prefixlen);
-		r += path_update(&ribs[i], peer, fasp, prefix, prefixlen);
+		if (action == ACTION_ALLOW) {
+			rde_update_log("update", i, peer,
+			    &fasp->nexthop->exit_nexthop, prefix, prefixlen);
+			r += path_update(&ribs[i], peer, fasp, prefix,
+			    prefixlen);
+		} else if (prefix_remove(&ribs[i], peer, prefix, prefixlen,
+		    0)) {
+			rde_update_log("filtered withdraw", i, peer,
+			    NULL, prefix, prefixlen);
+			f++;
+		}
 
-done:
 		/* free modified aspath */
 		if (fasp != asp)
 			path_put(fasp);
@@ -1114,6 +1402,8 @@ done:
 
 	if (r)
 		peer->prefix_cnt++;
+	else if (f)
+		peer->prefix_cnt--;
 }
 
 void
@@ -1152,7 +1442,7 @@ rde_update_withdraw(struct rde_peer *pee
 	} while (0)
 
 #define CHECK_FLAGS(s, t, m)	\
-	(((s) & ~(ATTR_EXTLEN | (m))) == (t))
+	(((s) & ~(ATTR_DEFMASK | (m))) == (t))
 
 int
 rde_attr_parse(u_char *p, u_int16_t len, struct rde_peer *peer,
@@ -1161,6 +1451,7 @@ rde_attr_parse(u_char *p, u_int16_t len,
 	struct bgpd_addr nexthop;
 	u_char		*op = p, *npath;
 	u_int32_t	 tmp32;
+	int		 err;
 	u_int16_t	 attr_len, nlen;
 	u_int16_t	 plen = 0;
 	u_int8_t	 flags;
@@ -1195,6 +1486,7 @@ bad_len:
 	switch (type) {
 	case ATTR_UNDEF:
 		/* ignore and drop path attributes with a type code of 0 */
+		plen += attr_len;
 		break;
 	case ATTR_ORIGIN:
 		if (attr_len != 1)
@@ -1220,7 +1512,17 @@ bad_flags:
 	case ATTR_ASPATH:
 		if (!CHECK_FLAGS(flags, ATTR_WELL_KNOWN, 0))
 			goto bad_flags;
-		if (aspath_verify(p, attr_len, rde_as4byte(peer)) != 0) {
+		err = aspath_verify(p, attr_len, rde_as4byte(peer));
+		if (err == AS_ERR_SOFT) {
+			/*
+			 * soft errors like unexpected segment types are
+			 * not considered fatal and the path is just
+			 * marked invalid.
+			 */
+			a->flags |= F_ATTR_PARSE_ERR;
+			log_peer_warnx(&peer->conf, "bad ASPATH, "
+			    "path invalidated and prefix withdrawn");
+		} else if (err != 0) {
 			rde_update_err(peer, ERR_UPDATE, ERR_UPD_ASPATH,
 			    NULL, 0);
 			return (-1);
@@ -1248,7 +1550,7 @@ bad_flags:
 		a->flags |= F_ATTR_NEXTHOP;
 
 		bzero(&nexthop, sizeof(nexthop));
-		nexthop.af = AF_INET;
+		nexthop.aid = AID_INET;
 		UPD_READ(&nexthop.v4.s_addr, p, plen, 4);
 		/*
 		 * Check if the nexthop is a valid IP address. We consider
@@ -1305,9 +1607,21 @@ bad_flags:
 		goto optattr;
 	case ATTR_AGGREGATOR:
 		if ((!rde_as4byte(peer) && attr_len != 6) ||
-		    (rde_as4byte(peer) && attr_len != 8))
-			goto bad_len;
-		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL|ATTR_TRANSITIVE, 0))
+		    (rde_as4byte(peer) && attr_len != 8)) {
+			/*
+			 * ignore attribute in case of error as per
+			 * draft-ietf-idr-optional-transitive-00.txt
+			 * but only if partial bit is set
+			 */
+			if ((flags & ATTR_PARTIAL) == 0)
+				goto bad_len;
+			log_peer_warnx(&peer->conf, "bad AGGREGATOR, "
+			    "partial attribute ignored");
+			plen += attr_len;
+			break;
+		}
+		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL|ATTR_TRANSITIVE,
+		    ATTR_PARTIAL))
 			goto bad_flags;
 		if (!rde_as4byte(peer)) {
 			/* need to inflate aggregator AS to 4-byte */
@@ -1323,8 +1637,35 @@ bad_flags:
 		/* 4-byte ready server take the default route */
 		goto optattr;
 	case ATTR_COMMUNITIES:
-		if ((attr_len & 0x3) != 0)
-			goto bad_len;
+		if (attr_len % 4 != 0) {
+			/*
+			 * mark update as bad and withdraw all routes as per
+			 * draft-ietf-idr-optional-transitive-00.txt
+			 * but only if partial bit is set
+			 */
+			if ((flags & ATTR_PARTIAL) == 0)
+				goto bad_len;
+			a->flags |= F_ATTR_PARSE_ERR;
+			log_peer_warnx(&peer->conf, "bad COMMUNITIES, "
+			    "path invalidated and prefix withdrawn");
+		}
+		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL|ATTR_TRANSITIVE,
+		    ATTR_PARTIAL))
+			goto bad_flags;
+		goto optattr;
+	case ATTR_EXT_COMMUNITIES:
+		if (attr_len % 8 != 0) {
+			/*
+			 * mark update as bad and withdraw all routes as per
+			 * draft-ietf-idr-optional-transitive-00.txt
+			 * but only if partial bit is set
+			 */
+			if ((flags & ATTR_PARTIAL) == 0)
+				goto bad_len;
+			a->flags |= F_ATTR_PARSE_ERR;
+			log_peer_warnx(&peer->conf, "bad EXT_COMMUNITIES, "
+			    "path invalidated and prefix withdrawn");
+		}
 		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL|ATTR_TRANSITIVE,
 		    ATTR_PARTIAL))
 			goto bad_flags;
@@ -1336,7 +1677,7 @@ bad_flags:
 			goto bad_flags;
 		goto optattr;
 	case ATTR_CLUSTER_LIST:
-		if ((attr_len & 0x3) != 0)
+		if (attr_len % 4 != 0)
 			goto bad_len;
 		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL, 0))
 			goto bad_flags;
@@ -1370,8 +1711,15 @@ bad_flags:
 		plen += attr_len;
 		break;
 	case ATTR_AS4_AGGREGATOR:
-		if (attr_len != 8)
-			goto bad_len;
+		if (attr_len != 8) {
+			/* see ATTR_AGGREGATOR ... */
+			if ((flags & ATTR_PARTIAL) == 0)
+				goto bad_len;
+			log_peer_warnx(&peer->conf, "bad AS4_AGGREGATOR, "
+			    "partial attribute ignored");
+			plen += attr_len;
+			break;
+		}
 		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL|ATTR_TRANSITIVE,
 		    ATTR_PARTIAL))
 			goto bad_flags;
@@ -1381,20 +1729,31 @@ bad_flags:
 		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL|ATTR_TRANSITIVE,
 		    ATTR_PARTIAL))
 			goto bad_flags;
-		if (aspath_verify(p, attr_len, 1) != 0) {
+		if ((err = aspath_verify(p, attr_len, 1)) != 0) {
 			/*
 			 * XXX RFC does not specify how to handle errors.
 			 * XXX Instead of dropping the session because of a
-			 * XXX bad path just mark the full update as not
-			 * XXX loop-free the update is no longer eligible and
-			 * XXX will not be considered for routing or
-			 * XXX redistribution. Something better is needed.
+			 * XXX bad path just mark the full update as having
+			 * XXX a parse error which makes the update no longer
+			 * XXX eligible and will not be considered for routing
+			 * XXX or redistribution.
+			 * XXX We follow draft-ietf-idr-optional-transitive
+			 * XXX by looking at the partial bit.
+			 * XXX Consider soft errors similar to a partial attr.
 			 */
-			a->flags |= F_ATTR_LOOP;
-			goto optattr;
-		}
-		a->flags |= F_ATTR_AS4BYTE_NEW;
-		goto optattr;
+			if (flags & ATTR_PARTIAL || err == AS_ERR_SOFT) {
+				a->flags |= F_ATTR_PARSE_ERR;
+				log_peer_warnx(&peer->conf, "bad AS4_PATH, "
+				    "path invalidated and prefix withdrawn");
+				goto optattr;
+			} else {
+				rde_update_err(peer, ERR_UPDATE, ERR_UPD_ASPATH,
+				    NULL, 0);
+				return (-1);
+			}
+		}
+		a->flags |= F_ATTR_AS4BYTE_NEW;
+		goto optattr;
 	default:
 		if ((flags & ATTR_OPTIONAL) == 0) {
 			rde_update_err(peer, ERR_UPDATE, ERR_UPD_UNKNWN_WK_ATTR,
@@ -1415,6 +1774,42 @@ bad_list:
 
 	return (plen);
 }
+
+int
+rde_attr_add(struct rde_aspath *a, u_char *p, u_int16_t len)
+{
+	u_int16_t	 attr_len;
+	u_int16_t	 plen = 0;
+	u_int8_t	 flags;
+	u_int8_t	 type;
+	u_int8_t	 tmp8;
+
+	if (a == NULL)		/* no aspath, nothing to do */
+		return (0);
+	if (len < 3)
+		return (-1);
+
+	UPD_READ(&flags, p, plen, 1);
+	UPD_READ(&type, p, plen, 1);
+
+	if (flags & ATTR_EXTLEN) {
+		if (len - plen < 2)
+			return (-1);
+		UPD_READ(&attr_len, p, plen, 2);
+		attr_len = ntohs(attr_len);
+	} else {
+		UPD_READ(&tmp8, p, plen, 1);
+		attr_len = tmp8;
+	}
+
+	if (len - plen < attr_len)
+		return (-1);
+
+	if (attr_optadd(a, flags, type, p, attr_len) == -1)
+		return (-1);
+	return (0);
+}
+
 #undef UPD_READ
 #undef CHECK_FLAGS
 
@@ -1440,8 +1835,8 @@ rde_attr_missing(struct rde_aspath *a, i
 }
 
 int
-rde_get_mp_nexthop(u_char *data, u_int16_t len, u_int16_t afi,
-    struct rde_aspath *asp)
+rde_get_mp_nexthop(u_char *data, u_int16_t len, u_int8_t aid,
+    struct rde_aspath *asp, struct rde_peer *peer)
 {
 	struct bgpd_addr	nexthop;
 	u_int8_t		totlen, nhlen;
@@ -1457,8 +1852,9 @@ rde_get_mp_nexthop(u_char *data, u_int16
 		return (-1);
 
 	bzero(&nexthop, sizeof(nexthop));
-	switch (afi) {
-	case AFI_IPv6:
+	nexthop.aid = aid;
+	switch (aid) {
+	case AID_INET6:
 		/*
 		 * RFC2545 describes that there may be a link-local
 		 * address carried in nexthop. Yikes!
@@ -1471,72 +1867,144 @@ rde_get_mp_nexthop(u_char *data, u_int16
 			log_warnx("bad multiprotocol nexthop, bad size");
 			return (-1);
 		}
-		nexthop.af = AF_INET6;
 		memcpy(&nexthop.v6.s6_addr, data, 16);
-		asp->nexthop = nexthop_get(&nexthop);
+#if defined(__KAME__) && defined(IPV6_LINKLOCAL_PEER)
+		if (IN6_IS_ADDR_LINKLOCAL(&nexthop.v6) &&
+		    peer->conf.lliface[0]) {
+			int ifindex;
+
+			ifindex = if_nametoindex(peer->conf.lliface);
+			if (ifindex != 0) {
+				SET_IN6_LINKLOCAL_IFINDEX(nexthop.v6, ifindex);
+				nexthop.scope_id = ifindex;
+			} else
+				log_warnx("bad interface: %s", peer->conf.lliface);
+		}
+#endif
+		break;
+	case AID_VPN_IPv4:
 		/*
-		 * lock the nexthop because it is not yet linked else
-		 * withdraws may remove this nexthop which in turn would
-		 * cause a use after free error.
+		 * Neither RFC4364 nor RFC3107 specify the format of the
+		 * nexthop in an explicit way. The quality of RFC went down
+		 * the toilet the larger the number got.
+		 * RFC4364 is very confusing about VPN-IPv4 address and the
+		 * VPN-IPv4 prefix that carries also a MPLS label.
+		 * So the nexthop is a 12-byte address with a 64bit RD and
+		 * an IPv4 address following. In the nexthop case the RD can
+		 * be ignored.
+		 * Since the nexthop has to be in the main IPv4 table just
+		 * create an AID_INET nexthop. So we don't need to handle
+		 * AID_VPN_IPv4 in nexthop and kroute.
 		 */
-		asp->nexthop->refcnt++;
-
-		/* ignore reserved (old SNPA) field as per RFC 4760 */
-		totlen += nhlen + 1;
-		data += nhlen + 1;
-
-		return (totlen);
-	default:
-		log_warnx("bad multiprotocol nexthop, bad AF");
+		if (nhlen != 12) {
+			log_warnx("bad multiprotocol nexthop, bad size");
+			return (-1);
+		}
+		data += sizeof(u_int64_t);
+		nexthop.aid = AID_INET;
+		memcpy(&nexthop.v4, data, sizeof(nexthop.v4));
 		break;
+	default:
+		log_warnx("bad multiprotocol nexthop, bad AID");
+		return (-1);
 	}
 
-	return (-1);
+	asp->nexthop = nexthop_get(&nexthop);
+	/*
+	 * lock the nexthop because it is not yet linked else
+	 * withdraws may remove this nexthop which in turn would
+	 * cause a use after free error.
+	 */
+	asp->nexthop->refcnt++;
+
+	/* ignore reserved (old SNPA) field as per RFC4760 */
+	totlen += nhlen + 1;
+	data += nhlen + 1;
+
+	return (totlen);
+}
+
+int
+rde_update_extract_prefix(u_char *p, u_int16_t len, void *va,
+    u_int8_t pfxlen, u_int8_t max)
+{
+	static u_char addrmask[] = {
+	    0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };
+	u_char		*a = va;
+	int		 i;
+	u_int16_t	 plen = 0;
+
+	for (i = 0; pfxlen && i < max; i++) {
+		if (len <= plen)
+			return (-1);
+		if (pfxlen < 8) {
+			a[i] = *p++ & addrmask[pfxlen];
+			plen++;
+			break;
+		} else {
+			a[i] = *p++;
+			plen++;
+			pfxlen -= 8;
+		}
+	}
+	return (plen);
 }
 
 int
 rde_update_get_prefix(u_char *p, u_int16_t len, struct bgpd_addr *prefix,
     u_int8_t *prefixlen)
 {
-	int		i;
-	u_int8_t	pfxlen;
-	u_int16_t	plen;
-	union {
-		struct in_addr	a32;
-		u_int8_t	a8[4];
-	}		addr;
+	u_int8_t	 pfxlen;
+	int		 plen;
 
 	if (len < 1)
 		return (-1);
 
-	memcpy(&pfxlen, p, 1);
-	p += 1;
-	plen = 1;
+	pfxlen = *p++;
+	len--;
 
 	bzero(prefix, sizeof(struct bgpd_addr));
-	addr.a32.s_addr = 0;
-	for (i = 0; i <= 3; i++) {
-		if (pfxlen > i * 8) {
-			if (len - plen < 1)
-				return (-1);
-			memcpy(&addr.a8[i], p++, 1);
-			plen++;
-		}
-	}
-	prefix->af = AF_INET;
-	prefix->v4.s_addr = addr.a32.s_addr;
+	prefix->aid = AID_INET;
 	*prefixlen = pfxlen;
 
-	return (plen);
+	if ((plen = rde_update_extract_prefix(p, len, &prefix->v4, pfxlen,
+	    sizeof(prefix->v4))) == -1)
+		return (-1);
+
+	return (plen + 1);	/* pfxlen needs to be added */
 }
 
 int
 rde_update_get_prefix6(u_char *p, u_int16_t len, struct bgpd_addr *prefix,
     u_int8_t *prefixlen)
 {
-	int		i;
+	int		plen;
 	u_int8_t	pfxlen;
-	u_int16_t	plen;
+
+	if (len < 1)
+		return (-1);
+
+	pfxlen = *p++;
+	len--;
+
+	bzero(prefix, sizeof(struct bgpd_addr));
+	prefix->aid = AID_INET6;
+	*prefixlen = pfxlen;
+
+	if ((plen = rde_update_extract_prefix(p, len, &prefix->v6, pfxlen,
+	    sizeof(prefix->v6))) == -1)
+		return (-1);
+
+	return (plen + 1);	/* pfxlen needs to be added */
+}
+
+int
+rde_update_get_vpn4(u_char *p, u_int16_t len, struct bgpd_addr *prefix,
+    u_int8_t *prefixlen)
+{
+	int		 rv, done = 0;
+	u_int8_t	 pfxlen;
+	u_int16_t	 plen;
 
 	if (len < 1)
 		return (-1);
@@ -1546,25 +2014,50 @@ rde_update_get_prefix6(u_char *p, u_int1
 	plen = 1;
 
 	bzero(prefix, sizeof(struct bgpd_addr));
-	for (i = 0; i <= 15; i++) {
-		if (pfxlen > i * 8) {
-			if (len - plen < 1)
-				return (-1);
-			memcpy(&prefix->v6.s6_addr[i], p++, 1);
-			plen++;
-		}
-	}
-	prefix->af = AF_INET6;
+
+	/* label stack */
+	do {
+		if (len - plen < 3 || pfxlen < 3 * 8)
+			return (-1);
+		if (prefix->vpn4.labellen + 3U >
+		    sizeof(prefix->vpn4.labelstack))
+			return (-1);
+		prefix->vpn4.labelstack[prefix->vpn4.labellen++] = *p++;
+		prefix->vpn4.labelstack[prefix->vpn4.labellen++] = *p++;
+		prefix->vpn4.labelstack[prefix->vpn4.labellen] = *p++;
+		if (prefix->vpn4.labelstack[prefix->vpn4.labellen] &
+		    BGP_MPLS_BOS)
+			done = 1;
+		prefix->vpn4.labellen++;
+		plen += 3;
+		pfxlen -= 3 * 8;
+	} while (!done);
+
+	/* RD */
+	if (len - plen < (int)sizeof(u_int64_t) ||
+	    pfxlen < sizeof(u_int64_t) * 8)
+		return (-1);
+	memcpy(&prefix->vpn4.rd, p, sizeof(u_int64_t));
+	pfxlen -= sizeof(u_int64_t) * 8;
+	p += sizeof(u_int64_t);
+	plen += sizeof(u_int64_t);
+
+	/* prefix */
+	prefix->aid = AID_VPN_IPv4;
 	*prefixlen = pfxlen;
 
-	return (plen);
+	if ((rv = rde_update_extract_prefix(p, len, &prefix->vpn4.addr,
+	    pfxlen, sizeof(prefix->vpn4.addr))) == -1)
+		return (-1);
+
+	return (plen + rv);
 }
 
 void
 rde_update_err(struct rde_peer *peer, u_int8_t error, u_int8_t suberr,
     void *data, u_int16_t size)
 {
-	struct buf	*wbuf;
+	struct ibuf	*wbuf;
 
 	if ((wbuf = imsg_create(ibuf_se, IMSG_UPDATE_ERR, peer->conf.id, 0,
 	    size + sizeof(error) + sizeof(suberr))) == NULL)
@@ -1616,16 +2109,30 @@ rde_as4byte_fixup(struct rde_peer *peer,
 	struct attr	*nasp, *naggr, *oaggr;
 	u_int32_t	 as;
 
+	/*
+	 * if either ATTR_AS4_AGGREGATOR or ATTR_AS4_PATH is present
+	 * try to fixup the attributes.
+	 * Do not fixup if F_ATTR_PARSE_ERR is set.
+	 */
+	if (!(a->flags & F_ATTR_AS4BYTE_NEW) || a->flags & F_ATTR_PARSE_ERR)
+		return;
+
 	/* first get the attributes */
 	nasp = attr_optget(a, ATTR_AS4_PATH);
 	naggr = attr_optget(a, ATTR_AS4_AGGREGATOR);
 
 	if (rde_as4byte(peer)) {
 		/* NEW session using 4-byte ASNs */
-		if (nasp)
+		if (nasp) {
+			log_peer_warnx(&peer->conf, "uses 4-byte ASN "
+			    "but sent AS4_PATH attribute.");
 			attr_free(a, nasp);
-		if (naggr)
+		}
+		if (naggr) {
+			log_peer_warnx(&peer->conf, "uses 4-byte ASN "
+			    "but sent AS4_AGGREGATOR attribute.");
 			attr_free(a, naggr);
+		}
 		return;
 	}
 	/* OLD session using 2-byte ASNs */
@@ -1669,6 +2176,10 @@ rde_reflector(struct rde_peer *peer, str
 	u_int16_t	 len;
 	u_int32_t	 id;
 
+	/* do not consider updates with parse errors */
+	if (asp->flags & F_ATTR_PARSE_ERR)
+		return;
+
 	/* check for originator id if eq router_id drop */
 	if ((a = attr_optget(asp, ATTR_ORIGINATOR_ID)) != NULL) {
 		if (memcmp(&conf->bgpid, a->data, sizeof(conf->bgpid)) == 0) {
@@ -1677,10 +2188,10 @@ rde_reflector(struct rde_peer *peer, str
 			return;
 		}
 	} else if (conf->flags & BGPD_FLAG_REFLECTOR) {
-		if (peer->conf.ebgp == 0)
-			id = htonl(peer->remote_bgpid);
-		else
+		if (peer->conf.ebgp)
 			id = conf->bgpid;
+		else
+			id = htonl(peer->remote_bgpid);
 		if (attr_optadd(asp, ATTR_OPTIONAL, ATTR_ORIGINATOR_ID,
 		    &id, sizeof(u_int32_t)) == -1)
 			fatalx("attr_optadd failed but impossible");
@@ -1724,17 +2235,17 @@ void
 rde_dump_rib_as(struct prefix *p, struct rde_aspath *asp, pid_t pid, int flags)
 {
 	struct ctl_show_rib	 rib;
-	struct buf		*wbuf;
+	struct ibuf		*wbuf;
 	struct attr		*a;
 	void			*bp;
+	time_t			 staletime;
 	u_int8_t		 l;
 
 	bzero(&rib, sizeof(rib));
 	rib.lastchange = p->lastchange;
 	rib.local_pref = asp->lpref;
 	rib.med = asp->med;
-	rib.prefix_cnt = asp->prefix_cnt;
-	rib.active_cnt = asp->active_cnt;
+	rib.weight = asp->weight;
 	strlcpy(rib.descr, asp->peer->conf.descr, sizeof(rib.descr));
 	memcpy(&rib.remote_addr, &asp->peer->remote_addr,
 	    sizeof(rib.remote_addr));
@@ -1748,23 +2259,26 @@ rde_dump_rib_as(struct prefix *p, struct
 		/* announced network may have a NULL nexthop */
 		bzero(&rib.true_nexthop, sizeof(rib.true_nexthop));
 		bzero(&rib.exit_nexthop, sizeof(rib.exit_nexthop));
-		rib.true_nexthop.af = p->prefix->af;
-		rib.exit_nexthop.af = p->prefix->af;
+		rib.true_nexthop.aid = p->prefix->aid;
+		rib.exit_nexthop.aid = p->prefix->aid;
 	}
 	pt_getaddr(p->prefix, &rib.prefix);
 	rib.prefixlen = p->prefix->prefixlen;
 	rib.origin = asp->origin;
 	rib.flags = 0;
 	if (p->rib->active == p)
-		rib.flags |= F_RIB_ACTIVE;
-	if (asp->peer->conf.ebgp == 0)
-		rib.flags |= F_RIB_INTERNAL;
+		rib.flags |= F_PREF_ACTIVE;
+	if (!asp->peer->conf.ebgp)
+		rib.flags |= F_PREF_INTERNAL;
 	if (asp->flags & F_PREFIX_ANNOUNCED)
-		rib.flags |= F_RIB_ANNOUNCE;
+		rib.flags |= F_PREF_ANNOUNCE;
 	if (asp->nexthop == NULL || asp->nexthop->state == NEXTHOP_REACH)
-		rib.flags |= F_RIB_ELIGIBLE;
+		rib.flags |= F_PREF_ELIGIBLE;
 	if (asp->flags & F_ATTR_LOOP)
-		rib.flags &= ~F_RIB_ELIGIBLE;
+		rib.flags &= ~F_PREF_ELIGIBLE;
+	staletime = asp->peer->staletime[p->prefix->aid];
+	if (staletime && p->lastchange <= staletime)
+		rib.flags |= F_PREF_STALE;
 	rib.aspath_len = aspath_length(asp->aspath);
 
 	if ((wbuf = imsg_create(ibuf_se_ctl, IMSG_CTL_SHOW_RIB, 0, pid,
@@ -1784,13 +2298,13 @@ rde_dump_rib_as(struct prefix *p, struct
 			    IMSG_CTL_SHOW_RIB_ATTR, 0, pid,
 			    attr_optlen(a))) == NULL)
 				return;
-			if ((bp = buf_reserve(wbuf, attr_optlen(a))) == NULL) {
-				buf_free(wbuf);
+			if ((bp = ibuf_reserve(wbuf, attr_optlen(a))) == NULL) {
+				ibuf_free(wbuf);
 				return;
 			}
 			if (attr_write(bp, attr_optlen(a), a->flags,
 			    a->type, a->data, a->len) == -1) {
-				buf_free(wbuf);
+				ibuf_free(wbuf);
 				return;
 			}
 			imsg_close(ibuf_se_ctl, wbuf);
@@ -1828,17 +2342,20 @@ rde_dump_filter(struct prefix *p, struct
 {
 	struct rde_peer		*peer;
 
-	if (req->flags & F_CTL_ADJ_IN || 
+	if (req->flags & F_CTL_ADJ_IN ||
 	    !(req->flags & (F_CTL_ADJ_IN|F_CTL_ADJ_OUT))) {
 		if (req->peerid && req->peerid != p->aspath->peer->conf.id)
 			return;
-		if (req->type == IMSG_CTL_SHOW_RIB_AS && 
-		    !aspath_match(p->aspath->aspath, req->as.type, req->as.as))
+		if (req->type == IMSG_CTL_SHOW_RIB_AS &&
+		    !aspath_match(p->aspath->aspath->data,
+		    p->aspath->aspath->len, req->as.type, req->as.as))
 			return;
 		if (req->type == IMSG_CTL_SHOW_RIB_COMMUNITY &&
-		    !rde_filter_community(p->aspath, req->community.as,
+		    !community_match(p->aspath, req->community.as,
 		    req->community.type))
 			return;
+		if ((req->flags & F_CTL_ACTIVE) && p->rib->active != p)
+			return;
 		rde_dump_rib_as(p, p->aspath, req->pid, req->flags);
 	} else if (req->flags & F_CTL_ADJ_OUT) {
 		if (p->rib->active != p)
@@ -1872,7 +2389,7 @@ rde_dump_prefix_upcall(struct rib_entry 
 
 	pt = re->prefix;
 	pt_getaddr(pt, &addr);
-	if (addr.af != ctx->req.prefix.af)
+	if (addr.aid != ctx->req.prefix.aid)
 		return;
 	if (ctx->req.prefixlen > pt->prefixlen)
 		return;
@@ -1889,6 +2406,7 @@ rde_dump_ctx_new(struct ctl_show_rib_req
 	struct rib_entry	*re;
 	u_int			 error;
 	u_int16_t		 id;
+	u_int8_t		 hostplen = 0;
 
 	if ((ctx = calloc(1, sizeof(*ctx))) == NULL) {
 		log_warn("rde_dump_ctx_new");
@@ -1902,6 +2420,7 @@ rde_dump_ctx_new(struct ctl_show_rib_req
 		error = CTL_RES_NOSUCHPEER;
 		imsg_compose(ibuf_se_ctl, IMSG_CTL_RESULT, 0, pid, -1, &error,
 		    sizeof(error));
+		free(ctx);
 		return;
 	}
 
@@ -1924,7 +2443,18 @@ rde_dump_ctx_new(struct ctl_show_rib_req
 			ctx->ribctx.ctx_upcall = rde_dump_prefix_upcall;
 			break;
 		}
-		if (req->prefixlen == 32)
+		switch (req->prefix.aid) {
+		case AID_INET:
+		case AID_VPN_IPv4:
+			hostplen = 32;
+			break;
+		case AID_INET6:
+			hostplen = 128;
+			break;
+		default:
+			fatalx("rde_dump_ctx_new: unknown af");
+		}
+		if (req->prefixlen == hostplen)
 			re = rib_lookup(&ribs[id], &req->prefix);
 		else
 			re = rib_get(&ribs[id], &req->prefix, req->prefixlen);
@@ -1937,7 +2467,7 @@ rde_dump_ctx_new(struct ctl_show_rib_req
 	}
 	ctx->ribctx.ctx_done = rde_dump_done;
 	ctx->ribctx.ctx_arg = ctx;
-	ctx->ribctx.ctx_af = ctx->req.af;
+	ctx->ribctx.ctx_aid = ctx->req.aid;
 	rib_dump_r(&ctx->ribctx);
 }
 
@@ -1971,13 +2501,17 @@ rde_dump_mrt_new(struct mrt *mrt, pid_t 
 		free(ctx);
 		return;
 	}
+
+	if (ctx->mrt.type == MRT_TABLE_DUMP_V2)
+		mrt_dump_v2_hdr(&ctx->mrt, conf, &peerlist);
+
 	ctx->ribctx.ctx_count = RDE_RUNNER_ROUNDS;
 	ctx->ribctx.ctx_rib = &ribs[id];
 	ctx->ribctx.ctx_upcall = mrt_dump_upcall;
-	ctx->ribctx.ctx_done = mrt_dump_done;
+	ctx->ribctx.ctx_done = mrt_done;
 	ctx->ribctx.ctx_arg = &ctx->mrt;
-	ctx->ribctx.ctx_af = AF_UNSPEC;
-	LIST_INSERT_HEAD(&rde_mrts, &ctx->mrt, entry);
+	ctx->ribctx.ctx_aid = AID_UNSPEC;
+	LIST_INSERT_HEAD(&rde_mrts, ctx, entry);
 	rde_mrt_cnt++;
 	rib_dump_r(&ctx->ribctx);
 }
@@ -1985,13 +2519,25 @@ rde_dump_mrt_new(struct mrt *mrt, pid_t 
 /*
  * kroute specific functions
  */
+int
+rde_rdomain_import(struct rde_aspath *asp, struct rdomain *rd)
+{
+	struct filter_set	*s;
+
+	TAILQ_FOREACH(s, &rd->import, entry) {
+		if (community_ext_match(asp, &s->action.ext_community, 0))
+			return (1);
+	}
+	return (0);
+}
+
 void
-rde_send_kroute(struct prefix *new, struct prefix *old)
+rde_send_kroute(struct prefix *new, struct prefix *old, u_int16_t ribid)
 {
-	struct kroute_label	 kl;
-	struct kroute6_label	 kl6;
+	struct kroute_full	 kr;
 	struct bgpd_addr	 addr;
 	struct prefix		*p;
+	struct rdomain		*rd;
 	enum imsg_type		 type;
 
 	/*
@@ -2011,43 +2557,43 @@ rde_send_kroute(struct prefix *new, stru
 	}
 
 	pt_getaddr(p->prefix, &addr);
-	switch (addr.af) {
-	case AF_INET:
-		bzero(&kl, sizeof(kl));
-		kl.kr.prefix.s_addr = addr.v4.s_addr;
-		kl.kr.prefixlen = p->prefix->prefixlen;
-		if (p->aspath->flags & F_NEXTHOP_REJECT)
-			kl.kr.flags |= F_REJECT;
-		if (p->aspath->flags & F_NEXTHOP_BLACKHOLE)
-			kl.kr.flags |= F_BLACKHOLE;
-		if (type == IMSG_KROUTE_CHANGE)
-			kl.kr.nexthop.s_addr =
-			    p->aspath->nexthop->true_nexthop.v4.s_addr;
-		strlcpy(kl.label, rtlabel_id2name(p->aspath->rtlabelid),
-		    sizeof(kl.label));
-		if (imsg_compose(ibuf_main, type, 0, 0, -1, &kl,
-		    sizeof(kl)) == -1)
-			fatal("imsg_compose error");
+	bzero(&kr, sizeof(kr));
+	memcpy(&kr.prefix, &addr, sizeof(kr.prefix));
+	kr.prefixlen = p->prefix->prefixlen;
+	if (p->aspath->flags & F_NEXTHOP_REJECT)
+		kr.flags |= F_REJECT;
+	if (p->aspath->flags & F_NEXTHOP_BLACKHOLE)
+		kr.flags |= F_BLACKHOLE;
+	if (type == IMSG_KROUTE_CHANGE)
+		memcpy(&kr.nexthop, &p->aspath->nexthop->true_nexthop,
+		    sizeof(kr.nexthop));
+	strlcpy(kr.label, rtlabel_id2name(p->aspath->rtlabelid),
+	    sizeof(kr.label));
+
+	switch (addr.aid) {
+	case AID_VPN_IPv4:
+		if (ribid != 1)
+			/* not Loc-RIB, no update for VPNs */
+			break;
+
+		SIMPLEQ_FOREACH(rd, rdomains_l, entry) {
+			if (!rde_rdomain_import(p->aspath, rd))
+				continue;
+			/* must send exit_nexthop so that correct MPLS tunnel
+			 * is chosen
+			 */
+			if (type == IMSG_KROUTE_CHANGE)
+				memcpy(&kr.nexthop,
+				    &p->aspath->nexthop->exit_nexthop,
+				    sizeof(kr.nexthop));
+			if (imsg_compose(ibuf_main, type, rd->rtableid, 0, -1,
+			    &kr, sizeof(kr)) == -1)
+				fatal("imsg_compose error");
+		}
 		break;
-	case AF_INET6:
-		bzero(&kl6, sizeof(kl6));
-		memcpy(&kl6.kr.prefix, &addr.v6, sizeof(struct in6_addr));
-		kl6.kr.prefixlen = p->prefix->prefixlen;
-		if (p->aspath->flags & F_NEXTHOP_REJECT)
-			kl6.kr.flags |= F_REJECT;
-		if (p->aspath->flags & F_NEXTHOP_BLACKHOLE)
-			kl6.kr.flags |= F_BLACKHOLE;
-		if (type == IMSG_KROUTE_CHANGE) {
-			type = IMSG_KROUTE6_CHANGE;
-			memcpy(&kl6.kr.nexthop,
-			    &p->aspath->nexthop->true_nexthop.v6,
-			    sizeof(struct in6_addr));
-		} else
-			type = IMSG_KROUTE6_DELETE;
-		strlcpy(kl6.label, rtlabel_id2name(p->aspath->rtlabelid),
-		    sizeof(kl6.label));
-		if (imsg_compose(ibuf_main, type, 0, 0, -1, &kl6,
-		    sizeof(kl6)) == -1)
+	default:
+		if (imsg_compose(ibuf_main, type, ribs[ribid].rtableid, 0, -1,
+		    &kr, sizeof(kr)) == -1)
 			fatal("imsg_compose error");
 		break;
 	}
@@ -2098,7 +2644,6 @@ rde_send_pftable_commit(void)
 void
 rde_send_nexthop(struct bgpd_addr *next, int valid)
 {
-	size_t			 size;
 	int			 type;
 
 	if (valid)
@@ -2106,8 +2651,6 @@ rde_send_nexthop(struct bgpd_addr *next,
 	else
 		type = IMSG_NEXTHOP_REMOVE;
 
-	size = sizeof(struct bgpd_addr);
-
 	if (imsg_compose(ibuf_main, type, 0, 0, -1, next,
 	    sizeof(struct bgpd_addr)) == -1)
 		fatal("imsg_compose error");
@@ -2201,6 +2744,10 @@ rde_softreconfig_in(struct rib_entry *re
 			continue;
 
 		for (i = 1; i < rib_size; i++) {
+			/* only active ribs need a softreconfig rerun */
+			if (ribs[i].state != RECONF_KEEP)
+				continue;
+
 			/* check if prefix changed */
 			oa = rde_filter(i, &oasp, rules_l, peer, asp, &addr,
 			    pt->prefixlen, peer, DIR_IN);
@@ -2228,7 +2775,7 @@ rde_softreconfig_in(struct rib_entry *re
 				if (path_compare(nasp, oasp) == 0)
 					goto done;
 				/* send update */
-				path_update(&ribs[1], peer, nasp, &addr,
+				path_update(&ribs[i], peer, nasp, &addr,
 				    pt->prefixlen);
 			}
 
@@ -2241,6 +2788,104 @@ done:
 	}
 }
 
+void
+rde_softreconfig_load(struct rib_entry *re, void *ptr)
+{
+	struct rib		*rib = ptr;
+	struct prefix		*p, *np;
+	struct pt_entry		*pt;
+	struct rde_peer		*peer;
+	struct rde_aspath	*asp, *nasp;
+	enum filter_actions	 action;
+	struct bgpd_addr	 addr;
+
+	pt = re->prefix;
+	pt_getaddr(pt, &addr);
+	for (p = LIST_FIRST(&re->prefix_h); p != NULL; p = np) {
+		np = LIST_NEXT(p, rib_l);
+
+		/* store aspath as prefix may change till we're done */
+		asp = p->aspath;
+		peer = asp->peer;
+
+		action = rde_filter(rib->id, &nasp, newrules, peer, asp, &addr,
+		    pt->prefixlen, peer, DIR_IN);
+		nasp = nasp != NULL ? nasp : asp;
+
+		if (action == ACTION_ALLOW) {
+			/* update Local-RIB */
+			path_update(rib, peer, nasp, &addr, pt->prefixlen);
+		}
+
+		if (nasp != asp)
+			path_put(nasp);
+	}
+}
+
+void
+rde_softreconfig_load_peer(struct rib_entry *re, void *ptr)
+{
+	struct rde_peer		*peer = ptr;
+	struct prefix		*p = re->active;
+	struct pt_entry		*pt;
+	struct rde_aspath	*nasp;
+	enum filter_actions	 na;
+	struct bgpd_addr	 addr;
+
+	pt = re->prefix;
+	pt_getaddr(pt, &addr);
+
+	/* check if prefix was announced */
+	if (up_test_update(peer, p) != 1)
+		return;
+
+	na = rde_filter(re->ribid, &nasp, newrules, peer, p->aspath,
+	    &addr, pt->prefixlen, p->aspath->peer, DIR_OUT);
+	nasp = nasp != NULL ? nasp : p->aspath;
+
+	if (na == ACTION_DENY)
+		/* nothing todo */
+		goto done;
+
+	/* send update */
+	up_generate(peer, nasp, &addr, pt->prefixlen);
+done:
+	if (nasp != p->aspath)
+		path_put(nasp);
+}
+
+void
+rde_softreconfig_unload_peer(struct rib_entry *re, void *ptr)
+{
+	struct rde_peer		*peer = ptr;
+	struct prefix		*p = re->active;
+	struct pt_entry		*pt;
+	struct rde_aspath	*oasp;
+	enum filter_actions	 oa;
+	struct bgpd_addr	 addr;
+
+	pt = re->prefix;
+	pt_getaddr(pt, &addr);
+
+	/* check if prefix was announced */
+	if (up_test_update(peer, p) != 1)
+		return;
+
+	oa = rde_filter(re->ribid, &oasp, rules_l, peer, p->aspath,
+	    &addr, pt->prefixlen, p->aspath->peer, DIR_OUT);
+	oasp = oasp != NULL ? oasp : p->aspath;
+
+	if (oa == ACTION_DENY)
+		/* nothing todo */
+		goto done;
+
+	/* send withdraw */
+	up_generate(peer, NULL, &addr, pt->prefixlen);
+done:
+	if (oasp != p->aspath)
+		path_put(oasp);
+}
+
 /*
  * update specific functions
  */
@@ -2252,7 +2897,7 @@ rde_up_dump_upcall(struct rib_entry *re,
 	struct rde_peer		*peer = ptr;
 
 	if (re->ribid != peer->ribid)
-		fatalx("King Bula: monsterous evil horror.");
+		fatalx("King Bula: monstrous evil horror.");
 	if (re->active == NULL)
 		return;
 	up_generate_updates(rules_l, peer, re->active, NULL);
@@ -2265,7 +2910,7 @@ rde_generate_updates(u_int16_t ribid, st
 
 	/*
 	 * If old is != NULL we know it was active and should be removed.
-	 * If new is != NULL we know it is reachable and then we should 
+	 * If new is != NULL we know it is reachable and then we should
 	 * generate an update.
 	 */
 	if (old == NULL && new == NULL)
@@ -2286,7 +2931,7 @@ void
 rde_update_queue_runner(void)
 {
 	struct rde_peer		*peer;
-	int			 r, sent, max = RDE_RUNNER_ROUNDS;
+	int			 r, sent, max = RDE_RUNNER_ROUNDS, eor = 0;
 	u_int16_t		 len, wd_len, wpos;
 
 	len = sizeof(queue_buf) - MSGSIZE_HEADER;
@@ -2300,7 +2945,7 @@ rde_update_queue_runner(void)
 			/* first withdraws */
 			wpos = 2; /* reserve space for the length field */
 			r = up_dump_prefix(queue_buf + wpos, len - wpos - 2,
-			    &peer->withdraws, peer);
+			    &peer->withdraws[AID_INET], peer);
 			wd_len = r;
 			/* write withdraws length filed */
 			wd_len = htons(wd_len);
@@ -2310,31 +2955,49 @@ rde_update_queue_runner(void)
 			/* now bgp path attributes */
 			r = up_dump_attrnlri(queue_buf + wpos, len - wpos,
 			    peer);
-			wpos += r;
-
-			if (wpos == 4)
-				/*
-				 * No packet to send. The 4 bytes are the
-				 * needed withdraw and path attribute length.
-				 */
-				continue;
+			switch (r) {
+			case -1:
+				eor = 1;
+				if (wd_len == 0) {
+					/* no withdraws queued just send EoR */
+					peer_send_eor(peer, AID_INET);
+					continue;
+				}
+				break;
+			case 2:
+				if (wd_len == 0) {
+					/*
+					 * No packet to send. No withdraws and
+					 * no path attributes. Skip.
+					 */
+					continue;
+				}
+				/* FALLTHROUGH */
+			default:
+				wpos += r;
+				break;
+			}
 
 			/* finally send message to SE */
 			if (imsg_compose(ibuf_se, IMSG_UPDATE, peer->conf.id,
 			    0, -1, queue_buf, wpos) == -1)
 				fatal("imsg_compose error");
 			sent++;
+			if (eor) {
+				eor = 0;
+				peer_send_eor(peer, AID_INET);
+			}
 		}
 		max -= sent;
 	} while (sent != 0 && max > 0);
 }
 
 void
-rde_update6_queue_runner(void)
+rde_update6_queue_runner(u_int8_t aid)
 {
 	struct rde_peer		*peer;
 	u_char			*b;
-	int			 sent, max = RDE_RUNNER_ROUNDS / 2;
+	int			 r, sent, max = RDE_RUNNER_ROUNDS / 2;
 	u_int16_t		 len;
 
 	/* first withdraws ... */
@@ -2346,7 +3009,7 @@ rde_update6_queue_runner(void)
 			if (peer->state != PEER_UP)
 				continue;
 			len = sizeof(queue_buf) - MSGSIZE_HEADER;
-			b = up_dump_mp_unreach(queue_buf, &len, peer);
+			b = up_dump_mp_unreach(queue_buf, &len, peer, aid);
 
 			if (b == NULL)
 				continue;
@@ -2369,10 +3032,18 @@ rde_update6_queue_runner(void)
 			if (peer->state != PEER_UP)
 				continue;
 			len = sizeof(queue_buf) - MSGSIZE_HEADER;
-			b = up_dump_mp_reach(queue_buf, &len, peer);
-
-			if (b == NULL)
+			r = up_dump_mp_reach(queue_buf, &len, peer, aid);
+			switch (r) {
+			case -2:
+				continue;
+			case -1:
+				peer_send_eor(peer, aid);
 				continue;
+			default:
+				b = queue_buf + r;
+				break;
+			}
+
 			/* finally send message to SE */
 			if (imsg_compose(ibuf_se, IMSG_UPDATE, peer->conf.id,
 			    0, -1, b, len) == -1)
@@ -2411,7 +3082,7 @@ rde_decisionflags(void)
 int
 rde_as4byte(struct rde_peer *peer)
 {
-	return (peer->capa_announced.as4byte && peer->capa_received.as4byte);
+	return (peer->capa.as4byte);
 }
 
 /*
@@ -2429,7 +3100,6 @@ void
 peer_init(u_int32_t hashsize)
 {
 	struct peer_config pc;
-	struct in_addr   id;
 	u_int32_t	 hs, i;
 
 	for (hs = 1; hs < hashsize; hs <<= 1)
@@ -2445,17 +3115,13 @@ peer_init(u_int32_t hashsize)
 	peertable.peer_hashmask = hs - 1;
 
 	bzero(&pc, sizeof(pc));
-	pc.remote_as = conf->as;
-	id.s_addr = conf->bgpid;
-	snprintf(pc.descr, sizeof(pc.descr), "LOCAL: ID %s", inet_ntoa(id));
+	snprintf(pc.descr, sizeof(pc.descr), "LOCAL");
 
 	peerself = peer_add(0, &pc);
 	if (peerself == NULL)
 		fatalx("peer_init add self");
 
 	peerself->state = PEER_UP;
-	peerself->remote_bgpid = ntohl(conf->bgpid);
-	peerself->short_as = conf->short_as;
 }
 
 void
@@ -2534,14 +3200,10 @@ peer_localaddrs(struct rde_peer *peer, s
 			if (ifa->ifa_addr->sa_family ==
 			    match->ifa_addr->sa_family)
 				ifa = match;
-			peer->local_v4_addr.af = AF_INET;
-			peer->local_v4_addr.v4.s_addr =
-			    ((struct sockaddr_in *)ifa->ifa_addr)->
-			    sin_addr.s_addr;
+			sa2addr(ifa->ifa_addr, &peer->local_v4_addr);
 			break;
 		}
 	}
-
 	for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
 		if (ifa->ifa_addr->sa_family == AF_INET6 &&
 		    strcmp(ifa->ifa_name, match->ifa_name) == 0) {
@@ -2559,13 +3221,7 @@ peer_localaddrs(struct rde_peer *peer, s
 			    &((struct sockaddr_in6 *)ifa->
 			    ifa_addr)->sin6_addr))
 				continue;
-			peer->local_v6_addr.af = AF_INET6;
-			memcpy(&peer->local_v6_addr.v6,
-			    &((struct sockaddr_in6 *)ifa->ifa_addr)->
-			    sin6_addr, sizeof(struct in6_addr));
-			peer->local_v6_addr.scope_id =
-			    ((struct sockaddr_in6 *)ifa->ifa_addr)->
-			    sin6_scope_id;
+			sa2addr(ifa->ifa_addr, &peer->local_v6_addr);
 			break;
 		}
 	}
@@ -2577,23 +3233,22 @@ void
 peer_up(u_int32_t id, struct session_up *sup)
 {
 	struct rde_peer	*peer;
+	u_int8_t	 i;
 
 	peer = peer_get(id);
 	if (peer == NULL) {
-		log_warnx("peer_up: peer id %d already exists", id);
+		log_warnx("peer_up: unknown peer id %d", id);
 		return;
 	}
 
-	if (peer->state != PEER_DOWN && peer->state != PEER_NONE)
+	if (peer->state != PEER_DOWN && peer->state != PEER_NONE &&
+	    peer->state != PEER_UP)
 		fatalx("peer_up: bad state");
 	peer->remote_bgpid = ntohl(sup->remote_bgpid);
 	peer->short_as = sup->short_as;
 	memcpy(&peer->remote_addr, &sup->remote_addr,
 	    sizeof(peer->remote_addr));
-	memcpy(&peer->capa_announced, &sup->capa_announced,
-	    sizeof(peer->capa_announced));
-	memcpy(&peer->capa_received, &sup->capa_received,
-	    sizeof(peer->capa_received));
+	memcpy(&peer->capa, &sup->capa, sizeof(peer->capa));
 
 	peer_localaddrs(peer, &sup->local_addr);
 
@@ -2607,7 +3262,10 @@ peer_up(u_int32_t id, struct session_up 
 		 */
 		return;
 
-	peer_dump(id, AFI_ALL, SAFI_ALL);
+	for (i = 0; i < AID_MAX; i++) {
+		if (peer->capa.mp[i] == 1)
+			peer_dump(id, i);
+	}
 }
 
 void
@@ -2641,43 +3299,90 @@ peer_down(u_int32_t id)
 	free(peer);
 }
 
+/*
+ * Flush all routes older then staletime. If staletime is 0 all routes will
+ * be flushed.
+ */
+void
+peer_flush(struct rde_peer *peer, u_int8_t aid)
+{
+	struct rde_aspath	*asp, *nasp;
+
+	/* walk through per peer RIB list and remove all stale prefixes. */
+	for (asp = LIST_FIRST(&peer->path_h); asp != NULL; asp = nasp) {
+		nasp = LIST_NEXT(asp, peer_l);
+		path_remove_stale(asp, aid);
+	}
+
+	/* Deletions are performed in path_remove() */
+	rde_send_pftable_commit();
+
+	/* flushed no need to keep staletime */
+	peer->staletime[aid] = 0;
+}
+
 void
-peer_dump(u_int32_t id, u_int16_t afi, u_int8_t safi)
+peer_stale(u_int32_t id, u_int8_t aid)
 {
 	struct rde_peer		*peer;
+	time_t			 now;
 
 	peer = peer_get(id);
 	if (peer == NULL) {
-		log_warnx("peer_down: unknown peer id %d", id);
+		log_warnx("peer_stale: unknown peer id %d", id);
 		return;
 	}
 
-	if (afi == AFI_ALL || afi == AFI_IPv4)
-		if (safi == SAFI_ALL || safi == SAFI_UNICAST) {
-			if (peer->conf.announce_type == ANNOUNCE_DEFAULT_ROUTE)
-				up_generate_default(rules_l, peer, AF_INET);
-			else
-				rib_dump(&ribs[peer->ribid], rde_up_dump_upcall,
-				    peer, AF_INET);
-		}
-	if (afi == AFI_ALL || afi == AFI_IPv6)
-		if (safi == SAFI_ALL || safi == SAFI_UNICAST) {
-			if (peer->conf.announce_type == ANNOUNCE_DEFAULT_ROUTE)
-				up_generate_default(rules_l, peer, AF_INET6);
-			else
-				rib_dump(&ribs[peer->ribid], rde_up_dump_upcall,
-				    peer, AF_INET6);
-		}
+	if (peer->staletime[aid])
+		peer_flush(peer, aid);
+	peer->staletime[aid] = now = time(NULL);
 
-	if (peer->capa_received.restart && peer->capa_announced.restart)
-		peer_send_eor(peer, afi, safi);
+	/* make sure new prefixes start on a higher timestamp */
+	do {
+		sleep(1);
+	} while (now >= time(NULL));
 }
 
-/* End-of-RIB marker, draft-ietf-idr-restart-13.txt */
 void
-peer_send_eor(struct rde_peer *peer, u_int16_t afi, u_int16_t safi)
+peer_dump(u_int32_t id, u_int8_t aid)
 {
-	if (afi == AFI_IPv4 && safi == SAFI_UNICAST) {
+	struct rde_peer		*peer;
+
+	peer = peer_get(id);
+	if (peer == NULL) {
+		log_warnx("peer_dump: unknown peer id %d", id);
+		return;
+	}
+
+	if (peer->conf.announce_type == ANNOUNCE_DEFAULT_ROUTE)
+		up_generate_default(rules_l, peer, aid);
+	else
+		rib_dump(&ribs[peer->ribid], rde_up_dump_upcall, peer, aid);
+	if (peer->capa.grestart.restart)
+		up_generate_marker(peer, aid);
+}
+
+/* End-of-RIB marker, RFC 4724 */
+void
+peer_recv_eor(struct rde_peer *peer, u_int8_t aid)
+{
+	peer->prefix_rcvd_eor++;
+
+	/* First notify SE to remove possible race with the timeout. */
+	if (imsg_compose(ibuf_se, IMSG_SESSION_RESTARTED, peer->conf.id,
+	    0, -1, &aid, sizeof(aid)) == -1)
+		fatal("imsg_compose error");
+}
+
+void
+peer_send_eor(struct rde_peer *peer, u_int8_t aid)
+{
+	u_int16_t	afi;
+	u_int8_t	safi;
+
+	peer->prefix_sent_eor++;
+
+	if (aid == AID_INET) {
 		u_char null[4];
 
 		bzero(&null, 4);
@@ -2688,6 +3393,9 @@ peer_send_eor(struct rde_peer *peer, u_i
 		u_int16_t	i;
 		u_char		buf[10];
 
+		if (aid2afi(aid, &afi, &safi) == -1)
+			fatalx("peer_send_eor: bad AID");
+
 		i = 0;	/* v4 withdrawn len */
 		bcopy(&i, &buf[0], sizeof(i));
 		i = htons(6);	/* path attr len */
@@ -2709,39 +3417,61 @@ peer_send_eor(struct rde_peer *peer, u_i
  * network announcement stuff
  */
 void
-network_init(struct network_head *net_l)
-{
-	struct network	*n;
-
-	reloadtime = time(NULL);
-
-	while ((n = TAILQ_FIRST(net_l)) != NULL) {
-		TAILQ_REMOVE(net_l, n, entry);
-		network_add(&n->net, 1);
-		free(n);
-	}
-}
-
-void
 network_add(struct network_config *nc, int flagstatic)
 {
+	struct rdomain		*rd;
 	struct rde_aspath	*asp;
+	struct filter_set_head	*vpnset = NULL;
+	in_addr_t		 prefix4;
 	u_int16_t		 i;
 
-	asp = path_get();
-	asp->aspath = aspath_get(NULL, 0);
-	asp->origin = ORIGIN_IGP;
-	asp->flags = F_ATTR_ORIGIN | F_ATTR_ASPATH |
-	    F_ATTR_LOCALPREF | F_PREFIX_ANNOUNCED;
-	/* the nexthop is unset unless a default set overrides it */
+	if (nc->rtableid) {
+		SIMPLEQ_FOREACH(rd, rdomains_l, entry) {
+			if (rd->rtableid != nc->rtableid)
+				continue;
+			switch (nc->prefix.aid) {
+			case AID_INET:
+				prefix4 = nc->prefix.v4.s_addr;
+				bzero(&nc->prefix, sizeof(nc->prefix));
+				nc->prefix.aid = AID_VPN_IPv4;
+				nc->prefix.vpn4.rd = rd->rd;
+				nc->prefix.vpn4.addr.s_addr = prefix4;
+				nc->prefix.vpn4.labellen = 3;
+				nc->prefix.vpn4.labelstack[0] =
+				    (rd->label >> 12) & 0xff;
+				nc->prefix.vpn4.labelstack[1] =
+				    (rd->label >> 4) & 0xff;
+				nc->prefix.vpn4.labelstack[2] =
+				    (rd->label << 4) & 0xf0;
+				nc->prefix.vpn4.labelstack[2] |= BGP_MPLS_BOS;
+				vpnset = &rd->export;
+				break;
+			default:
+				log_warnx("unable to VPNize prefix");
+				filterset_free(&nc->attrset);
+				return;
+			}
+		}
+	}
+
+	if (nc->type == NETWORK_MRTCLONE) {
+		asp = nc->asp;
+	} else {
+		asp = path_get();
+		asp->aspath = aspath_get(NULL, 0);
+		asp->origin = ORIGIN_IGP;
+		asp->flags = F_ATTR_ORIGIN | F_ATTR_ASPATH |
+		    F_ATTR_LOCALPREF | F_PREFIX_ANNOUNCED;
+		/* the nexthop is unset unless a default set overrides it */
+	}
 	if (!flagstatic)
 		asp->flags |= F_ANN_DYNAMIC;
-
-	rde_apply_set(asp, &nc->attrset, nc->prefix.af, peerself, peerself);
+	rde_apply_set(asp, &nc->attrset, nc->prefix.aid, peerself, peerself);
+	if (vpnset)
+		rde_apply_set(asp, vpnset, nc->prefix.aid, peerself, peerself);
 	for (i = 1; i < rib_size; i++)
 		path_update(&ribs[i], peerself, asp, &nc->prefix,
 		    nc->prefixlen);
-
 	path_put(asp);
 	filterset_free(&nc->attrset);
 }
@@ -2749,12 +3479,41 @@ network_add(struct network_config *nc, i
 void
 network_delete(struct network_config *nc, int flagstatic)
 {
-	u_int32_t	flags = F_PREFIX_ANNOUNCED;
-	u_int32_t	i;
+	struct rdomain	*rd;
+	in_addr_t	 prefix4;
+	u_int32_t	 flags = F_PREFIX_ANNOUNCED;
+	u_int32_t	 i;
 
 	if (!flagstatic)
 		flags |= F_ANN_DYNAMIC;
 
+	if (nc->rtableid) {
+		SIMPLEQ_FOREACH(rd, rdomains_l, entry) {
+			if (rd->rtableid != nc->rtableid)
+				continue;
+			switch (nc->prefix.aid) {
+			case AID_INET:
+				prefix4 = nc->prefix.v4.s_addr;
+				bzero(&nc->prefix, sizeof(nc->prefix));
+				nc->prefix.aid = AID_VPN_IPv4;
+				nc->prefix.vpn4.rd = rd->rd;
+				nc->prefix.vpn4.addr.s_addr = prefix4;
+				nc->prefix.vpn4.labellen = 3;
+				nc->prefix.vpn4.labelstack[0] =
+				    (rd->label >> 12) & 0xff;
+				nc->prefix.vpn4.labelstack[1] =
+				    (rd->label >> 4) & 0xff;
+				nc->prefix.vpn4.labelstack[2] =
+				    (rd->label << 4) & 0xf0;
+				nc->prefix.vpn4.labelstack[2] |= BGP_MPLS_BOS;
+				break;
+			default:
+				log_warnx("unable to VPNize prefix");
+				return;
+			}
+		}
+	}
+
 	for (i = rib_size - 1; i > 0; i--)
 		prefix_remove(&ribs[i], peerself, &nc->prefix, nc->prefixlen,
 		    flags);
@@ -2764,38 +3523,31 @@ void
 network_dump_upcall(struct rib_entry *re, void *ptr)
 {
 	struct prefix		*p;
-	struct kroute		 k;
-	struct kroute6		 k6;
+	struct kroute_full	 k;
 	struct bgpd_addr	 addr;
 	struct rde_dump_ctx	*ctx = ptr;
 
 	LIST_FOREACH(p, &re->prefix_h, rib_l) {
 		if (!(p->aspath->flags & F_PREFIX_ANNOUNCED))
 			continue;
-		if (p->prefix->af == AF_INET) {
-			bzero(&k, sizeof(k));
-			pt_getaddr(p->prefix, &addr);
-			k.prefix.s_addr = addr.v4.s_addr;
-			k.prefixlen = p->prefix->prefixlen;
-			if (p->aspath->peer == peerself)
-				k.flags = F_KERNEL;
-			if (imsg_compose(ibuf_se_ctl, IMSG_CTL_SHOW_NETWORK, 0,
-			    ctx->req.pid, -1, &k, sizeof(k)) == -1)
-				log_warnx("network_dump_upcall: "
-				    "imsg_compose error");
-		}
-		if (p->prefix->af == AF_INET6) {
-			bzero(&k6, sizeof(k6));
-			pt_getaddr(p->prefix, &addr);
-			memcpy(&k6.prefix, &addr.v6, sizeof(k6.prefix));
-			k6.prefixlen = p->prefix->prefixlen;
-			if (p->aspath->peer == peerself)
-				k6.flags = F_KERNEL;
-			if (imsg_compose(ibuf_se_ctl, IMSG_CTL_SHOW_NETWORK6, 0,
-			    ctx->req.pid, -1, &k6, sizeof(k6)) == -1)
-				log_warnx("network_dump_upcall: "
-				    "imsg_compose error");
-		}
+		pt_getaddr(p->prefix, &addr);
+
+		bzero(&k, sizeof(k));
+		memcpy(&k.prefix, &addr, sizeof(k.prefix));
+		if (p->aspath->nexthop == NULL ||
+		    p->aspath->nexthop->state != NEXTHOP_REACH)
+			k.nexthop.aid = k.prefix.aid;
+		else
+			memcpy(&k.nexthop, &p->aspath->nexthop->true_nexthop,
+			    sizeof(k.nexthop));
+		k.prefixlen = p->prefix->prefixlen;
+		k.flags = F_KERNEL;
+		if ((p->aspath->flags & F_ANN_DYNAMIC) == 0)
+			k.flags = F_STATIC;
+		if (imsg_compose(ibuf_se_ctl, IMSG_CTL_SHOW_NETWORK, 0,
+		    ctx->req.pid, -1, &k, sizeof(k)) == -1)
+			log_warnx("network_dump_upcall: "
+			    "imsg_compose error");
 	}
 }
 
@@ -2841,10 +3593,10 @@ sa_cmp(struct bgpd_addr *a, struct socka
 	struct sockaddr_in	*in_b;
 	struct sockaddr_in6	*in6_b;
 
-	if (a->af != b->sa_family)
+	if (aid2af(a->aid) != b->sa_family)
 		return (1);
 
-	switch (a->af) {
+	switch (b->sa_family) {
 	case AF_INET:
 		in_b = (struct sockaddr_in *)b;
 		if (a->v4.s_addr != in_b->sin_addr.s_addr)
@@ -2855,10 +3607,11 @@ sa_cmp(struct bgpd_addr *a, struct socka
 #ifdef __KAME__
 		/* directly stolen from sbin/ifconfig/ifconfig.c */
 		if (IN6_IS_ADDR_LINKLOCAL(&in6_b->sin6_addr)) {
-			in6_b->sin6_scope_id =
-			    ntohs(*(u_int16_t *)&in6_b->sin6_addr.s6_addr[2]);
-			in6_b->sin6_addr.s6_addr[2] =
-			    in6_b->sin6_addr.s6_addr[3] = 0;
+			if (in6_b->sin6_scope_id == 0) {
+				in6_b->sin6_scope_id =
+				    IN6_LINKLOCAL_IFINDEX(in6_b->sin6_addr);
+			}
+			SET_IN6_LINKLOCAL_IFINDEX(in6_b->sin6_addr, 0);
 		}
 #endif
 		if (bcmp(&a->v6, &in6_b->sin6_addr,
