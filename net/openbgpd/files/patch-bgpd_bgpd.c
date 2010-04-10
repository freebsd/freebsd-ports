Index: bgpd/bgpd.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/bgpd.c,v
retrieving revision 1.1.1.7
retrieving revision 1.1.1.9
diff -u -p -r1.1.1.7 -r1.1.1.9
--- bgpd/bgpd.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/bgpd.c	10 Apr 2010 12:13:04 -0000	1.1.1.9
@@ -1,4 +1,4 @@
-/*	$OpenBSD: bgpd.c,v 1.148 2009/06/07 00:30:23 claudio Exp $ */
+/*	$OpenBSD: bgpd.c,v 1.156 2010/03/29 09:09:25 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -42,7 +42,7 @@ int		main(int, char *[]);
 int		check_child(pid_t, const char *);
 int		send_filterset(struct imsgbuf *, struct filter_set_head *);
 int		reconfigure(char *, struct bgpd_config *, struct mrt_head *,
-		    struct peer **, struct filter_head *);
+		    struct peer **);
 int		dispatch_imsg(struct imsgbuf *, int);
 
 int			 rfd = -1;
@@ -101,15 +101,10 @@ int
 main(int argc, char *argv[])
 {
 	struct bgpd_config	 conf;
-	struct peer		*peer_l, *p;
 	struct mrt_head		 mrt_l;
-	struct network_head	 net_l;
-	struct filter_head	*rules_l;
-	struct network		*net;
-	struct filter_rule	*r;
+	struct peer		*peer_l, *p;
 	struct mrt		*m;
 	struct listen_addr	*la;
-	struct rde_rib		*rr;
 	struct pollfd		 pfd[POLL_MAX];
 	pid_t			 io_pid = 0, rde_pid = 0, pid;
 	char			*conffile;
@@ -125,13 +120,8 @@ main(int argc, char *argv[])
 
 	log_init(1);		/* log to stderr until daemonized */
 
-	if ((rules_l = calloc(1, sizeof(struct filter_head))) == NULL)
-		err(1, NULL);
-
 	bzero(&conf, sizeof(conf));
 	LIST_INIT(&mrt_l);
-	TAILQ_INIT(&net_l);
-	TAILQ_INIT(rules_l);
 	peer_l = NULL;
 	conf.csock = SOCKET_NAME;
 
@@ -158,6 +148,7 @@ main(int argc, char *argv[])
 			if (conf.opts & BGPD_OPT_VERBOSE)
 				conf.opts |= BGPD_OPT_VERBOSE2;
 			conf.opts |= BGPD_OPT_VERBOSE;
+			log_verbose(1);
 			break;
 		case 'r':
 			conf.rcsock = optarg;
@@ -176,14 +167,16 @@ main(int argc, char *argv[])
 	if (argc > 0)
 		usage();
 
-	if (parse_config(conffile, &conf, &mrt_l, &peer_l, &net_l, rules_l)) {
-		free(rules_l);
-		exit(1);
-	}
-
 	if (conf.opts & BGPD_OPT_NOACTION) {
+		struct network_head	net_l;
+		struct filter_head	rules_l;
+
+		if (parse_config(conffile, &conf, &mrt_l, &peer_l, &net_l,
+		    &rules_l))
+			exit(1);
+
 		if (conf.opts & BGPD_OPT_VERBOSE)
-			print_config(&conf, &ribnames, &net_l, peer_l, rules_l,
+			print_config(&conf, &ribnames, &net_l, peer_l, &rules_l,
 			    &mrt_l);
 		else
 			fprintf(stderr, "configuration OK\n");
@@ -225,13 +218,10 @@ main(int argc, char *argv[])
 	session_socket_blockmode(pipe_s2r_c[0], BM_NONBLOCK);
 	session_socket_blockmode(pipe_s2r_c[1], BM_NONBLOCK);
 
-	prepare_listeners(&conf);
-
 	/* fork children */
-	rde_pid = rde_main(&conf, peer_l, &net_l, rules_l, &mrt_l, &ribnames,
-	    pipe_m2r, pipe_s2r, pipe_m2s, pipe_s2r_c, debug);
-	io_pid = session_main(&conf, peer_l, &net_l, rules_l, &mrt_l, &ribnames,
-	    pipe_m2s, pipe_s2r, pipe_m2r, pipe_s2r_c);
+	rde_pid = rde_main(pipe_m2r, pipe_s2r, pipe_m2s, pipe_s2r_c, debug);
+	io_pid = session_main(pipe_m2s, pipe_s2r, pipe_m2r, pipe_s2r_c,
+	    conf.csock, conf.rcsock);
 
 	setproctitle("parent");
 
@@ -254,33 +244,13 @@ main(int argc, char *argv[])
 	imsg_init(ibuf_se, pipe_m2s[0]);
 	imsg_init(ibuf_rde, pipe_m2r[0]);
 	mrt_init(ibuf_rde, ibuf_se);
+	quit = reconfigure(conffile, &conf, &mrt_l, &peer_l);
 	if ((rfd = kr_init(!(conf.flags & BGPD_FLAG_NO_FIB_UPDATE),
 	    conf.rtableid)) == -1)
 		quit = 1;
 	if (pftable_clear_all() != 0)
 		quit = 1;
 
-	while ((net = TAILQ_FIRST(&net_l)) != NULL) {
-		TAILQ_REMOVE(&net_l, net, entry);
-		filterset_free(&net->net.attrset);
-		free(net);
-	}
-
-	while ((r = TAILQ_FIRST(rules_l)) != NULL) {
-		TAILQ_REMOVE(rules_l, r, entry);
-		free(r);
-	}
-	TAILQ_FOREACH(la, conf.listen_addrs, entry) {
-		close(la->fd);
-		la->fd = -1;
-	}
-	while ((rr = SIMPLEQ_FIRST(&ribnames))) {
-		SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
-		free(rr);
-	}
-
-	mrt_reconfigure(&mrt_l);
-
 	while (quit == 0) {
 		bzero(pfd, sizeof(pfd));
 		pfd[PFD_PIPE_SESSION].fd = ibuf_se->fd;
@@ -336,8 +306,7 @@ main(int argc, char *argv[])
 
 			reconfig = 0;
 			log_info("rereading config");
-			switch (reconfigure(conffile, &conf, &mrt_l, &peer_l,
-			    rules_l)) {
+			switch (reconfigure(conffile, &conf, &mrt_l, &peer_l)) {
 			case -1:	/* fatal error */
 				quit = 1;
 				break;
@@ -389,13 +358,13 @@ main(int argc, char *argv[])
 		LIST_REMOVE(m, entry);
 		free(m);
 	}
-	while ((la = TAILQ_FIRST(conf.listen_addrs)) != NULL) {
-		TAILQ_REMOVE(conf.listen_addrs, la, entry);
-		close(la->fd);
-		free(la);
-	}
+	if (conf.listen_addrs)
+		while ((la = TAILQ_FIRST(conf.listen_addrs)) != NULL) {
+			TAILQ_REMOVE(conf.listen_addrs, la, entry);
+			close(la->fd);
+			free(la);
+		}
 
-	free(rules_l);
 	control_cleanup(conf.csock);
 	control_cleanup(conf.rcsock);
 	carp_demote_shutdown();
@@ -452,18 +421,23 @@ send_filterset(struct imsgbuf *i, struct
 
 int
 reconfigure(char *conffile, struct bgpd_config *conf, struct mrt_head *mrt_l,
-    struct peer **peer_l, struct filter_head *rules_l)
+    struct peer **peer_l)
 {
 	struct network_head	 net_l;
+	struct filter_head	 rules_l;
 	struct network		*n;
 	struct peer		*p;
 	struct filter_rule	*r;
 	struct listen_addr	*la;
 	struct rde_rib		*rr;
 
-	if (parse_config(conffile, conf, mrt_l, peer_l, &net_l, rules_l)) {
+	if (parse_config(conffile, conf, mrt_l, peer_l, &net_l, &rules_l)) {
 		log_warnx("config file %s has errors, not reloading",
 		    conffile);
+		while ((rr = SIMPLEQ_FIRST(&ribnames))) {
+			SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
+			free(rr);
+		}
 		return (1);
 	}
 
@@ -525,13 +499,13 @@ reconfigure(char *conffile, struct bgpd_
 		return (-1);
 
 	/* filters for the RDE */
-	while ((r = TAILQ_FIRST(rules_l)) != NULL) {
+	while ((r = TAILQ_FIRST(&rules_l)) != NULL) {
 		if (imsg_compose(ibuf_rde, IMSG_RECONF_FILTER, 0, 0, -1,
 		    r, sizeof(struct filter_rule)) == -1)
 			return (-1);
 		if (send_filterset(ibuf_rde, &r->set) == -1)
 			return (-1);
-		TAILQ_REMOVE(rules_l, r, entry);
+		TAILQ_REMOVE(&rules_l, r, entry);
 		filterset_free(&r->set);
 		free(r);
 	}
@@ -550,8 +524,8 @@ int
 dispatch_imsg(struct imsgbuf *ibuf, int idx)
 {
 	struct imsg		 imsg;
-	int			 n;
-	int			 rv;
+	ssize_t			 n;
+	int			 rv, verbose;
 
 	if ((n = imsg_read(ibuf)) == -1)
 		return (-1);
@@ -692,6 +666,11 @@ dispatch_imsg(struct imsgbuf *ibuf, int 
 				carp_demote_set(msg->demote_group, msg->level);
 			}
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			/* already checked by SE */
+			memcpy(&verbose, imsg.data, sizeof(verbose));
+			log_verbose(verbose);
+			break;
 		default:
 			break;
 		}
@@ -707,7 +686,7 @@ send_nexthop_update(struct kroute_nextho
 {
 	char	*gw = NULL;
 
-	if (msg->gateway.af)
+	if (msg->gateway.aid)
 		if (asprintf(&gw, ": via %s",
 		    log_addr(&msg->gateway)) == -1) {
 			log_warn("send_nexthop_update");
@@ -717,7 +696,7 @@ send_nexthop_update(struct kroute_nextho
 	log_info("nexthop %s now %s%s%s", log_addr(&msg->nexthop),
 	    msg->valid ? "valid" : "invalid",
 	    msg->connected ? ": directly connected" : "",
-	    msg->gateway.af ? gw : "");
+	    msg->gateway.aid ? gw : "");
 
 	free(gw);
 
@@ -758,17 +737,16 @@ bgpd_redistribute(int type, struct krout
 		fatalx("bgpd_redistribute: unable to redistribute v4 and v6"
 		    "together");
 	if (kr != NULL) {
-		net.prefix.af = AF_INET;
+		net.prefix.aid = AID_INET;
 		net.prefix.v4.s_addr = kr->prefix.s_addr;
 		net.prefixlen = kr->prefixlen;
 	}
 	if (kr6 != NULL) {
-		net.prefix.af = AF_INET6;
+		net.prefix.aid = AID_INET6;
 		memcpy(&net.prefix.v6, &kr6->prefix, sizeof(struct in6_addr));
 		net.prefixlen = kr6->prefixlen;
 	}
 
-
 	if (imsg_compose(ibuf_rde, type, 0, 0, -1, &net,
 	    sizeof(struct network_config)) == -1)
 		return (-1);
