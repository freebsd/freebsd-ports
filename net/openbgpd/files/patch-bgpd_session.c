Index: bgpd/session.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/session.c,v
retrieving revision 1.1.1.8
retrieving revision 1.13
diff -u -p -r1.1.1.8 -r1.13
--- bgpd/session.c	14 Feb 2010 20:19:57 -0000	1.1.1.8
+++ bgpd/session.c	8 Dec 2012 20:17:59 -0000	1.13
@@ -1,4 +1,4 @@
-/*	$OpenBSD: session.c,v 1.293 2009/06/07 05:56:24 eric Exp $ */
+/*	$OpenBSD: session.c,v 1.325 2012/09/18 09:45:50 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004, 2005 Henning Brauer <henning@openbsd.org>
@@ -21,18 +21,21 @@
 
 #include <sys/mman.h>
 #include <sys/socket.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 #include <sys/un.h>
+#include <sys/queue.h>
 #include <net/if_types.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
+#include <netinet/tcp_var.h>
 #include <arpa/inet.h>
 
 #include <err.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <limits.h>
 #include <poll.h>
 #include <pwd.h>
 #include <signal.h>
@@ -50,7 +53,12 @@
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
@@ -65,9 +73,9 @@ void	session_accept(int);
 int	session_connect(struct peer *);
 void	session_tcp_established(struct peer *);
 void	session_capa_ann_none(struct peer *);
-int	session_capa_add(struct peer *, struct buf *, u_int8_t, u_int8_t,
-	    u_int8_t *);
-int	session_capa_add_mp(struct buf *, u_int16_t, u_int8_t);
+int	session_capa_add(struct ibuf *, u_int8_t, u_int8_t);
+int	session_capa_add_mp(struct ibuf *, u_int8_t);
+int	session_capa_add_gr(struct peer *, struct ibuf *, u_int8_t);
 struct bgp_msg	*session_newmsg(enum msg_type, u_int16_t);
 int	session_sendmsg(struct bgp_msg *, struct peer *);
 void	session_open(struct peer *);
@@ -75,30 +83,34 @@ void	session_keepalive(struct peer *);
 void	session_update(u_int32_t, void *, size_t);
 void	session_notification(struct peer *, u_int8_t, u_int8_t, void *,
 	    ssize_t);
-void	session_rrefresh(struct peer *, u_int16_t, u_int8_t);
+void	session_rrefresh(struct peer *, u_int8_t);
+int	session_graceful_restart(struct peer *);
+int	session_graceful_is_restarting(struct peer *);
+int	session_graceful_stop(struct peer *);
 int	session_dispatch_msg(struct pollfd *, struct peer *);
+int	session_process_msg(struct peer *);
 int	parse_header(struct peer *, u_char *, u_int16_t *, u_int8_t *);
 int	parse_open(struct peer *);
 int	parse_update(struct peer *);
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
@@ -106,6 +118,7 @@ struct imsgbuf		*ibuf_rde_ctl;
 struct imsgbuf		*ibuf_main;
 
 struct mrt_head		 mrthead;
+time_t			 pauseaccept;
 
 void
 session_sighdlr(int sig)
@@ -125,6 +138,22 @@ setup_listeners(u_int *la_cnt)
 	int			 opt;
 	struct listen_addr	*la;
 	u_int			 cnt = 0;
+#if defined(__FreeBSD__)
+	int			 s;
+
+	/* Check if TCP_MD5SIG is supported. */
+	s = socket(PF_LOCAL, SOCK_STREAM, 0);
+	if (s < 0)
+		fatal("socket open for TCP_MD5SIG check");
+	opt = TF_SIGNATURE;
+	if (setsockopt(s, IPPROTO_TCP, TCP_MD5SIG, &opt, sizeof(opt)) == -1) {
+		if (errno == ENOPROTOOPT || errno == EINVAL)
+			sysdep.no_md5sig = 1;
+		else
+			fatal("setsockopt TCP_MD5SIG");
+	}
+	close(s);
+#endif /* defined(__FreeBSD__) */
 
 	TAILQ_FOREACH(la, conf->listen_addrs, entry) {
 		la->reconf = RECONF_NONE;
@@ -140,6 +169,7 @@ setup_listeners(u_int *la_cnt)
 		}
 
 		opt = 1;
+#if !defined(__FreeBSD__)
 		if (setsockopt(la->fd, IPPROTO_TCP, TCP_MD5SIG,
 		    &opt, sizeof(opt)) == -1) {
 			if (errno == ENOPROTOOPT) {	/* system w/o md5sig */
@@ -148,6 +178,7 @@ setup_listeners(u_int *la_cnt)
 			} else
 				fatal("setsockopt TCP_MD5SIG");
 		}
+#endif /* !defined(__FreeBSD__) */
 
 		/* set ttl to 255 so that ttl-security works */
 		if (la->sa.ss_family == AF_INET && setsockopt(la->fd,
@@ -175,12 +206,10 @@ setup_listeners(u_int *la_cnt)
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
+	int			 nfds, timeout, pfkeysock;
 	unsigned int		 i, j, idx_peers, idx_listeners, idx_mrts;
 	pid_t			 pid;
 	u_int			 pfd_elms = 0, peer_l_elms = 0, mrt_l_elms = 0;
@@ -189,19 +218,13 @@ session_main(struct bgpd_config *config,
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
@@ -211,13 +234,6 @@ session_main(struct bgpd_config *config,
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
 
@@ -228,29 +244,25 @@ session_main(struct bgpd_config *config,
 
 	setproctitle("session engine");
 	bgpd_process = PROC_SE;
-
-	if (pfkey_init(&sysdep) == -1)
-		fatalx("pfkey setup failed");
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
@@ -258,37 +270,21 @@ session_main(struct bgpd_config *config,
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
@@ -308,8 +304,9 @@ session_main(struct bgpd_config *config,
 
 				/* reinit due? */
 				if (p->conf.reconf_action == RECONF_REINIT) {
-					bgp_fsm(p, EVNT_STOP);
-					timer_set(p, Timer_IdleHold, 0);
+					session_stop(p, ERR_CEASE_ADMIN_RESET);
+					if (!p->conf.down)
+						timer_set(p, Timer_IdleHold, 0);
 				}
 
 				/* deletion due? */
@@ -317,7 +314,7 @@ session_main(struct bgpd_config *config,
 					if (p->demoted)
 						session_demote(p, -1);
 					p->conf.demote_group[0] = 0;
-					bgp_fsm(p, EVNT_STOP);
+					session_stop(p, ERR_CEASE_PEER_UNCONF);
 					log_peer_warnx(&p->conf, "removed");
 					if (last != NULL)
 						last->next = next;
@@ -346,9 +343,17 @@ session_main(struct bgpd_config *config,
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
@@ -394,18 +399,31 @@ session_main(struct bgpd_config *config,
 		if (ctl_queued < SESSION_CTL_QUEUE_MAX)
 			/*
 			 * Do not act as unlimited buffer. Don't read in more
-			 * messages if the ctl sockets are getting full. 
+			 * messages if the ctl sockets are getting full.
 			 */
 			pfd[PFD_PIPE_ROUTE_CTL].events = POLLIN;
-		pfd[PFD_SOCK_CTL].fd = csock;
-		pfd[PFD_SOCK_CTL].events = POLLIN;
-		pfd[PFD_SOCK_RCTL].fd = rcsock;
-		pfd[PFD_SOCK_RCTL].events = POLLIN;
-
+		if (pauseaccept == 0) {
+			pfd[PFD_SOCK_CTL].fd = csock;
+			pfd[PFD_SOCK_CTL].events = POLLIN;
+			pfd[PFD_SOCK_RCTL].fd = rcsock;
+			pfd[PFD_SOCK_RCTL].events = POLLIN;
+		} else {
+			pfd[PFD_SOCK_CTL].fd = -1;
+			pfd[PFD_SOCK_RCTL].fd = -1;
+		}
+		pfd[PFD_SOCK_PFKEY].fd = pfkeysock;
+#if !defined(__FreeBSD__)
+		pfd[PFD_SOCK_PFKEY].events = POLLIN;
+#else
+		pfd[PFD_SOCK_PFKEY].events = 0;
+#endif
 		i = PFD_LISTENERS_START;
 		TAILQ_FOREACH(la, conf->listen_addrs, entry) {
-			pfd[i].fd = la->fd;
-			pfd[i].events = POLLIN;
+			if (pauseaccept == 0) {
+				pfd[i].fd = la->fd;
+				pfd[i].events = POLLIN;
+			} else
+				pfd[i].fd = -1;
 			i++;
 		}
 		idx_listeners = i;
@@ -450,6 +468,10 @@ session_main(struct bgpd_config *config,
 					    p->state == STATE_ESTABLISHED)
 						session_demote(p, -1);
 					break;
+				case Timer_RestartTimeout:
+					timer_stop(p, Timer_RestartTimeout);
+					session_graceful_stop(p);
+					break;
 				default:
 					fatalx("King Bula lost in time");
 				}
@@ -462,6 +484,9 @@ session_main(struct bgpd_config *config,
 			events = POLLIN;
 			if (p->wbuf.queued > 0 || p->state == STATE_CONNECT)
 				events |= POLLOUT;
+			/* is there still work to do? */
+			if (p->rbuf && p->rbuf->wpos)
+				timeout = 0;
 
 			/* poll events */
 			if (p->fd != -1 && events != 0) {
@@ -492,12 +517,21 @@ session_main(struct bgpd_config *config,
 			i++;
 		}
 
+		if (pauseaccept && timeout > 1)
+			timeout = 1;
 		if (timeout < 0)
 			timeout = 0;
 		if ((nfds = poll(pfd, i, timeout * 1000)) == -1)
 			if (errno != EINTR)
 				fatal("poll error");
 
+		/*
+		 * If we previously saw fd exhaustion, we stop accept()
+		 * for 1 second to throttle the accept() loop.
+		 */
+		if (pauseaccept && getmonotime() > pauseaccept + 1)
+			pauseaccept = 0;
+
 		if (nfds > 0 && pfd[PFD_PIPE_MAIN].revents & POLLOUT)
 			if (msgbuf_write(&ibuf_main->w) < 0)
 				fatal("pipe write error");
@@ -534,6 +568,14 @@ session_main(struct bgpd_config *config,
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
@@ -545,6 +587,10 @@ session_main(struct bgpd_config *config,
 			nfds -= session_dispatch_msg(&pfd[j],
 			    peer_l[j - idx_listeners]);
 
+		for (p = peers; p != NULL; p = p->next)
+			if (p->rbuf && p->rbuf->wpos)
+				session_process_msg(p);
+
 		for (; nfds > 0 && j < idx_mrts; j++)
 			if (pfd[j].revents & POLLOUT) {
 				nfds--;
@@ -557,7 +603,7 @@ session_main(struct bgpd_config *config,
 
 	while ((p = peers) != NULL) {
 		peers = p->next;
-		bgp_fsm(p, EVNT_STOP);
+		session_stop(p, ERR_CEASE_ADMIN_DOWN);
 		pfkey_remove(p);
 		free(p);
 	}
@@ -643,10 +689,9 @@ bgp_fsm(struct peer *peer, enum session_
 			timer_stop(peer, Timer_IdleHold);
 
 			/* allocate read buffer */
-			peer->rbuf = calloc(1, sizeof(struct buf_read));
+			peer->rbuf = calloc(1, sizeof(struct ibuf_read));
 			if (peer->rbuf == NULL)
 				fatal(NULL);
-			peer->rbuf->wpos = 0;
 
 			/* init write buffer */
 			msgbuf_init(&peer->wbuf);
@@ -746,7 +791,6 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
@@ -780,7 +824,8 @@ bgp_fsm(struct peer *peer, enum session_
 				change_state(peer, STATE_IDLE, event);
 			break;
 		default:
-			session_notification(peer, ERR_FSM, 0, NULL, 0);
+			session_notification(peer,
+			    ERR_FSM, ERR_FSM_UNEX_OPENSENT, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		}
@@ -791,7 +836,6 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
@@ -815,7 +859,8 @@ bgp_fsm(struct peer *peer, enum session_
 			change_state(peer, STATE_IDLE, event);
 			break;
 		default:
-			session_notification(peer, ERR_FSM, 0, NULL, 0);
+			session_notification(peer,
+			    ERR_FSM, ERR_FSM_UNEX_OPENCONFIRM, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		}
@@ -826,7 +871,6 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
@@ -856,7 +900,8 @@ bgp_fsm(struct peer *peer, enum session_
 			change_state(peer, STATE_IDLE, event);
 			break;
 		default:
-			session_notification(peer, ERR_FSM, 0, NULL, 0);
+			session_notification(peer,
+			    ERR_FSM, ERR_FSM_UNEX_ESTABLISHED, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		}
@@ -885,9 +930,10 @@ start_timer_keepalive(struct peer *peer)
 void
 session_close_connection(struct peer *peer)
 {
-	if (peer->fd != -1)
+	if (peer->fd != -1) {
 		close(peer->fd);
-
+		pauseaccept = 0;
+	}
 	peer->fd = peer->wbuf.fd = -1;
 }
 
@@ -923,20 +969,31 @@ change_state(struct peer *peer, enum ses
 		timer_stop(peer, Timer_ConnectRetry);
 		timer_stop(peer, Timer_Keepalive);
 		timer_stop(peer, Timer_Hold);
+		timer_stop(peer, Timer_IdleHold);
 		timer_stop(peer, Timer_IdleHoldReset);
 		session_close_connection(peer);
 		msgbuf_clear(&peer->wbuf);
 		free(peer->rbuf);
 		peer->rbuf = NULL;
 		bzero(&peer->capa.peer, sizeof(peer->capa.peer));
-		if (peer->state == STATE_ESTABLISHED)
-			session_down(peer);
+
 		if (event != EVNT_STOP) {
 			timer_set(peer, Timer_IdleHold, peer->IdleHoldTime);
 			if (event != EVNT_NONE &&
 			    peer->IdleHoldTime < MAX_IDLE_HOLD/2)
 				peer->IdleHoldTime *= 2;
 		}
+		if (peer->state == STATE_ESTABLISHED) {
+			if (peer->capa.neg.grestart.restart == 2 &&
+			    (event == EVNT_CON_CLOSED ||
+			    event == EVNT_CON_FATAL)) {
+				/* don't punish graceful restart */
+				timer_set(peer, Timer_IdleHold, 0);
+				peer->IdleHoldTime /= 2;
+				session_graceful_restart(peer);
+			} else
+				session_down(peer);
+		}
 		if (peer->state == STATE_NONE ||
 		    peer->state == STATE_ESTABLISHED) {
 			/* initialize capability negotiation structures */
@@ -947,6 +1004,20 @@ change_state(struct peer *peer, enum ses
 		}
 		break;
 	case STATE_CONNECT:
+		if (peer->state == STATE_ESTABLISHED &&
+		    peer->capa.neg.grestart.restart == 2) {
+			/* do the graceful restart dance */
+			session_graceful_restart(peer);
+			peer->holdtime = INTERVAL_HOLD_INITIAL;
+			timer_stop(peer, Timer_ConnectRetry);
+			timer_stop(peer, Timer_Keepalive);
+			timer_stop(peer, Timer_Hold);
+			timer_stop(peer, Timer_IdleHold);
+			timer_stop(peer, Timer_IdleHoldReset);
+			session_close_connection(peer);
+			msgbuf_clear(&peer->wbuf);
+			bzero(&peer->capa.peer, sizeof(peer->capa.peer));
+		}
 		break;
 	case STATE_ACTIVE:
 		break;
@@ -990,7 +1061,10 @@ session_accept(int listenfd)
 	len = sizeof(cliaddr);
 	if ((connfd = accept(listenfd,
 	    (struct sockaddr *)&cliaddr, &len)) == -1) {
-		if (errno == EWOULDBLOCK || errno == EINTR)
+		if (errno == ENFILE || errno == EMFILE) {
+			pauseaccept = getmonotime();
+			return;
+		} else if (errno == EWOULDBLOCK || errno == EINTR)
 			return;
 		else
 			log_warn("accept");
@@ -1017,6 +1091,7 @@ session_accept(int listenfd)
 			}
 		}
 
+open:
 		if (p->conf.auth.method != AUTH_NONE && sysdep.no_pfkey) {
 			log_peer_warnx(&p->conf,
 			    "ipsec or md5sig configured but not available");
@@ -1049,6 +1124,13 @@ session_accept(int listenfd)
 		}
 		session_socket_blockmode(connfd, BM_NONBLOCK);
 		bgp_fsm(p, EVNT_CON_OPEN);
+		return;
+	} else if (p != NULL && p->state == STATE_ESTABLISHED &&
+	    p->capa.neg.grestart.restart == 2) {
+		/* first do the graceful restart dance */
+		change_state(p, STATE_CONNECT, EVNT_CON_CLOSED);
+		/* then do part of the open dance */
+		goto open;
 	} else {
 		log_conn_attempt(p, (struct sockaddr *)&cliaddr);
 		close(connfd);
@@ -1069,7 +1151,7 @@ session_connect(struct peer *peer)
 	if (peer->fd != -1)
 		return (-1);
 
-	if ((peer->fd = socket(peer->conf.remote_addr.af, SOCK_STREAM,
+	if ((peer->fd = socket(aid2af(peer->conf.remote_addr.aid), SOCK_STREAM,
 	    IPPROTO_TCP)) == -1) {
 		log_peer_warn(&peer->conf, "session_connect socket");
 		bgp_fsm(peer, EVNT_CON_OPENFAIL);
@@ -1100,8 +1182,7 @@ session_connect(struct peer *peer)
 	peer->wbuf.fd = peer->fd;
 
 	/* if update source is set we need to bind() */
-	if (peer->conf.local_addr.af) {
-		sa = addr2sa(&peer->conf.local_addr, 0);
+	if ((sa = addr2sa(&peer->conf.local_addr, 0)) != NULL) {
 		if (bind(peer->fd, sa, sa->sa_len) == -1) {
 			log_peer_warn(&peer->conf, "session_connect bind");
 			bgp_fsm(peer, EVNT_CON_OPENFAIL);
@@ -1139,42 +1220,50 @@ session_setup_socket(struct peer *p)
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
@@ -1185,24 +1274,18 @@ session_setup_socket(struct peer *p)
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
 		bsize = 65535;
-		while (setsockopt(p->fd, SOL_SOCKET, SO_RCVBUF, &bsize,
-		    sizeof(bsize)) == -1)
+		while (bsize > 8192 &&
+		    setsockopt(p->fd, SOL_SOCKET, SO_RCVBUF, &bsize,
+		    sizeof(bsize)) == -1 && errno != EINVAL)
 			bsize /= 2;
 		bsize = 65535;
-		while (setsockopt(p->fd, SOL_SOCKET, SO_SNDBUF, &bsize,
-		    sizeof(bsize)) == -1)
+		while (bsize > 8192 &&
+		    setsockopt(p->fd, SOL_SOCKET, SO_SNDBUF, &bsize,
+		    sizeof(bsize)) == -1 && errno != EINVAL)
 			bsize /= 2;
 	}
 
@@ -1244,40 +1327,56 @@ session_tcp_established(struct peer *pee
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
-{
-	u_int8_t	op_type, op_len, tot_len, errs = 0;
-
-	op_type = OPT_PARAM_CAPABILITIES;
-	op_len = sizeof(capa_code) + sizeof(capa_len) + capa_len;
-	tot_len = sizeof(op_type) + sizeof(op_len) + op_len;
-	errs += buf_add(opb, &op_type, sizeof(op_type));
-	errs += buf_add(opb, &op_len, sizeof(op_len));
-	errs += buf_add(opb, &capa_code, sizeof(capa_code));
-	errs += buf_add(opb, &capa_len, sizeof(capa_len));
-	*optparamlen += tot_len;
+session_capa_add(struct ibuf *opb, u_int8_t capa_code, u_int8_t capa_len)
+{
+	int errs = 0;
+
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
+	afi = htons(afi);
+	errs += ibuf_add(buf, &afi, sizeof(afi));
+	errs += ibuf_add(buf, &pad, sizeof(pad));
+	errs += ibuf_add(buf, &safi, sizeof(safi));
+
+	return (errs);
+}
+
+int
+session_capa_add_gr(struct peer *p, struct ibuf *b, u_int8_t aid)
+{
+	u_int		errs = 0;
+	u_int16_t	afi;
+	u_int8_t	flags, safi;
+
+	if (aid2afi(aid, &afi, &safi)) {
+		log_warn("session_capa_add_gr: bad AID");
+		return (1);
+	}
+	if (p->capa.neg.grestart.flags[aid] & CAPA_GR_RESTARTING)
+		flags = CAPA_GR_F_FLAG;
+	else
+		flags = 0;
+
 	afi = htons(afi);
-	errs += buf_add(buf, &afi, sizeof(afi));
-	errs += buf_add(buf, &pad, sizeof(pad));
-	errs += buf_add(buf, &safi, sizeof(safi));
+	errs += ibuf_add(b, &afi, sizeof(afi));
+	errs += ibuf_add(b, &safi, sizeof(safi));
+	errs += ibuf_add(b, &flags, sizeof(flags));
 
 	return (errs);
 }
@@ -1287,23 +1386,22 @@ session_newmsg(enum msg_type msgtype, u_
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
 
@@ -1329,7 +1427,7 @@ session_sendmsg(struct bgp_msg *msg, str
 			mrt_dump_bgp_msg(mrt, msg->buf->buf, msg->len, p);
 	}
 
-	buf_close(&p->wbuf, msg->buf);
+	ibuf_close(&p->wbuf, msg->buf);
 	free(msg);
 	return (0);
 }
@@ -1338,40 +1436,70 @@ void
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
+	int			 mpcapa = 0;
 
 
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
+			mpcapa++;
+		}
 
 	/* route refresh, RFC 2918 */
 	if (p->capa.ann.refresh)	/* no data */
-		errs += session_capa_add(p, opb, CAPA_REFRESH, 0, &optparamlen);
+		errs += session_capa_add(opb, CAPA_REFRESH, 0);
 
-	/* End-of-RIB marker, RFC 4724 */
-	if (p->capa.ann.restart) {	/* 2 bytes data */
-		u_char		c[2];
-
-		bzero(&c, 2);
-		c[0] = 0x80; /* we're always restarting */
-		errs += session_capa_add(p, opb, CAPA_RESTART, 2, &optparamlen);
-		errs += buf_add(opb, &c, 2);
+	/* graceful restart and End-of-RIB marker, RFC 4724 */
+	if (p->capa.ann.grestart.restart) {
+		int		rst = 0;
+		u_int16_t	hdr;
+		u_int8_t	grlen;
+
+		if (mpcapa) {
+			grlen = 2 + 4 * mpcapa;
+			for (i = 0; i < AID_MAX; i++) {
+				if (p->capa.neg.grestart.flags[i] &
+				    CAPA_GR_RESTARTING)
+					rst++;
+			}
+		} else {	/* AID_INET */
+			grlen = 2 + 4;
+			if (p->capa.neg.grestart.flags[AID_INET] &
+			    CAPA_GR_RESTARTING)
+				rst++;
+		}
+
+		hdr = conf->holdtime;		/* default timeout */
+		/* if client does graceful restart don't set R flag */
+		if (!rst)
+			hdr |= CAPA_GR_R_FLAG;
+		hdr = htons(hdr);
+
+		errs += session_capa_add(opb, CAPA_RESTART, grlen);
+		errs += ibuf_add(opb, &hdr, sizeof(hdr));
+
+		if (mpcapa) {
+			for (i = 0; i < AID_MAX; i++) {
+				if (p->capa.ann.mp[i]) {
+					errs += session_capa_add_gr(p, opb, i);
+				}
+			}
+		} else {	/* AID_INET */
+			errs += session_capa_add_gr(p, opb, AID_INET);
+		}
 	}
 
 	/* 4-bytes AS numbers, draft-ietf-idr-as4bytes-13 */
@@ -1379,13 +1507,17 @@ session_open(struct peer *p)
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
@@ -1399,19 +1531,24 @@ session_open(struct peer *p)
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
@@ -1459,8 +1596,8 @@ session_update(u_int32_t peerid, void *d
 		return;
 	}
 
-	if (buf_add(buf->buf, data, datalen)) {
-		buf_free(buf->buf);
+	if (ibuf_add(buf->buf, data, datalen)) {
+		ibuf_free(buf->buf);
 		free(buf);
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
@@ -1480,29 +1617,27 @@ session_notification(struct peer *p, u_i
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
@@ -1521,23 +1656,29 @@ session_notification(struct peer *p, u_i
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
@@ -1545,12 +1686,12 @@ session_rrefresh(struct peer *p, u_int16
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
@@ -1565,13 +1706,74 @@ session_rrefresh(struct peer *p, u_int16
 }
 
 int
+session_graceful_restart(struct peer *p)
+{
+	u_int8_t	i;
+
+	timer_set(p, Timer_RestartTimeout, p->capa.neg.grestart.timeout);
+
+	for (i = 0; i < AID_MAX; i++) {
+		if (p->capa.neg.grestart.flags[i] & CAPA_GR_PRESENT) {
+			if (imsg_compose(ibuf_rde, IMSG_SESSION_STALE,
+			    p->conf.id, 0, -1, &i, sizeof(i)) == -1)
+				return (-1);
+			log_peer_warnx(&p->conf,
+			    "graceful restart of %s, keeping routes",
+			    aid2str(i));
+			p->capa.neg.grestart.flags[i] |= CAPA_GR_RESTARTING;
+		} else if (p->capa.neg.mp[i]) {
+			if (imsg_compose(ibuf_rde, IMSG_SESSION_FLUSH,
+			    p->conf.id, 0, -1, &i, sizeof(i)) == -1)
+				return (-1);
+			log_peer_warnx(&p->conf,
+			    "graceful restart of %s, flushing routes",
+			    aid2str(i));
+		}
+	}
+	return (0);
+}
+
+int
+session_graceful_is_restarting(struct peer *p)
+{
+	u_int8_t	i;
+
+	for (i = 0; i < AID_MAX; i++)
+		if (p->capa.neg.grestart.flags[i] & CAPA_GR_RESTARTING)
+			return (1);
+	return (0);
+}
+
+int
+session_graceful_stop(struct peer *p)
+{
+	u_int8_t	i;
+
+	for (i = 0; i < AID_MAX; i++) {
+		/*
+		 * Only flush if the peer is restarting and the peer indicated
+		 * it hold the forwarding state. In all other cases the
+		 * session was already flushed when the session came up.
+		 */
+		if (p->capa.neg.grestart.flags[i] & CAPA_GR_RESTARTING &&
+		    p->capa.neg.grestart.flags[i] & CAPA_GR_FORWARD) {
+			log_peer_warnx(&p->conf, "graceful restart of %s, "
+			    "time-out, flushing", aid2str(i));
+			if (imsg_compose(ibuf_rde, IMSG_SESSION_FLUSH,
+			    p->conf.id, 0, -1, &i, sizeof(i)) == -1)
+				return (-1);
+		}
+		p->capa.neg.grestart.flags[i] &= ~CAPA_GR_RESTARTING;
+	}
+	return (0);
+}
+
+int
 session_dispatch_msg(struct pollfd *pfd, struct peer *p)
 {
-	ssize_t		n, rpos, av, left;
+	ssize_t		n;
 	socklen_t	len;
-	int		error, processed = 0;
-	u_int16_t	msglen;
-	u_int8_t	msgtype;
+	int		error;
 
 	if (p->state == STATE_CONNECT) {
 		if (pfd->revents & POLLOUT) {
@@ -1641,71 +1843,83 @@ session_dispatch_msg(struct pollfd *pfd,
 			return (1);
 		}
 
-		rpos = 0;
-		av = p->rbuf->wpos + n;
+		p->rbuf->wpos += n;
 		p->stats.last_read = time(NULL);
+		return (1);
+	}
+	return (0);
+}
 
-		/*
-		 * session might drop to IDLE -> buffers deallocated
-		 * we MUST check rbuf != NULL before use
-		 */
-		for (;;) {
-			if (rpos + MSGSIZE_HEADER > av)
-				break;
-			if (p->rbuf == NULL)
-				break;
-			if (parse_header(p, p->rbuf->buf + rpos, &msglen,
-			    &msgtype) == -1)
-				return (0);
-			if (rpos + msglen > av)
-				break;
-			p->rbuf->rptr = p->rbuf->buf + rpos;
-
-			switch (msgtype) {
-			case OPEN:
-				bgp_fsm(p, EVNT_RCVD_OPEN);
-				p->stats.msg_rcvd_open++;
-				break;
-			case UPDATE:
-				bgp_fsm(p, EVNT_RCVD_UPDATE);
-				p->stats.msg_rcvd_update++;
-				break;
-			case NOTIFICATION:
-				bgp_fsm(p, EVNT_RCVD_NOTIFICATION);
-				p->stats.msg_rcvd_notification++;
-				break;
-			case KEEPALIVE:
-				bgp_fsm(p, EVNT_RCVD_KEEPALIVE);
-				p->stats.msg_rcvd_keepalive++;
-				break;
-			case RREFRESH:
-				parse_refresh(p);
-				p->stats.msg_rcvd_rrefresh++;
-				break;
-			default:	/* cannot happen */
-				session_notification(p, ERR_HEADER,
-				    ERR_HDR_TYPE, &msgtype, 1);
-				log_warnx("received message with "
-				    "unknown type %u", msgtype);
-				bgp_fsm(p, EVNT_CON_FATAL);
-			}
-			rpos += msglen;
-			if (++processed > MSG_PROCESS_LIMIT)
-				break;
-		}
-		if (p->rbuf == NULL)
-			return (1);
+int
+session_process_msg(struct peer *p)
+{
+	ssize_t		rpos, av, left;
+	int		processed = 0;
+	u_int16_t	msglen;
+	u_int8_t	msgtype;
 
-		if (rpos < av) {
-			left = av - rpos;
-			memcpy(&p->rbuf->buf, p->rbuf->buf + rpos, left);
-			p->rbuf->wpos = left;
-		} else
-			p->rbuf->wpos = 0;
+	rpos = 0;
+	av = p->rbuf->wpos;
 
-		return (1);
+	/*
+	 * session might drop to IDLE -> buffers deallocated
+	 * we MUST check rbuf != NULL before use
+	 */
+	for (;;) {
+		if (rpos + MSGSIZE_HEADER > av)
+			break;
+		if (p->rbuf == NULL)
+			break;
+		if (parse_header(p, p->rbuf->buf + rpos, &msglen,
+		    &msgtype) == -1)
+			return (0);
+		if (rpos + msglen > av)
+			break;
+		p->rbuf->rptr = p->rbuf->buf + rpos;
+
+		switch (msgtype) {
+		case OPEN:
+			bgp_fsm(p, EVNT_RCVD_OPEN);
+			p->stats.msg_rcvd_open++;
+			break;
+		case UPDATE:
+			bgp_fsm(p, EVNT_RCVD_UPDATE);
+			p->stats.msg_rcvd_update++;
+			break;
+		case NOTIFICATION:
+			bgp_fsm(p, EVNT_RCVD_NOTIFICATION);
+			p->stats.msg_rcvd_notification++;
+			break;
+		case KEEPALIVE:
+			bgp_fsm(p, EVNT_RCVD_KEEPALIVE);
+			p->stats.msg_rcvd_keepalive++;
+			break;
+		case RREFRESH:
+			parse_refresh(p);
+			p->stats.msg_rcvd_rrefresh++;
+			break;
+		default:	/* cannot happen */
+			session_notification(p, ERR_HEADER, ERR_HDR_TYPE,
+			    &msgtype, 1);
+			log_warnx("received message with unknown type %u",
+			    msgtype);
+			bgp_fsm(p, EVNT_CON_FATAL);
+		}
+		rpos += msglen;
+		if (++processed > MSG_PROCESS_LIMIT)
+			break;
 	}
-	return (0);
+	if (p->rbuf == NULL)
+		return (1);
+
+	if (rpos < av) {
+		left = av - rpos;
+		memcpy(&p->rbuf->buf, p->rbuf->buf + rpos, left);
+		p->rbuf->wpos = left;
+	} else
+		p->rbuf->wpos = 0;
+
+	return (1);
 }
 
 int
@@ -1853,12 +2067,6 @@ parse_open(struct peer *peer)
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
 
@@ -1966,6 +2174,15 @@ parse_open(struct peer *peer)
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
@@ -1974,6 +2191,14 @@ parse_open(struct peer *peer)
 		return (-1);
 	}
 
+	if (capa_neg_calc(peer) == -1) {
+		log_peer_warnx(&peer->conf,
+		    "capability negotiation calculation failed");
+		session_notification(peer, ERR_OPEN, 0, NULL, 0);
+		change_state(peer, STATE_IDLE, EVNT_RCVD_OPEN);
+		return (-1);
+	}
+
 	return (0);
 }
 
@@ -2008,24 +2233,35 @@ int
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
@@ -2035,11 +2271,12 @@ int
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
@@ -2059,7 +2296,7 @@ parse_notification(struct peer *peer)
 	p += sizeof(subcode);
 	datalen -= sizeof(subcode);
 
-	log_notification(peer, errcode, subcode, p, datalen);
+	log_notification(peer, errcode, subcode, p, datalen, "received");
 	peer->errcnt++;
 
 	if (errcode == ERR_OPEN && subcode == ERR_OPEN_CAPA) {
@@ -2094,8 +2331,8 @@ parse_notification(struct peer *peer)
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
@@ -2105,7 +2342,7 @@ parse_notification(struct peer *peer)
 				    "disabling route refresh capability");
 				break;
 			case CAPA_RESTART:
-				peer->capa.ann.restart = 0;
+				peer->capa.ann.grestart.restart = 0;
 				log_peer_warnx(&peer->conf,
 				    "disabling restart capability");
 				break;
@@ -2139,19 +2376,23 @@ parse_notification(struct peer *peer)
 int
 parse_capabilities(struct peer *peer, u_char *d, u_int16_t dlen, u_int32_t *as)
 {
+	u_char		*capa_val;
+	u_int32_t	 remote_as;
 	u_int16_t	 len;
+	u_int16_t	 afi;
+	u_int16_t	 gr_header;
+	u_int8_t	 safi;
+	u_int8_t	 aid;
+	u_int8_t	 gr_flags;
 	u_int8_t	 capa_code;
 	u_int8_t	 capa_len;
-	u_char		*capa_val;
-	u_int16_t	 mp_afi;
-	u_int8_t	 mp_safi;
-	u_int32_t	 remote_as;
+	u_int8_t	 i;
 
 	len = dlen;
 	while (len > 0) {
 		if (len < 2) {
-			log_peer_warnx(&peer->conf, "parse_capabilities: "
-			    "expect len >= 2, len is %u", len);
+			log_peer_warnx(&peer->conf, "Bad capabilities attr "
+			    "length: %u, too short", len);
 			return (-1);
 		}
 		memcpy(&capa_code, d, sizeof(capa_code));
@@ -2163,7 +2404,7 @@ parse_capabilities(struct peer *peer, u_
 		if (capa_len > 0) {
 			if (len < capa_len) {
 				log_peer_warnx(&peer->conf,
-				    "parse_capabilities: "
+				    "Bad capabilities attr length: "
 				    "len %u smaller than capa_len %u",
 				    len, capa_len);
 				return (-1);
@@ -2178,47 +2419,82 @@ parse_capabilities(struct peer *peer, u_
 		case CAPA_MP:			/* RFC 4760 */
 			if (capa_len != 4) {
 				log_peer_warnx(&peer->conf,
-				    "parse_capabilities: "
-				    "expect len 4, len is %u", capa_len);
-				return (-1);
-			}
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
+				    "Bad multi protocol capability length: "
+				    "%u", capa_len);
 				break;
-			case AFI_IPv6:
-				if (mp_safi < 1 || mp_safi > 3)
-					log_peer_warnx(&peer->conf,
-					    "parse_capabilities: AFI IPv6, "
-					    "mp_safi %u unknown", mp_safi);
-				else
-					peer->capa.peer.mp_v6 = mp_safi;
-				break;
-			default:			/* ignore */
+			}
+			memcpy(&afi, capa_val, sizeof(afi));
+			afi = ntohs(afi);
+			memcpy(&safi, capa_val + 3, sizeof(safi));
+			if (afi2aid(afi, safi, &aid) == -1) {
+				log_peer_warnx(&peer->conf,
+				    "Received multi protocol capability: "
+				    " unknown AFI %u, safi %u pair",
+				    afi, safi);
 				break;
 			}
+			peer->capa.peer.mp[aid] = 1;
 			break;
 		case CAPA_REFRESH:
 			peer->capa.peer.refresh = 1;
 			break;
 		case CAPA_RESTART:
-			peer->capa.peer.restart = 1;
-			/* we don't care about the further restart capas yet */
+			if (capa_len == 2) {
+				/* peer only supports EoR marker */
+				peer->capa.peer.grestart.restart = 1;
+				peer->capa.peer.grestart.timeout = 0;
+				break;
+			} else if (capa_len % 4 != 2) {
+				log_peer_warnx(&peer->conf,
+				    "Bad graceful restart capability length: "
+				    "%u", capa_len);
+				peer->capa.peer.grestart.restart = 0;
+				peer->capa.peer.grestart.timeout = 0;
+				break;
+			}
+
+			memcpy(&gr_header, capa_val, sizeof(gr_header));
+			gr_header = ntohs(gr_header);
+			peer->capa.peer.grestart.timeout =
+			    gr_header & CAPA_GR_TIMEMASK;
+			if (peer->capa.peer.grestart.timeout == 0) {
+				log_peer_warnx(&peer->conf, "Received "
+				    "graceful restart timeout is zero");
+				peer->capa.peer.grestart.restart = 0;
+				break;
+			}
+
+			for (i = 2; i <= capa_len - 4; i += 4) {
+				memcpy(&afi, capa_val + i, sizeof(afi));
+				afi = ntohs(afi);
+				memcpy(&safi, capa_val + i + 2, sizeof(safi));
+				if (afi2aid(afi, safi, &aid) == -1) {
+					log_peer_warnx(&peer->conf,
+					    "Received graceful restart capa: "
+					    " unknown AFI %u, safi %u pair",
+					    afi, safi);
+					continue;
+				}
+				memcpy(&gr_flags, capa_val + i + 3,
+				    sizeof(gr_flags));
+				peer->capa.peer.grestart.flags[aid] |=
+				    CAPA_GR_PRESENT;
+				if (gr_flags & CAPA_GR_F_FLAG)
+					peer->capa.peer.grestart.flags[aid] |=
+					    CAPA_GR_FORWARD;
+				if (gr_header & CAPA_GR_R_FLAG)
+					peer->capa.peer.grestart.flags[aid] |=
+					    CAPA_GR_RESTART;
+				peer->capa.peer.grestart.restart = 2;
+			}
 			break;
 		case CAPA_AS4BYTE:
 			if (capa_len != 4) {
 				log_peer_warnx(&peer->conf,
-				    "parse_capabilities: "
-				    "expect len 4, len is %u", capa_len);
-				return (-1);
+				    "Bad AS4BYTE capability length: "
+				    "%u", capa_len);
+				peer->capa.peer.as4byte = 0;
+				break;
 			}
 			memcpy(&remote_as, capa_val, sizeof(remote_as));
 			*as = ntohl(remote_as);
@@ -2232,6 +2508,66 @@ parse_capabilities(struct peer *peer, u_
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
+	/* if no MP capability present default to IPv4 unicast mode */
+	if (!hasmp)
+		p->capa.neg.mp[AID_INET] = 1;
+
+	/*
+	 * graceful restart: only the peer capabilities are of interest here.
+	 * It is necessary to compare the new values with the previous ones
+	 * and act acordingly. AFI/SAFI that are not part in the MP capability
+	 * are treated as not being present.
+	 */
+
+	for (i = 0; i < AID_MAX; i++) {
+		/* disable GR if the AFI/SAFI is not present */
+		if (p->capa.peer.grestart.flags[i] & CAPA_GR_PRESENT &&
+		    p->capa.neg.mp[i] == 0)
+			p->capa.peer.grestart.flags[i] = 0;	/* disable */
+		/* look at current GR state and decide what to do */
+		if (p->capa.neg.grestart.flags[i] & CAPA_GR_RESTARTING) {
+			if (!(p->capa.peer.grestart.flags[i] &
+			    CAPA_GR_FORWARD)) {
+				if (imsg_compose(ibuf_rde, IMSG_SESSION_FLUSH,
+				    p->conf.id, 0, -1, &i, sizeof(i)) == -1)
+					return (-1);
+				log_peer_warnx(&p->conf, "graceful restart of "
+				    "%s, not restarted, flushing", aid2str(i));
+			}
+			p->capa.neg.grestart.flags[i] =
+			    p->capa.peer.grestart.flags[i] | CAPA_GR_RESTARTING;
+		} else
+			p->capa.neg.grestart.flags[i] =
+			    p->capa.peer.grestart.flags[i];
+	}
+	p->capa.neg.grestart.timeout = p->capa.peer.grestart.timeout;
+	p->capa.neg.grestart.restart = p->capa.peer.grestart.restart;
+
+	return (0);
+}
+
 void
 session_dispatch_imsg(struct imsgbuf *ibuf, int idx, u_int *listener_cnt)
 {
@@ -2244,8 +2580,8 @@ session_dispatch_imsg(struct imsgbuf *ib
 	struct kif		*kif;
 	u_char			*data;
 	enum reconf_action	 reconf;
-	int			 n, depend_ok;
-	u_int8_t		 errcode, subcode;
+	int			 n, depend_ok, restricted;
+	u_int8_t		 aid, errcode, subcode;
 
 	if ((n = imsg_read(ibuf)) == -1)
 		fatal("session_dispatch_imsg: imsg_read error");
@@ -2332,15 +2668,42 @@ session_dispatch_imsg(struct imsgbuf *ib
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
@@ -2388,6 +2751,8 @@ session_dispatch_imsg(struct imsgbuf *ib
 			nconf = NULL;
 			pending_reconf = 0;
 			log_info("SE reconfigured");
+			imsg_compose(ibuf_main, IMSG_RECONF_DONE, 0, 0,
+			    -1, NULL, 0);
 			break;
 		case IMSG_IFINFO:
 			if (idx != PFD_PIPE_MAIN)
@@ -2397,9 +2762,7 @@ session_dispatch_imsg(struct imsgbuf *ib
 				fatalx("IFINFO imsg with wrong len");
 			kif = imsg.data;
 			depend_ok = (kif->flags & IFF_UP) &&
-			    (LINK_STATE_IS_UP(kif->link_state) ||
-			    (kif->link_state == LINK_STATE_UNKNOWN &&
-			    kif->media_type != IFT_CARP));
+			    LINK_STATE_IS_UP(kif->link_state);
 
 			for (p = peers; p != NULL; p = p->next)
 				if (!strcmp(p->conf.if_depend, kif->ifname)) {
@@ -2408,7 +2771,8 @@ session_dispatch_imsg(struct imsgbuf *ib
 						bgp_fsm(p, EVNT_START);
 					} else if (!depend_ok && p->depend_ok) {
 						p->depend_ok = depend_ok;
-						bgp_fsm(p, EVNT_STOP);
+						session_stop(p,
+						    ERR_CEASE_OTHER_CHANGE);
 					}
 				}
 			break;
@@ -2456,10 +2820,10 @@ session_dispatch_imsg(struct imsgbuf *ib
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
@@ -2469,7 +2833,6 @@ session_dispatch_imsg(struct imsgbuf *ib
 		case IMSG_CTL_SHOW_RIB_ATTR:
 		case IMSG_CTL_SHOW_RIB_MEM:
 		case IMSG_CTL_SHOW_NETWORK:
-		case IMSG_CTL_SHOW_NETWORK6:
 		case IMSG_CTL_SHOW_NEIGHBOR:
 			if (idx != PFD_PIPE_ROUTE_CTL)
 				fatalx("ctl rib request not from RDE");
@@ -2531,6 +2894,40 @@ session_dispatch_imsg(struct imsgbuf *ib
 				break;
 			}
 			break;
+		case IMSG_SESSION_RESTARTED:
+			if (idx != PFD_PIPE_ROUTE)
+				fatalx("update request not from RDE");
+			if (imsg.hdr.len < IMSG_HEADER_SIZE + sizeof(aid)) {
+				log_warnx("RDE sent invalid restart msg");
+				break;
+			}
+			if ((p = getpeerbyid(imsg.hdr.peerid)) == NULL) {
+				log_warnx("no such peer: id=%u",
+				    imsg.hdr.peerid);
+				break;
+			}
+			memcpy(&aid, imsg.data, sizeof(aid));
+			if (aid >= AID_MAX)
+				fatalx("IMSG_SESSION_RESTARTED: bad AID");
+			if (p->capa.neg.grestart.flags[aid] &
+			    CAPA_GR_RESTARTING &&
+			    p->capa.neg.grestart.flags[aid] &
+			    CAPA_GR_FORWARD) {
+				log_peer_warnx(&p->conf,
+				    "graceful restart of %s finished",
+				    aid2str(aid));
+				p->capa.neg.grestart.flags[aid] &=
+				    ~CAPA_GR_RESTARTING;
+				timer_stop(p, Timer_RestartTimeout);
+
+				/* signal back to RDE to cleanup stale routes */
+				if (imsg_compose(ibuf_rde,
+				    IMSG_SESSION_RESTARTED, imsg.hdr.peerid, 0,
+				    -1, &aid, sizeof(aid)) == -1)
+					fatal("imsg_compose: "
+					    "IMSG_SESSION_RESTARTED");
+			}
+			break;
 		default:
 			break;
 		}
@@ -2612,29 +3009,23 @@ getpeerbydesc(const char *descr)
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
@@ -2653,21 +3044,19 @@ getpeerbyip(struct sockaddr *ip)
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
@@ -2680,40 +3069,24 @@ getpeerbyip(struct sockaddr *ip)
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
 
@@ -2733,6 +3106,7 @@ getpeerbyid(u_int32_t peerid)
 void
 session_down(struct peer *peer)
 {
+	bzero(&peer->capa.neg, sizeof(peer->capa.neg));
 	peer->stats.last_updown = time(NULL);
 	if (imsg_compose(ibuf_rde, IMSG_SESSION_DOWN, peer->conf.id, 0, -1,
 	    NULL, 0) == -1)
@@ -2744,39 +3118,17 @@ session_up(struct peer *p)
 {
 	struct session_up	 sup;
 
-	if (imsg_compose(ibuf_rde, IMSG_SESSION_ADD, p->conf.id, 0, -1,
-	    &p->conf, sizeof(p->conf)) == -1)
-		fatalx("imsg_compose error");
+	if (!session_graceful_is_restarting(p))
+		if (imsg_compose(ibuf_rde, IMSG_SESSION_ADD, p->conf.id, 0, -1,
+		    &p->conf, sizeof(p->conf)) == -1)
+			fatalx("imsg_compose error");
 
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
@@ -2784,9 +3136,10 @@ session_up(struct peer *p)
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
@@ -2795,34 +3148,6 @@ imsg_compose_rde(int type, pid_t pid, vo
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
@@ -2837,3 +3162,19 @@ session_demote(struct peer *p, int level
 
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
