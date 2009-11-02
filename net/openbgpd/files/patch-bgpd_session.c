Index: bgpd/session.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/session.c,v
retrieving revision 1.1.1.1
retrieving revision 1.5
diff -u -p -r1.1.1.1 -r1.5
--- bgpd/session.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/session.c	22 Oct 2009 15:10:02 -0000	1.5
@@ -1,4 +1,4 @@
-/*	$OpenBSD: session.c,v 1.282 2008/06/26 00:01:51 claudio Exp $ */
+/*	$OpenBSD: session.c,v 1.294 2009/07/24 13:09:29 claudio Exp $ */
 
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
@@ -65,8 +69,7 @@ void	session_accept(int);
 int	session_connect(struct peer *);
 void	session_tcp_established(struct peer *);
 void	session_capa_ann_none(struct peer *);
-int	session_capa_add(struct peer *, struct buf *, u_int8_t, u_int8_t,
-	    u_int8_t *);
+int	session_capa_add(struct buf *, u_int8_t, u_int8_t);
 int	session_capa_add_mp(struct buf *, u_int16_t, u_int8_t);
 struct bgp_msg	*session_newmsg(enum msg_type, u_int16_t);
 int	session_sendmsg(struct bgp_msg *, struct peer *);
@@ -177,8 +180,8 @@ setup_listeners(u_int *la_cnt)
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
@@ -195,6 +198,7 @@ session_main(struct bgpd_config *config,
 	struct pollfd		*pfd = NULL;
 	struct ctl_conn		*ctl_conn;
 	struct listen_addr	*la;
+	struct rde_rib		*rr;
 	void			*newp;
 	short			 events;
 
@@ -283,6 +287,11 @@ session_main(struct bgpd_config *config,
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
@@ -302,7 +311,7 @@ session_main(struct bgpd_config *config,
 
 				/* reinit due? */
 				if (p->conf.reconf_action == RECONF_REINIT) {
-					bgp_fsm(p, EVNT_STOP);
+					session_stop(p, ERR_CEASE_ADMIN_RESET);
 					timer_set(p, Timer_IdleHold, 0);
 				}
 
@@ -311,7 +320,7 @@ session_main(struct bgpd_config *config,
 					if (p->demoted)
 						session_demote(p, -1);
 					p->conf.demote_group[0] = 0;
-					bgp_fsm(p, EVNT_STOP);
+					session_stop(p, ERR_CEASE_PEER_UNCONF);
 					log_peer_warnx(&p->conf, "removed");
 					if (last != NULL)
 						last->next = next;
@@ -341,7 +350,7 @@ session_main(struct bgpd_config *config,
 
 		mrt_cnt = 0;
 		LIST_FOREACH(m, &mrthead, entry)
-			if (m->queued)
+			if (m->wbuf.queued)
 				mrt_cnt++;
 
 		if (mrt_cnt > mrt_l_elms) {
@@ -438,6 +447,12 @@ session_main(struct bgpd_config *config,
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
@@ -446,17 +461,6 @@ session_main(struct bgpd_config *config,
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
@@ -474,8 +478,8 @@ session_main(struct bgpd_config *config,
 		idx_peers = i;
 
 		LIST_FOREACH(m, &mrthead, entry)
-			if (m->queued) {
-				pfd[i].fd = m->fd;
+			if (m->wbuf.queued) {
+				pfd[i].fd = m->wbuf.fd;
 				pfd[i].events = POLLOUT;
 				mrt_l[i - idx_peers] = m;
 				i++;
@@ -556,7 +560,7 @@ session_main(struct bgpd_config *config,
 
 	while ((p = peers) != NULL) {
 		peers = p->next;
-		bgp_fsm(p, EVNT_STOP);
+		session_stop(p, ERR_CEASE_ADMIN_DOWN);
 		pfkey_remove(p);
 		free(p);
 	}
@@ -594,6 +598,8 @@ init_conf(struct bgpd_config *c)
 {
 	if (!c->holdtime)
 		c->holdtime = INTERVAL_HOLD;
+	if (!c->connectretry)
+		c->connectretry = INTERVAL_CONNECTRETRY;
 }
 
 void
@@ -668,7 +674,7 @@ bgp_fsm(struct peer *peer, enum session_
 			} else {
 				change_state(peer, STATE_CONNECT, event);
 				timer_set(peer, Timer_ConnectRetry,
-				    INTERVAL_CONNECTRETRY);
+				    conf->connectretry);
 				session_connect(peer);
 			}
 			peer->passive = 0;
@@ -693,13 +699,13 @@ bgp_fsm(struct peer *peer, enum session_
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
@@ -722,7 +728,7 @@ bgp_fsm(struct peer *peer, enum session_
 			break;
 		case EVNT_CON_OPENFAIL:
 			timer_set(peer, Timer_ConnectRetry,
-			    INTERVAL_CONNECTRETRY);
+			    conf->connectretry);
 			session_close_connection(peer);
 			change_state(peer, STATE_ACTIVE, event);
 			break;
@@ -743,13 +749,12 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
 			session_close_connection(peer);
 			timer_set(peer, Timer_ConnectRetry,
-			    INTERVAL_CONNECTRETRY);
+			    conf->connectretry);
 			change_state(peer, STATE_ACTIVE, event);
 			break;
 		case EVNT_CON_FATAL:
@@ -788,7 +793,6 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
@@ -823,7 +827,6 @@ bgp_fsm(struct peer *peer, enum session_
 			/* ignore */
 			break;
 		case EVNT_STOP:
-			session_notification(peer, ERR_CEASE, 0, NULL, 0);
 			change_state(peer, STATE_IDLE, event);
 			break;
 		case EVNT_CON_CLOSED:
@@ -953,6 +956,9 @@ change_state(struct peer *peer, enum ses
 		break;
 	case STATE_ESTABLISHED:
 		timer_set(peer, Timer_IdleHoldReset, peer->IdleHoldTime);
+		if (peer->demoted)
+			timer_set(peer, Timer_CarpUndemote,
+			    INTERVAL_HOLD_DEMOTED);
 		session_up(peer);
 		break;
 	default:		/* something seriously fucked */
@@ -961,13 +967,12 @@ change_state(struct peer *peer, enum ses
 
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
@@ -1247,21 +1252,12 @@ session_capa_ann_none(struct peer *peer)
 }
 
 int
-session_capa_add(struct peer *p, struct buf *opb, u_int8_t capa_code,
-    u_int8_t capa_len, u_int8_t *optparamlen)
+session_capa_add(struct buf *opb, u_int8_t capa_code, u_int8_t capa_len)
 {
-	u_int8_t	op_type, op_len, tot_len, errs = 0;
+	int errs = 0;
 
-	op_type = OPT_PARAM_CAPABILITIES;
-	op_len = sizeof(capa_code) + sizeof(capa_len) + capa_len;
-	tot_len = sizeof(op_type) + sizeof(op_len) + op_len;
-	if (buf_grow(opb, tot_len) == NULL)
-		return (1);
-	errs += buf_add(opb, &op_type, sizeof(op_type));
-	errs += buf_add(opb, &op_len, sizeof(op_len));
 	errs += buf_add(opb, &capa_code, sizeof(capa_code));
 	errs += buf_add(opb, &capa_len, sizeof(capa_len));
-	*optparamlen += tot_len;
 	return (errs);
 }
 
@@ -1317,22 +1313,16 @@ session_sendmsg(struct bgp_msg *msg, str
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
@@ -1344,36 +1334,37 @@ session_open(struct peer *p)
 	struct buf		*opb;
 	struct msg_open		 msg;
 	u_int16_t		 len;
-	u_int8_t		 optparamlen = 0;
+	u_int8_t		 op_type, optparamlen = 0;
 	u_int			 errs = 0;
 
 
-	if ((opb = buf_open(0)) == NULL) {
+	if ((opb = buf_dynamic(0, UCHAR_MAX - sizeof(op_type) -
+	    sizeof(optparamlen))) == NULL) {
 		bgp_fsm(p, EVNT_CON_FATAL);
 		return;
 	}
 
 	/* multiprotocol extensions, RFC 4760 */
 	if (p->capa.ann.mp_v4) {	/* 4 bytes data */
-		errs += session_capa_add(p, opb, CAPA_MP, 4, &optparamlen);
+		errs += session_capa_add(opb, CAPA_MP, 4);
 		errs += session_capa_add_mp(opb, AFI_IPv4, p->capa.ann.mp_v4);
 	}
 	if (p->capa.ann.mp_v6) {	/* 4 bytes data */
-		errs += session_capa_add(p, opb, CAPA_MP, 4, &optparamlen);
+		errs += session_capa_add(opb, CAPA_MP, 4);
 		errs += session_capa_add_mp(opb, AFI_IPv6, p->capa.ann.mp_v6);
 	}
 
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
+		c[1] = 0;
+		errs += session_capa_add(opb, CAPA_RESTART, 2);
 		errs += buf_add(opb, &c, 2);
 	}
 
@@ -1382,10 +1373,14 @@ session_open(struct peer *p)
 		u_int32_t	nas;
 
 		nas = htonl(conf->as);
-		errs += session_capa_add(p, opb, CAPA_AS4BYTE, 4, &optparamlen);
-		errs += buf_add(opb, &nas, 4);
+		errs += session_capa_add(opb, CAPA_AS4BYTE, sizeof(nas));
+		errs += buf_add(opb, &nas, sizeof(nas));
 	}
 
+	if (buf_size(opb))
+		optparamlen = buf_size(opb) + sizeof(op_type) +
+		    sizeof(optparamlen);
+
 	len = MSGSIZE_OPEN_MIN + optparamlen;
 	if (errs || (buf = session_newmsg(OPEN, len)) == NULL) {
 		buf_free(opb);
@@ -1394,10 +1389,7 @@ session_open(struct peer *p)
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
@@ -1411,8 +1403,13 @@ session_open(struct peer *p)
 	errs += buf_add(buf->buf, &msg.bgpid, sizeof(msg.bgpid));
 	errs += buf_add(buf->buf, &msg.optparamlen, sizeof(msg.optparamlen));
 
-	if (optparamlen)
-		errs += buf_add(buf->buf, opb->buf, optparamlen);
+	if (optparamlen) {
+		op_type = OPT_PARAM_CAPABILITIES;
+		optparamlen = buf_size(opb);
+		errs += buf_add(buf->buf, &op_type, sizeof(op_type));
+		errs += buf_add(buf->buf, &optparamlen, sizeof(optparamlen));
+		errs += buf_add(buf->buf, opb->buf, buf_size(opb));
+	}
 
 	buf_free(opb);
 
@@ -1487,7 +1484,6 @@ session_notification(struct peer *p, u_i
 {
 	struct bgp_msg		*buf;
 	u_int			 errs = 0;
-	u_int8_t		 null8 = 0;
 
 	if (p->stats.last_sent_errcode)	/* some notification already sent */
 		return;
@@ -1499,10 +1495,7 @@ session_notification(struct peer *p, u_i
 	}
 
 	errs += buf_add(buf->buf, &errcode, sizeof(errcode));
-	if (errcode == ERR_CEASE)
-		errs += buf_add(buf->buf, &null8, sizeof(null8));
-	else
-		errs += buf_add(buf->buf, &subcode, sizeof(subcode));
+	errs += buf_add(buf->buf, &subcode, sizeof(subcode));
 
 	if (datalen > 0)
 		errs += buf_add(buf->buf, data, datalen);
@@ -1809,13 +1802,13 @@ parse_header(struct peer *peer, u_char *
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
@@ -1859,12 +1852,6 @@ parse_open(struct peer *peer)
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
 
@@ -1972,6 +1959,15 @@ parse_open(struct peer *peer)
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
@@ -2193,22 +2189,20 @@ parse_capabilities(struct peer *peer, u_
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
@@ -2318,7 +2312,7 @@ session_dispatch_imsg(struct imsgbuf *ib
 					fatalx("king bula sez: "
 					    "expected REINIT");
 
-				if ((nla->fd = imsg_get_fd(ibuf)) == -1)
+				if ((nla->fd = imsg.fd) == -1)
 					log_warnx("expected to receive fd for "
 					    "%s but didn't receive any",
 					    log_sockaddr((struct sockaddr *)
@@ -2416,7 +2410,8 @@ session_dispatch_imsg(struct imsgbuf *ib
 						bgp_fsm(p, EVNT_START);
 					} else if (!depend_ok && p->depend_ok) {
 						p->depend_ok = depend_ok;
-						bgp_fsm(p, EVNT_STOP);
+						session_stop(p,
+						    ERR_CEASE_OTHER_CHANGE);
 					}
 				}
 			break;
@@ -2429,7 +2424,7 @@ session_dispatch_imsg(struct imsgbuf *ib
 			}
 
 			memcpy(&xmrt, imsg.data, sizeof(struct mrt));
-			if ((xmrt.fd = imsg_get_fd(ibuf)) == -1)
+			if ((xmrt.wbuf.fd = imsg.fd) == -1)
 				log_warnx("expected to receive fd for mrt dump "
 				    "but didn't receive any");
 
@@ -2440,12 +2435,12 @@ session_dispatch_imsg(struct imsgbuf *ib
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
@@ -2667,7 +2662,7 @@ getpeerbyip(struct sockaddr *ip)
 			newpeer->conf.remote_masklen = 32;
 		}
 		if (newpeer->conf.remote_addr.af == AF_INET6) {
-			memcpy(&p->conf.remote_addr.v6,
+			memcpy(&newpeer->conf.remote_addr.v6,
 			    &((struct sockaddr_in6 *)ip)->sin6_addr,
 			    sizeof(newpeer->conf.remote_addr.v6));
 			newpeer->conf.remote_masklen = 128;
@@ -2675,7 +2670,7 @@ getpeerbyip(struct sockaddr *ip)
 		newpeer->conf.template = 0;
 		newpeer->conf.cloned = 1;
 		newpeer->state = newpeer->prev_state = STATE_NONE;
-		newpeer->conf.reconf_action = RECONF_REINIT;
+		newpeer->conf.reconf_action = RECONF_KEEP;
 		newpeer->rbuf = NULL;
 		init_peer(newpeer);
 		bgp_fsm(newpeer, EVNT_START);
@@ -2845,3 +2840,19 @@ session_demote(struct peer *p, int level
 
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
