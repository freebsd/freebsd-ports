--- dev/ptx/ptx_proc.c.orig	2011-07-18 06:48:32.000000000 +0900
+++ dev/ptx/ptx_proc.c	2011-07-18 06:53:27.000000000 +0900
@@ -23,8 +23,13 @@
 int
 ptx_proc_start(struct ptx_softc *scp)
 {
+#if (__FreeBSD_version < 800000)
+	int err = kthread_create(ptx_daemon, scp, &scp->ptxdaemon,
+	    RFTHREAD, 0, "ptxdaemon");
+#else
 	int err = kthread_add(ptx_daemon, scp, NULL,
 	    &scp->ptxdaemon, RFTHREAD, 0, "ptxdaemon");
+#endif
 	if (err) {
 		device_printf(scp->device, "ptx_proc_start: kthread_add retured %d\n", err);
 		return ENXIO;
@@ -81,7 +86,11 @@
 		ptx_pause("ptxdmn", MSTOTICK(1));
 	}
 
+#if (__FreeBSD_version < 800000)
+	kthread_exit(0);
+#else
 	kthread_exit();
+#endif
 }
 
 static void
