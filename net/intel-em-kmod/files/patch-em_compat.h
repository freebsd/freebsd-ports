--- em_compat.h.orig	2020-04-08 22:13:17.000000000 +0700
+++ em_compat.h	2026-05-24 15:21:37.852854000 +0700
@@ -43,6 +43,11 @@
 #include <net/if_var.h>
 #include <net/if_vlan_var.h>
 
+/* Forward compatibility for 15+ */
+#if __FreeBSD_version >= 1500000
+void if_etherbpfmtap(if_t ifp, struct mbuf *m);
+#endif
+
 /* Backward compatibility for pre-11 */
 #if __FreeBSD_version < 1100000
 
