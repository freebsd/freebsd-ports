--- ng_ipacct/ng_ipacct.c.orig	2008-09-28 17:37:23.000000000 +0000
+++ ng_ipacct/ng_ipacct.c	2008-09-28 17:39:37.000000000 +0000
@@ -902,7 +902,11 @@
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
