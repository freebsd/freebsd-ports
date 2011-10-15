diff --git a/src/rx/FBSD/rx_knet.c b/src/rx/FBSD/rx_knet.c
index c6d2d84..ded3f7c 100644
--- a/src/rx/FBSD/rx_knet.c
+++ b/src/rx/FBSD/rx_knet.c
@@ -92,7 +92,11 @@ osi_StopListener(void)
     p = pfind(rxk_ListenerPid);
     if (p) {
 	afs_warn("osi_StopListener: rxk_ListenerPid %u\n", rxk_ListenerPid);
+#if (__FreeBSD_version >= 90004)
+	kern_psignal(p, SIGUSR1);
+#else
 	psignal(p, SIGUSR1);
+#endif
 	PROC_UNLOCK(p);
     } else
 	afs_warn("osi_StopListener: rxk_Listener not found (pid %u)\n",
