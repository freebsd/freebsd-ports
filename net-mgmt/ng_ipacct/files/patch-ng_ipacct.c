--- ng_ipacct/ng_ipacct.c.orig	2006-12-05 23:46:04.000000000 +0300
+++ ng_ipacct/ng_ipacct.c	2013-08-13 16:21:16.000000000 +0400
@@ -140,9 +140,6 @@
 struct ipacct_hook {
 	hook_p  		hook;
 	node_p			node;
-#if __FreeBSD_version >= 503000
-    struct mtx      h_mtx;         /* protects hook data */
-#endif
 	struct ip_acct_hash  	*active;	/* active database */
 	struct ip_acct_hash	*checked;	/* checkpointed database */
 	struct ng_ipacct_hinfo	hi;		/* hook info */
@@ -242,9 +239,6 @@
 
 	if (!strncmp(name + strlen(name) - 3, "_in", 3))
 		hip->hi.hi_flags |= HI_INCOMING_HOOK;
-#if __FreeBSD_version >= 503000
-    mtx_init(&hip->h_mtx, "ng_ipacct hash", NULL, MTX_DEF);
-#endif
 	NG_HOOK_SET_PRIVATE(hook, hip);
 	hip->hi.hi_debug = 0;
 #ifdef VERBOSE
@@ -531,13 +525,7 @@
 	if (!error) {
 		Dbg_print(DBG_DLT, ("IP packet, m_pkthdr.len = %d, m_len = %d\n", 
 			      m->m_pkthdr.len, m->m_len));
-#if __FreeBSD_version >= 503000
-        mtx_lock(&hip->h_mtx);
-#endif
 		error = ip_account_add(hip, &m);
-#if __FreeBSD_version >= 503000
-        mtx_unlock(&hip->h_mtx);
-#endif
 	}
 
 #if __FreeBSD_version >= 503000
@@ -581,9 +569,6 @@
 
 	ip_account_stop(hip);
 	NG_HOOK_SET_PRIVATE(hook, NULL);
-#if __FreeBSD_version >= 503000
-    mtx_destroy(&hip->h_mtx);
-#endif
 	FREE(hip, M_NETGRAPH);
 #ifdef VERBOSE
 	printf("NG_ipacct: disconnect hook %s\n", NG_HOOK_NAME(hook));
@@ -902,7 +899,11 @@
 	int		i;
 
 	for (i = 0, ina = r->r_dst, port = r->r_dport; i < 2; i++) {
+#if __FreeBSD_version >= 700110
+	    pcb = in_pcblookup_local(pcbinfo, ina, port, 1, NOCRED);
+#else
 	    pcb = in_pcblookup_local(pcbinfo, ina, port, 1);
+#endif
 	    if ((pcb != NULL) &&
 		(pcb->inp_laddr.s_addr == ina.s_addr)) {
 		break;
