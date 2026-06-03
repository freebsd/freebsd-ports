--- ng_ipacct/ng_ipacct.c.orig	2021-03-14 18:52:22 UTC
+++ ng_ipacct/ng_ipacct.c
@@ -49,6 +49,9 @@ static const char rcs_id[] =
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/in_pcb.h>
+#if __FreeBSD_version >= 1400039
+#include <netinet/in_pcb_var.h>
+#endif
 #include <netinet/ip.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/ip_var.h>
@@ -980,7 +983,9 @@ pcb_get_cred(struct ip_acct_stream *r, struct inpcbinf
 #endif
 #endif
 	for (i = 0, ina = r->r_dst, port = r->r_dport; i < 2; i++) {
-#if __FreeBSD_version >= 700110
+#if __FreeBSD_version >= 1402502
+		pcb = in_pcblookup_local(pcbinfo, ina, port, RT_ALL_FIBS, 1, thread0.td_ucred);
+#elif __FreeBSD_version >= 700110
 		pcb = in_pcblookup_local(pcbinfo, ina, port, 1, NOCRED);
 #else
 		pcb = in_pcblookup_local(pcbinfo, ina, port, 1);
