Index: bgpd/session.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/session.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpd/session.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/session.c	9 Jul 2009 17:22:14 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: session.c,v 1.282 2008/06/26 00:01:51 claudio Exp $ */
+/*	$OpenBSD: session.c,v 1.293 2009/06/07 05:56:24 eric Exp $ */
 
 /*
  * Copyright (c) 2003, 2004, 2005 Henning Brauer <henning@openbsd.org>
@@ -52,6 +52,10 @@
 #define PFD_SOCK_RCTL		4
 #define PFD_LISTENERS_START	5
 
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)  ((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */ 
+
 void	session_sighdlr(int);
 int	setup_listeners(u_int *);
 void	init_conf(struct bgpd_config *);
@@ -177,8 +181,8 @@ setup_listeners(u_int *la_cnt)
 pid_t
 session_main(struct bgpd_config *config, struct peer *cpeers,
     struct network_head *net_l, struct filter_head *rules,
-    struct mrt_head *m_l, int pipe_m2s[2], int pipe_s2r[2], int pipe_m2r[2],
-    int pipe_s2rctl[2])
+    struct mrt_head *m_l, struct rib_names *rib_l, int pipe_m2s[2],
+    int pipe_s2r[2], int pipe_m2r[2], int pipe_s2rctl[2])
 {
 	int			 nfds, timeout;
 	unsigned int		 i, j, idx_peers, idx_listeners, idx_mrts;
@@ -195,6 +199,7 @@ session_main(struct bgpd_config *config,
 	struct pollfd		*pfd = NULL;
 	struct ctl_conn		*ctl_conn;
 	struct listen_addr	*la;
+	struct rde_rib		*rr;
 	void			*newp;
 	short			 events;
 
@@ -283,6 +288,11 @@ session_main(struct bgpd_config *config,
 		LIST_REMOVE(m, entry);
 		free(m);
 	}
+	/* rib names not used in the SE */
+	while ((rr = SIMPLEQ_FIRST(&ribnames))) {
+		SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
+		free(rr);
+	}
 
 	while (session_quit == 0) {
 		/* check for peers to be initialized or deleted */
@@ -341,7 +351,7 @@ session_main(struct bgpd_config *config,
 
 		mrt_cnt = 0;
 		LIST_FOREACH(m, &mrthead, entry)
-			if (m->queued)
+			if (m->wbuf.queued)
 				mrt_cnt++;
 
 		if (mrt_cnt > mrt_l_elms) {
@@ -438,6 +448,12 @@ session_main(struct bgpd_config *config,
 						    Timer_IdleHoldReset,
 						    p->IdleHoldTime);
 					break;
+				case Timer_CarpUndemote:
+					timer_stop(p, Timer_CarpUndemote);
+					if (p->demoted &&
+					    p->state == STATE_ESTABLISHED)
+						session_demote(p, -1);
+					break;
 				default:
 					fatalx("King Bula lost in time");
 				}
@@ -446,17 +462,6 @@ session_main(struct bgpd_config *config,
 			    nextaction < timeout)
 				timeout = nextaction;
 
-			/* XXX carp demotion */
-			if (p->demoted && p->state == STATE_ESTABLISHED) {
-				if (time(NULL) - p->stats.last_updown >=
-				    INTERVAL_HOLD_DEMOTED)
-					session_demote(p, -1);
-				if (p->stats.last_updown + INTERVAL_HOLD_DEMOTED
-				    - time(NULL) < timeout)
-					timeout = p->stats.last_updown +
-					    INTERVAL_HOLD_DEMOTED - time(NULL);
-			}
-
 			/* are we waiting for a write? */
 			events = POLLIN;
 			if (p->wbuf.queued > 0 || p->state == STATE_CONNECT)
@@ -474,8 +479,8 @@ session_main(struct bgpd_config *config,
 		idx_peers = i;
 
 		LIST_FOREACH(m, &mrthead, entry)
-			if (m->queued) {
-				pfd[i].fd = m->fd;
+			if (m->wbuf.queued) {
+				pfd[i].fd = m->wbuf.fd;
 				pfd[i].events = POLLOUT;
 				mrt_l[i - idx_peers] = m;
 				i++;
@@ -594,6 +599,8 @@ init_conf(struct bgpd_config *c)
 {
 	if (!c->holdtime)
 		c->holdtime = INTERVAL_HOLD;
+	if (!c->connectretry)
+		c->connectretry = INTERVAL_CONNECTRETRY;
 }
 
 void
@@ -668,7 +675,7 @@ bgp_fsm(struct peer *peer, enum session_
 			} else {
 				change_state(peer, STATE_CONNECT, event);
 				timer_set(peer, Timer_ConnectRetry,
-				    INTERVAL_CONNECTRETRY);
+				    conf->connectretry);
 				session_connect(peer);
 			}
 			peer->passive = 0;
@@ -693,13 +700,13 @@ bgp_fsm(struct peer *peer, enum session_
 			break;
 		case EVNT_CON_OPENFAIL:
 			timer_set(peer, Timer_ConnectRetry,
-			    INTERVAL_CONNECTRETRY);
+			    conf->connectretry);
 			session_close_connection(peer);
 			change_state(peer, STATE_ACTIVE, event);
 			break;
 		case EVNT_TIMER_CONNRETRY:
 			timer_set(peer, Timer_ConnectRetry,
-			    INTERVAL_CONNECTRETRY);
+			    conf->connectretry);
 			session_connect(peer);
 			break;
 		default:
@@ -722,7 +729,7 @@ bgp_fsm(struct peer *peer, enum session_
 			break;
 		case EVNT_CON_OPENFAIL:
 			timer_set(peer, Timer_ConnectRetry,
-			    INTERVAL_CONNECTRETRY);
+			    conf->connectretry);
 			session_close_connection(peer);
 			change_state(peer, STATE_ACTIVE, event);
 			break;
@@ -749,7 +756,7 @@ bgp_fsm(struct peer *peer, enum session_
 		case EVNT_CON_CLOSED:
 			session_close_connection(peer);
 			timer_set(peer, Timer_ConnectRetry,
-			    INTERVAL_CONNECTRETRY);
+			    conf->connectretry);
 			change_state(peer, STATE_ACTIVE, event);
 			break;
 		case EVNT_CON_FATAL:
@@ -953,6 +960,9 @@ change_state(struct peer *peer, enum ses
 		break;
 	case STATE_ESTABLISHED:
 		timer_set(peer, Timer_IdleHoldReset, peer->IdleHoldTime);
+		if (peer->demoted)
+			timer_set(peer, Timer_CarpUndemote,
+			    INTERVAL_HOLD_DEMOTED);
 		session_up(peer);
 		break;
 	default:		/* something seriously fucked */
@@ -961,13 +971,12 @@ change_state(struct peer *peer, enum ses
 
 	log_statechange(peer, state, event);
 	LIST_FOREACH(mrt, &mrthead, entry) {
-		if (mrt->type != MRT_ALL_IN && mrt->type != MRT_ALL_OUT)
+		if (!(mrt->type == MRT_ALL_IN || mrt->type == MRT_ALL_OUT))
 			continue;
 		if ((mrt->peer_id == 0 && mrt->group_id == 0) ||
-		    mrt->peer_id == peer->conf.id ||
-		    mrt->group_id == peer->conf.groupid)
-			mrt_dump_state(mrt, peer->state, state,
-			    peer, conf);
+		    mrt->peer_id == peer->conf.id || (mrt->group_id != 0 &&
+		    mrt->group_id == peer->conf.groupid))
+			mrt_dump_state(mrt, peer->state, state, peer);
 	}
 	peer->prev_state = peer->state;
 	peer->state = state;
@@ -1255,8 +1264,6 @@ session_capa_add(struct peer *p, struct 
 	op_type = OPT_PARAM_CAPABILITIES;
 	op_len = sizeof(capa_code) + sizeof(capa_len) + capa_len;
 	tot_len = sizeof(op_type) + sizeof(op_len) + op_len;
-	if (buf_grow(opb, tot_len) == NULL)
-		return (1);
 	errs += buf_add(opb, &op_type, sizeof(op_type));
 	errs += buf_add(opb, &op_len, sizeof(op_len));
 	errs += buf_add(opb, &capa_code, sizeof(capa_code));
@@ -1317,22 +1324,16 @@ session_sendmsg(struct bgp_msg *msg, str
 	struct mrt		*mrt;
 
 	LIST_FOREACH(mrt, &mrthead, entry) {
-		if (mrt->type != MRT_ALL_OUT &&
-		    msg->type == UPDATE && mrt->type != MRT_UPDATE_OUT)
+		if (!(mrt->type == MRT_ALL_OUT || (msg->type == UPDATE &&
+		    mrt->type == MRT_UPDATE_OUT)))
 			continue;
 		if ((mrt->peer_id == 0 && mrt->group_id == 0) ||
-		    mrt->peer_id == p->conf.id ||
-		    mrt->group_id == p->conf.groupid)
-			mrt_dump_bgp_msg(mrt, msg->buf->buf, msg->len, p, conf);
-	}
-
-	if (buf_close(&p->wbuf, msg->buf) == -1) {
-		log_peer_warn(&p->conf, "session_sendmsg buf_close");
-		buf_free(msg->buf);
-		free(msg);
-		return (-1);
+		    mrt->peer_id == p->conf.id || (mrt->group_id == 0 &&
+		    mrt->group_id == p->conf.groupid))
+			mrt_dump_bgp_msg(mrt, msg->buf->buf, msg->len, p);
 	}
 
+	buf_close(&p->wbuf, msg->buf);
 	free(msg);
 	return (0);
 }
@@ -1348,7 +1349,7 @@ session_open(struct peer *p)
 	u_int			 errs = 0;
 
 
-	if ((opb = buf_open(0)) == NULL) {
+	if ((opb = buf_dynamic(0, MAX_PKTSIZE - MSGSIZE_OPEN_MIN)) == NULL) {
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
 	}
@@ -1394,10 +1395,7 @@ session_open(struct peer *p)
 	}
 
 	msg.version = 4;
-	if (conf->as > USHRT_MAX)
-		msg.myas = htons(conf->short_as);
-	else
-		msg.myas = htons(conf->as);
+	msg.myas = htons(conf->short_as);
 	if (p->conf.holdtime)
 		msg.holdtime = htons(p->conf.holdtime);
 	else
@@ -1809,13 +1807,13 @@ parse_header(struct peer *peer, u_char *
 		return (-1);
 	}
 	LIST_FOREACH(mrt, &mrthead, entry) {
-		if (mrt->type != MRT_ALL_IN && (mrt->type != MRT_UPDATE_IN ||
-		    *type != UPDATE))
+		if (!(mrt->type == MRT_ALL_IN || (*type == UPDATE &&
+		    mrt->type == MRT_UPDATE_IN)))
 			continue;
 		if ((mrt->peer_id == 0 && mrt->group_id == 0) ||
-		    mrt->peer_id == peer->conf.id ||
-		    mrt->group_id == peer->conf.groupid)
-			mrt_dump_bgp_msg(mrt, data, *len, peer, conf);
+		    mrt->peer_id == peer->conf.id || (mrt->group_id != 0 &&
+		    mrt->group_id == peer->conf.groupid))
+			mrt_dump_bgp_msg(mrt, data, *len, peer);
 	}
 	return (0);
 }
@@ -2193,22 +2191,20 @@ parse_capabilities(struct peer *peer, u_
 			memcpy(&mp_safi, capa_val + 3, sizeof(mp_safi));
 			switch (mp_afi) {
 			case AFI_IPv4:
-				if (mp_safi < 1 || mp_safi > 3) {
+				if (mp_safi < 1 || mp_safi > 3)
 					log_peer_warnx(&peer->conf,
 					    "parse_capabilities: AFI IPv4, "
-					    "mp_safi %u illegal", mp_safi);
-					return (-1);
-				}
-				peer->capa.peer.mp_v4 = mp_safi;
+					    "mp_safi %u unknown", mp_safi);
+				else
+					peer->capa.peer.mp_v4 = mp_safi;
 				break;
 			case AFI_IPv6:
-				if (mp_safi < 1 || mp_safi > 3) {
+				if (mp_safi < 1 || mp_safi > 3)
 					log_peer_warnx(&peer->conf,
 					    "parse_capabilities: AFI IPv6, "
-					    "mp_safi %u illegal", mp_safi);
-					return (-1);
-				}
-				peer->capa.peer.mp_v6 = mp_safi;
+					    "mp_safi %u unknown", mp_safi);
+				else
+					peer->capa.peer.mp_v6 = mp_safi;
 				break;
 			default:			/* ignore */
 				break;
@@ -2318,7 +2314,7 @@ session_dispatch_imsg(struct imsgbuf *ib
 					fatalx("king bula sez: "
 					    "expected REINIT");
 
-				if ((nla->fd = imsg_get_fd(ibuf)) == -1)
+				if ((nla->fd = imsg.fd) == -1)
 					log_warnx("expected to receive fd for "
 					    "%s but didn't receive any",
 					    log_sockaddr((struct sockaddr *)
@@ -2429,7 +2425,7 @@ session_dispatch_imsg(struct imsgbuf *ib
 			}
 
 			memcpy(&xmrt, imsg.data, sizeof(struct mrt));
-			if ((xmrt.fd = imsg_get_fd(ibuf)) == -1)
+			if ((xmrt.wbuf.fd = imsg.fd) == -1)
 				log_warnx("expected to receive fd for mrt dump "
 				    "but didn't receive any");
 
@@ -2440,12 +2436,12 @@ session_dispatch_imsg(struct imsgbuf *ib
 				if (mrt == NULL)
 					fatal("session_dispatch_imsg");
 				memcpy(mrt, &xmrt, sizeof(struct mrt));
-				TAILQ_INIT(&mrt->bufs);
+				TAILQ_INIT(&mrt->wbuf.bufs);
 				LIST_INSERT_HEAD(&mrthead, mrt, entry);
 			} else {
 				/* old dump reopened */
-				close(mrt->fd);
-				mrt->fd = xmrt.fd;
+				close(mrt->wbuf.fd);
+				mrt->wbuf.fd = xmrt.wbuf.fd;
 			}
 			break;
 		case IMSG_MRT_CLOSE:
