--- em_compat.c.orig	2020-04-08 22:13:17.000000000 +0700
+++ em_compat.c	2026-05-24 15:19:17.203086000 +0700
@@ -30,6 +30,17 @@
 
 #include "em_compat.h"
 
+/* Forward compatibility for post-15 */
+#if __FreeBSD_version >= 1500000
+
+void
+if_etherbpfmtap(if_t ifh, struct mbuf *m)
+{
+	ether_bpf_mtap_if(ifh, m);
+}
+
+#endif
+
 /* Backward compatibility for pre-11 */
 #if __FreeBSD_version < 1100000
 
