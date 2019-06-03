Index: bgpd/bgpd.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/bgpd.c,v
retrieving revision 1.1.1.7
retrieving revision 1.1.1.12
diff -u -p -r1.1.1.7 -r1.1.1.12
--- bgpd/bgpd.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/bgpd.c	8 Dec 2012 10:37:08 -0000	1.1.1.12
@@ -1,4 +1,4 @@
-/*	$OpenBSD: bgpd.c,v 1.148 2009/06/07 00:30:23 claudio Exp $ */
+/*	$OpenBSD: bgpd.c,v 1.169 2012/09/18 09:45:51 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -32,8 +32,8 @@
 #include <string.h>
 #include <unistd.h>
 
-#include "mrt.h"
 #include "bgpd.h"
+#include "mrt.h"
 #include "session.h"
 
 void		sighdlr(int);
@@ -42,23 +42,23 @@ int		main(int, char *[]);
 int		check_child(pid_t, const char *);
 int		send_filterset(struct imsgbuf *, struct filter_set_head *);
 int		reconfigure(char *, struct bgpd_config *, struct mrt_head *,
-		    struct peer **, struct filter_head *);
+		    struct peer **);
 int		dispatch_imsg(struct imsgbuf *, int);
+int		control_setup(struct bgpd_config *);
 
 int			 rfd = -1;
-int			 cflags = 0;
-struct filter_set_head	*connectset;
-struct filter_set_head	*connectset6;
-struct filter_set_head	*staticset;
-struct filter_set_head	*staticset6;
-volatile sig_atomic_t	 mrtdump = 0;
-volatile sig_atomic_t	 quit = 0;
-volatile sig_atomic_t	 sigchld = 0;
-volatile sig_atomic_t	 reconfig = 0;
-pid_t			 reconfpid = 0;
+int			 cflags;
+volatile sig_atomic_t	 mrtdump;
+volatile sig_atomic_t	 quit;
+volatile sig_atomic_t	 sigchld;
+volatile sig_atomic_t	 reconfig;
+pid_t			 reconfpid;
+int			 reconfpending;
 struct imsgbuf		*ibuf_se;
 struct imsgbuf		*ibuf_rde;
 struct rib_names	 ribnames = SIMPLEQ_HEAD_INITIALIZER(ribnames);
+char			*cname;
+char			*rcname;
 
 void
 sighdlr(int sig)
@@ -86,8 +86,8 @@ usage(void)
 {
 	extern char *__progname;
 
-	fprintf(stderr, "usage: %s [-cdnv] ", __progname);
-	fprintf(stderr, "[-D macro=value] [-f file] [-r path] [-s path]\n");
+	fprintf(stderr, "usage: %s [-cdnv] [-D macro=value] [-f file]\n",
+	    __progname);
 	exit(1);
 }
 
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
@@ -124,18 +119,13 @@ main(int argc, char *argv[])
 	bgpd_process = PROC_MAIN;
 
 	log_init(1);		/* log to stderr until daemonized */
-
-	if ((rules_l = calloc(1, sizeof(struct filter_head))) == NULL)
-		err(1, NULL);
+	log_verbose(1);
 
 	bzero(&conf, sizeof(conf));
 	LIST_INIT(&mrt_l);
-	TAILQ_INIT(&net_l);
-	TAILQ_INIT(rules_l);
 	peer_l = NULL;
-	conf.csock = SOCKET_NAME;
 
-	while ((ch = getopt(argc, argv, "cdD:f:nr:s:v")) != -1) {
+	while ((ch = getopt(argc, argv, "cdD:f:nv")) != -1) {
 		switch (ch) {
 		case 'c':
 			conf.opts |= BGPD_OPT_FORCE_DEMOTE;
@@ -158,12 +148,7 @@ main(int argc, char *argv[])
 			if (conf.opts & BGPD_OPT_VERBOSE)
 				conf.opts |= BGPD_OPT_VERBOSE2;
 			conf.opts |= BGPD_OPT_VERBOSE;
-			break;
-		case 'r':
-			conf.rcsock = optarg;
-			break;
-		case 's':
-			conf.csock = optarg;
+			log_verbose(1);
 			break;
 		default:
 			usage();
@@ -176,24 +161,22 @@ main(int argc, char *argv[])
 	if (argc > 0)
 		usage();
 
-	if (parse_config(conffile, &conf, &mrt_l, &peer_l, &net_l, rules_l)) {
-		free(rules_l);
-		exit(1);
-	}
-
 	if (conf.opts & BGPD_OPT_NOACTION) {
+		struct network_head	net_l;
+		struct rdomain_head	rdom_l;
+		struct filter_head	rules_l;
+
+		if (parse_config(conffile, &conf, &mrt_l, &peer_l, &net_l,
+		    &rules_l, &rdom_l))
+			exit(1);
+
 		if (conf.opts & BGPD_OPT_VERBOSE)
-			print_config(&conf, &ribnames, &net_l, peer_l, rules_l,
-			    &mrt_l);
+			print_config(&conf, &ribnames, &net_l, peer_l, &rules_l,
+			    &mrt_l, &rdom_l);
 		else
 			fprintf(stderr, "configuration OK\n");
 		exit(0);
 	}
-	cflags = conf.flags;
-	connectset = &conf.connectset;
-	staticset = &conf.staticset;
-	connectset6 = &conf.connectset6;
-	staticset6 = &conf.staticset6;
 
 	if (geteuid())
 		errx(1, "need root privileges");
@@ -202,6 +185,7 @@ main(int argc, char *argv[])
 		errx(1, "unknown user %s", BGPD_USER);
 
 	log_init(debug);
+	log_verbose(conf.opts & BGPD_OPT_VERBOSE);
 
 	if (!debug)
 		daemon(1, 0);
@@ -225,13 +209,9 @@ main(int argc, char *argv[])
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
+	io_pid = session_main(pipe_m2s, pipe_s2r, pipe_m2r, pipe_s2r_c);
 
 	setproctitle("parent");
 
@@ -254,33 +234,12 @@ main(int argc, char *argv[])
 	imsg_init(ibuf_se, pipe_m2s[0]);
 	imsg_init(ibuf_rde, pipe_m2r[0]);
 	mrt_init(ibuf_rde, ibuf_se);
-	if ((rfd = kr_init(!(conf.flags & BGPD_FLAG_NO_FIB_UPDATE),
-	    conf.rtableid)) == -1)
+	if ((rfd = kr_init()) == -1)
 		quit = 1;
+	quit = reconfigure(conffile, &conf, &mrt_l, &peer_l);
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
@@ -335,15 +294,16 @@ main(int argc, char *argv[])
 			u_int	error;
 
 			reconfig = 0;
-			log_info("rereading config");
-			switch (reconfigure(conffile, &conf, &mrt_l, &peer_l,
-			    rules_l)) {
+			switch (reconfigure(conffile, &conf, &mrt_l, &peer_l)) {
 			case -1:	/* fatal error */
 				quit = 1;
 				break;
 			case 0:		/* all OK */
 				error = 0;
 				break;
+			case 2:
+				error = CTL_RES_PENDING;
+				break;
 			default:	/* parse error */
 				error = CTL_RES_PARSE_ERROR;
 				break;
@@ -389,13 +349,13 @@ main(int argc, char *argv[])
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
@@ -413,6 +373,8 @@ main(int argc, char *argv[])
 	free(ibuf_se);
 	msgbuf_clear(&ibuf_rde->w);
 	free(ibuf_rde);
+	free(rcname);
+	free(cname);
 
 	log_info("Terminating");
 	return (0);
@@ -452,27 +414,33 @@ send_filterset(struct imsgbuf *i, struct
 
 int
 reconfigure(char *conffile, struct bgpd_config *conf, struct mrt_head *mrt_l,
-    struct peer **peer_l, struct filter_head *rules_l)
+    struct peer **peer_l)
 {
 	struct network_head	 net_l;
-	struct network		*n;
+	struct rdomain_head	 rdom_l;
+	struct filter_head	 rules_l;
 	struct peer		*p;
 	struct filter_rule	*r;
 	struct listen_addr	*la;
 	struct rde_rib		*rr;
+	struct rdomain		*rd;
 
-	if (parse_config(conffile, conf, mrt_l, peer_l, &net_l, rules_l)) {
+	if (reconfpending) {
+		log_info("previous reload still running");
+		return (2);
+	}
+	reconfpending = 2;	/* one per child */
+
+	log_info("rereading config");
+	if (parse_config(conffile, conf, mrt_l, peer_l, &net_l, &rules_l,
+	    &rdom_l)) {
 		log_warnx("config file %s has errors, not reloading",
 		    conffile);
+		reconfpending = 0;
 		return (1);
 	}
 
 	cflags = conf->flags;
-	connectset = &conf->connectset;
-	staticset = &conf->staticset;
-	connectset6 = &conf->connectset6;
-	staticset6 = &conf->staticset6;
-
 	prepare_listeners(conf);
 
 	/* start reconfiguration */
@@ -483,12 +451,6 @@ reconfigure(char *conffile, struct bgpd_
 	    conf, sizeof(struct bgpd_config)) == -1)
 		return (-1);
 
-	/* send peer list and listeners to the SE */
-	for (p = *peer_l; p != NULL; p = p->next)
-		if (imsg_compose(ibuf_se, IMSG_RECONF_PEER, p->conf.id, 0, -1,
-		    &p->conf, sizeof(struct peer_config)) == -1)
-			return (-1);
-
 	TAILQ_FOREACH(la, conf->listen_addrs, entry) {
 		if (imsg_compose(ibuf_se, IMSG_RECONF_LISTENER, 0, 0, la->fd,
 		    la, sizeof(struct listen_addr)) == -1)
@@ -496,51 +458,104 @@ reconfigure(char *conffile, struct bgpd_
 		la->fd = -1;
 	}
 
+	if (control_setup(conf) == -1)
+		return (-1);
+
+	/* adjust fib syncing on reload */
+	ktable_preload();
+
 	/* RIBs for the RDE */
 	while ((rr = SIMPLEQ_FIRST(&ribnames))) {
 		SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
+		if (ktable_update(rr->rtableid, rr->name, NULL,
+		    rr->flags) == -1) {
+			log_warnx("failed to load rdomain %d",
+			    rr->rtableid);
+			return (-1);
+		}
 		if (imsg_compose(ibuf_rde, IMSG_RECONF_RIB, 0, 0, -1,
 		    rr, sizeof(struct rde_rib)) == -1)
 			return (-1);
 		free(rr);
 	}
 
-	/* networks for the RDE */
-	while ((n = TAILQ_FIRST(&net_l)) != NULL) {
-		if (imsg_compose(ibuf_rde, IMSG_NETWORK_ADD, 0, 0, -1,
-		    &n->net, sizeof(struct network_config)) == -1)
-			return (-1);
-		if (send_filterset(ibuf_rde, &n->net.attrset) == -1)
-			return (-1);
-		if (imsg_compose(ibuf_rde, IMSG_NETWORK_DONE, 0, 0, -1,
-		    NULL, 0) == -1)
-			return (-1);
-		TAILQ_REMOVE(&net_l, n, entry);
-		filterset_free(&n->net.attrset);
-		free(n);
+	/* send peer list and listeners to the SE and RDE */
+	for (p = *peer_l; p != NULL; p = p->next) {
+		if (imsg_compose(ibuf_se, IMSG_RECONF_PEER, p->conf.id, 0, -1,
+		    &p->conf, sizeof(struct peer_config)) == -1)
+			return (-1);
+		if (imsg_compose(ibuf_rde, IMSG_RECONF_PEER, p->conf.id, 0, -1,
+		    &p->conf, sizeof(struct peer_config)) == -1)
+			return (-1);
 	}
 
-	/* redistribute list needs to be reloaded too */
-	if (kr_reload() == -1)
+	/* networks go via kroute to the RDE */
+	if (kr_net_reload(0, &net_l))
 		return (-1);
 
 	/* filters for the RDE */
-	while ((r = TAILQ_FIRST(rules_l)) != NULL) {
+	while ((r = TAILQ_FIRST(&rules_l)) != NULL) {
+		TAILQ_REMOVE(&rules_l, r, entry);
 		if (imsg_compose(ibuf_rde, IMSG_RECONF_FILTER, 0, 0, -1,
 		    r, sizeof(struct filter_rule)) == -1)
 			return (-1);
 		if (send_filterset(ibuf_rde, &r->set) == -1)
 			return (-1);
-		TAILQ_REMOVE(rules_l, r, entry);
 		filterset_free(&r->set);
 		free(r);
 	}
 
+	while ((rd = SIMPLEQ_FIRST(&rdom_l)) != NULL) {
+		SIMPLEQ_REMOVE_HEAD(&rdom_l, entry);
+		if (ktable_update(rd->rtableid, rd->descr, rd->ifmpe,
+		    rd->flags) == -1) {
+			log_warnx("failed to load rdomain %d",
+			    rd->rtableid);
+			return (-1);
+		}
+		/* networks go via kroute to the RDE */
+		if (kr_net_reload(rd->rtableid, &rd->net_l))
+			return (-1);
+
+		if (imsg_compose(ibuf_rde, IMSG_RECONF_RDOMAIN, 0, 0, -1,
+		    rd, sizeof(*rd)) == -1)
+			return (-1);
+
+		/* export targets */
+		if (imsg_compose(ibuf_rde, IMSG_RECONF_RDOMAIN_EXPORT, 0, 0,
+		    -1, NULL, 0) == -1)
+			return (-1);
+		if (send_filterset(ibuf_rde, &rd->export) == -1)
+			return (-1);
+		filterset_free(&rd->export);
+
+		/* import targets */
+		if (imsg_compose(ibuf_rde, IMSG_RECONF_RDOMAIN_IMPORT, 0, 0,
+		    -1, NULL, 0) == -1)
+			return (-1);
+		if (send_filterset(ibuf_rde, &rd->import) == -1)
+			return (-1);
+		filterset_free(&rd->import);
+
+		if (imsg_compose(ibuf_rde, IMSG_RECONF_RDOMAIN_DONE, 0, 0,
+		    -1, NULL, 0) == -1)
+			return (-1);
+
+		free(rd);
+	}
+
 	/* signal both childs to replace their config */
 	if (imsg_compose(ibuf_se, IMSG_RECONF_DONE, 0, 0, -1, NULL, 0) == -1 ||
 	    imsg_compose(ibuf_rde, IMSG_RECONF_DONE, 0, 0, -1, NULL, 0) == -1)
 		return (-1);
 
+	/* fix kroute information */
+	ktable_postload();
+
+	/* redistribute list needs to be reloaded too */
+	if (kr_reload() == -1)
+		return (-1);
+
 	/* mrt changes can be sent out of bound */
 	mrt_reconfigure(mrt_l);
 	return (0);
@@ -550,8 +565,8 @@ int
 dispatch_imsg(struct imsgbuf *ibuf, int idx)
 {
 	struct imsg		 imsg;
-	int			 n;
-	int			 rv;
+	ssize_t			 n;
+	int			 rv, verbose;
 
 	if ((n = imsg_read(ibuf)) == -1)
 		return (-1);
@@ -573,46 +588,39 @@ dispatch_imsg(struct imsgbuf *ibuf, int 
 		case IMSG_KROUTE_CHANGE:
 			if (idx != PFD_PIPE_ROUTE)
 				log_warnx("route request not from RDE");
-			else if (kr_change(imsg.data))
+			else if (imsg.hdr.len != IMSG_HEADER_SIZE +
+			    sizeof(struct kroute_full))
+				log_warnx("wrong imsg len");
+			else if (kr_change(imsg.hdr.peerid, imsg.data))
 				rv = -1;
 			break;
 		case IMSG_KROUTE_DELETE:
 			if (idx != PFD_PIPE_ROUTE)
 				log_warnx("route request not from RDE");
-			else if (kr_delete(imsg.data))
-				rv = -1;
-			break;
-		case IMSG_KROUTE6_CHANGE:
-			if (idx != PFD_PIPE_ROUTE)
-				log_warnx("route request not from RDE");
-			else if (kr6_change(imsg.data))
-				rv = -1;
-			break;
-		case IMSG_KROUTE6_DELETE:
-			if (idx != PFD_PIPE_ROUTE)
-				log_warnx("route request not from RDE");
-			else if (kr6_delete(imsg.data))
+			else if (imsg.hdr.len != IMSG_HEADER_SIZE +
+			    sizeof(struct kroute_full))
+				log_warnx("wrong imsg len");
+			else if (kr_delete(imsg.hdr.peerid, imsg.data))
 				rv = -1;
 			break;
 		case IMSG_NEXTHOP_ADD:
 			if (idx != PFD_PIPE_ROUTE)
 				log_warnx("nexthop request not from RDE");
-			else
-				if (imsg.hdr.len != IMSG_HEADER_SIZE +
-				    sizeof(struct bgpd_addr))
-					log_warnx("wrong imsg len");
-				else if (kr_nexthop_add(imsg.data) == -1)
-					rv = -1;
+			else if (imsg.hdr.len != IMSG_HEADER_SIZE +
+			    sizeof(struct bgpd_addr))
+				log_warnx("wrong imsg len");
+			else if (kr_nexthop_add(imsg.hdr.peerid, imsg.data) ==
+			    -1)
+				rv = -1;
 			break;
 		case IMSG_NEXTHOP_REMOVE:
 			if (idx != PFD_PIPE_ROUTE)
 				log_warnx("nexthop request not from RDE");
+			else if (imsg.hdr.len != IMSG_HEADER_SIZE +
+			    sizeof(struct bgpd_addr))
+				log_warnx("wrong imsg len");
 			else
-				if (imsg.hdr.len != IMSG_HEADER_SIZE +
-				    sizeof(struct bgpd_addr))
-					log_warnx("wrong imsg len");
-				else
-					kr_nexthop_delete(imsg.data);
+				kr_nexthop_delete(imsg.hdr.peerid, imsg.data);
 			break;
 		case IMSG_PFTABLE_ADD:
 			if (idx != PFD_PIPE_ROUTE)
@@ -646,26 +654,28 @@ dispatch_imsg(struct imsgbuf *ibuf, int 
 		case IMSG_CTL_RELOAD:
 			if (idx != PFD_PIPE_SESSION)
 				log_warnx("reload request not from SE");
-			else
+			else {
 				reconfig = 1;
 				reconfpid = imsg.hdr.pid;
+			}
 			break;
 		case IMSG_CTL_FIB_COUPLE:
 			if (idx != PFD_PIPE_SESSION)
 				log_warnx("couple request not from SE");
 			else
-				kr_fib_couple();
+				kr_fib_couple(imsg.hdr.peerid);
 			break;
 		case IMSG_CTL_FIB_DECOUPLE:
 			if (idx != PFD_PIPE_SESSION)
 				log_warnx("decouple request not from SE");
 			else
-				kr_fib_decouple();
+				kr_fib_decouple(imsg.hdr.peerid);
 			break;
 		case IMSG_CTL_KROUTE:
 		case IMSG_CTL_KROUTE_ADDR:
 		case IMSG_CTL_SHOW_NEXTHOP:
 		case IMSG_CTL_SHOW_INTERFACE:
+		case IMSG_CTL_SHOW_FIB_TABLES:
 			if (idx != PFD_PIPE_SESSION)
 				log_warnx("kroute request not from SE");
 			else
@@ -692,6 +702,16 @@ dispatch_imsg(struct imsgbuf *ibuf, int 
 				carp_demote_set(msg->demote_group, msg->level);
 			}
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			/* already checked by SE */
+			memcpy(&verbose, imsg.data, sizeof(verbose));
+			log_verbose(verbose);
+			break;
+		case IMSG_RECONF_DONE:
+			if (reconfpending == 0)
+				log_warnx("unexpected RECONF_DONE received");
+			reconfpending--;
+			break;
 		default:
 			break;
 		}
@@ -707,7 +727,7 @@ send_nexthop_update(struct kroute_nextho
 {
 	char	*gw = NULL;
 
-	if (msg->gateway.af)
+	if (msg->gateway.aid)
 		if (asprintf(&gw, ": via %s",
 		    log_addr(&msg->gateway)) == -1) {
 			log_warn("send_nexthop_update");
@@ -717,7 +737,7 @@ send_nexthop_update(struct kroute_nextho
 	log_info("nexthop %s now %s%s%s", log_addr(&msg->nexthop),
 	    msg->valid ? "valid" : "invalid",
 	    msg->connected ? ": directly connected" : "",
-	    msg->gateway.af ? gw : "");
+	    msg->gateway.aid ? gw : "");
 
 	free(gw);
 
@@ -733,56 +753,20 @@ send_imsg_session(int type, pid_t pid, v
 }
 
 int
-bgpd_redistribute(int type, struct kroute *kr, struct kroute6 *kr6)
+send_network(int type, struct network_config *net, struct filter_set_head *h)
 {
-	struct network_config	 net;
-	struct filter_set_head	*h;
-
-	if ((cflags & BGPD_FLAG_REDIST_CONNECTED) && kr &&
-	    (kr->flags & F_CONNECTED))
-		h = connectset;
-	else if ((cflags & BGPD_FLAG_REDIST_STATIC) && kr &&
-	    (kr->flags & F_STATIC))
-		h = staticset;
-	else if ((cflags & BGPD_FLAG_REDIST6_CONNECTED) && kr6 &&
-	    (kr6->flags & F_CONNECTED))
-		h = connectset6;
-	else if ((cflags & BGPD_FLAG_REDIST6_STATIC) && kr6 &&
-	    (kr6->flags & F_STATIC))
-		h = staticset6;
-	else
-		return (0);
-
-	bzero(&net, sizeof(net));
-	if (kr && kr6)
-		fatalx("bgpd_redistribute: unable to redistribute v4 and v6"
-		    "together");
-	if (kr != NULL) {
-		net.prefix.af = AF_INET;
-		net.prefix.v4.s_addr = kr->prefix.s_addr;
-		net.prefixlen = kr->prefixlen;
-	}
-	if (kr6 != NULL) {
-		net.prefix.af = AF_INET6;
-		memcpy(&net.prefix.v6, &kr6->prefix, sizeof(struct in6_addr));
-		net.prefixlen = kr6->prefixlen;
-	}
-
-
-	if (imsg_compose(ibuf_rde, type, 0, 0, -1, &net,
+	if (imsg_compose(ibuf_rde, type, 0, 0, -1, net,
 	    sizeof(struct network_config)) == -1)
 		return (-1);
-
 	/* networks that get deleted don't need to send the filter set */
 	if (type == IMSG_NETWORK_REMOVE)
-		return (1);
-
+		return (0);
 	if (send_filterset(ibuf_rde, h) == -1)
 		return (-1);
 	if (imsg_compose(ibuf_rde, IMSG_NETWORK_DONE, 0, 0, -1, NULL, 0) == -1)
 		return (-1);
 
-	return (1);
+	return (0);
 }
 
 int
@@ -810,3 +794,45 @@ bgpd_filternexthop(struct kroute *kr, st
 
 	return (1);
 }
+
+int
+control_setup(struct bgpd_config *conf)
+{
+	int fd, restricted;
+
+	/* control socket is outside chroot */
+	if (!cname || strcmp(cname, conf->csock)) {
+		if (cname) {
+			control_cleanup(cname);
+			free(cname);
+		}
+		if ((cname = strdup(conf->csock)) == NULL)
+			fatal("strdup");
+		if ((fd = control_init(0, cname)) == -1)
+			fatalx("control socket setup failed");
+		restricted = 0;
+		if (imsg_compose(ibuf_se, IMSG_RECONF_CTRL, 0, 0, fd,
+		    &restricted, sizeof(restricted)) == -1)
+			return (-1);
+	}
+	if (!conf->rcsock) {
+		/* remove restricted socket */
+		control_cleanup(rcname);
+		free(rcname);
+		rcname = NULL;
+	} else if (!rcname || strcmp(rcname, conf->rcsock)) {
+		if (rcname) {
+			control_cleanup(rcname);
+			free(rcname);
+		}
+		if ((rcname = strdup(conf->rcsock)) == NULL)
+			fatal("strdup");
+		if ((fd = control_init(1, rcname)) == -1)
+			fatalx("control socket setup failed");
+		restricted = 1;
+		if (imsg_compose(ibuf_se, IMSG_RECONF_CTRL, 0, 0, fd,
+		    &restricted, sizeof(restricted)) == -1)
+			return (-1);
+	}
+	return (0);
+}
