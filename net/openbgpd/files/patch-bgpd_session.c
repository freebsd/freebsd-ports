Index: bgpd/session.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/session.c,v
retrieving revision 1.1.1.8
retrieving revision 1.9
diff -u -p -r1.1.1.8 -r1.9
--- bgpd/session.c	14 Feb 2010 20:19:57 -0000	1.1.1.8
+++ bgpd/session.c	3 Jul 2011 11:18:26 -0000	1.9
@@ -1,4 +1,4 @@
-/*	$OpenBSD: session.c,v 1.293 2009/06/07 05:56:24 eric Exp $ */
+/*	$OpenBSD: session.c,v 1.304 2010/01/05 08:49:57 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004, 2005 Henning Brauer <henning@openbsd.org>
@@ -21,6 +21,8 @@
 
 #include <sys/mman.h>
 #include <sys/socket.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 #include <sys/un.h>
 #include <net/if_types.h>
 #include <netinet/in.h>
@@ -50,7 +52,12 @@
 #define PFD_PIPE_ROUTE_CTL	2
 #define PFD_SOCK_CTL		3
 #define PFD_SOCK_RCTL		4
-#define PFD_LISTENERS_START	5
+#define PFD_SOCK_PFKEY		5
+#define PFD_LISTENERS_START	6
+
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)  ((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */ 
 
 void	session_sighdlr(int);
 int	setup_listeners(u_int *);
@@ -65,9 +72,8 @@ void	session_accept(int);
 int	session_connect(struct peer *);
 void	session_tcp_established(struct peer *);
 void	session_capa_ann_none(struct peer *);
-int	session_capa_add(struct peer *, struct buf *, u_int8_t, u_int8_t,
-	    u_int8_t *);
-int	session_capa_add_mp(struct buf *, u_int16_t, u_int8_t);
+int	session_capa_add(struct ibuf *, u_int8_t, u_int8_t);
+int	session_capa_add_mp(struct ibuf *, u_int8_t);
 struct bgp_msg	*session_newmsg(enum msg_type, u_int16_t);
 int	session_sendmsg(struct bgp_msg *, struct peer *);
 void	session_open(struct peer *);
@@ -75,7 +81,7 @@ void	session_keepalive(struct peer *);
 void	session_update(u_int32_t, void *, size_t);
 void	session_notification(struct peer *, u_int8_t, u_int8_t, void *,
 	    ssize_t);
-void	session_rrefresh(struct peer *, u_int16_t, u_int8_t);
+void	session_rrefresh(struct peer *, u_int8_t);
 int	session_dispatch_msg(struct pollfd *, struct peer *);
 int	parse_header(struct peer *, u_char *, u_int16_t *, u_int8_t *);
 int	parse_open(struct peer *);
@@ -83,22 +89,22 @@ int	parse_update(struct peer *);
 int	parse_refresh(struct peer *);
 int	parse_notification(struct peer *);
 int	parse_capabilities(struct peer *, u_char *, u_int16_t, u_int32_t *);
+int	capa_neg_calc(struct peer *);
 void	session_dispatch_imsg(struct imsgbuf *, int, u_int *);
 void	session_up(struct peer *);
 void	session_down(struct peer *);
 void	session_demote(struct peer *, int);
 
-int			 la_cmp(struct listen_addr *, struct listen_addr *);
-struct peer		*getpeerbyip(struct sockaddr *);
-int			 session_match_mask(struct peer *, struct sockaddr *);
-struct peer		*getpeerbyid(u_int32_t);
-static struct sockaddr	*addr2sa(struct bgpd_addr *, u_int16_t);
+int		 la_cmp(struct listen_addr *, struct listen_addr *);
+struct peer	*getpeerbyip(struct sockaddr *);
+int		 session_match_mask(struct peer *, struct bgpd_addr *);
+struct peer	*getpeerbyid(u_int32_t);
 
-struct bgpd_config	*conf, *nconf = NULL;
+struct bgpd_config	*conf, *nconf;
 struct bgpd_sysdep	 sysdep;
-struct peer		*npeers;
-volatile sig_atomic_t	 session_quit = 0;
-int			 pending_reconf = 0;
+struct peer		*peers, *npeers;
+volatile sig_atomic_t	 session_quit;
+int			 pending_reconf;
 int			 csock = -1, rcsock = -1;
 u_int			 peer_cnt;
 struct imsgbuf		*ibuf_rde;
@@ -175,12 +181,11 @@ setup_listeners(u_int *la_cnt)
 }
 
 pid_t
-session_main(struct bgpd_config *config, struct peer *cpeers,
-    struct network_head *net_l, struct filter_head *rules,
-    struct mrt_head *m_l, struct rib_names *rib_l, int pipe_m2s[2],
-    int pipe_s2r[2], int pipe_m2r[2], int pipe_s2rctl[2])
+session_main(int pipe_m2s[2], int pipe_s2r[2], int pipe_m2r[2],
+    int pipe_s2rctl[2])
 {
-	int			 nfds, timeout;
+	struct rlimit		 rl;
+	int			 nfds, timeout, pfkeysock;
 	unsigned int		 i, j, idx_peers, idx_listeners, idx_mrts;
 	pid_t			 pid;
 	u_int			 pfd_elms = 0, peer_l_elms = 0, mrt_l_elms = 0;
@@ -189,19 +194,13 @@ session_main(struct bgpd_config *config,
 	u_int32_t		 ctl_queued;
 	struct passwd		*pw;
 	struct peer		*p, **peer_l = NULL, *last, *next;
-	struct network		*net;
-	struct mrt		*m, **mrt_l = NULL;
-	struct filter_rule	*r;
+	struct mrt		*m, *xm, **mrt_l = NULL;
 	struct pollfd		*pfd = NULL;
 	struct ctl_conn		*ctl_conn;
 	struct listen_addr	*la;
-	struct rde_rib		*rr;
 	void			*newp;
 	short			 events;
 
-	conf = config;
-	peers = cpeers;
-
 	switch (pid = fork()) {
 	case -1:
 		fatal("cannot fork");
@@ -211,13 +210,6 @@ session_main(struct bgpd_config *config,
 		return (pid);
 	}
 
-	/* control socket is outside chroot */
-	if ((csock = control_init(0, conf->csock)) == -1)
-		fatalx("control socket setup failed");
-	if (conf->rcsock != NULL &&
-	    (rcsock = control_init(1, conf->rcsock)) == -1)
-		fatalx("control socket setup failed");
-
 	if ((pw = getpwnam(BGPD_USER)) == NULL)
 		fatal(NULL);
 
@@ -229,28 +221,31 @@ session_main(struct bgpd_config *config,
 	setproctitle("session engine");
 	bgpd_process = PROC_SE;
 
-	if (pfkey_init(&sysdep) == -1)
-		fatalx("pfkey setup failed");
+	if (getrlimit(RLIMIT_NOFILE, &rl) == -1)
+		fatal("getrlimit");
+	rl.rlim_cur = rl.rlim_max;
+	if (setrlimit(RLIMIT_NOFILE, &rl) == -1)
+		fatal("setrlimit");
+
+	pfkeysock = pfkey_init(&sysdep);
 
 	if (setgroups(1, &pw->pw_gid) ||
 	    setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) ||
 	    setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid))
 		fatal("can't drop privileges");
 
-	listener_cnt = 0;
-	setup_listeners(&listener_cnt);
-
 	signal(SIGTERM, session_sighdlr);
 	signal(SIGINT, session_sighdlr);
 	signal(SIGPIPE, SIG_IGN);
 	signal(SIGHUP, SIG_IGN);
-	log_info("session engine ready");
+	signal(SIGALRM, SIG_IGN);
+	signal(SIGUSR1, SIG_IGN);
+
 	close(pipe_m2s[0]);
 	close(pipe_s2r[1]);
 	close(pipe_s2rctl[1]);
 	close(pipe_m2r[0]);
 	close(pipe_m2r[1]);
-	init_conf(conf);
 	if ((ibuf_rde = malloc(sizeof(struct imsgbuf))) == NULL ||
 	    (ibuf_rde_ctl = malloc(sizeof(struct imsgbuf))) == NULL ||
 	    (ibuf_main = malloc(sizeof(struct imsgbuf))) == NULL)
@@ -258,37 +253,21 @@ session_main(struct bgpd_config *config,
 	imsg_init(ibuf_rde, pipe_s2r[0]);
 	imsg_init(ibuf_rde_ctl, pipe_s2rctl[0]);
 	imsg_init(ibuf_main, pipe_m2s[1]);
+
 	TAILQ_INIT(&ctl_conns);
-	control_listen(csock);
-	control_listen(rcsock);
 	LIST_INIT(&mrthead);
+	listener_cnt = 0;
 	peer_cnt = 0;
 	ctl_cnt = 0;
 
-	/* filter rules are not used in the SE */
-	while ((r = TAILQ_FIRST(rules)) != NULL) {
-		TAILQ_REMOVE(rules, r, entry);
-		free(r);
-	}
-	free(rules);
-
-	/* network list is not used in the SE */
-	while ((net = TAILQ_FIRST(net_l)) != NULL) {
-		TAILQ_REMOVE(net_l, net, entry);
-		filterset_free(&net->net.attrset);
-		free(net);
-	}
+	if ((conf = calloc(1, sizeof(struct bgpd_config))) == NULL)
+		fatal(NULL);
+	if ((conf->listen_addrs = calloc(1, sizeof(struct listen_addrs))) ==
+	    NULL)
+		fatal(NULL);
+	TAILQ_INIT(conf->listen_addrs);
 
-	/* main mrt list is not used in the SE */
-	while ((m = LIST_FIRST(m_l)) != NULL) {
-		LIST_REMOVE(m, entry);
-		free(m);
-	}
-	/* rib names not used in the SE */
-	while ((rr = SIMPLEQ_FIRST(&ribnames))) {
-		SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
-		free(rr);
-	}
+	log_info("session engine ready");
 
 	while (session_quit == 0) {
 		/* check for peers to be initialized or deleted */
@@ -308,8 +287,9 @@ session_main(struct bgpd_config *config,
 
 				/* reinit due? */
 				if (p->conf.reconf_action == RECONF_REINIT) {
-					bgp_fsm(p, EVNT_STOP);
-					timer_set(p, Timer_IdleHold, 0);
+					session_stop(p, ERR_CEASE_ADMIN_RESET);
+					if (!p->conf.down)
+						timer_set(p, Timer_IdleHold, 0);
 				}
 
 				/* deletion due? */
@@ -317,7 +297,7 @@ session_main(struct bgpd_config *config,
 					if (p->demoted)
 						session_demote(p, -1);
 					p->conf.demote_group[0] = 0;
-					bgp_fsm(p, EVNT_STOP);
+					session_stop(p, ERR_CEASE_PEER_UNCONF);
 					log_peer_warnx(&p->conf, "removed");
 					if (last != NULL)
 						last->next = next;
@@ -346,9 +326,17 @@ session_main(struct bgpd_config *config,
 		}
 
 		mrt_cnt = 0;
-		LIST_FOREACH(m, &mrthead, entry)
+		for (m = LIST_FIRST(&mrthead); m != NULL; m = xm) {
+			xm = LIST_NEXT(m, entry);
+			if (m->state == MRT_STATE_REMOVE) {
+				mrt_clean(m);
+				LIST_REMOVE(m, entry);
+				free(m);
+				continue;
+			}
 			if (m->wbuf.queued)
 				mrt_cnt++;
+		}
 
 		if (mrt_cnt > mrt_l_elms) {
 			if ((newp = realloc(mrt_l, sizeof(struct mrt *) *
@@ -394,14 +382,19 @@ session_main(struct bgpd_config *config,
 		if (ctl_queued < SESSION_CTL_QUEUE_MAX)
 			/*
 			 * Do not act as unlimited buffer. Don't read in more
-			 * messages if the ctl sockets are getting full. 
+			 * messages if the ctl sockets are getting full.
 			 */
 			pfd[PFD_PIPE_ROUTE_CTL].events = POLLIN;
 		pfd[PFD_SOCK_CTL].fd = csock;
 		pfd[PFD_SOCK_CTL].events = POLLIN;
 		pfd[PFD_SOCK_RCTL].fd = rcsock;
 		pfd[PFD_SOCK_RCTL].events = POLLIN;
-
+		pfd[PFD_SOCK_PFKEY].fd = pfkeysock;
+#if !defined(__FreeBSD__)
+		pfd[PFD_SOCK_PFKEY].events = POLLIN;
+#else
+		pfd[PFD_SOCK_PFKEY].events = 0;
+#endif
 		i = PFD_LISTENERS_START;
 		TAILQ_FOREACH(la, conf->listen_addrs, entry) {
 			pfd[i].fd = la->fd;
@@ -534,6 +527,14 @@ session_main(struct bgpd_config *config,
 			ctl_cnt += control_accept(rcsock, 1);
 		}
 
+		if (nfds > 0 && pfd[PFD_SOCK_PFKEY].revents & POLLIN) {
+			nfds--;
+			if (pfkey_read(pfkeysock, NULL) == -1) {
+				log_warnx("pfkey_read failed, exiting...");
+				session_quit = 1;
+			}
+		}
+
 		for (j = PFD_LISTENERS_START; nfds > 0 && j < idx_listeners;
 		    j++)
 			if (pfd[j].revents & POLLIN) {
@@ -557,7 +558,7 @@ session_main(struct bgpd_config *config,
 
 	while ((p = peers) != NULL) {
 		peers = p->next;
-		bgp_fsm(p, EVNT_STOP);
+		session_stop(p, ERR_CEASE_ADMIN_DOWN);
 		pfkey_remove(p);
 		free(p);
 	}
@@ -643,10 +644,9 @@ bgp_fsm(struct peer *peer, enum session_
 			timer_stop(peer, Timer_IdleHold);
 
 			/* allocate read buffer */
-			peer->rbuf = calloc(1, sizeof(struct buf_read));
+			peer->rbuf = calloc(1, sizeof(struct ibuf_read));
 			if (peer->rbuf == NULL)
 				fatal(NULL);
-			peer->rbuf->wpos = 0;
 
 			/* init write buffer */
 			msgbuf_init(&peer->wbuf);
@@ -746,7 +746,6 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
@@ -780,7 +779,8 @@ bgp_fsm(struct peer *peer, enum session_
 				change_state(peer, STATE_IDLE, event);
 			break;
 		default:
-			session_notification(peer, ERR_FSM, 0, NULL, 0);
+			session_notification(peer,
+			    ERR_FSM, ERR_FSM_UNEX_OPENSENT, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		}
@@ -791,7 +791,6 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
@@ -815,7 +814,8 @@ bgp_fsm(struct peer *peer, enum session_
 			change_state(peer, STATE_IDLE, event);
 			break;
 		default:
-			session_notification(peer, ERR_FSM, 0, NULL, 0);
+			session_notification(peer,
+			    ERR_FSM, ERR_FSM_UNEX_OPENCONFIRM, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		}
@@ -826,7 +826,6 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
@@ -856,7 +855,8 @@ bgp_fsm(struct peer *peer, enum session_
 			change_state(peer, STATE_IDLE, event);
 			break;
 		default:
-			session_notification(peer, ERR_FSM, 0, NULL, 0);
+			session_notification(peer,
+			    ERR_FSM, ERR_FSM_UNEX_ESTABLISHED, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		}
@@ -923,6 +923,7 @@ change_state(struct peer *peer, enum ses
 		timer_stop(peer, Timer_ConnectRetry);
 		timer_stop(peer, Timer_Keepalive);
 		timer_stop(peer, Timer_Hold);
+		timer_stop(peer, Timer_IdleHold);
 		timer_stop(peer, Timer_IdleHoldReset);
 		session_close_connection(peer);
 		msgbuf_clear(&peer->wbuf);
@@ -1069,7 +1070,7 @@ session_connect(struct peer *peer)
 	if (peer->fd != -1)
 		return (-1);
 
-	if ((peer->fd = socket(peer->conf.remote_addr.af, SOCK_STREAM,
+	if ((peer->fd = socket(aid2af(peer->conf.remote_addr.aid), SOCK_STREAM,
 	    IPPROTO_TCP)) == -1) {
 		log_peer_warn(&peer->conf, "session_connect socket");
 		bgp_fsm(peer, EVNT_CON_OPENFAIL);
@@ -1100,8 +1101,7 @@ session_connect(struct peer *peer)
 	peer->wbuf.fd = peer->fd;
 
 	/* if update source is set we need to bind() */
-	if (peer->conf.local_addr.af) {
-		sa = addr2sa(&peer->conf.local_addr, 0);
+	if ((sa = addr2sa(&peer->conf.local_addr, 0)) != NULL) {
 		if (bind(peer->fd, sa, sa->sa_len) == -1) {
 			log_peer_warn(&peer->conf, "session_connect bind");
 			bgp_fsm(peer, EVNT_CON_OPENFAIL);
@@ -1139,42 +1139,50 @@ session_setup_socket(struct peer *p)
 	int	nodelay = 1;
 	int	bsize;
 
-	if (p->conf.ebgp && p->conf.remote_addr.af == AF_INET) {
-		/* set TTL to foreign router's distance - 1=direct n=multihop
-		   with ttlsec, we always use 255 */
-		if (p->conf.ttlsec) {
-			ttl = 256 - p->conf.distance;
-			if (setsockopt(p->fd, IPPROTO_IP, IP_MINTTL, &ttl,
+	switch (p->conf.remote_addr.aid) {
+	case AID_INET:
+		/* set precedence, see RFC 1771 appendix 5 */
+		if (setsockopt(p->fd, IPPROTO_IP, IP_TOS, &pre, sizeof(pre)) ==
+		    -1) {
+			log_peer_warn(&p->conf,
+			    "session_setup_socket setsockopt TOS");
+			return (-1);
+		}
+
+		if (p->conf.ebgp) {
+			/* set TTL to foreign router's distance
+			   1=direct n=multihop with ttlsec, we always use 255 */
+			if (p->conf.ttlsec) {
+				ttl = 256 - p->conf.distance;
+				if (setsockopt(p->fd, IPPROTO_IP, IP_MINTTL,
+				    &ttl, sizeof(ttl)) == -1) {
+					log_peer_warn(&p->conf,
+					    "session_setup_socket: "
+					    "setsockopt MINTTL");
+					return (-1);
+				}
+				ttl = 255;
+			}
+
+			if (setsockopt(p->fd, IPPROTO_IP, IP_TTL, &ttl,
 			    sizeof(ttl)) == -1) {
 				log_peer_warn(&p->conf,
-				    "session_setup_socket setsockopt MINTTL");
+				    "session_setup_socket setsockopt TTL");
 				return (-1);
 			}
-			ttl = 255;
-		}
-
-		if (setsockopt(p->fd, IPPROTO_IP, IP_TTL, &ttl,
-		    sizeof(ttl)) == -1) {
-			log_peer_warn(&p->conf,
-			    "session_setup_socket setsockopt TTL");
-			return (-1);
 		}
-	}
-
-	if (p->conf.ebgp && p->conf.remote_addr.af == AF_INET6)
-		/* set hoplimit to foreign router's distance */
-		if (setsockopt(p->fd, IPPROTO_IPV6, IPV6_UNICAST_HOPS, &ttl,
-		    sizeof(ttl)) == -1) {
-			log_peer_warn(&p->conf,
-			    "session_setup_socket setsockopt hoplimit");
-			return (-1);
+		break;
+	case AID_INET6:
+		if (p->conf.ebgp) {
+			/* set hoplimit to foreign router's distance */
+			if (setsockopt(p->fd, IPPROTO_IPV6, IPV6_UNICAST_HOPS,
+			    &ttl, sizeof(ttl)) == -1) {
+				log_peer_warn(&p->conf,
+				    "session_setup_socket setsockopt hoplimit");
+				return (-1);
+			}
 		}
-
-	/* if ttlsec is in use, set minttl */
-	if (p->conf.ttlsec) {
-		ttl = 256 - p->conf.distance;
-		setsockopt(p->fd, IPPROTO_IP, IP_MINTTL, &ttl, sizeof(ttl));
-
+		break;
 	}
 
 	/* set TCP_NODELAY */
@@ -1185,14 +1193,6 @@ session_setup_socket(struct peer *p)
 		return (-1);
 	}
 
-	/* set precedence, see RFC 1771 appendix 5 */
-	if (p->conf.remote_addr.af == AF_INET &&
-	    setsockopt(p->fd, IPPROTO_IP, IP_TOS, &pre, sizeof(pre)) == -1) {
-		log_peer_warn(&p->conf,
-		    "session_setup_socket setsockopt TOS");
-		return (-1);
-	}
-
 	/* only increase bufsize (and thus window) if md5 or ipsec is in use */
 	if (p->conf.auth.method != AUTH_NONE) {
 		/* try to increase bufsize. no biggie if it fails */
@@ -1244,40 +1244,32 @@ session_tcp_established(struct peer *pee
 void
 session_capa_ann_none(struct peer *peer)
 {
-	peer->capa.ann.mp_v4 = SAFI_NONE;
-	peer->capa.ann.mp_v4 = SAFI_NONE;
-	peer->capa.ann.refresh = 0;
-	peer->capa.ann.restart = 0;
-	peer->capa.ann.as4byte = 0;
+	bzero(&peer->capa.ann, sizeof(peer->capa.ann));
 }
 
 int
-session_capa_add(struct peer *p, struct buf *opb, u_int8_t capa_code,
-    u_int8_t capa_len, u_int8_t *optparamlen)
+session_capa_add(struct ibuf *opb, u_int8_t capa_code, u_int8_t capa_len)
 {
-	u_int8_t	op_type, op_len, tot_len, errs = 0;
+	int errs = 0;
 
-	op_type = OPT_PARAM_CAPABILITIES;
-	op_len = sizeof(capa_code) + sizeof(capa_len) + capa_len;
-	tot_len = sizeof(op_type) + sizeof(op_len) + op_len;
-	errs += buf_add(opb, &op_type, sizeof(op_type));
-	errs += buf_add(opb, &op_len, sizeof(op_len));
-	errs += buf_add(opb, &capa_code, sizeof(capa_code));
-	errs += buf_add(opb, &capa_len, sizeof(capa_len));
-	*optparamlen += tot_len;
+	errs += ibuf_add(opb, &capa_code, sizeof(capa_code));
+	errs += ibuf_add(opb, &capa_len, sizeof(capa_len));
 	return (errs);
 }
 
 int
-session_capa_add_mp(struct buf *buf, u_int16_t afi, u_int8_t safi)
+session_capa_add_mp(struct ibuf *buf, u_int8_t aid)
 {
-	u_int8_t		 pad = 0;
+	u_int8_t		 safi, pad = 0;
+	u_int16_t		 afi;
 	int			 errs = 0;
 
+	if (aid2afi(aid, &afi, &safi) == -1)
+		fatalx("session_capa_add_mp: bad afi/safi pair");
 	afi = htons(afi);
-	errs += buf_add(buf, &afi, sizeof(afi));
-	errs += buf_add(buf, &pad, sizeof(pad));
-	errs += buf_add(buf, &safi, sizeof(safi));
+	errs += ibuf_add(buf, &afi, sizeof(afi));
+	errs += ibuf_add(buf, &pad, sizeof(pad));
+	errs += ibuf_add(buf, &safi, sizeof(safi));
 
 	return (errs);
 }
@@ -1287,23 +1279,22 @@ session_newmsg(enum msg_type msgtype, u_
 {
 	struct bgp_msg		*msg;
 	struct msg_header	 hdr;
-	struct buf		*buf;
+	struct ibuf		*buf;
 	int			 errs = 0;
 
 	memset(&hdr.marker, 0xff, sizeof(hdr.marker));
 	hdr.len = htons(len);
 	hdr.type = msgtype;
 
-	if ((buf = buf_open(len)) == NULL)
+	if ((buf = ibuf_open(len)) == NULL)
 		return (NULL);
 
-	errs += buf_add(buf, &hdr.marker, sizeof(hdr.marker));
-	errs += buf_add(buf, &hdr.len, sizeof(hdr.len));
-	errs += buf_add(buf, &hdr.type, sizeof(hdr.type));
-
-	if (errs > 0 ||
-	    (msg = calloc(1, sizeof(*msg))) == NULL) {
-		buf_free(buf);
+	errs += ibuf_add(buf, &hdr.marker, sizeof(hdr.marker));
+	errs += ibuf_add(buf, &hdr.len, sizeof(hdr.len));
+	errs += ibuf_add(buf, &hdr.type, sizeof(hdr.type));
+
+	if (errs || (msg = calloc(1, sizeof(*msg))) == NULL) {
+		ibuf_free(buf);
 		return (NULL);
 	}
 
@@ -1329,7 +1320,7 @@ session_sendmsg(struct bgp_msg *msg, str
 			mrt_dump_bgp_msg(mrt, msg->buf->buf, msg->len, p);
 	}
 
-	buf_close(&p->wbuf, msg->buf);
+	ibuf_close(&p->wbuf, msg->buf);
 	free(msg);
 	return (0);
 }
@@ -1338,40 +1329,38 @@ void
 session_open(struct peer *p)
 {
 	struct bgp_msg		*buf;
-	struct buf		*opb;
+	struct ibuf		*opb;
 	struct msg_open		 msg;
 	u_int16_t		 len;
-	u_int8_t		 optparamlen = 0;
-	u_int			 errs = 0;
+	u_int8_t		 i, op_type, optparamlen = 0;
+	int			 errs = 0;
 
 
-	if ((opb = buf_dynamic(0, MAX_PKTSIZE - MSGSIZE_OPEN_MIN)) == NULL) {
+	if ((opb = ibuf_dynamic(0, UCHAR_MAX - sizeof(op_type) -
+	    sizeof(optparamlen))) == NULL) {
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
 	}
 
 	/* multiprotocol extensions, RFC 4760 */
-	if (p->capa.ann.mp_v4) {	/* 4 bytes data */
-		errs += session_capa_add(p, opb, CAPA_MP, 4, &optparamlen);
-		errs += session_capa_add_mp(opb, AFI_IPv4, p->capa.ann.mp_v4);
-	}
-	if (p->capa.ann.mp_v6) {	/* 4 bytes data */
-		errs += session_capa_add(p, opb, CAPA_MP, 4, &optparamlen);
-		errs += session_capa_add_mp(opb, AFI_IPv6, p->capa.ann.mp_v6);
-	}
+	for (i = 0; i < AID_MAX; i++)
+		if (p->capa.ann.mp[i]) {	/* 4 bytes data */
+			errs += session_capa_add(opb, CAPA_MP, 4);
+			errs += session_capa_add_mp(opb, i);
+		}
 
 	/* route refresh, RFC 2918 */
 	if (p->capa.ann.refresh)	/* no data */
-		errs += session_capa_add(p, opb, CAPA_REFRESH, 0, &optparamlen);
+		errs += session_capa_add(opb, CAPA_REFRESH, 0);
 
 	/* End-of-RIB marker, RFC 4724 */
 	if (p->capa.ann.restart) {	/* 2 bytes data */
 		u_char		c[2];
 
-		bzero(&c, 2);
 		c[0] = 0x80; /* we're always restarting */
-		errs += session_capa_add(p, opb, CAPA_RESTART, 2, &optparamlen);
-		errs += buf_add(opb, &c, 2);
+		c[1] = 0;
+		errs += session_capa_add(opb, CAPA_RESTART, 2);
+		errs += ibuf_add(opb, &c, 2);
 	}
 
 	/* 4-bytes AS numbers, draft-ietf-idr-as4bytes-13 */
@@ -1379,13 +1368,17 @@ session_open(struct peer *p)
 		u_int32_t	nas;
 
 		nas = htonl(conf->as);
-		errs += session_capa_add(p, opb, CAPA_AS4BYTE, 4, &optparamlen);
-		errs += buf_add(opb, &nas, 4);
+		errs += session_capa_add(opb, CAPA_AS4BYTE, sizeof(nas));
+		errs += ibuf_add(opb, &nas, sizeof(nas));
 	}
 
+	if (ibuf_size(opb))
+		optparamlen = ibuf_size(opb) + sizeof(op_type) +
+		    sizeof(optparamlen);
+
 	len = MSGSIZE_OPEN_MIN + optparamlen;
 	if (errs || (buf = session_newmsg(OPEN, len)) == NULL) {
-		buf_free(opb);
+		ibuf_free(opb);
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
 	}
@@ -1399,19 +1392,24 @@ session_open(struct peer *p)
 	msg.bgpid = conf->bgpid;	/* is already in network byte order */
 	msg.optparamlen = optparamlen;
 
-	errs += buf_add(buf->buf, &msg.version, sizeof(msg.version));
-	errs += buf_add(buf->buf, &msg.myas, sizeof(msg.myas));
-	errs += buf_add(buf->buf, &msg.holdtime, sizeof(msg.holdtime));
-	errs += buf_add(buf->buf, &msg.bgpid, sizeof(msg.bgpid));
-	errs += buf_add(buf->buf, &msg.optparamlen, sizeof(msg.optparamlen));
-
-	if (optparamlen)
-		errs += buf_add(buf->buf, opb->buf, optparamlen);
+	errs += ibuf_add(buf->buf, &msg.version, sizeof(msg.version));
+	errs += ibuf_add(buf->buf, &msg.myas, sizeof(msg.myas));
+	errs += ibuf_add(buf->buf, &msg.holdtime, sizeof(msg.holdtime));
+	errs += ibuf_add(buf->buf, &msg.bgpid, sizeof(msg.bgpid));
+	errs += ibuf_add(buf->buf, &msg.optparamlen, sizeof(msg.optparamlen));
+
+	if (optparamlen) {
+		op_type = OPT_PARAM_CAPABILITIES;
+		optparamlen = ibuf_size(opb);
+		errs += ibuf_add(buf->buf, &op_type, sizeof(op_type));
+		errs += ibuf_add(buf->buf, &optparamlen, sizeof(optparamlen));
+		errs += ibuf_add(buf->buf, opb->buf, ibuf_size(opb));
+	}
 
-	buf_free(opb);
+	ibuf_free(opb);
 
-	if (errs > 0) {
-		buf_free(buf->buf);
+	if (errs) {
+		ibuf_free(buf->buf);
 		free(buf);
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
@@ -1459,8 +1457,8 @@ session_update(u_int32_t peerid, void *d
 		return;
 	}
 
-	if (buf_add(buf->buf, data, datalen)) {
-		buf_free(buf->buf);
+	if (ibuf_add(buf->buf, data, datalen)) {
+		ibuf_free(buf->buf);
 		free(buf);
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
@@ -1480,29 +1478,27 @@ session_notification(struct peer *p, u_i
     void *data, ssize_t datalen)
 {
 	struct bgp_msg		*buf;
-	u_int			 errs = 0;
-	u_int8_t		 null8 = 0;
+	int			 errs = 0;
 
 	if (p->stats.last_sent_errcode)	/* some notification already sent */
 		return;
 
+	log_notification(p, errcode, subcode, data, datalen, "sending");
+
 	if ((buf = session_newmsg(NOTIFICATION,
 	    MSGSIZE_NOTIFICATION_MIN + datalen)) == NULL) {
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
 	}
 
-	errs += buf_add(buf->buf, &errcode, sizeof(errcode));
-	if (errcode == ERR_CEASE)
-		errs += buf_add(buf->buf, &null8, sizeof(null8));
-	else
-		errs += buf_add(buf->buf, &subcode, sizeof(subcode));
+	errs += ibuf_add(buf->buf, &errcode, sizeof(errcode));
+	errs += ibuf_add(buf->buf, &subcode, sizeof(subcode));
 
 	if (datalen > 0)
-		errs += buf_add(buf->buf, data, datalen);
+		errs += ibuf_add(buf->buf, data, datalen);
 
-	if (errs > 0) {
-		buf_free(buf->buf);
+	if (errs) {
+		ibuf_free(buf->buf);
 		free(buf);
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
@@ -1521,23 +1517,29 @@ session_notification(struct peer *p, u_i
 int
 session_neighbor_rrefresh(struct peer *p)
 {
+	u_int8_t	i;
+
 	if (!p->capa.peer.refresh)
 		return (-1);
 
-	if (p->capa.peer.mp_v4 != SAFI_NONE)
-		session_rrefresh(p, AFI_IPv4, p->capa.peer.mp_v4);
-	if (p->capa.peer.mp_v6 != SAFI_NONE)
-		session_rrefresh(p, AFI_IPv6, p->capa.peer.mp_v6);
+	for (i = 0; i < AID_MAX; i++) {
+		if (p->capa.peer.mp[i] != 0)
+			session_rrefresh(p, i);
+	}
 
 	return (0);
 }
 
 void
-session_rrefresh(struct peer *p, u_int16_t afi, u_int8_t safi)
+session_rrefresh(struct peer *p, u_int8_t aid)
 {
 	struct bgp_msg		*buf;
 	int			 errs = 0;
-	u_int8_t		 null8 = 0;
+	u_int16_t		 afi;
+	u_int8_t		 safi, null8 = 0;
+
+	if (aid2afi(aid, &afi, &safi) == -1)
+		fatalx("session_rrefresh: bad afi/safi pair");
 
 	if ((buf = session_newmsg(RREFRESH, MSGSIZE_RREFRESH)) == NULL) {
 		bgp_fsm(p, EVNT_CON_FATAL);
@@ -1545,12 +1547,12 @@ session_rrefresh(struct peer *p, u_int16
 	}
 
 	afi = htons(afi);
-	errs += buf_add(buf->buf, &afi, sizeof(afi));
-	errs += buf_add(buf->buf, &null8, sizeof(null8));
-	errs += buf_add(buf->buf, &safi, sizeof(safi));
+	errs += ibuf_add(buf->buf, &afi, sizeof(afi));
+	errs += ibuf_add(buf->buf, &null8, sizeof(null8));
+	errs += ibuf_add(buf->buf, &safi, sizeof(safi));
 
-	if (errs > 0) {
-		buf_free(buf->buf);
+	if (errs) {
+		ibuf_free(buf->buf);
 		free(buf);
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
@@ -1853,12 +1855,6 @@ parse_open(struct peer *peer)
 	p += sizeof(short_as);
 	as = peer->short_as = ntohs(short_as);
 
-	/* if remote-as is zero and it's a cloned neighbor, accept any */
-	if (peer->conf.cloned && !peer->conf.remote_as && as != AS_TRANS) {
-		peer->conf.remote_as = as;
-		peer->conf.ebgp = (peer->conf.remote_as != conf->as);
-	}
-
 	memcpy(&oholdtime, p, sizeof(oholdtime));
 	p += sizeof(oholdtime);
 
@@ -1966,6 +1962,15 @@ parse_open(struct peer *peer)
 		}
 	}
 
+	/* if remote-as is zero and it's a cloned neighbor, accept any */
+	if (peer->conf.cloned && !peer->conf.remote_as && as != AS_TRANS) {
+		peer->conf.remote_as = as;
+		peer->conf.ebgp = (peer->conf.remote_as != conf->as);
+		if (!peer->conf.ebgp)
+			/* force enforce_as off for iBGP sessions */
+			peer->conf.enforce_as = ENFORCE_AS_OFF;
+	}
+
 	if (peer->conf.remote_as != as) {
 		log_peer_warnx(&peer->conf, "peer sent wrong AS %s",
 		    log_as(as));
@@ -1974,6 +1979,14 @@ parse_open(struct peer *peer)
 		return (-1);
 	}
 
+	if (capa_neg_calc(peer) == -1) {
+		log_peer_warnx(&peer->conf,
+		    "capabilitiy negotiation calculation failed");
+		session_notification(peer, ERR_OPEN, 0, NULL, 0);
+		change_state(peer, STATE_IDLE, EVNT_RCVD_OPEN);
+		return (-1);
+	}
+
 	return (0);
 }
 
@@ -2008,24 +2021,35 @@ int
 parse_refresh(struct peer *peer)
 {
 	u_char		*p;
-	struct rrefresh	 r;
+	u_int16_t	 afi;
+	u_int8_t	 aid, safi;
 
 	p = peer->rbuf->rptr;
 	p += MSGSIZE_HEADER;	/* header is already checked */
 
+	/*
+	 * We could check if we actually announced the capability but
+	 * as long as the message is correctly encoded we don't care.
+	 */
+
 	/* afi, 2 byte */
-	memcpy(&r.afi, p, sizeof(r.afi));
-	r.afi = ntohs(r.afi);
+	memcpy(&afi, p, sizeof(afi));
+	afi = ntohs(afi);
 	p += 2;
 	/* reserved, 1 byte */
 	p += 1;
 	/* safi, 1 byte */
-	memcpy(&r.safi, p, sizeof(r.safi));
+	memcpy(&safi, p, sizeof(safi));
 
 	/* afi/safi unchecked -	unrecognized values will be ignored anyway */
+	if (afi2aid(afi, safi, &aid) == -1) {
+		log_peer_warnx(&peer->conf, "peer sent bad refresh, "
+		    "invalid afi/safi pair");
+		return (0);
+	}
 
-	if (imsg_compose(ibuf_rde, IMSG_REFRESH, peer->conf.id, 0, -1, &r,
-	    sizeof(r)) == -1)
+	if (imsg_compose(ibuf_rde, IMSG_REFRESH, peer->conf.id, 0, -1, &aid,
+	    sizeof(aid)) == -1)
 		return (-1);
 
 	return (0);
@@ -2035,11 +2059,12 @@ int
 parse_notification(struct peer *peer)
 {
 	u_char		*p;
+	u_int16_t	 datalen;
 	u_int8_t	 errcode;
 	u_int8_t	 subcode;
-	u_int16_t	 datalen;
 	u_int8_t	 capa_code;
 	u_int8_t	 capa_len;
+	u_int8_t	 i;
 
 	/* just log */
 	p = peer->rbuf->rptr;
@@ -2059,7 +2084,7 @@ parse_notification(struct peer *peer)
 	p += sizeof(subcode);
 	datalen -= sizeof(subcode);
 
-	log_notification(peer, errcode, subcode, p, datalen);
+	log_notification(peer, errcode, subcode, p, datalen, "received");
 	peer->errcnt++;
 
 	if (errcode == ERR_OPEN && subcode == ERR_OPEN_CAPA) {
@@ -2094,8 +2119,8 @@ parse_notification(struct peer *peer)
 			datalen -= capa_len;
 			switch (capa_code) {
 			case CAPA_MP:
-				peer->capa.ann.mp_v4 = SAFI_NONE;
-				peer->capa.ann.mp_v6 = SAFI_NONE;
+				for (i = 0; i < AID_MAX; i++)
+					peer->capa.ann.mp[i] = 0;
 				log_peer_warnx(&peer->conf,
 				    "disabling multiprotocol capability");
 				break;
@@ -2139,13 +2164,14 @@ parse_notification(struct peer *peer)
 int
 parse_capabilities(struct peer *peer, u_char *d, u_int16_t dlen, u_int32_t *as)
 {
+	u_char		*capa_val;
+	u_int32_t	 remote_as;
 	u_int16_t	 len;
+	u_int16_t	 afi;
+	u_int8_t	 safi;
+	u_int8_t	 aid;
 	u_int8_t	 capa_code;
 	u_int8_t	 capa_len;
-	u_char		*capa_val;
-	u_int16_t	 mp_afi;
-	u_int8_t	 mp_safi;
-	u_int32_t	 remote_as;
 
 	len = dlen;
 	while (len > 0) {
@@ -2182,29 +2208,16 @@ parse_capabilities(struct peer *peer, u_
 				    "expect len 4, len is %u", capa_len);
 				return (-1);
 			}
-			memcpy(&mp_afi, capa_val, sizeof(mp_afi));
-			mp_afi = ntohs(mp_afi);
-			memcpy(&mp_safi, capa_val + 3, sizeof(mp_safi));
-			switch (mp_afi) {
-			case AFI_IPv4:
-				if (mp_safi < 1 || mp_safi > 3)
-					log_peer_warnx(&peer->conf,
-					    "parse_capabilities: AFI IPv4, "
-					    "mp_safi %u unknown", mp_safi);
-				else
-					peer->capa.peer.mp_v4 = mp_safi;
-				break;
-			case AFI_IPv6:
-				if (mp_safi < 1 || mp_safi > 3)
-					log_peer_warnx(&peer->conf,
-					    "parse_capabilities: AFI IPv6, "
-					    "mp_safi %u unknown", mp_safi);
-				else
-					peer->capa.peer.mp_v6 = mp_safi;
-				break;
-			default:			/* ignore */
+			memcpy(&afi, capa_val, sizeof(afi));
+			afi = ntohs(afi);
+			memcpy(&safi, capa_val + 3, sizeof(safi));
+			if (afi2aid(afi, safi, &aid) == -1) {
+				log_peer_warnx(&peer->conf,
+				    "parse_capabilities: AFI %u, "
+				    "safi %u unknown", afi, safi);
 				break;
 			}
+			peer->capa.peer.mp[aid] = 1;
 			break;
 		case CAPA_REFRESH:
 			peer->capa.peer.refresh = 1;
@@ -2232,6 +2245,37 @@ parse_capabilities(struct peer *peer, u_
 	return (0);
 }
 
+int
+capa_neg_calc(struct peer *p)
+{
+	u_int8_t	i, hasmp = 0;
+
+	/* refresh: does not realy matter here, use peer setting */
+	p->capa.neg.refresh = p->capa.peer.refresh;
+
+	/* as4byte: both side must announce capability */
+	if (p->capa.ann.as4byte && p->capa.peer.as4byte)
+		p->capa.neg.as4byte = 1;
+	else
+		p->capa.neg.as4byte = 0;
+
+	/* MP: both side must announce capability */
+	for (i = 0; i < AID_MAX; i++) {
+		if (p->capa.ann.mp[i] && p->capa.peer.mp[i]) {
+			p->capa.neg.mp[i] = 1;
+			hasmp = 1;
+		} else
+			p->capa.neg.mp[i] = 0;
+	}
+	/* if no MP capability present for default IPv4 unicast mode */
+	if (!hasmp)
+		p->capa.neg.mp[AID_INET] = 1;
+
+	p->capa.neg.restart = p->capa.peer.restart;
+
+	return (0);
+}
+
 void
 session_dispatch_imsg(struct imsgbuf *ibuf, int idx, u_int *listener_cnt)
 {
@@ -2244,7 +2288,7 @@ session_dispatch_imsg(struct imsgbuf *ib
 	struct kif		*kif;
 	u_char			*data;
 	enum reconf_action	 reconf;
-	int			 n, depend_ok;
+	int			 n, depend_ok, restricted;
 	u_int8_t		 errcode, subcode;
 
 	if ((n = imsg_read(ibuf)) == -1)
@@ -2332,15 +2376,42 @@ session_dispatch_imsg(struct imsgbuf *ib
 			}
 
 			break;
+		case IMSG_RECONF_CTRL:
+			if (idx != PFD_PIPE_MAIN)
+				fatalx("reconf request not from parent");
+			if (imsg.hdr.len != IMSG_HEADER_SIZE +
+			    sizeof(restricted))
+				fatalx("IFINFO imsg with wrong len");
+			memcpy(&restricted, imsg.data, sizeof(restricted));
+			if (imsg.fd == -1) {
+				log_warnx("expected to receive fd for control "
+				    "socket but didn't receive any");
+				break;
+			}
+			if (restricted) {
+				control_shutdown(rcsock);
+				rcsock = imsg.fd;
+				control_listen(rcsock);
+			} else {
+				control_shutdown(csock);
+				csock = imsg.fd;
+				control_listen(csock);
+			}
+			break;
 		case IMSG_RECONF_DONE:
 			if (idx != PFD_PIPE_MAIN)
 				fatalx("reconf request not from parent");
 			if (nconf == NULL)
 				fatalx("got IMSG_RECONF_DONE but no config");
+			conf->flags = nconf->flags;
+			conf->log = nconf->log;
+			conf->bgpid = nconf->bgpid;
+			conf->clusterid = nconf->clusterid;
 			conf->as = nconf->as;
+			conf->short_as = nconf->short_as;
 			conf->holdtime = nconf->holdtime;
-			conf->bgpid = nconf->bgpid;
 			conf->min_holdtime = nconf->min_holdtime;
+			conf->connectretry = nconf->connectretry;
 
 			/* add new peers */
 			for (p = npeers; p != NULL; p = next) {
@@ -2408,7 +2479,8 @@ session_dispatch_imsg(struct imsgbuf *ib
 						bgp_fsm(p, EVNT_START);
 					} else if (!depend_ok && p->depend_ok) {
 						p->depend_ok = depend_ok;
-						bgp_fsm(p, EVNT_STOP);
+						session_stop(p,
+						    ERR_CEASE_OTHER_CHANGE);
 					}
 				}
 			break;
@@ -2456,10 +2528,10 @@ session_dispatch_imsg(struct imsgbuf *ib
 			}
 			break;
 		case IMSG_CTL_KROUTE:
-		case IMSG_CTL_KROUTE6:
 		case IMSG_CTL_KROUTE_ADDR:
 		case IMSG_CTL_SHOW_NEXTHOP:
 		case IMSG_CTL_SHOW_INTERFACE:
+		case IMSG_CTL_SHOW_FIB_TABLES:
 			if (idx != PFD_PIPE_MAIN)
 				fatalx("ctl kroute request not from parent");
 			control_imsg_relay(&imsg);
@@ -2469,7 +2541,6 @@ session_dispatch_imsg(struct imsgbuf *ib
 		case IMSG_CTL_SHOW_RIB_ATTR:
 		case IMSG_CTL_SHOW_RIB_MEM:
 		case IMSG_CTL_SHOW_NETWORK:
-		case IMSG_CTL_SHOW_NETWORK6:
 		case IMSG_CTL_SHOW_NEIGHBOR:
 			if (idx != PFD_PIPE_ROUTE_CTL)
 				fatalx("ctl rib request not from RDE");
@@ -2612,29 +2683,23 @@ getpeerbydesc(const char *descr)
 struct peer *
 getpeerbyip(struct sockaddr *ip)
 {
+	struct bgpd_addr addr;
 	struct peer	*p, *newpeer, *loose = NULL;
 	u_int32_t	 id;
 
+	sa2addr(ip, &addr);
+
 	/* we might want a more effective way to find peers by IP */
 	for (p = peers; p != NULL; p = p->next)
 		if (!p->conf.template &&
-		    p->conf.remote_addr.af == ip->sa_family) {
-			if (p->conf.remote_addr.af == AF_INET &&
-			    p->conf.remote_addr.v4.s_addr ==
-			    ((struct sockaddr_in *)ip)->sin_addr.s_addr)
-				return (p);
-			if (p->conf.remote_addr.af == AF_INET6 &&
-			    !bcmp(&p->conf.remote_addr.v6,
-			    &((struct sockaddr_in6 *)ip)->sin6_addr,
-			    sizeof(p->conf.remote_addr.v6)))
-				return (p);
-		}
+		    !memcmp(&addr, &p->conf.remote_addr, sizeof(addr)))
+			return (p);
 
 	/* try template matching */
 	for (p = peers; p != NULL; p = p->next)
 		if (p->conf.template &&
-		    p->conf.remote_addr.af == ip->sa_family &&
-		    session_match_mask(p, ip))
+		    p->conf.remote_addr.aid == addr.aid &&
+		    session_match_mask(p, &addr))
 			if (loose == NULL || loose->conf.remote_masklen <
 			    p->conf.remote_masklen)
 				loose = p;
@@ -2653,21 +2718,19 @@ getpeerbyip(struct sockaddr *ip)
 				break;
 			}
 		}
-		if (newpeer->conf.remote_addr.af == AF_INET) {
-			newpeer->conf.remote_addr.v4.s_addr =
-			    ((struct sockaddr_in *)ip)->sin_addr.s_addr;
+		sa2addr(ip, &newpeer->conf.remote_addr);
+		switch (ip->sa_family) {
+		case AF_INET:
 			newpeer->conf.remote_masklen = 32;
-		}
-		if (newpeer->conf.remote_addr.af == AF_INET6) {
-			memcpy(&p->conf.remote_addr.v6,
-			    &((struct sockaddr_in6 *)ip)->sin6_addr,
-			    sizeof(newpeer->conf.remote_addr.v6));
+			break;
+		case AF_INET6:
 			newpeer->conf.remote_masklen = 128;
+			break;
 		}
 		newpeer->conf.template = 0;
 		newpeer->conf.cloned = 1;
 		newpeer->state = newpeer->prev_state = STATE_NONE;
-		newpeer->conf.reconf_action = RECONF_REINIT;
+		newpeer->conf.reconf_action = RECONF_KEEP;
 		newpeer->rbuf = NULL;
 		init_peer(newpeer);
 		bgp_fsm(newpeer, EVNT_START);
@@ -2680,40 +2743,24 @@ getpeerbyip(struct sockaddr *ip)
 }
 
 int
-session_match_mask(struct peer *p, struct sockaddr *ip)
+session_match_mask(struct peer *p, struct bgpd_addr *a)
 {
-	int		 i;
 	in_addr_t	 v4mask;
-	struct in6_addr	*in;
-	struct in6_addr	 mask;
+	struct in6_addr	 masked;
 
-	if (p->conf.remote_addr.af == AF_INET) {
+	switch (p->conf.remote_addr.aid) {
+	case AID_INET:
 		v4mask = htonl(prefixlen2mask(p->conf.remote_masklen));
-		if (p->conf.remote_addr.v4.s_addr ==
-		    ((((struct sockaddr_in *)ip)->sin_addr.s_addr) & v4mask))
+		if (p->conf.remote_addr.v4.s_addr == (a->v4.s_addr & v4mask))
 			return (1);
-		else
-			return (0);
-	}
-
-	if (p->conf.remote_addr.af == AF_INET6) {
-		bzero(&mask, sizeof(mask));
-		for (i = 0; i < p->conf.remote_masklen / 8; i++)
-			mask.s6_addr[i] = 0xff;
-		i = p->conf.remote_masklen % 8;
-		if (i)
-			mask.s6_addr[p->conf.remote_masklen / 8] = 0xff00 >> i;
-
-		in = &((struct sockaddr_in6 *)ip)->sin6_addr;
-
-		for (i = 0; i < 16; i++)
-			if ((in->s6_addr[i] & mask.s6_addr[i]) !=
-			    p->conf.remote_addr.addr8[i])
-				return (0);
+		return (0);
+	case AID_INET6:
+		inet6applymask(&masked, &a->v6, p->conf.remote_masklen);
 
-		return (1);
+		if (!memcmp(&masked, &p->conf.remote_addr.v6, sizeof(masked)))
+			return (1);
+		return (0);
 	}
-
 	return (0);
 }
 
@@ -2733,6 +2780,7 @@ getpeerbyid(u_int32_t peerid)
 void
 session_down(struct peer *peer)
 {
+	bzero(&peer->capa.neg, sizeof(peer->capa.neg));
 	peer->stats.last_updown = time(NULL);
 	if (imsg_compose(ibuf_rde, IMSG_SESSION_DOWN, peer->conf.id, 0, -1,
 	    NULL, 0) == -1)
@@ -2748,35 +2796,12 @@ session_up(struct peer *p)
 	    &p->conf, sizeof(p->conf)) == -1)
 		fatalx("imsg_compose error");
 
-	switch (p->sa_local.ss_family) {
-	case AF_INET:
-		sup.local_addr.af = AF_INET;
-		memcpy(&sup.local_addr.v4,
-		    &((struct sockaddr_in *)&p->sa_local)->sin_addr,
-		    sizeof(sup.local_addr.v4));
-		sup.remote_addr.af = AF_INET;
-		memcpy(&sup.remote_addr.v4,
-		    &((struct sockaddr_in *)&p->sa_remote)->sin_addr,
-		    sizeof(sup.remote_addr.v4));
-		break;
-	case AF_INET6:
-		sup.local_addr.af = AF_INET6;
-		memcpy(&sup.local_addr.v6,
-		    &((struct sockaddr_in6 *)&p->sa_local)->sin6_addr,
-		    sizeof(sup.local_addr.v6));
-		sup.remote_addr.af = AF_INET6;
-		memcpy(&sup.remote_addr.v6,
-		    &((struct sockaddr_in6 *)&p->sa_remote)->sin6_addr,
-		    sizeof(sup.remote_addr.v6));
-		break;
-	default:
-		fatalx("session_up: unsupported address family");
-	}
+	sa2addr((struct sockaddr *)&p->sa_local, &sup.local_addr);
+	sa2addr((struct sockaddr *)&p->sa_remote, &sup.remote_addr);
 
 	sup.remote_bgpid = p->remote_bgpid;
 	sup.short_as = p->short_as;
-	memcpy(&sup.capa_announced, &p->capa.ann, sizeof(sup.capa_announced));
-	memcpy(&sup.capa_received, &p->capa.peer, sizeof(sup.capa_received));
+	memcpy(&sup.capa, &p->capa.neg, sizeof(sup.capa));
 	p->stats.last_updown = time(NULL);
 	if (imsg_compose(ibuf_rde, IMSG_SESSION_UP, p->conf.id, 0, -1,
 	    &sup, sizeof(sup)) == -1)
@@ -2784,9 +2809,10 @@ session_up(struct peer *p)
 }
 
 int
-imsg_compose_parent(int type, pid_t pid, void *data, u_int16_t datalen)
+imsg_compose_parent(int type, u_int32_t peerid, pid_t pid, void *data,
+    u_int16_t datalen)
 {
-	return (imsg_compose(ibuf_main, type, 0, pid, -1, data, datalen));
+	return (imsg_compose(ibuf_main, type, peerid, pid, -1, data, datalen));
 }
 
 int
@@ -2795,34 +2821,6 @@ imsg_compose_rde(int type, pid_t pid, vo
 	return (imsg_compose(ibuf_rde, type, 0, pid, -1, data, datalen));
 }
 
-static struct sockaddr *
-addr2sa(struct bgpd_addr *addr, u_int16_t port)
-{
-	static struct sockaddr_storage	 ss;
-	struct sockaddr_in		*sa_in = (struct sockaddr_in *)&ss;
-	struct sockaddr_in6		*sa_in6 = (struct sockaddr_in6 *)&ss;
-
-	bzero(&ss, sizeof(ss));
-	switch (addr->af) {
-	case AF_INET:
-		sa_in->sin_family = AF_INET;
-		sa_in->sin_len = sizeof(struct sockaddr_in);
-		sa_in->sin_addr.s_addr = addr->v4.s_addr;
-		sa_in->sin_port = htons(port);
-		break;
-	case AF_INET6:
-		sa_in6->sin6_family = AF_INET6;
-		sa_in6->sin6_len = sizeof(struct sockaddr_in6);
-		memcpy(&sa_in6->sin6_addr, &addr->v6,
-		    sizeof(sa_in6->sin6_addr));
-		sa_in6->sin6_port = htons(port);
-		sa_in6->sin6_scope_id = addr->scope_id;
-		break;
-	}
-
-	return ((struct sockaddr *)&ss);
-}
-
 void
 session_demote(struct peer *p, int level)
 {
@@ -2837,3 +2835,19 @@ session_demote(struct peer *p, int level
 
 	p->demoted += level;
 }
+
+void
+session_stop(struct peer *peer, u_int8_t subcode)
+{
+	switch (peer->state) {
+	case STATE_OPENSENT:
+	case STATE_OPENCONFIRM:
+	case STATE_ESTABLISHED:
+		session_notification(peer, ERR_CEASE, subcode, NULL, 0);
+		break;
+	default:
+		/* session not open, no need to send notification */
+		break;
+	}
+	bgp_fsm(peer, EVNT_STOP);
+}
