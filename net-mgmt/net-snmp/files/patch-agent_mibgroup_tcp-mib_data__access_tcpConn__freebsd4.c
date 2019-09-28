--- agent/mibgroup/tcp-mib/data_access/tcpConn_freebsd4.c.orig	2018-07-16 14:33:40 UTC
+++ agent/mibgroup/tcp-mib/data_access/tcpConn_freebsd4.c
@@ -163,7 +163,11 @@ _load(netsnmp_container *container, u_int load_flags)
 #else
 	xig = (struct xinpgen *) ((char *) xig + xig->xig_len);
 #endif
+#if __FreeBSD_version >= 1200026
+	state = StateMap[pcb.t_state];
+#else
 	state = StateMap[pcb.xt_tp.t_state];
+#endif
 
 	if (load_flags) {
 	    if (state == TCPCONNECTIONSTATE_LISTEN) {
@@ -223,6 +227,8 @@ _load(netsnmp_container *container, u_int load_flags)
         entry->arbitrary_index = CONTAINER_SIZE(container) + 1;
         CONTAINER_INSERT(container, entry);
     }
+
+    free(tcpcb_buf);
 
     free(tcpcb_buf);
 
