# One chunk of this OpenBSD patch has been removed as it's
# already part of patch-pftop.c, another one has been extended
# to fix the rule display in some views.
$OpenBSD: patch-pftop_c,v 1.12 2009/12/02 21:16:10 sthen Exp $
--- pftop.c.orig	Wed Nov  7 06:36:46 2007
+++ pftop.c	Wed Dec  2 21:14:56 2009
@@ -127,6 +127,13 @@
 #define PT_NOROUTE(x) (0)
 #endif
 
+#ifdef HAVE_NETWORK_ORDER
+#define PF_TSTAMP(x) ntohl(x)
+#else
+#define PF_TSTAMP(x) (x)
+#endif
+
+
 /* view management */
 int select_states(void);
 int read_states(void);
@@ -445,11 +452,11 @@ sort_pkt_callback(const void *s1, const void *s2)
 int
 sort_age_callback(const void *s1, const void *s2)
 {
-	if (state_buf[* (u_int32_t *) s2].creation >
-	    state_buf[* (u_int32_t *) s1].creation)
+	if (PF_TSTAMP(state_buf[* (u_int32_t *) s2].creation) >
+	    PF_TSTAMP(state_buf[* (u_int32_t *) s1].creation))
 		return sortdir;
-	if (state_buf[* (u_int32_t *) s2].creation <
-	    state_buf[* (u_int32_t *) s1].creation)
+	if (PF_TSTAMP(state_buf[* (u_int32_t *) s2].creation) <
+	    PF_TSTAMP(state_buf[* (u_int32_t *) s1].creation))
 		return -sortdir;
 	return 0;
 }
@@ -457,11 +464,11 @@ sort_age_callback(const void *s1, const void *s2)
 int
 sort_exp_callback(const void *s1, const void *s2)
 {
-	if (state_buf[* (u_int32_t *) s2].expire >
-	    state_buf[* (u_int32_t *) s1].expire)
+	if (PF_TSTAMP(state_buf[* (u_int32_t *) s2].expire) >
+	    PF_TSTAMP(state_buf[* (u_int32_t *) s1].expire))
 		return sortdir;
-	if (state_buf[* (u_int32_t *) s2].expire <
-	    state_buf[* (u_int32_t *) s1].expire)
+	if (PF_TSTAMP(state_buf[* (u_int32_t *) s2].expire) <
+	    PF_TSTAMP(state_buf[* (u_int32_t *) s1].expire))
 		return -sortdir;
 	return 0;
 }
@@ -535,6 +542,8 @@ compare_addr(int af, const struct pf_addr *a, const st
 	return 0;
 }
 
+#ifdef HAVE_PFSYNC_KEY
+
 #ifdef __GNUC__
 __inline__
 #endif
@@ -542,6 +551,113 @@ int
 sort_addr_callback(const pf_state_t *s1,
 		   const pf_state_t *s2, int dir)
 {
+	const struct pf_addr *aa, *ab;
+	u_int16_t pa, pb;
+	int af, ret, ii, io;
+
+	af = s1->af;
+
+
+	if (af > s2->af)
+		return sortdir;
+	if (af < s2->af)
+		return -sortdir;
+	
+       	ii = io = 0;
+
+	if (dir == PF_OUT)	/* looking for source addr */
+		io = 1;
+	else			/* looking for dest addr */
+		ii = 1;
+	
+	if (s1->direction == PF_IN) {
+		aa = &s1->key[PF_SK_STACK].addr[ii];
+		pa =  s1->key[PF_SK_STACK].port[ii];
+	} else {
+		aa = &s1->key[PF_SK_WIRE].addr[io];
+		pa =  s1->key[PF_SK_WIRE].port[io];
+	}
+
+	if (s2->direction == PF_IN) {
+		ab = &s2->key[PF_SK_STACK].addr[ii];;
+		pb =  s2->key[PF_SK_STACK].port[ii];
+	} else {
+		ab = &s2->key[PF_SK_WIRE].addr[io];;
+		pb =  s2->key[PF_SK_WIRE].port[io];
+	}
+
+	ret = compare_addr(af, aa, ab);
+	if (ret)
+		return ret * sortdir;
+
+	if (ntohs(pa) > ntohs(pb))
+		return sortdir;
+	return -sortdir;
+}
+
+#ifdef __GNUC__
+__inline__
+#endif
+int
+sort_port_callback(const pf_state_t *s1,
+		   const pf_state_t *s2, int dir)
+{
+	const struct pf_addr *aa, *ab;
+	u_int16_t pa, pb;
+	int af, ret, ii, io;
+
+	af = s1->af;
+
+
+	if (af > s2->af)
+		return sortdir;
+	if (af < s2->af)
+		return -sortdir;
+	
+       	ii = io = 0;
+
+	if (dir == PF_OUT)	/* looking for source addr */
+		io = 1;
+	else			/* looking for dest addr */
+		ii = 1;
+	
+	if (s1->direction == PF_IN) {
+		aa = &s1->key[PF_SK_STACK].addr[ii];
+		pa =  s1->key[PF_SK_STACK].port[ii];
+	} else {
+		aa = &s1->key[PF_SK_WIRE].addr[io];
+		pa =  s1->key[PF_SK_WIRE].port[io];
+	}
+
+	if (s2->direction == PF_IN) {
+		ab = &s2->key[PF_SK_STACK].addr[ii];;
+		pb =  s2->key[PF_SK_STACK].port[ii];
+	} else {
+		ab = &s2->key[PF_SK_WIRE].addr[io];;
+		pb =  s2->key[PF_SK_WIRE].port[io];
+	}
+
+
+	if (ntohs(pa) > ntohs(pb))
+		return sortdir;
+	if (ntohs(pa) < ntohs(pb))
+		return - sortdir;
+
+	ret = compare_addr(af, aa, ab);
+	if (ret)
+		return ret * sortdir;
+	return -sortdir;
+}
+
+#else	/* HAVE_PFSYNC_KEY */
+
+#ifdef __GNUC__
+__inline__
+#endif
+int
+sort_addr_callback(const pf_state_t *s1,
+		   const pf_state_t *s2, int dir)
+{
 	const pf_state_host_t *a, *b;
 	int af, ret;
 
@@ -573,20 +689,6 @@ sort_addr_callback(const pf_state_t *s1,
 	return -sortdir;
 }
 
-int sort_sa_callback(const void *p1, const void *p2)
-{
-	pf_state_t *s1 = state_buf + (* (u_int32_t *) p1);
-	pf_state_t *s2 = state_buf + (* (u_int32_t *) p2);
-	return sort_addr_callback(s1, s2, PF_OUT);
-}
-
-int sort_da_callback(const void *p1, const void *p2)
-{
-	pf_state_t *s1 = state_buf + (* (u_int32_t *) p1);
-	pf_state_t *s2 = state_buf + (* (u_int32_t *) p2);
-	return sort_addr_callback(s1, s2, PF_IN);
-}
-
 #ifdef __GNUC__
 __inline__
 #endif
@@ -625,7 +727,22 @@ sort_port_callback(const pf_state_t *s1,
 		return sortdir;
 	return -sortdir;
 }
+#endif	/* HAVE_PFSYNC_KEY */
 
+int sort_sa_callback(const void *p1, const void *p2)
+{
+	pf_state_t *s1 = state_buf + (* (u_int32_t *) p1);
+	pf_state_t *s2 = state_buf + (* (u_int32_t *) p2);
+	return sort_addr_callback(s1, s2, PF_OUT);
+}
+
+int sort_da_callback(const void *p1, const void *p2)
+{
+	pf_state_t *s1 = state_buf + (* (u_int32_t *) p1);
+	pf_state_t *s2 = state_buf + (* (u_int32_t *) p2);
+	return sort_addr_callback(s1, s2, PF_IN);
+}
+
 int
 sort_sp_callback(const void *p1, const void *p2)
 {
@@ -865,7 +982,48 @@ tb_print_addr(struct pf_addr * addr, struct pf_addr * 
 			tbprintf("/%u", unmask(mask, af));
 	}
 }
+#ifdef HAVE_PFSYNC_KEY
+void
+print_fld_host2(field_def *fld, struct pfsync_state_key *ks,
+		struct pfsync_state_key *kn, int idx, int af)
+{
+	struct pf_addr *as = &ks->addr[idx];
+	struct pf_addr *an = &kn->addr[idx];
 
+	u_int16_t ps = ntohs(ks->port[idx]);
+	u_int16_t pn = ntohs(kn->port[idx]);
+
+	if (fld == NULL)
+		return;
+
+	if (fld->width < 3) {
+		print_fld_str(fld, "*");
+		return;
+	}
+
+	tb_start();
+	tb_print_addr(as, NULL, af);
+
+	if (af == AF_INET)
+		tbprintf(":%u", ps);
+	else
+		tbprintf("[%u]", ps);
+
+	print_fld_tb(fld);
+
+	if (PF_ANEQ(as, an, af) || ps != pn) {
+		tb_start();
+		tb_print_addr(an, NULL, af);
+
+		if (af == AF_INET)
+			tbprintf(":%u", pn);
+		else
+			tbprintf("[%u]", pn);
+		print_fld_tb(FLD_GW);
+	}
+
+}
+#else
 void
 print_fld_host(field_def *fld, pf_state_host_t * h, int af)
 {
@@ -889,6 +1047,7 @@ print_fld_host(field_def *fld, pf_state_host_t * h, in
 
 	print_fld_tb(fld);
 }
+#endif
 
 void
 print_fld_state(field_def *fld, unsigned int proto,
@@ -960,7 +1119,20 @@ print_state(pf_state_t * s, struct sc_ent * ent)
 	else
 		print_fld_uint(FLD_PROTO, s->proto);
 
+#ifdef HAVE_PFSYNC_KEY
 	if (s->direction == PF_OUT) {
+		print_fld_host2(FLD_SRC, &s->key[PF_SK_WIRE],
+		    &s->key[PF_SK_STACK], 1, s->af);
+		print_fld_host2(FLD_DEST, &s->key[PF_SK_WIRE],
+		    &s->key[PF_SK_STACK], 0, s->af);
+	} else {
+		print_fld_host2(FLD_SRC, &s->key[PF_SK_STACK],
+		    &s->key[PF_SK_WIRE], 0, s->af);
+		print_fld_host2(FLD_DEST, &s->key[PF_SK_STACK],
+		    &s->key[PF_SK_WIRE], 1, s->af);
+	}
+#else
+	if (s->direction == PF_OUT) {
 		print_fld_host(FLD_SRC, &s->lan, s->af);
 		print_fld_host(FLD_DEST, &s->ext, s->af);
 	} else {
@@ -972,6 +1144,7 @@ print_state(pf_state_t * s, struct sc_ent * ent)
 	    (s->lan.port != s->gwy.port)) {
 		print_fld_host(FLD_GW, &s->gwy, s->af);
 	}
+#endif
 
 	if (s->direction == PF_OUT)
 		print_fld_str(FLD_DIR, "Out");
@@ -979,8 +1152,8 @@ print_state(pf_state_t * s, struct sc_ent * ent)
 		print_fld_str(FLD_DIR, "In");
 
 	print_fld_state(FLD_STATE, s->proto, src->state, dst->state);
-	print_fld_age(FLD_AGE, s->creation);
-	print_fld_age(FLD_EXP, s->expire);
+	print_fld_age(FLD_AGE, PF_TSTAMP(s->creation));
+	print_fld_age(FLD_EXP, PF_TSTAMP(s->expire));
 #ifdef HAVE_INOUT_COUNT
 	{
 		u_int64_t sz = COUNTER(s->bytes[0]) + COUNTER(s->bytes[1]);
@@ -988,18 +1161,18 @@ print_state(pf_state_t * s, struct sc_ent * ent)
 		print_fld_size(FLD_PKTS, COUNTER(s->packets[0]) +
 			       COUNTER(s->packets[1]));
 		print_fld_size(FLD_BYTES, sz);
-		print_fld_rate(FLD_SA, (s->creation > 0) ?
-			       ((double)sz/(double)s->creation) : -1);
+		print_fld_rate(FLD_SA, (s->creation) ?
+			       ((double)sz/PF_TSTAMP((double)s->creation)) : -1);
 	}
 #else
 	print_fld_size(FLD_PKTS, s->packets);
 	print_fld_size(FLD_BYTES, s->bytes);
-	print_fld_rate(FLD_SA, (s->creation > 0) ?
-		       ((double)s->bytes/(double)s->creation) : -1);
+	print_fld_rate(FLD_SA, (s->creation) ?
+		       ((double)s->bytes/PF_TSTAMP((double)s->creation)) : -1);
 
 #endif
 #ifdef HAVE_PFSYNC_STATE
-	print_fld_uint(FLD_RULE, s->rule);
+	print_fld_uint(FLD_RULE, ntohl(s->rule));
 #else
 #ifdef HAVE_RULE_NUMBER
 	print_fld_uint(FLD_RULE, s->rule.nr);
@@ -1475,8 +1648,12 @@ print_rule(struct pf_rule *pr)
 	print_fld_str(FLD_LABEL, pr->label);
 #endif
 #ifdef HAVE_RULE_STATES
+#ifdef HAVE_PFSYNC_KEY
+	print_fld_size(FLD_STATS, pr->states_tot);
+#else
 	print_fld_size(FLD_STATS, pr->states);
 #endif
+#endif
 
 #ifdef HAVE_INOUT_COUNT_RULES
 	print_fld_size(FLD_PKTS, pr->packets[0] + pr->packets[1]);
@@ -1729,12 +1912,19 @@ pfctl_insert_altq_node(struct pf_altq_node **root,
 			prev->next = node;
 		}
 	}
-	if (*root != node) {
-		struct pf_altq_node	*prev_flat = *root;
-		while (prev_flat->next_flat != NULL) {
-			prev_flat = prev_flat->next_flat;
-		}
-		prev_flat->next_flat = node;
+}
+
+void
+pfctl_set_next_flat(struct pf_altq_node *node, struct pf_altq_node *up)
+{
+	while (node) {
+		struct pf_altq_node *next = node->next ? node->next : up;
+		if (node->children) {
+			node->next_flat = node->children;
+			pfctl_set_next_flat(node->children, next);
+		} else
+			node->next_flat = next;
+		node = node->next;
 	}
 }
 
@@ -1747,6 +1937,7 @@ pfctl_update_qstats(struct pf_altq_node **root, int *i
 	u_int32_t		 nr;
 	struct queue_stats	 qstats;
 	u_int32_t		 nr_queues;
+	int			 ret = 0;
 
 	*inserts = 0;
 	memset(&pa, 0, sizeof(pa));
@@ -1757,13 +1948,15 @@ pfctl_update_qstats(struct pf_altq_node **root, int *i
 			  strerror(errno));
 		return (-1);
 	}
+
 	num_queues = nr_queues = pa.nr;
 	for (nr = 0; nr < nr_queues; ++nr) {
 		pa.nr = nr;
 		if (ioctl(pf_dev, DIOCGETALTQ, &pa)) {
 			msgprintf("Error Reading Queue (DIOCGETALTQ): %s",
 				  strerror(errno));
-			return (-1);
+			ret = -1;
+			break;
 		}
 		if (pa.altq.qid > 0) {
 			pq.nr = nr;
@@ -1773,7 +1966,8 @@ pfctl_update_qstats(struct pf_altq_node **root, int *i
 			if (ioctl(pf_dev, DIOCGETQSTATS, &pq)) {
 				msgprintf("Error Reading Queue (DIOCGETQSTATS): %s",
 					  strerror(errno));
-				return (-1);
+				ret = -1;
+				break;
 			}
 			qstats.valid = 1;
 			gettimeofday(&qstats.timestamp, NULL);
@@ -1794,7 +1988,10 @@ pfctl_update_qstats(struct pf_altq_node **root, int *i
 		else
 			--num_queues;
 	}
-	return (0);
+
+	pfctl_set_next_flat(*root, NULL);
+
+	return (ret);
 }
 
 void
