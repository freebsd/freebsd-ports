--- relayd/pfe_filter.c.orig	2011-05-19 10:56:49.000000000 +0200
+++ relayd/pfe_filter.c	2011-05-22 10:32:36.639918375 +0200
@@ -24,7 +24,10 @@
 #include <net/if.h>
 #include <net/pfvar.h>
 #include <netinet/in.h>
+#ifndef __FreeBSD__
+/* New pf */
 #include <netinet/tcp.h>
+#endif
 #include <arpa/inet.h>
 
 #include <limits.h>
@@ -43,8 +46,14 @@
 struct pfdata {
 	int			 dev;
 	struct pf_anchor	*anchor;
+#ifndef __FreeBSD__
 	struct pfioc_trans	 pft;
 	struct pfioc_trans_e	 pfte;
+#else
+	/* Old pf */
+	struct pfioc_trans	 pft[PF_RULESET_MAX];
+	struct pfioc_trans_e	 pfte[PF_RULESET_MAX];
+#endif
 	u_int8_t		 pfused;
 };
 
@@ -103,6 +112,10 @@
 		    sizeof(tables[i].pfrt_name))
 			goto toolong;
 		tables[i].pfrt_flags |= PFR_TFLAG_PERSIST;
+#ifdef __FreeBSD__
+		log_debug("init_tables: prepare anchor \"%s\" and table \"%s\"",
+		    tables[i].pfrt_anchor, tables[i].pfrt_name);
+#endif
 		i++;
 	}
 	if (i != env->sc_rdrcount)
@@ -286,12 +299,18 @@
 		}
 
 		psnk.psnk_af = host->conf.ss.ss_family;
+#ifndef __FreeBSD__
 		psnk.psnk_killed = 0;
+#endif
 
 		if (ioctl(env->sc_pf->dev,
 		    DIOCKILLSRCNODES, &psnk) == -1)
 			fatal("kill_srcnodes: cannot kill src nodes");
+#ifndef __FreeBSD__
 		cnt += psnk.psnk_killed;
+#else
+		cnt += psnk.psnk_af;
+#endif
 	}
 
 	return (cnt);
@@ -335,6 +354,7 @@
 int
 transaction_init(struct relayd *env, const char *anchor)
 {
+#ifndef __FreeBSD__
 	env->sc_pf->pft.size = 1;
 	env->sc_pf->pft.esize = sizeof(env->sc_pf->pfte);
 	env->sc_pf->pft.array = &env->sc_pf->pfte;
@@ -347,17 +367,45 @@
 	if (ioctl(env->sc_pf->dev, DIOCXBEGIN,
 	    &env->sc_pf->pft) == -1)
 		return (-1);
+#else
+	/* Old pf */
+	int i;
+
+	for (i = 0; i < PF_RULESET_MAX; i++) {
+		env->sc_pf->pft[i].size = 1;
+		env->sc_pf->pft[i].esize = sizeof(env->sc_pf->pfte[i]);
+		env->sc_pf->pft[i].array = &env->sc_pf->pfte[i];
+
+		bzero(&env->sc_pf->pfte[i], sizeof(env->sc_pf->pfte[i]));
+		(void)strlcpy(env->sc_pf->pfte[i].anchor,
+		    anchor, PF_ANCHOR_NAME_SIZE);
+		env->sc_pf->pfte[i].rs_num = i;
 
+		if (ioctl(env->sc_pf->dev, DIOCXBEGIN,
+		    &env->sc_pf->pft[i]) == -1)
+			return (-1);
+	}
+#endif
 	return (0);
 }
 
 int
 transaction_commit(struct relayd *env)
 {
+#ifndef __FreeBSD__
 	if (ioctl(env->sc_pf->dev, DIOCXCOMMIT,
 	    &env->sc_pf->pft) == -1)
 		return (-1);
-
+#else
+	/* Old pf */
+	int i;
+
+	for (i = 0; i < PF_RULESET_MAX; i++) {
+		if (ioctl(env->sc_pf->dev, DIOCXCOMMIT,
+		    &env->sc_pf->pft[i]) == -1)
+			return (-1);
+	}
+#endif
 	return (0);
 }
 
@@ -365,10 +413,18 @@
 sync_ruleset(struct relayd *env, struct rdr *rdr, int enable)
 {
 	struct pfioc_rule	 rio;
+#ifdef __FreeBSD__
+	/* Old pf */
+	struct pfioc_pooladdr	pio;
+#endif
 	struct sockaddr_in	*sain;
 	struct sockaddr_in6	*sain6;
 	struct address		*address;
 	char			 anchor[PF_ANCHOR_NAME_SIZE];
+#ifdef __FreeBSD__
+	/* Old pf */
+	int			rs = 0;
+#endif
 	struct table		*t = rdr->table;
 
 	if ((env->sc_flags & F_NEEDPF) == 0)
@@ -397,8 +453,14 @@
 
 	TAILQ_FOREACH(address, &rdr->virts, entry) {
 		memset(&rio, 0, sizeof(rio));
+#ifdef __FreeBSD__
+		/* Old pf */
+		memset(&pio, 0, sizeof(pio));
+#endif
 		(void)strlcpy(rio.anchor, anchor, sizeof(rio.anchor));
 
+#ifndef __FreeBSD__
+		/* New pf */
 		if (rdr->conf.flags & F_MATCH) {
 			rio.rule.action = PF_MATCH;
 			rio.rule.quick = 0;
@@ -409,28 +471,61 @@
 		rio.rule.direction = PF_IN;
 		rio.rule.keep_state = PF_STATE_NORMAL;
 
+#endif
 		switch (t->conf.fwdmode) {
 		case FWD_NORMAL:
+#ifndef __FreeBSD__
 			/* traditional redirection */
 			if (address->ipproto == IPPROTO_TCP) {
 				rio.rule.flags = TH_SYN;
 				rio.rule.flagset = (TH_SYN|TH_ACK);
 			}
+#else
+			/* Old pf */
+			/* traditional redirection in the rdr-anchor */
+			rs = PF_RULESET_RDR;
+			rio.rule.action = PF_RDR;
+#endif
 			break;
 		case FWD_ROUTE:
 			/* re-route with pf for DSR (direct server return) */
+#ifdef __FreeBSD__
+			/* Old pf */
+			rs = PF_RULESET_FILTER;
+			rio.rule.action = PF_PASS;
+#endif
 			rio.rule.rt = PF_ROUTETO;
+#ifdef __FreeBSD__
+			/* Old pf */
+			rio.rule.direction = PF_IN;
+			rio.rule.quick = 1; /* force first match */
+#endif
 
 			/* Use sloppy state handling for half connections */
+#ifdef __FreeBSD__
+			/* Old pf */
+			rio.rule.keep_state = PF_STATE_NORMAL;
+#endif
+#ifdef PFRULE_STATESLOPPY
 			rio.rule.rule_flag = PFRULE_STATESLOPPY;
+#endif
 			break;
 		default:
 			fatalx("sync_ruleset: invalid forward mode");
 			/* NOTREACHED */
 		}
 
+#ifndef __FreeBSD__
 		rio.ticket = env->sc_pf->pfte.ticket;
 
+#else
+		/* Old pf */
+		rio.ticket = env->sc_pf->pfte[rs].ticket;
+		if (ioctl(env->sc_pf->dev, DIOCBEGINADDRS, &pio) == -1)
+			fatal("sync_ruleset: cannot initialise address pool");
+
+		rio.pool_ticket = pio.ticket;
+#endif
 		rio.rule.af = address->ss.ss_family;
 		rio.rule.proto = address->ipproto;
 		rio.rule.src.addr.type = PF_ADDR_ADDRMASK;
@@ -438,7 +533,9 @@
 		rio.rule.dst.port_op = address->port.op;
 		rio.rule.dst.port[0] = address->port.val[0];
 		rio.rule.dst.port[1] = address->port.val[1];
+#ifndef __FreeBSD__
 		rio.rule.rtableid = -1; /* stay in the main routing table */
+#endif
 
 		if (rio.rule.proto == IPPROTO_TCP)
 			rio.rule.timeout[PFTM_TCP_ESTABLISHED] =
@@ -466,18 +563,36 @@
 			memset(&rio.rule.dst.addr.v.a.mask.addr8, 0xff, 16);
 		}
 
+#ifndef __FreeBSD__
 		rio.rule.nat.addr.type = PF_ADDR_NONE;
 		rio.rule.rdr.addr.type = PF_ADDR_TABLE;
+#else
+		/* Old pf */
+		pio.addr.addr.type = PF_ADDR_TABLE;
+#endif
 		if (strlen(t->conf.ifname))
+#ifndef __FreeBSD__
 			(void)strlcpy(rio.rule.rdr.ifname, t->conf.ifname,
 			    sizeof(rio.rule.rdr.ifname));
 		if (strlcpy(rio.rule.rdr.addr.v.tblname, rdr->conf.name,
 		    sizeof(rio.rule.rdr.addr.v.tblname)) >=
 		    sizeof(rio.rule.rdr.addr.v.tblname))
 			fatal("sync_ruleset: table name too long");
+#else
+		/* Old pf */
+			(void)strlcpy(pio.addr.ifname, t->conf.ifname,
+			    sizeof(pio.addr.ifname));
+		if (strlcpy(pio.addr.addr.v.tblname, rdr->conf.name,
+		    sizeof(pio.addr.addr.v.tblname)) >=
+		    sizeof(pio.addr.addr.v.tblname))
+			fatal("sync_ruleset: table name too long");
+		if (ioctl(env->sc_pf->dev, DIOCADDADDR, &pio) == -1)
+			fatal("sync_ruleset: cannot add address to pool");
+#endif
 
 		if (address->port.op == PF_OP_EQ ||
 		    rdr->table->conf.flags & F_PORT) {
+#ifndef __FreeBSD__
 			rio.rule.rdr.proxy_port[0] =
 			    ntohs(rdr->table->conf.port);
 			rio.rule.rdr.port_op = PF_OP_EQ;
@@ -491,10 +606,27 @@
 			   sizeof(rio.rule.route));
 			rio.rule.rdr.addr.type = PF_ADDR_NONE;
 		}
+#else
+			/* Old pf */
+			rio.rule.rpool.proxy_port[0] =
+			    ntohs(rdr->table->conf.port);
+			rio.rule.rpool.port_op = PF_OP_EQ;
+		}
+		rio.rule.rpool.opts = PF_POOL_ROUNDROBIN;
+		if (rdr->conf.flags & F_STICKY)
+			rio.rule.rpool.opts |= PF_POOL_STICKYADDR;
+#endif
 
 		if (ioctl(env->sc_pf->dev, DIOCADDRULE, &rio) == -1)
 			fatal("cannot add rule");
+#ifndef __FreeBSD__
 		log_debug("%s: rule added to anchor \"%s\"", __func__, anchor);
+#else
+		/* Old pf */
+		log_debug("%s: rule added to %sanchor \"%s\"", __func__,
+		    rdr->table->conf.fwdmode == FWD_ROUTE ?
+		    "" : "rdr-", anchor);
+#endif
 	}
 	if (transaction_commit(env) == -1)
 		log_warn("%s: add rules transaction failed", __func__);
