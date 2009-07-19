Index: bgpd/rde.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde.c,v
retrieving revision 1.1.1.1
retrieving revision 1.4
diff -u -p -r1.1.1.1 -r1.4
--- bgpd/rde.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde.c	9 Jul 2009 17:26:41 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde.c,v 1.232.2.1 2009/01/30 22:37:34 claudio Exp $ */
+/*	$OpenBSD: rde.c,v 1.264 2009/06/29 12:22:16 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -38,24 +38,28 @@
 #define PFD_PIPE_MAIN		0
 #define PFD_PIPE_SESSION	1
 #define PFD_PIPE_SESSION_CTL	2
-#define PFD_MRT_FILE		3
+#define PFD_PIPE_COUNT		3
 
 void		 rde_sighdlr(int);
 void		 rde_dispatch_imsg_session(struct imsgbuf *);
 void		 rde_dispatch_imsg_parent(struct imsgbuf *);
 int		 rde_update_dispatch(struct imsg *);
+void		 rde_update_update(struct rde_peer *, struct rde_aspath *,
+		     struct bgpd_addr *, u_int8_t);
+void		 rde_update_withdraw(struct rde_peer *, struct bgpd_addr *,
+		     u_int8_t);
 int		 rde_attr_parse(u_char *, u_int16_t, struct rde_peer *,
 		     struct rde_aspath *, struct mpattr *);
 u_int8_t	 rde_attr_missing(struct rde_aspath *, int, u_int16_t);
 int		 rde_get_mp_nexthop(u_char *, u_int16_t, u_int16_t,
-		     struct rde_aspath *);
+		     struct rde_aspath *, struct rde_peer *);
 int		 rde_update_get_prefix(u_char *, u_int16_t, struct bgpd_addr *,
 		     u_int8_t *);
 int		 rde_update_get_prefix6(u_char *, u_int16_t, struct bgpd_addr *,
 		     u_int8_t *);
 void		 rde_update_err(struct rde_peer *, u_int8_t , u_int8_t,
 		     void *, u_int16_t);
-void		 rde_update_log(const char *,
+void		 rde_update_log(const char *, u_int16_t,
 		     const struct rde_peer *, const struct bgpd_addr *,
 		     const struct bgpd_addr *, u_int8_t);
 void		 rde_as4byte_fixup(struct rde_peer *, struct rde_aspath *);
@@ -67,19 +71,16 @@ void		 rde_dump_filter(struct prefix *,
 		     struct ctl_show_rib_request *);
 void		 rde_dump_filterout(struct rde_peer *, struct prefix *,
 		     struct ctl_show_rib_request *);
-void		 rde_dump_upcall(struct pt_entry *, void *);
-void		 rde_dump_as(struct ctl_show_rib_request *);
-void		 rde_dump_prefix_upcall(struct pt_entry *, void *);
-void		 rde_dump_prefix(struct ctl_show_rib_request *);
-void		 rde_dump_community(struct ctl_show_rib_request *);
+void		 rde_dump_upcall(struct rib_entry *, void *);
+void		 rde_dump_prefix_upcall(struct rib_entry *, void *);
 void		 rde_dump_ctx_new(struct ctl_show_rib_request *, pid_t,
 		     enum imsg_type);
-void		 rde_dump_runner(void);
-int		 rde_dump_pending(void);
+void		 rde_dump_mrt_new(struct mrt *, pid_t, int);
+void		 rde_dump_done(void *);
 
-void		 rde_up_dump_upcall(struct pt_entry *, void *);
-void		 rde_softreconfig_out(struct pt_entry *, void *);
-void		 rde_softreconfig_in(struct pt_entry *, void *);
+void		 rde_up_dump_upcall(struct rib_entry *, void *);
+void		 rde_softreconfig_out(struct rib_entry *, void *);
+void		 rde_softreconfig_in(struct rib_entry *, void *);
 void		 rde_update_queue_runner(void);
 void		 rde_update6_queue_runner(void);
 
@@ -96,8 +97,7 @@ void		 peer_send_eor(struct rde_peer *, 
 void		 network_init(struct network_head *);
 void		 network_add(struct network_config *, int);
 void		 network_delete(struct network_config *, int);
-void		 network_dump_upcall(struct pt_entry *, void *);
-void		 network_flush(int);
+void		 network_dump_upcall(struct rib_entry *, void *);
 
 void		 rde_shutdown(void);
 int		 sa_cmp(struct bgpd_addr *, struct sockaddr *);
@@ -106,23 +106,26 @@ volatile sig_atomic_t	 rde_quit = 0;
 struct bgpd_config	*conf, *nconf;
 time_t			 reloadtime;
 struct rde_peer_head	 peerlist;
-struct rde_peer		 peerself;
-struct rde_peer		 peerdynamic;
+struct rde_peer		*peerself;
 struct filter_head	*rules_l, *newrules;
 struct imsgbuf		*ibuf_se;
 struct imsgbuf		*ibuf_se_ctl;
 struct imsgbuf		*ibuf_main;
-struct mrt		*mrt;
 struct rde_memstats	 rdemem;
 
 struct rde_dump_ctx {
-	TAILQ_ENTRY(rde_dump_ctx)	entry;
-	struct pt_context		ptc;
+	struct rib_context		ribctx;
 	struct ctl_show_rib_request	req;
 	sa_family_t			af;
 };
 
-TAILQ_HEAD(, rde_dump_ctx) rde_dump_h = TAILQ_HEAD_INITIALIZER(rde_dump_h);
+struct rde_mrt_ctx {
+	struct mrt		 mrt;
+	struct rib_context	 ribctx;
+};
+
+struct mrt_head rde_mrts = LIST_HEAD_INITIALIZER(rde_mrts);
+u_int rde_mrt_cnt;
 
 void
 rde_sighdlr(int sig)
@@ -143,18 +146,22 @@ u_int32_t	nexthophashsize = 64;
 pid_t
 rde_main(struct bgpd_config *config, struct peer *peer_l,
     struct network_head *net_l, struct filter_head *rules,
-    struct mrt_head *mrt_l, int pipe_m2r[2], int pipe_s2r[2], int pipe_m2s[2],
-    int pipe_s2rctl[2], int debug)
+    struct mrt_head *mrt_l, struct rib_names *rib_n, int pipe_m2r[2],
+    int pipe_s2r[2], int pipe_m2s[2], int pipe_s2rctl[2], int debug)
 {
 	pid_t			 pid;
 	struct passwd		*pw;
 	struct peer		*p;
 	struct listen_addr	*la;
-	struct pollfd		 pfd[4];
+	struct pollfd		*pfd = NULL;
 	struct filter_rule	*f;
 	struct filter_set	*set;
 	struct nexthop		*nh;
-	int			 i, timeout;
+	struct rde_rib		*rr;
+	struct mrt		*mrt, *xmrt;
+	void			*newp;
+	u_int			 pfd_elms = 0, i, j;
+	int			 timeout;
 
 	switch (pid = fork()) {
 	case -1:
@@ -213,7 +220,6 @@ rde_main(struct bgpd_config *config, str
 		LIST_REMOVE(mrt, entry);
 		free(mrt);
 	}
-	mrt = NULL;
 
 	while ((la = TAILQ_FIRST(config->listen_addrs)) != NULL) {
 		TAILQ_REMOVE(config->listen_addrs, la, entry);
@@ -223,6 +229,11 @@ rde_main(struct bgpd_config *config, str
 	free(config->listen_addrs);
 
 	pt_init();
+	while ((rr = SIMPLEQ_FIRST(&ribnames))) {
+		SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
+		rib_new(-1, rr->name, rr->flags);
+		free(rr);
+	}
 	path_init(pathhashsize);
 	aspath_init(pathhashsize);
 	attr_init(attrhashsize);
@@ -234,6 +245,7 @@ rde_main(struct bgpd_config *config, str
 	log_info("route decision engine ready");
 
 	TAILQ_FOREACH(f, rules, entry) {
+		f->peer.ribid = rib_find(f->rib);
 		TAILQ_FOREACH(set, &f->set, entry) {
 			if (set->type == ACTION_SET_NEXTHOP) {
 				nh = nexthop_get(&set->action.nexthop);
@@ -243,8 +255,20 @@ rde_main(struct bgpd_config *config, str
 	}
 
 	while (rde_quit == 0) {
+		if (pfd_elms < PFD_PIPE_COUNT + rde_mrt_cnt) {
+			if ((newp = realloc(pfd, sizeof(struct pollfd) *
+			    (PFD_PIPE_COUNT + rde_mrt_cnt))) == NULL) {
+				/* panic for now  */
+				log_warn("could not resize pfd from %u -> %u"
+				    " entries", pfd_elms, PFD_PIPE_COUNT +
+				    rde_mrt_cnt);
+				fatalx("exiting");
+			}
+			pfd = newp;
+			pfd_elms = PFD_PIPE_COUNT + rde_mrt_cnt;
+		}
 		timeout = INFTIM;
-		bzero(pfd, sizeof(pfd));
+		bzero(pfd, sizeof(struct pollfd) * pfd_elms);
 		pfd[PFD_PIPE_MAIN].fd = ibuf_main->fd;
 		pfd[PFD_PIPE_MAIN].events = POLLIN;
 		if (ibuf_main->w.queued > 0)
@@ -259,14 +283,16 @@ rde_main(struct bgpd_config *config, str
 		pfd[PFD_PIPE_SESSION_CTL].events = POLLIN;
 		if (ibuf_se_ctl->w.queued > 0)
 			pfd[PFD_PIPE_SESSION_CTL].events |= POLLOUT;
-		else if (rde_dump_pending())
+		else if (rib_dump_pending())
 			timeout = 0;
 
-		i = 3;
-		if (mrt && mrt->queued) {
-			pfd[PFD_MRT_FILE].fd = mrt->fd;
-			pfd[PFD_MRT_FILE].events = POLLOUT;
-			i++;
+		i = PFD_PIPE_COUNT;
+		LIST_FOREACH(mrt, &rde_mrts, entry) {
+			if (mrt->wbuf.queued) {
+				pfd[i].fd = mrt->wbuf.fd;
+				pfd[i].events = POLLOUT;
+				i++;
+			}
 		}
 
 		if (poll(pfd, i, timeout) == -1) {
@@ -299,24 +325,39 @@ rde_main(struct bgpd_config *config, str
 		if (pfd[PFD_PIPE_SESSION_CTL].revents & POLLIN)
 			rde_dispatch_imsg_session(ibuf_se_ctl);
 
-		if (pfd[PFD_MRT_FILE].revents & POLLOUT) {
-			if (mrt_write(mrt) == -1) {
+		for (j = PFD_PIPE_COUNT, mrt = LIST_FIRST(&rde_mrts);
+		    j < i && mrt != 0; j++) {
+			xmrt = LIST_NEXT(mrt, entry);
+			if (pfd[j].fd == mrt->wbuf.fd &&
+			    pfd[j].revents & POLLOUT)
+				mrt_write(mrt);
+			if (mrt->wbuf.queued == 0 && 
+			    mrt->state == MRT_STATE_REMOVE) {
+				close(mrt->wbuf.fd);
+				LIST_REMOVE(mrt, entry);
 				free(mrt);
-				mrt = NULL;
-			} else if (mrt->queued == 0)
-				close(mrt->fd);
+				rde_mrt_cnt--;
+			}
+			mrt = xmrt;
 		}
 
 		rde_update_queue_runner();
 		rde_update6_queue_runner();
 		if (ibuf_se_ctl->w.queued <= 0)
-			rde_dump_runner();
+			rib_dump_runner();
 	}
 
 	/* do not clean up on shutdown on production, it takes ages. */
 	if (debug)
 		rde_shutdown();
 
+	while ((mrt = LIST_FIRST(&rde_mrts)) != NULL) {
+		msgbuf_clear(&mrt->wbuf);
+		close(mrt->wbuf.fd);
+		LIST_REMOVE(mrt, entry);
+		free(mrt);
+	}
+
 	msgbuf_clear(&ibuf_se->w);
 	free(ibuf_se);
 	msgbuf_clear(&ibuf_se_ctl->w);
@@ -344,7 +385,6 @@ rde_dispatch_imsg_session(struct imsgbuf
 	struct filter_set	*s;
 	struct nexthop		*nh;
 	int			 n;
-	sa_family_t		 af = AF_UNSPEC;
 
 	if ((n = imsg_read(ibuf)) == -1)
 		fatal("rde_dispatch_imsg_session: imsg_read error");
@@ -438,7 +478,8 @@ badnet:
 				log_warnx("rde_dispatch: wrong imsg len");
 				break;
 			}
-			network_flush(0);
+			prefix_network_clean(peerself, time(NULL),
+			    F_ANN_DYNAMIC);
 			break;
 		case IMSG_FILTER_SET:
 			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
@@ -462,54 +503,16 @@ badnet:
 			}
 			break;
 		case IMSG_CTL_SHOW_NETWORK:
-			if (imsg.hdr.len != IMSG_HEADER_SIZE + sizeof(af)) {
-				log_warnx("rde_dispatch: wrong imsg len");
-				break;
-			}
-			bzero(&req, sizeof(req));
-			memcpy(&req.af, imsg.data, sizeof(af));
-			rde_dump_ctx_new(&req, imsg.hdr.pid, imsg.hdr.type);
-			break;
 		case IMSG_CTL_SHOW_RIB:
-			if (imsg.hdr.len != IMSG_HEADER_SIZE + sizeof(req)) {
-				log_warnx("rde_dispatch: wrong imsg len");
-				break;
-			}
-			memcpy(&req, imsg.data, sizeof(req));
-			rde_dump_ctx_new(&req, imsg.hdr.pid, imsg.hdr.type);
-			break;
 		case IMSG_CTL_SHOW_RIB_AS:
-			if (imsg.hdr.len != IMSG_HEADER_SIZE + sizeof(req)) {
-				log_warnx("rde_dispatch: wrong imsg len");
-				break;
-			}
-			memcpy(&req, imsg.data, sizeof(req));
-			req.pid = imsg.hdr.pid;
-			rde_dump_as(&req);
-			imsg_compose(ibuf_se_ctl, IMSG_CTL_END, 0, req.pid, -1,
-			    NULL, 0);
-			break;
-		case IMSG_CTL_SHOW_RIB_PREFIX:
-			if (imsg.hdr.len != IMSG_HEADER_SIZE + sizeof(req)) {
-				log_warnx("rde_dispatch: wrong imsg len");
-				break;
-			}
-			memcpy(&req, imsg.data, sizeof(req));
-			req.pid = imsg.hdr.pid;
-			rde_dump_prefix(&req);
-			imsg_compose(ibuf_se_ctl, IMSG_CTL_END, 0, req.pid, -1,
-			    NULL, 0);
-			break;
 		case IMSG_CTL_SHOW_RIB_COMMUNITY:
+		case IMSG_CTL_SHOW_RIB_PREFIX:
 			if (imsg.hdr.len != IMSG_HEADER_SIZE + sizeof(req)) {
 				log_warnx("rde_dispatch: wrong imsg len");
 				break;
 			}
 			memcpy(&req, imsg.data, sizeof(req));
-			req.pid = imsg.hdr.pid;
-			rde_dump_community(&req);
-			imsg_compose(ibuf_se_ctl, IMSG_CTL_END, 0, req.pid, -1,
-			    NULL, 0);
+			rde_dump_ctx_new(&req, imsg.hdr.pid, imsg.hdr.type);
 			break;
 		case IMSG_CTL_SHOW_NEIGHBOR:
 			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
@@ -552,12 +555,14 @@ void
 rde_dispatch_imsg_parent(struct imsgbuf *ibuf)
 {
 	struct imsg		 imsg;
+	struct mrt		 xmrt;
+	struct rde_rib		 rn;
 	struct rde_peer		*peer;
 	struct filter_rule	*r;
 	struct filter_set	*s;
-	struct mrt		*xmrt;
 	struct nexthop		*nh;
-	int			 n, reconf_in = 0, reconf_out = 0;
+	int			 n, fd, reconf_in = 0, reconf_out = 0;
+	u_int16_t		 rid;
 
 	if ((n = imsg_read(ibuf)) == -1)
 		fatal("rde_dispatch_imsg_parent: imsg_read error");
@@ -581,6 +586,8 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			    NULL)
 				fatal(NULL);
 			memcpy(nconf, imsg.data, sizeof(struct bgpd_config));
+			for (rid = 0; rid < rib_size; rid++)
+				ribs[rid].state = RIB_DELETE;
 			break;
 		case IMSG_NETWORK_ADD:
 			memcpy(&netconf_p, imsg.data, sizeof(netconf_p));
@@ -601,6 +608,17 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			TAILQ_INIT(&netconf_p.attrset);
 			network_delete(&netconf_p, 1);
 			break;
+		case IMSG_RECONF_RIB:
+			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
+			    sizeof(struct rde_rib))
+				fatalx("IMSG_RECONF_RIB bad len");
+			memcpy(&rn, imsg.data, sizeof(rn));
+			rid = rib_find(rn.name);
+			if (rid == RIB_FAILED)
+				rib_new(-1, rn.name, rn.flags);
+			else
+				ribs[rid].state = RIB_ACTIVE;
+			break;
 		case IMSG_RECONF_FILTER:
 			if (imsg.hdr.len - IMSG_HEADER_SIZE !=
 			    sizeof(struct filter_rule))
@@ -609,6 +627,7 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 				fatal(NULL);
 			memcpy(r, imsg.data, sizeof(struct filter_rule));
 			TAILQ_INIT(&r->set);
+			r->peer.ribid = rib_find(r->rib);
 			parent_set = &r->set;
 			TAILQ_INSERT_TAIL(newrules, r, entry);
 			break;
@@ -628,10 +647,12 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			free(nconf);
 			nconf = NULL;
 			parent_set = NULL;
-			prefix_network_clean(&peerself, reloadtime);
+			prefix_network_clean(peerself, reloadtime, 0);
 
 			/* check if filter changed */
 			LIST_FOREACH(peer, &peerlist, peer_l) {
+				if (peer->conf.id == 0)
+					continue;
 				peer->reconf_out = 0;
 				peer->reconf_in = 0;
 				if (peer->conf.softreconfig_out &&
@@ -647,12 +668,18 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 					reconf_in = 1;
 				}
 			}
+			/* XXX this needs rework anyway */
 			/* sync local-RIB first */
 			if (reconf_in)
-				pt_dump(rde_softreconfig_in, NULL, AF_UNSPEC);
+				rib_dump(&ribs[0], rde_softreconfig_in, NULL,
+				    AF_UNSPEC);
 			/* then sync peers */
-			if (reconf_out)
-				pt_dump(rde_softreconfig_out, NULL, AF_UNSPEC);
+			if (reconf_out) {
+				int i;
+				for (i = 1; i < rib_size; i++)
+					rib_dump(&ribs[i], rde_softreconfig_out,
+					    NULL, AF_UNSPEC);
+			}
 
 			while ((r = TAILQ_FIRST(rules_l)) != NULL) {
 				TAILQ_REMOVE(rules_l, r, entry);
@@ -661,6 +688,10 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 			}
 			free(rules_l);
 			rules_l = newrules;
+			for (rid = 0; rid < rib_size; rid++) {
+				if (ribs[rid].state == RIB_DELETE)
+					rib_free(&ribs[rid]);
+			}
 			log_info("RDE reconfigured");
 			break;
 		case IMSG_NEXTHOP_UPDATE:
@@ -689,30 +720,15 @@ rde_dispatch_imsg_parent(struct imsgbuf 
 				log_warnx("wrong imsg len");
 				break;
 			}
-
-			xmrt = calloc(1, sizeof(struct mrt));
-			if (xmrt == NULL)
-				fatal("rde_dispatch_imsg_parent");
-			memcpy(xmrt, imsg.data, sizeof(struct mrt));
-			TAILQ_INIT(&xmrt->bufs);
-
-			if ((xmrt->fd = imsg_get_fd(ibuf)) == -1)
+			memcpy(&xmrt, imsg.data, sizeof(xmrt));
+			if ((fd = imsg.fd) == -1)
 				log_warnx("expected to receive fd for mrt dump "
 				    "but didn't receive any");
-
-			if (xmrt->type == MRT_TABLE_DUMP) {
-				/* do not dump if another is still running */
-				if (mrt == NULL || mrt->queued == 0) {
-					free(mrt);
-					mrt = xmrt;
-					mrt_clear_seq();
-					pt_dump(mrt_dump_upcall, mrt,
-					    AF_UNSPEC);
-					break;
-				}
-			}
-			close(xmrt->fd);
-			free(xmrt);
+			else if (xmrt.type == MRT_TABLE_DUMP ||
+			    xmrt.type == MRT_TABLE_DUMP_MP) {
+				rde_dump_mrt_new(&xmrt, imsg.hdr.pid, fd);
+			} else
+				close(fd);
 			break;
 		case IMSG_MRT_CLOSE:
 			/* ignore end message because a dump is atomic */
@@ -729,7 +745,7 @@ int
 rde_update_dispatch(struct imsg *imsg)
 {
 	struct rde_peer		*peer;
-	struct rde_aspath	*asp = NULL, *fasp;
+	struct rde_aspath	*asp = NULL;
 	u_char			*p, *mpp = NULL;
 	int			 error = -1, pos = 0;
 	u_int16_t		 afi, len, mplen;
@@ -795,7 +811,7 @@ rde_update_dispatch(struct imsg *imsg)
 		}
 
 		/*
-		 * if either ATTR_NEW_AGGREGATOR or ATTR_NEW_ASPATH is present
+		 * if either ATTR_AS4_AGGREGATOR or ATTR_AS4_PATH is present
 		 * try to fixup the attributes.
 		 * XXX do not fixup if F_ATTR_LOOP is set.
 		 */
@@ -808,6 +824,8 @@ rde_update_dispatch(struct imsg *imsg)
 		    peer->conf.enforce_as == ENFORCE_AS_ON)
 			if (peer->conf.remote_as !=
 			    aspath_neighbor(asp->aspath)) {
+				log_peer_warnx(&peer->conf, "bad path, "
+				    "enforce remote-as enabled");
 				rde_update_err(peer, ERR_UPDATE, ERR_UPD_ASPATH,
 				    NULL, 0);
 				goto done;
@@ -850,14 +868,19 @@ rde_update_dispatch(struct imsg *imsg)
 			goto done;
 		}
 
-		peer->prefix_rcvd_withdraw++;
-		rde_update_log("withdraw", peer, NULL, &prefix, prefixlen);
-		prefix_remove(peer, &prefix, prefixlen, F_LOCAL);
-		prefix_remove(peer, &prefix, prefixlen, F_ORIGINAL);
+		rde_update_withdraw(peer, &prefix, prefixlen);
 	}
 
-	if (attrpath_len == 0) /* 0 = no NLRI information in this message */
+	if (attrpath_len == 0) {
+		/* 0 = no NLRI information in this message */
+		if (nlri_len != 0) {
+			/* crap at end of update which should not be there */
+			rde_update_err(peer, ERR_UPDATE,
+			    ERR_UPD_ATTRLIST, NULL, 0);
+			return (-1);
+		}
 		return (0);
+	}
 
 	/* withdraw MP_UNREACH_NLRI if available */
 	if (mpa.unreach_len != 0) {
@@ -900,13 +923,7 @@ rde_update_dispatch(struct imsg *imsg)
 				mpp += pos;
 				mplen -= pos;
 
-				peer->prefix_rcvd_withdraw++;
-				rde_update_log("withdraw", peer, NULL,
-				    &prefix, prefixlen);
-				prefix_remove(peer, &prefix, prefixlen,
-				    F_LOCAL);
-				prefix_remove(peer, &prefix, prefixlen,
-				    F_ORIGINAL);
+				rde_update_withdraw(peer, &prefix, prefixlen);
 			}
 			break;
 		default:
@@ -954,17 +971,7 @@ rde_update_dispatch(struct imsg *imsg)
 			goto done;
 		}
 
-		peer->prefix_rcvd_update++;
-		/* add original path to the Adj-RIB-In */
-		if (peer->conf.softreconfig_in)
-			path_update(peer, asp, &prefix, prefixlen, F_ORIGINAL);
-
-		/* input filter */
-		if (rde_filter(&fasp, rules_l, peer, asp, &prefix, prefixlen,
-		    peer, DIR_IN) == ACTION_DENY) {
-			path_put(fasp);
-			continue;
-		}
+		rde_update_update(peer, asp, &prefix, prefixlen);
 
 		/* max prefix checker */
 		if (peer->conf.max_prefix &&
@@ -972,20 +979,9 @@ rde_update_dispatch(struct imsg *imsg)
 			log_peer_warnx(&peer->conf, "prefix limit reached");
 			rde_update_err(peer, ERR_CEASE, ERR_CEASE_MAX_PREFIX,
 			    NULL, 0);
-			path_put(fasp);
 			goto done;
 		}
 
-		if (fasp == NULL)
-			fasp = asp;
-
-		rde_update_log("update", peer, &fasp->nexthop->exit_nexthop,
-		    &prefix, prefixlen);
-		path_update(peer, fasp, &prefix, prefixlen, F_LOCAL);
-
-		/* free modified aspath */
-		if (fasp != asp)
-			path_put(fasp);
 	}
 
 	/* add MP_REACH_NLRI if available */
@@ -1008,7 +1004,7 @@ rde_update_dispatch(struct imsg *imsg)
 			(void)nexthop_delete(asp->nexthop);
 			asp->nexthop = NULL;
 		}
-		if ((pos = rde_get_mp_nexthop(mpp, mplen, afi, asp)) == -1) {
+		if ((pos = rde_get_mp_nexthop(mpp, mplen, afi, asp, peer)) == -1) {
 			log_peer_warnx(&peer->conf, "bad IPv6 nlri prefix");
 			rde_update_err(peer, ERR_UPDATE, ERR_UPD_OPTATTR,
 			    mpa.reach, mpa.reach_len);
@@ -1047,19 +1043,8 @@ rde_update_dispatch(struct imsg *imsg)
 				mpp += pos;
 				mplen -= pos;
 
-				peer->prefix_rcvd_update++;
-				/* add original path to the Adj-RIB-In */
-				if (peer->conf.softreconfig_in)
-					path_update(peer, asp, &prefix,
-					    prefixlen, F_ORIGINAL);
-
-				/* input filter */
-				if (rde_filter(&fasp, rules_l, peer, asp,
-				    &prefix, prefixlen, peer, DIR_IN) ==
-				    ACTION_DENY) {
-					path_put(fasp);
-					continue;
-				}
+				rde_update_update(peer, asp, &prefix,
+				    prefixlen);
 
 				/* max prefix checker */
 				if (peer->conf.max_prefix &&
@@ -1068,22 +1053,9 @@ rde_update_dispatch(struct imsg *imsg)
 					    "prefix limit reached");
 					rde_update_err(peer, ERR_CEASE,
 					    ERR_CEASE_MAX_PREFIX, NULL, 0);
-					path_put(fasp);
 					goto done;
 				}
 
-				if (fasp == NULL)
-					fasp = asp;
-
-				rde_update_log("update", peer,
-				    &asp->nexthop->exit_nexthop,
-				    &prefix, prefixlen);
-				path_update(peer, fasp, &prefix, prefixlen,
-				    F_LOCAL);
-
-				/* free modified aspath */
-				if (fasp != asp)
-					path_put(fasp);
 			}
 			break;
 		default:
@@ -1106,6 +1078,67 @@ done:
 	return (error);
 }
 
+extern u_int16_t rib_size;
+
+void
+rde_update_update(struct rde_peer *peer, struct rde_aspath *asp,
+    struct bgpd_addr *prefix, u_int8_t prefixlen)
+{
+	struct rde_aspath	*fasp;
+	int			 r = 0;
+	u_int16_t		 i;
+
+	peer->prefix_rcvd_update++;
+	/* add original path to the Adj-RIB-In */
+	if (peer->conf.softreconfig_in)
+		r += path_update(&ribs[0], peer, asp, prefix, prefixlen);
+
+	for (i = 1; i < rib_size; i++) {
+		/* input filter */
+		if (rde_filter(i, &fasp, rules_l, peer, asp, prefix, prefixlen,
+		    peer, DIR_IN) == ACTION_DENY)
+			goto done;
+
+		if (fasp == NULL)
+			fasp = asp;
+
+		rde_update_log("update", i, peer, &fasp->nexthop->exit_nexthop,
+		    prefix, prefixlen);
+		r += path_update(&ribs[i], peer, fasp, prefix, prefixlen);
+
+done:
+		/* free modified aspath */
+		if (fasp != asp)
+			path_put(fasp);
+	}
+
+	if (r)
+		peer->prefix_cnt++;
+}
+
+void
+rde_update_withdraw(struct rde_peer *peer, struct bgpd_addr *prefix,
+    u_int8_t prefixlen)
+{
+	int r = 0;
+	u_int16_t i;
+
+	peer->prefix_rcvd_withdraw++;
+
+	for (i = rib_size - 1; ; i--) {
+		if (prefix_remove(&ribs[i], peer, prefix, prefixlen, 0)) {
+			rde_update_log("withdraw", i, peer, NULL, prefix,
+			    prefixlen);
+			r++;
+		}
+		if (i == 0)
+			break;
+	}
+
+	if (r)
+		peer->prefix_cnt--;
+}
+
 /*
  * BGP UPDATE parser functions
  */
@@ -1336,7 +1369,7 @@ bad_flags:
 		mpa->unreach_len = attr_len;
 		plen += attr_len;
 		break;
-	case ATTR_NEW_AGGREGATOR:
+	case ATTR_AS4_AGGREGATOR:
 		if (attr_len != 8)
 			goto bad_len;
 		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL|ATTR_TRANSITIVE,
@@ -1344,7 +1377,7 @@ bad_flags:
 			goto bad_flags;
 		a->flags |= F_ATTR_AS4BYTE_NEW;
 		goto optattr;
-	case ATTR_NEW_ASPATH:
+	case ATTR_AS4_PATH:
 		if (!CHECK_FLAGS(flags, ATTR_OPTIONAL|ATTR_TRANSITIVE,
 		    ATTR_PARTIAL))
 			goto bad_flags;
@@ -1408,7 +1441,7 @@ rde_attr_missing(struct rde_aspath *a, i
 
 int
 rde_get_mp_nexthop(u_char *data, u_int16_t len, u_int16_t afi,
-    struct rde_aspath *asp)
+    struct rde_aspath *asp, struct rde_peer *peer)
 {
 	struct bgpd_addr	nexthop;
 	u_int8_t		totlen, nhlen;
@@ -1440,6 +1473,18 @@ rde_get_mp_nexthop(u_char *data, u_int16
 		}
 		nexthop.af = AF_INET6;
 		memcpy(&nexthop.v6.s6_addr, data, 16);
+#if defined(__KAME__) && defined(IPV6_LINKLOCAL_PEER)
+		if (IN6_IS_ADDR_LINKLOCAL(&nexthop.v6) &&
+		    peer->conf.lliface[0]) {
+			int ifindex;
+
+			ifindex = if_nametoindex(peer->conf.lliface);
+			if (ifindex != 0)
+				SET_IN6_LINKLOCAL_IFINDEX(nexthop.v6, ifindex);
+			else
+				log_warnx("bad interface: %s", peer->conf.lliface);
+		}
+#endif
 		asp->nexthop = nexthop_get(&nexthop);
 		/*
 		 * lock the nexthop because it is not yet linked else
@@ -1540,13 +1585,12 @@ rde_update_err(struct rde_peer *peer, u_
 	    imsg_add(wbuf, &suberr, sizeof(suberr)) == -1 ||
 	    imsg_add(wbuf, data, size) == -1)
 		fatal("imsg_add error");
-	if (imsg_close(ibuf_se, wbuf) == -1)
-		fatal("imsg_close error");
+	imsg_close(ibuf_se, wbuf);
 	peer->state = PEER_ERR;
 }
 
 void
-rde_update_log(const char *message,
+rde_update_log(const char *message, u_int16_t rid,
     const struct rde_peer *peer, const struct bgpd_addr *next,
     const struct bgpd_addr *prefix, u_int8_t prefixlen)
 {
@@ -1563,7 +1607,7 @@ rde_update_log(const char *message,
 	if (asprintf(&p, "%s/%u", log_addr(prefix), prefixlen) == -1)
 		p = NULL;
 	l = log_fmt_peer(&peer->conf);
-	log_info("%s AS%s: %s %s%s",
+	log_info("Rib %s: %s AS%s: %s %s%s", ribs[rid].name,
 	    l, log_as(peer->conf.remote_as), message,
 	    p ? p : "out of memory", n ? n : "");
 
@@ -1585,8 +1629,8 @@ rde_as4byte_fixup(struct rde_peer *peer,
 	u_int32_t	 as;
 
 	/* first get the attributes */
-	nasp = attr_optget(a, ATTR_NEW_ASPATH);
-	naggr = attr_optget(a, ATTR_NEW_AGGREGATOR);
+	nasp = attr_optget(a, ATTR_AS4_PATH);
+	naggr = attr_optget(a, ATTR_AS4_AGGREGATOR);
 
 	if (rde_as4byte(peer)) {
 		/* NEW session using 4-byte ASNs */
@@ -1601,7 +1645,7 @@ rde_as4byte_fixup(struct rde_peer *peer,
 	if ((oaggr = attr_optget(a, ATTR_AGGREGATOR))) {
 		memcpy(&as, oaggr->data, sizeof(as));
 		if (ntohl(as) != AS_TRANS) {
-			/* per RFC draft ignore NEW_ASPATH and NEW_AGGREGATOR */
+			/* per RFC ignore AS4_PATH and AS4_AGGREGATOR */
 			if (nasp)
 				attr_free(a, nasp);
 			if (naggr)
@@ -1616,11 +1660,11 @@ rde_as4byte_fixup(struct rde_peer *peer,
 				fatalx("attr_optadd failed but impossible");
 		}
 	}
-	/* there is no need for NEW_AGGREGATOR any more */
+	/* there is no need for AS4_AGGREGATOR any more */
 	if (naggr)
 		attr_free(a, naggr);
 
-	/* merge NEW_ASPATH with ASPATH */
+	/* merge AS4_PATH with ASPATH */
 	if (nasp)
 		aspath_merge(a, nasp);
 }
@@ -1703,7 +1747,6 @@ rde_dump_rib_as(struct prefix *p, struct
 	rib.med = asp->med;
 	rib.prefix_cnt = asp->prefix_cnt;
 	rib.active_cnt = asp->active_cnt;
-	rib.adjrib_cnt = asp->adjrib_cnt;
 	strlcpy(rib.descr, asp->peer->conf.descr, sizeof(rib.descr));
 	memcpy(&rib.remote_addr, &asp->peer->remote_addr,
 	    sizeof(rib.remote_addr));
@@ -1724,7 +1767,7 @@ rde_dump_rib_as(struct prefix *p, struct
 	rib.prefixlen = p->prefix->prefixlen;
 	rib.origin = asp->origin;
 	rib.flags = 0;
-	if (p->prefix->active == p)
+	if (p->rib->active == p)
 		rib.flags |= F_RIB_ACTIVE;
 	if (asp->peer->conf.ebgp == 0)
 		rib.flags |= F_RIB_INTERNAL;
@@ -1743,8 +1786,7 @@ rde_dump_rib_as(struct prefix *p, struct
 	    imsg_add(wbuf, aspath_dump(asp->aspath),
 	    rib.aspath_len) == -1)
 		return;
-	if (imsg_close(ibuf_se_ctl, wbuf) == -1)
-		return;
+	imsg_close(ibuf_se_ctl, wbuf);
 
 	if (flags & F_CTL_DETAIL)
 		for (l = 0; l < asp->others_len; l++) {
@@ -1763,8 +1805,7 @@ rde_dump_rib_as(struct prefix *p, struct
 				buf_free(wbuf);
 				return;
 			}
-			if (imsg_close(ibuf_se_ctl, wbuf) == -1)
-				return;
+			imsg_close(ibuf_se_ctl, wbuf);
 		}
 }
 
@@ -1780,7 +1821,7 @@ rde_dump_filterout(struct rde_peer *peer
 		return;
 
 	pt_getaddr(p->prefix, &addr);
-	a = rde_filter(&asp, rules_l, peer, p->aspath, &addr,
+	a = rde_filter(1 /* XXX */, &asp, rules_l, peer, p->aspath, &addr,
 	    p->prefix->prefixlen, p->aspath->peer, DIR_OUT);
 	if (asp)
 		asp->peer = p->aspath->peer;
@@ -1799,108 +1840,57 @@ rde_dump_filter(struct prefix *p, struct
 {
 	struct rde_peer		*peer;
 
-	if ((req->flags & F_CTL_ADJ_IN && p->flags & F_ORIGINAL) ||
-	    (!(req->flags & (F_CTL_ADJ_IN|F_CTL_ADJ_OUT)) &&
-	    p->flags & F_LOCAL)) {
+	if (req->flags & F_CTL_ADJ_IN || 
+	    !(req->flags & (F_CTL_ADJ_IN|F_CTL_ADJ_OUT))) {
 		if (req->peerid && req->peerid != p->aspath->peer->conf.id)
 			return;
+		if (req->type == IMSG_CTL_SHOW_RIB_AS && 
+		    !aspath_match(p->aspath->aspath, req->as.type, req->as.as))
+			return;
+		if (req->type == IMSG_CTL_SHOW_RIB_COMMUNITY &&
+		    !rde_filter_community(p->aspath, req->community.as,
+		    req->community.type))
+			return;
 		rde_dump_rib_as(p, p->aspath, req->pid, req->flags);
-	} else if (req->flags & F_CTL_ADJ_OUT && p->flags & F_LOCAL) {
-		if (p->prefix->active != p)
+	} else if (req->flags & F_CTL_ADJ_OUT) {
+		if (p->rib->active != p)
 			/* only consider active prefix */
 			return;
-
 		if (req->peerid) {
 			if ((peer = peer_get(req->peerid)) != NULL)
 				rde_dump_filterout(peer, p, req);
 			return;
 		}
-		LIST_FOREACH(peer, &peerlist, peer_l)
-			rde_dump_filterout(peer, p, req);
 	}
 }
 
 void
-rde_dump_upcall(struct pt_entry *pt, void *ptr)
+rde_dump_upcall(struct rib_entry *re, void *ptr)
 {
 	struct prefix		*p;
-	struct ctl_show_rib_request	*req = ptr;
+	struct rde_dump_ctx	*ctx = ptr;
 
-	LIST_FOREACH(p, &pt->prefix_h, prefix_l)
-		rde_dump_filter(p, req);
+	LIST_FOREACH(p, &re->prefix_h, rib_l)
+		rde_dump_filter(p, &ctx->req);
 }
 
 void
-rde_dump_as(struct ctl_show_rib_request *req)
+rde_dump_prefix_upcall(struct rib_entry *re, void *ptr)
 {
-	extern struct path_table	 pathtable;
-	struct rde_aspath		*asp;
-	struct prefix			*p;
-	u_int32_t			 i;
-
-	for (i = 0; i <= pathtable.path_hashmask; i++) {
-		LIST_FOREACH(asp, &pathtable.path_hashtbl[i], path_l) {
-			if (!aspath_match(asp->aspath, req->as.type,
-			    req->as.as))
-				continue;
-			/* match found */
-			LIST_FOREACH(p, &asp->prefix_h, path_l)
-				rde_dump_filter(p, req);
-		}
-	}
-}
-
-void
-rde_dump_prefix_upcall(struct pt_entry *pt, void *ptr)
-{
-	struct ctl_show_rib_request	*req = ptr;
-	struct prefix			*p;
-	struct bgpd_addr		 addr;
+	struct rde_dump_ctx	*ctx = ptr;
+	struct prefix		*p;
+	struct pt_entry		*pt;
+	struct bgpd_addr	 addr;
 
+	pt = re->prefix;
 	pt_getaddr(pt, &addr);
-	if (addr.af != req->prefix.af)
+	if (addr.af != ctx->req.prefix.af)
 		return;
-	if (req->prefixlen > pt->prefixlen)
+	if (ctx->req.prefixlen > pt->prefixlen)
 		return;
-	if (!prefix_compare(&req->prefix, &addr, req->prefixlen))
-		LIST_FOREACH(p, &pt->prefix_h, prefix_l)
-			rde_dump_filter(p, req);
-}
-
-void
-rde_dump_prefix(struct ctl_show_rib_request *req)
-{
-	struct pt_entry	*pt;
-
-	if (req->prefixlen == 32) {
-		if ((pt = pt_lookup(&req->prefix)) != NULL)
-			rde_dump_upcall(pt, req);
-	} else if (req->flags & F_LONGER) {
-		pt_dump(rde_dump_prefix_upcall, req, req->prefix.af);
-	} else {
-		if ((pt = pt_get(&req->prefix, req->prefixlen)) != NULL)
-			rde_dump_upcall(pt, req);
-	}
-}
-
-void
-rde_dump_community(struct ctl_show_rib_request *req)
-{
-	extern struct path_table	 pathtable;
-	struct rde_aspath		*asp;
-	struct prefix			*p;
-	u_int32_t			 i;
-
-	for (i = 0; i <= pathtable.path_hashmask; i++) {
-		LIST_FOREACH(asp, &pathtable.path_hashtbl[i], path_l) {
-			if (!rde_filter_community(asp, req->community.as,
-			    req->community.type))
-				continue;
-			/* match found */
-			LIST_FOREACH(p, &asp->prefix_h, path_l)
-				rde_dump_filter(p, req);
-		}
-	}
+	if (!prefix_compare(&ctx->req.prefix, &addr, ctx->req.prefixlen))
+		LIST_FOREACH(p, &re->prefix_h, rib_l)
+			rde_dump_filter(p, &ctx->req);
 }
 
 void
@@ -1908,7 +1898,9 @@ rde_dump_ctx_new(struct ctl_show_rib_req
     enum imsg_type type)
 {
 	struct rde_dump_ctx	*ctx;
+	struct rib_entry	*re;
 	u_int			 error;
+	u_int16_t		 id;
 
 	if ((ctx = calloc(1, sizeof(*ctx))) == NULL) {
 		log_warn("rde_dump_ctx_new");
@@ -1917,52 +1909,89 @@ rde_dump_ctx_new(struct ctl_show_rib_req
 		    sizeof(error));
 		return;
 	}
+	if ((id = rib_find(req->rib)) == RIB_FAILED) {
+		log_warnx("rde_dump_ctx_new: no such rib %s", req->rib);
+		error = CTL_RES_NOSUCHPEER;
+		imsg_compose(ibuf_se_ctl, IMSG_CTL_RESULT, 0, pid, -1, &error,
+		    sizeof(error));
+		return;
+	}
+
 	memcpy(&ctx->req, req, sizeof(struct ctl_show_rib_request));
 	ctx->req.pid = pid;
 	ctx->req.type = type;
-	ctx->ptc.count = RDE_RUNNER_ROUNDS;
-	ctx->af = ctx->req.af;
-	if (ctx->af == AF_UNSPEC)
-		ctx->af = AF_INET;
-
-	TAILQ_INSERT_TAIL(&rde_dump_h, ctx, entry);
+	ctx->ribctx.ctx_count = RDE_RUNNER_ROUNDS;
+	ctx->ribctx.ctx_rib = &ribs[id];
+	switch (ctx->req.type) {
+	case IMSG_CTL_SHOW_NETWORK:
+		ctx->ribctx.ctx_upcall = network_dump_upcall;
+		break;
+	case IMSG_CTL_SHOW_RIB:
+	case IMSG_CTL_SHOW_RIB_AS:
+	case IMSG_CTL_SHOW_RIB_COMMUNITY:
+		ctx->ribctx.ctx_upcall = rde_dump_upcall;
+		break;
+	case IMSG_CTL_SHOW_RIB_PREFIX:
+		if (req->flags & F_LONGER) {
+			ctx->ribctx.ctx_upcall = rde_dump_prefix_upcall;
+			break;
+		}
+		if (req->prefixlen == 32)
+			re = rib_lookup(&ribs[id], &req->prefix);
+		else
+			re = rib_get(&ribs[id], &req->prefix, req->prefixlen);
+		if (re)
+			rde_dump_upcall(re, ctx);
+		rde_dump_done(ctx);
+		return;
+	default:
+		fatalx("rde_dump_ctx_new: unsupported imsg type");
+	}
+	ctx->ribctx.ctx_done = rde_dump_done;
+	ctx->ribctx.ctx_arg = ctx;
+	ctx->ribctx.ctx_af = ctx->req.af;
+	rib_dump_r(&ctx->ribctx);
 }
 
 void
-rde_dump_runner(void)
+rde_dump_done(void *arg)
 {
-	struct rde_dump_ctx	*ctx, *next;
+	struct rde_dump_ctx	*ctx = arg;
 
-	for (ctx = TAILQ_FIRST(&rde_dump_h); ctx != NULL; ctx = next) {
-		next = TAILQ_NEXT(ctx, entry);
-		if (ctx->ptc.done) {
-			imsg_compose(ibuf_se_ctl, IMSG_CTL_END, 0, ctx->req.pid,
-			    -1, NULL, 0);
-			TAILQ_REMOVE(&rde_dump_h, ctx, entry);
-			free(ctx);
-			continue;
-		}
-		switch (ctx->req.type) {
-		case IMSG_CTL_SHOW_NETWORK:
-			pt_dump_r(network_dump_upcall, &ctx->req.pid,
-			    ctx->af, &ctx->ptc);
-			break;
-		case IMSG_CTL_SHOW_RIB:
-			pt_dump_r(rde_dump_upcall, &ctx->req, ctx->af,
-			    &ctx->ptc);
-			break;
-		default:
-			fatalx("rde_dump_runner: unsupported imsg type");
-		}
-		if (ctx->ptc.done && ctx->req.af == AF_UNSPEC)
-			ctx->af = AF_INET6;
-	}
+	imsg_compose(ibuf_se_ctl, IMSG_CTL_END, 0, ctx->req.pid,
+	    -1, NULL, 0);
+	free(ctx);
 }
 
-int
-rde_dump_pending(void)
+void
+rde_dump_mrt_new(struct mrt *mrt, pid_t pid, int fd)
 {
-	return (!TAILQ_EMPTY(&rde_dump_h));
+	struct rde_mrt_ctx	*ctx;
+	u_int16_t		 id;
+
+	if ((ctx = calloc(1, sizeof(*ctx))) == NULL) {
+		log_warn("rde_dump_mrt_new");
+		return;
+	}
+	memcpy(&ctx->mrt, mrt, sizeof(struct mrt));
+	TAILQ_INIT(&ctx->mrt.wbuf.bufs);
+	ctx->mrt.wbuf.fd = fd;
+	ctx->mrt.state = MRT_STATE_RUNNING;
+	id = rib_find(ctx->mrt.rib);
+	if (id == RIB_FAILED) {
+		log_warnx("non existing RIB %s for mrt dump", ctx->mrt.rib);
+		free(ctx);
+		return;
+	}
+	ctx->ribctx.ctx_count = RDE_RUNNER_ROUNDS;
+	ctx->ribctx.ctx_rib = &ribs[id];
+	ctx->ribctx.ctx_upcall = mrt_dump_upcall;
+	ctx->ribctx.ctx_done = mrt_dump_done;
+	ctx->ribctx.ctx_arg = &ctx->mrt;
+	ctx->ribctx.ctx_af = AF_UNSPEC;
+	LIST_INSERT_HEAD(&rde_mrts, &ctx->mrt, entry);
+	rde_mrt_cnt++;
+	rib_dump_r(&ctx->ribctx);
 }
 
 /*
@@ -2100,9 +2129,10 @@ rde_send_nexthop(struct bgpd_addr *next,
  * soft reconfig specific functions
  */
 void
-rde_softreconfig_out(struct pt_entry *pt, void *ptr)
+rde_softreconfig_out(struct rib_entry *re, void *ptr)
 {
-	struct prefix		*p = pt->active;
+	struct prefix		*p = re->active;
+	struct pt_entry		*pt;
 	struct rde_peer		*peer;
 	struct rde_aspath	*oasp, *nasp;
 	enum filter_actions	 oa, na;
@@ -2111,17 +2141,22 @@ rde_softreconfig_out(struct pt_entry *pt
 	if (p == NULL)
 		return;
 
+	pt = re->prefix;
 	pt_getaddr(pt, &addr);
 	LIST_FOREACH(peer, &peerlist, peer_l) {
+		if (peer->conf.id == 0)
+			continue;
+		if (peer->ribid != re->ribid)
+			continue;
 		if (peer->reconf_out == 0)
 			continue;
 		if (up_test_update(peer, p) != 1)
 			continue;
 
-		oa = rde_filter(&oasp, rules_l, peer, p->aspath, &addr,
-		    pt->prefixlen, p->aspath->peer, DIR_OUT);
-		na = rde_filter(&nasp, newrules, peer, p->aspath, &addr,
-		    pt->prefixlen, p->aspath->peer, DIR_OUT);
+		oa = rde_filter(re->ribid, &oasp, rules_l, peer, p->aspath,
+		    &addr, pt->prefixlen, p->aspath->peer, DIR_OUT);
+		na = rde_filter(re->ribid, &nasp, newrules, peer, p->aspath,
+		    &addr, pt->prefixlen, p->aspath->peer, DIR_OUT);
 		oasp = oasp != NULL ? oasp : p->aspath;
 		nasp = nasp != NULL ? nasp : p->aspath;
 
@@ -2154,60 +2189,67 @@ done:
 }
 
 void
-rde_softreconfig_in(struct pt_entry *pt, void *ptr)
+rde_softreconfig_in(struct rib_entry *re, void *ptr)
 {
 	struct prefix		*p, *np;
+	struct pt_entry		*pt;
 	struct rde_peer		*peer;
 	struct rde_aspath	*asp, *oasp, *nasp;
 	enum filter_actions	 oa, na;
 	struct bgpd_addr	 addr;
+	u_int16_t		 i;
 
+	pt = re->prefix;
 	pt_getaddr(pt, &addr);
-	for (p = LIST_FIRST(&pt->prefix_h); p != NULL; p = np) {
-		np = LIST_NEXT(p, prefix_l);
-		if (!(p->flags & F_ORIGINAL))
-			continue;
+	for (p = LIST_FIRST(&re->prefix_h); p != NULL; p = np) {
+		np = LIST_NEXT(p, rib_l);
 
 		/* store aspath as prefix may change till we're done */
 		asp = p->aspath;
 		peer = asp->peer;
 
+		/* XXX how can this happen ??? */
 		if (peer->reconf_in == 0)
 			continue;
 
-		/* check if prefix changed */
-		oa = rde_filter(&oasp, rules_l, peer, asp, &addr,
-		    pt->prefixlen, peer, DIR_IN);
-		na = rde_filter(&nasp, newrules, peer, asp, &addr,
-		    pt->prefixlen, peer, DIR_IN);
-		oasp = oasp != NULL ? oasp : asp;
-		nasp = nasp != NULL ? nasp : asp;
+		for (i = 1; i < rib_size; i++) {
+			/* check if prefix changed */
+			oa = rde_filter(i, &oasp, rules_l, peer, asp, &addr,
+			    pt->prefixlen, peer, DIR_IN);
+			na = rde_filter(i, &nasp, newrules, peer, asp, &addr,
+			    pt->prefixlen, peer, DIR_IN);
+			oasp = oasp != NULL ? oasp : asp;
+			nasp = nasp != NULL ? nasp : asp;
 
-		if (oa == ACTION_DENY && na == ACTION_DENY)
-			/* nothing todo */
-			goto done;
-		if (oa == ACTION_DENY && na == ACTION_ALLOW) {
-			/* update Local-RIB */
-			path_update(peer, nasp, &addr, pt->prefixlen, F_LOCAL);
-			goto done;
-		}
-		if (oa == ACTION_ALLOW && na == ACTION_DENY) {
-			/* remove from Local-RIB */
-			prefix_remove(peer, &addr, pt->prefixlen, F_LOCAL);
-			goto done;
-		}
-		if (oa == ACTION_ALLOW && na == ACTION_ALLOW) {
-			if (path_compare(nasp, oasp) == 0)
+			if (oa == ACTION_DENY && na == ACTION_DENY)
+				/* nothing todo */
 				goto done;
-			/* send update */
-			path_update(peer, nasp, &addr, pt->prefixlen, F_LOCAL);
-		}
+			if (oa == ACTION_DENY && na == ACTION_ALLOW) {
+				/* update Local-RIB */
+				path_update(&ribs[i], peer, nasp, &addr,
+				    pt->prefixlen);
+				goto done;
+			}
+			if (oa == ACTION_ALLOW && na == ACTION_DENY) {
+				/* remove from Local-RIB */
+				prefix_remove(&ribs[i], peer, &addr,
+				    pt->prefixlen, 0);
+				goto done;
+			}
+			if (oa == ACTION_ALLOW && na == ACTION_ALLOW) {
+				if (path_compare(nasp, oasp) == 0)
+					goto done;
+				/* send update */
+				path_update(&ribs[1], peer, nasp, &addr,
+				    pt->prefixlen);
+			}
 
 done:
-		if (oasp != asp)
-			path_put(oasp);
-		if (nasp != asp)
-			path_put(nasp);
+			if (oasp != asp)
+				path_put(oasp);
+			if (nasp != asp)
+				path_put(nasp);
+		}
 	}
 }
 
@@ -2217,17 +2259,19 @@ done:
 u_char	queue_buf[4096];
 
 void
-rde_up_dump_upcall(struct pt_entry *pt, void *ptr)
+rde_up_dump_upcall(struct rib_entry *re, void *ptr)
 {
 	struct rde_peer		*peer = ptr;
 
-	if (pt->active == NULL)
+	if (re->ribid != peer->ribid)
+		fatalx("King Bula: monsterous evil horror.");
+	if (re->active == NULL)
 		return;
-	up_generate_updates(rules_l, peer, pt->active, NULL);
+	up_generate_updates(rules_l, peer, re->active, NULL);
 }
 
 void
-rde_generate_updates(struct prefix *new, struct prefix *old)
+rde_generate_updates(u_int16_t ribid, struct prefix *new, struct prefix *old)
 {
 	struct rde_peer			*peer;
 
@@ -2240,6 +2284,10 @@ rde_generate_updates(struct prefix *new,
 		return;
 
 	LIST_FOREACH(peer, &peerlist, peer_l) {
+		if (peer->conf.id == 0)
+			continue;
+		if (peer->ribid != ribid)
+			continue;
 		if (peer->state != PEER_UP)
 			continue;
 		up_generate_updates(rules_l, peer, new, old);
@@ -2257,6 +2305,8 @@ rde_update_queue_runner(void)
 	do {
 		sent = 0;
 		LIST_FOREACH(peer, &peerlist, peer_l) {
+			if (peer->conf.id == 0)
+				continue;
 			if (peer->state != PEER_UP)
 				continue;
 			/* first withdraws */
@@ -2303,6 +2353,8 @@ rde_update6_queue_runner(void)
 	do {
 		sent = 0;
 		LIST_FOREACH(peer, &peerlist, peer_l) {
+			if (peer->conf.id == 0)
+				continue;
 			if (peer->state != PEER_UP)
 				continue;
 			len = sizeof(queue_buf) - MSGSIZE_HEADER;
@@ -2324,6 +2376,8 @@ rde_update6_queue_runner(void)
 	do {
 		sent = 0;
 		LIST_FOREACH(peer, &peerlist, peer_l) {
+			if (peer->conf.id == 0)
+				continue;
 			if (peer->state != PEER_UP)
 				continue;
 			len = sizeof(queue_buf) - MSGSIZE_HEADER;
@@ -2386,6 +2440,8 @@ struct peer_table {
 void
 peer_init(u_int32_t hashsize)
 {
+	struct peer_config pc;
+	struct in_addr   id;
 	u_int32_t	 hs, i;
 
 	for (hs = 1; hs < hashsize; hs <<= 1)
@@ -2399,6 +2455,19 @@ peer_init(u_int32_t hashsize)
 	LIST_INIT(&peerlist);
 
 	peertable.peer_hashmask = hs - 1;
+
+	bzero(&pc, sizeof(pc));
+	pc.remote_as = conf->as;
+	id.s_addr = conf->bgpid;
+	snprintf(pc.descr, sizeof(pc.descr), "LOCAL: ID %s", inet_ntoa(id));
+
+	peerself = peer_add(0, &pc);
+	if (peerself == NULL)
+		fatalx("peer_init add self");
+
+	peerself->state = PEER_UP;
+	peerself->remote_bgpid = ntohl(conf->bgpid);
+	peerself->short_as = conf->short_as;
 }
 
 void
@@ -2444,6 +2513,7 @@ peer_add(u_int32_t id, struct peer_confi
 	LIST_INIT(&peer->path_h);
 	memcpy(&peer->conf, p_conf, sizeof(struct peer_config));
 	peer->remote_bgpid = 0;
+	peer->ribid = rib_find(peer->conf.rib);
 	peer->state = PEER_NONE;
 	up_init(peer);
 
@@ -2573,6 +2643,7 @@ peer_down(u_int32_t id)
 		path_remove(asp);
 	}
 	LIST_INIT(&peer->path_h);
+	peer->prefix_cnt = 0;
 
 	/* Deletions are performed in path_remove() */
 	rde_send_pftable_commit();
@@ -2595,19 +2666,19 @@ peer_dump(u_int32_t id, u_int16_t afi, u
 
 	if (afi == AFI_ALL || afi == AFI_IPv4)
 		if (safi == SAFI_ALL || safi == SAFI_UNICAST) {
-			if (peer->conf.announce_type ==
-			    ANNOUNCE_DEFAULT_ROUTE)
+			if (peer->conf.announce_type == ANNOUNCE_DEFAULT_ROUTE)
 				up_generate_default(rules_l, peer, AF_INET);
 			else
-				pt_dump(rde_up_dump_upcall, peer, AF_INET);
+				rib_dump(&ribs[peer->ribid], rde_up_dump_upcall,
+				    peer, AF_INET);
 		}
 	if (afi == AFI_ALL || afi == AFI_IPv6)
 		if (safi == SAFI_ALL || safi == SAFI_UNICAST) {
-			if (peer->conf.announce_type ==
-			    ANNOUNCE_DEFAULT_ROUTE)
+			if (peer->conf.announce_type == ANNOUNCE_DEFAULT_ROUTE)
 				up_generate_default(rules_l, peer, AF_INET6);
 			else
-				pt_dump(rde_up_dump_upcall, peer, AF_INET6);
+				rib_dump(&ribs[peer->ribid], rde_up_dump_upcall,
+				    peer, AF_INET6);
 		}
 
 	if (peer->capa_received.restart && peer->capa_announced.restart)
@@ -2653,24 +2724,8 @@ void
 network_init(struct network_head *net_l)
 {
 	struct network	*n;
-	struct in_addr   id;
 
 	reloadtime = time(NULL);
-	bzero(&peerself, sizeof(peerself));
-	peerself.state = PEER_UP;
-	peerself.remote_bgpid = ntohl(conf->bgpid);
-	id.s_addr = conf->bgpid;
-	peerself.conf.remote_as = conf->as;
-	peerself.short_as = conf->short_as;
-	snprintf(peerself.conf.descr, sizeof(peerself.conf.descr),
-	    "LOCAL: ID %s", inet_ntoa(id));
-	bzero(&peerdynamic, sizeof(peerdynamic));
-	peerdynamic.state = PEER_UP;
-	peerdynamic.remote_bgpid = ntohl(conf->bgpid);
-	peerdynamic.conf.remote_as = conf->as;
-	peerdynamic.short_as = conf->short_as;
-	snprintf(peerdynamic.conf.descr, sizeof(peerdynamic.conf.descr),
-	    "LOCAL: ID %s", inet_ntoa(id));
 
 	while ((n = TAILQ_FIRST(net_l)) != NULL) {
 		TAILQ_REMOVE(net_l, n, entry);
@@ -2683,7 +2738,7 @@ void
 network_add(struct network_config *nc, int flagstatic)
 {
 	struct rde_aspath	*asp;
-	struct rde_peer		*p;
+	u_int16_t		 i;
 
 	asp = path_get();
 	asp->aspath = aspath_get(NULL, 0);
@@ -2691,15 +2746,13 @@ network_add(struct network_config *nc, i
 	asp->flags = F_ATTR_ORIGIN | F_ATTR_ASPATH |
 	    F_ATTR_LOCALPREF | F_PREFIX_ANNOUNCED;
 	/* the nexthop is unset unless a default set overrides it */
+	if (!flagstatic)
+		asp->flags |= F_ANN_DYNAMIC;
 
-	if (flagstatic)
-		p = &peerself;
-	else
-		p = &peerdynamic;
-
-	rde_apply_set(asp, &nc->attrset, nc->prefix.af, p, p);
-	path_update(p, asp, &nc->prefix, nc->prefixlen, F_ORIGINAL);
-	path_update(p, asp, &nc->prefix, nc->prefixlen, F_LOCAL);
+	rde_apply_set(asp, &nc->attrset, nc->prefix.af, peerself, peerself);
+	for (i = 1; i < rib_size; i++)
+		path_update(&ribs[i], peerself, asp, &nc->prefix,
+		    nc->prefixlen);
 
 	path_put(asp);
 	filterset_free(&nc->attrset);
@@ -2708,29 +2761,27 @@ network_add(struct network_config *nc, i
 void
 network_delete(struct network_config *nc, int flagstatic)
 {
-	struct rde_peer	*p;
+	u_int32_t	flags = F_PREFIX_ANNOUNCED;
+	u_int32_t	i;
 
-	if (flagstatic)
-		p = &peerself;
-	else
-		p = &peerdynamic;
+	if (!flagstatic)
+		flags |= F_ANN_DYNAMIC;
 
-	prefix_remove(p, &nc->prefix, nc->prefixlen, F_LOCAL);
-	prefix_remove(p, &nc->prefix, nc->prefixlen, F_ORIGINAL);
+	for (i = rib_size - 1; i > 0; i--)
+		prefix_remove(&ribs[i], peerself, &nc->prefix, nc->prefixlen,
+		    flags);
 }
 
 void
-network_dump_upcall(struct pt_entry *pt, void *ptr)
+network_dump_upcall(struct rib_entry *re, void *ptr)
 {
 	struct prefix		*p;
 	struct kroute		 k;
 	struct kroute6		 k6;
 	struct bgpd_addr	 addr;
-	pid_t			 pid;
-
-	memcpy(&pid, ptr, sizeof(pid));
+	struct rde_dump_ctx	*ctx = ptr;
 
-	LIST_FOREACH(p, &pt->prefix_h, prefix_l) {
+	LIST_FOREACH(p, &re->prefix_h, rib_l) {
 		if (!(p->aspath->flags & F_PREFIX_ANNOUNCED))
 			continue;
 		if (p->prefix->af == AF_INET) {
@@ -2738,10 +2789,10 @@ network_dump_upcall(struct pt_entry *pt,
 			pt_getaddr(p->prefix, &addr);
 			k.prefix.s_addr = addr.v4.s_addr;
 			k.prefixlen = p->prefix->prefixlen;
-			if (p->aspath->peer == &peerself)
+			if (p->aspath->peer == peerself)
 				k.flags = F_KERNEL;
 			if (imsg_compose(ibuf_se_ctl, IMSG_CTL_SHOW_NETWORK, 0,
-			    pid, -1, &k, sizeof(k)) == -1)
+			    ctx->req.pid, -1, &k, sizeof(k)) == -1)
 				log_warnx("network_dump_upcall: "
 				    "imsg_compose error");
 		}
@@ -2750,31 +2801,21 @@ network_dump_upcall(struct pt_entry *pt,
 			pt_getaddr(p->prefix, &addr);
 			memcpy(&k6.prefix, &addr.v6, sizeof(k6.prefix));
 			k6.prefixlen = p->prefix->prefixlen;
-			if (p->aspath->peer == &peerself)
+			if (p->aspath->peer == peerself)
 				k6.flags = F_KERNEL;
 			if (imsg_compose(ibuf_se_ctl, IMSG_CTL_SHOW_NETWORK6, 0,
-			    pid, -1, &k6, sizeof(k6)) == -1)
+			    ctx->req.pid, -1, &k6, sizeof(k6)) == -1)
 				log_warnx("network_dump_upcall: "
 				    "imsg_compose error");
 		}
 	}
 }
 
-void
-network_flush(int flagstatic)
-{
-	if (flagstatic)
-		prefix_network_clean(&peerself, time(NULL));
-	else
-		prefix_network_clean(&peerdynamic, time(NULL));
-}
-
 /* clean up */
 void
 rde_shutdown(void)
 {
 	struct rde_peer		*p;
-	struct rde_aspath	*asp, *nasp;
 	struct filter_rule	*r;
 	u_int32_t		 i;
 
@@ -2790,21 +2831,6 @@ rde_shutdown(void)
 		while ((p = LIST_FIRST(&peertable.peer_hashtbl[i])) != NULL)
 			peer_down(p->conf.id);
 
-	/* free announced network prefixes */
-	peerself.remote_bgpid = 0;
-	peerself.state = PEER_DOWN;
-	for (asp = LIST_FIRST(&peerself.path_h); asp != NULL; asp = nasp) {
-		nasp = LIST_NEXT(asp, peer_l);
-		path_remove(asp);
-	}
-
-	peerdynamic.remote_bgpid = 0;
-	peerdynamic.state = PEER_DOWN;
-	for (asp = LIST_FIRST(&peerdynamic.path_h); asp != NULL; asp = nasp) {
-		nasp = LIST_NEXT(asp, peer_l);
-		path_remove(asp);
-	}
-
 	/* free filters */
 	while ((r = TAILQ_FIRST(rules_l)) != NULL) {
 		TAILQ_REMOVE(rules_l, r, entry);
@@ -2819,7 +2845,6 @@ rde_shutdown(void)
 	attr_shutdown();
 	pt_shutdown();
 	peer_shutdown();
-	free(mrt);
 }
 
 int
