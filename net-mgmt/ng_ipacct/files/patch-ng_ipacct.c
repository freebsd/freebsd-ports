--- ng_ipacct/ng_ipacct.c.orig	2015-03-16 13:38:23.000000000 +0700
+++ ng_ipacct/ng_ipacct.c	2015-03-16 13:46:21.000000000 +0700
@@ -965,7 +965,11 @@ pcb_get_cred(struct ip_acct_stream *r, s
 	int i;
 	uid_t res;
 
+#if __FreeBSD_version < 900039
+	INP_INFO_RLOCK(pcbinfo);
+#else
 	INP_HASH_RLOCK(pcbinfo);
+#endif
 	for (i = 0, ina = r->r_dst, port = r->r_dport; i < 2; i++) {
 #if __FreeBSD_version >= 700110
 		pcb = in_pcblookup_local(pcbinfo, ina, port, 1, NOCRED);
@@ -984,6 +988,10 @@ pcb_get_cred(struct ip_acct_stream *r, s
 	    (pcb->inp_socket != NULL) && (pcb->inp_socket->so_cred != NULL)) {
 		res = pcb->inp_socket->so_cred->cr_uid;
 	}
+#if __FreeBSD_version < 900039
+	INP_INFO_RUNLOCK(pcbinfo);
+#else
 	INP_HASH_RUNLOCK(pcbinfo);
+#endif
 	return res;
 }
