Index: bgpd/printconf.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/printconf.c,v
retrieving revision 1.1.1.1
retrieving revision 1.4
diff -u -p -r1.1.1.1 -r1.4
--- bgpd/printconf.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/printconf.c	9 Jul 2009 17:22:14 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: printconf.c,v 1.65 2007/11/22 11:37:25 henning Exp $	*/
+/*	$OpenBSD: printconf.c,v 1.70 2009/06/06 01:10:29 claudio Exp $	*/
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -19,10 +19,14 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif
 
 #include "bgpd.h"
 #include "mrt.h"
 #include "session.h"
+#include "rde.h"
 
 void		 print_op(enum comp_ops);
 void		 print_community(int, int);
@@ -185,6 +189,8 @@ print_mainconf(struct bgpd_config *conf)
 		printf("holdtime %u\n", conf->holdtime);
 	if (conf->min_holdtime)
 		printf("holdtime min %u\n", conf->min_holdtime);
+	if (conf->connectretry)
+		printf("connect-retry %u\n", conf->connectretry);
 
 	if (conf->flags & BGPD_FLAG_NO_FIB_UPDATE)
 		printf("fib-update no\n");
@@ -200,9 +206,6 @@ print_mainconf(struct bgpd_config *conf)
 	if (conf->flags & BGPD_FLAG_DECISION_MED_ALWAYS)
 		printf("rde med compare always\n");
 
-	if (conf->flags & BGPD_FLAG_DECISION_TRANS_AS)
-		printf("transparent-as yes\n");
-
 	if (conf->log & BGPD_LOG_UPDATES)
 		printf("log updates\n");
 
@@ -271,6 +274,8 @@ print_peer(struct peer_config *p, struct
 		printf("%sneighbor %s {\n", c, log_addr(&p->remote_addr));
 	if (p->descr[0])
 		printf("%s\tdescr \"%s\"\n", c, p->descr);
+	if (p->rib[0])
+		printf("%s\trib \"%s\"\n", c, p->rib);
 	if (p->remote_as)
 		printf("%s\tremote-as %s\n", c, log_as(p->remote_as));
 	if (p->down)
@@ -320,6 +325,12 @@ print_peer(struct peer_config *p, struct
 		printf("%s\tdemote %s\n", c, p->demote_group);
 	if (p->if_depend[0])
 		printf("%s\tdepend on \"%s\"\n", c, p->if_depend);
+	if (p->flags & PEERFLAG_TRANS_AS)
+		printf("%s\ttransparent-as yes\n", c);
+#if defined(IPV6_LINKLOCAL_PEER)
+	if (p->lliface[0])
+		printf("%s\tinterface %s\n", c, p->lliface);
+#endif
 
 	if (p->auth.method == AUTH_MD5SIG)
 		printf("%s\ttcp md5sig\n", c);
@@ -419,10 +430,12 @@ print_rule(struct peer *peer_l, struct f
 		printf("deny ");
 	else
 		printf("match ");
-
 	if (r->quick)
 		printf("quick ");
 
+	if (r->rib[0])
+		printf("rib %s ", r->rib);
+
 	if (r->dir == DIR_IN)
 		printf("from ");
 	else if (r->dir == DIR_OUT)
@@ -532,12 +545,14 @@ print_mrt(u_int32_t pid, u_int32_t gid, 
 	LIST_FOREACH(m, xmrt_l, entry)
 		if ((gid != 0 && m->group_id == gid) ||
 		    (m->peer_id == pid && m->group_id == gid)) {
+			printf("%s%sdump ", prep, prep2);
+			if (m->rib[0])
+				printf("rib %s ", m->rib);
 			if (MRT2MC(m)->ReopenTimerInterval == 0)
-				printf("%s%sdump %s %s\n", prep, prep2,
-				    mrt_type(m->type), MRT2MC(m)->name);
+				printf("%s %s\n", mrt_type(m->type),
+				    MRT2MC(m)->name);
 			else
-				printf("%s%sdump %s %s %d\n", prep, prep2,
-				    mrt_type(m->type),
+				printf("%s %s %d\n", mrt_type(m->type),
 				    MRT2MC(m)->name,
 				    MRT2MC(m)->ReopenTimerInterval);
 		}
@@ -602,16 +617,25 @@ peer_compare(const void *aa, const void 
 }
 
 void
-print_config(struct bgpd_config *conf, struct network_head *net_l,
-    struct peer *peer_l, struct filter_head *rules_l, struct mrt_head *mrt_l)
+print_config(struct bgpd_config *conf, struct rib_names *rib_l,
+    struct network_head *net_l, struct peer *peer_l,
+    struct filter_head *rules_l, struct mrt_head *mrt_l)
 {
 	struct filter_rule	*r;
 	struct network		*n;
+	struct rde_rib		*rr;
 
 	xmrt_l = mrt_l;
 	printf("\n");
 	print_mainconf(conf);
 	printf("\n");
+	SIMPLEQ_FOREACH(rr, rib_l, entry) {
+		if (rr->flags & F_RIB_NOEVALUATE)
+			printf("rde rib %s no evaluate\n", rr->name);
+		else
+			printf("rde rib %s\n", rr->name);
+	}
+	printf("\n");
 	TAILQ_FOREACH(n, net_l, entry)
 		print_network(&n->net);
 	printf("\n");
