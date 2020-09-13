--- src/ntp.c.orig	2017-06-19 13:23:10 UTC
+++ src/ntp.c
@@ -1,4 +1,4 @@
-/*	$OpenBSD: ntp.c,v 1.146 2017/05/30 23:30:48 benno Exp $ */
+/*	$OpenBSD: ntp.c,v 1.167 2020/09/11 07:09:41 otto Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -42,7 +42,7 @@
 
 volatile sig_atomic_t	 ntp_quit = 0;
 struct imsgbuf		*ibuf_main;
-struct imsgbuf		*ibuf_dns;
+static struct imsgbuf	*ibuf_dns;
 struct ntpd_conf	*conf;
 struct ctl_conns	 ctl_conns;
 u_int			 peer_cnt;
@@ -87,6 +87,7 @@ ntp_main(struct ntpd_conf *nconf, struct passwd *pw, i
 	struct stat		 stb;
 	struct ctl_conn		*cc;
 	time_t			 nextaction, last_sensor_scan = 0, now;
+	time_t			 last_action = 0, interval;
 	void			*newp;
 
 	if (socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, PF_UNSPEC,
@@ -395,11 +396,28 @@ ntp_main(struct ntpd_conf *nconf, struct passwd *pw, i
 
 		for (; nfds > 0 && j < idx_clients; j++) {
 			if (pfd[j].revents & (POLLIN|POLLERR)) {
+				struct ntp_peer *pp = idx2peer[j - idx_peers];
+
 				nfds--;
-				if (client_dispatch(idx2peer[j - idx_peers],
-				    conf->settime) == -1) {
-					log_warn("pipe write error (settime)");
-					ntp_quit = 1;
+				switch (client_dispatch(pp, conf->settime)) {
+				case -1:
+					log_debug("no reply from %s "
+					    "received", log_sockaddr(
+					    (struct sockaddr *) &pp->addr->ss));
+					if (pp->trustlevel >=
+					    TRUSTLEVEL_BADPEER &&
+					    (pp->trustlevel /= 2) <
+					    TRUSTLEVEL_BADPEER)
+						log_info("peer %s now invalid",
+						    log_sockaddr(
+						    (struct sockaddr *)
+						    &pp->addr->ss));
+					break;
+				case 0: /* invalid replies are ignored */
+					break;
+				case 1:
+					last_action = now;
+					break;
 				}
 			}
 		}
@@ -411,9 +429,24 @@ ntp_main(struct ntpd_conf *nconf, struct passwd *pw, i
 		for (s = TAILQ_FIRST(&conf->ntp_sensors); s != NULL;
 		    s = next_s) {
 			next_s = TAILQ_NEXT(s, entry);
-			if (s->next <= getmonotime())
+			if (s->next <= now) {
+				last_action = now;
 				sensor_query(s);
+			}
 		}
+
+		/*
+		 * Compute maximum of scale_interval(INTERVAL_QUERY_NORMAL),
+		 * if we did not process a time message for three times that
+		 * interval, stop advertising we're synced.
+		 */
+		interval = INTERVAL_QUERY_NORMAL * conf->scale;
+		interval += SCALE_INTERVAL(interval) - 1;
+		if (conf->status.synced && last_action + 3 * interval < now) {
+			log_info("clock is now unsynced due to lack of replies");
+			conf->status.synced = 0;
+			conf->scale = 1;
+		}
 	}
 
 	msgbuf_write(&ibuf_main->w);
@@ -760,7 +793,7 @@ scale_interval(time_t requested)
 	time_t interval, r;
 
 	interval = requested * conf->scale;
-	r = arc4random_uniform(MAXIMUM(5, interval / 10));
+	r = arc4random_uniform(SCALE_INTERVAL(interval));
 	return (interval + r);
 }
 
