--- agent/mibgroup/tcp-mib/data_access/tcpConn_freebsd4.c.orig	2017-03-15 18:15:07.000000000 +0000
+++ agent/mibgroup/tcp-mib/data_access/tcpConn_freebsd4.c	2017-03-15 18:15:07.000000000 +0000
@@ -163,7 +163,11 @@
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
@@ -215,6 +219,8 @@
         entry->arbitrary_index = CONTAINER_SIZE(container) + 1;
         CONTAINER_INSERT(container, entry);
     }
+
+    free(tcpcb_buf);
 
     if(rc<0)
         return rc;
