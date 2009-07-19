Index: bgpd/bgpd.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/bgpd.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/bgpd.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/bgpd.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: bgpd.c,v 1.145 2008/05/12 19:15:02 pyr Exp $ */
+/*	$OpenBSD: bgpd.c,v 1.148 2009/06/07 00:30:23 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -58,6 +58,7 @@ volatile sig_atomic_t	 reconfig = 0;
 pid_t			 reconfpid = 0;
 struct imsgbuf		*ibuf_se;
 struct imsgbuf		*ibuf_rde;
+struct rib_names	 ribnames = SIMPLEQ_HEAD_INITIALIZER(ribnames);
 
 void
 sighdlr(int sig)
@@ -108,6 +109,7 @@ main(int argc, char *argv[])
 	struct filter_rule	*r;
 	struct mrt		*m;
 	struct listen_addr	*la;
+	struct rde_rib		*rr;
 	struct pollfd		 pfd[POLL_MAX];
 	pid_t			 io_pid = 0, rde_pid = 0, pid;
 	char			*conffile;
@@ -181,7 +183,8 @@ main(int argc, char *argv[])
 
 	if (conf.opts & BGPD_OPT_NOACTION) {
 		if (conf.opts & BGPD_OPT_VERBOSE)
-			print_config(&conf, &net_l, peer_l, rules_l, &mrt_l);
+			print_config(&conf, &ribnames, &net_l, peer_l, rules_l,
+			    &mrt_l);
 		else
 			fprintf(stderr, "configuration OK\n");
 		exit(0);
@@ -225,9 +228,9 @@ main(int argc, char *argv[])
 	prepare_listeners(&conf);
 
 	/* fork children */
-	rde_pid = rde_main(&conf, peer_l, &net_l, rules_l, &mrt_l,
+	rde_pid = rde_main(&conf, peer_l, &net_l, rules_l, &mrt_l, &ribnames,
 	    pipe_m2r, pipe_s2r, pipe_m2s, pipe_s2r_c, debug);
-	io_pid = session_main(&conf, peer_l, &net_l, rules_l, &mrt_l,
+	io_pid = session_main(&conf, peer_l, &net_l, rules_l, &mrt_l, &ribnames,
 	    pipe_m2s, pipe_s2r, pipe_m2r, pipe_s2r_c);
 
 	setproctitle("parent");
@@ -271,6 +274,10 @@ main(int argc, char *argv[])
 		close(la->fd);
 		la->fd = -1;
 	}
+	while ((rr = SIMPLEQ_FIRST(&ribnames))) {
+		SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
+		free(rr);
+	}
 
 	mrt_reconfigure(&mrt_l);
 
@@ -452,6 +459,7 @@ reconfigure(char *conffile, struct bgpd_
 	struct peer		*p;
 	struct filter_rule	*r;
 	struct listen_addr	*la;
+	struct rde_rib		*rr;
 
 	if (parse_config(conffile, conf, mrt_l, peer_l, &net_l, rules_l)) {
 		log_warnx("config file %s has errors, not reloading",
@@ -488,6 +496,15 @@ reconfigure(char *conffile, struct bgpd_
 		la->fd = -1;
 	}
 
+	/* RIBs for the RDE */
+	while ((rr = SIMPLEQ_FIRST(&ribnames))) {
+		SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
+		if (imsg_compose(ibuf_rde, IMSG_RECONF_RIB, 0, 0, -1,
+		    rr, sizeof(struct rde_rib)) == -1)
+			return (-1);
+		free(rr);
+	}
+
 	/* networks for the RDE */
 	while ((n = TAILQ_FIRST(&net_l)) != NULL) {
 		if (imsg_compose(ibuf_rde, IMSG_NETWORK_ADD, 0, 0, -1,
