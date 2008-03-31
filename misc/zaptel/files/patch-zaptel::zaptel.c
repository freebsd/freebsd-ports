
$FreeBSD$

--- zaptel/zaptel.c.orig	2007-01-26 09:51:48.000000000 +0100
+++ zaptel/zaptel.c	2008-03-31 15:44:58.000000000 +0200
@@ -254,7 +254,11 @@
         while (1) {
                 if (kthread_must_exit) {
                         wakeup(cookie);
+#if (__FreeBSD_version >= 800002)
+                        kthread_exit();
+#else
                         kthread_exit(0);
+#endif
                 }
 
                 ZAP_LOCK(toselwakeup_lock);
@@ -396,7 +400,7 @@
 
 int schluffen(void *q)
 {
-	int rc = tsleep(q, PZERO | PCATCH, "schluffen", 0);
+	int rc = tsleep(q, PZERO | PCATCH, "schluffen", 10);
 	switch(rc)
 	{
 		case EINTR:
@@ -675,7 +679,11 @@
 	/* Free dev_info, if exist */
 	if(dev->si_drv2) free(dev->si_drv2, M_ZAP);
 	dev->si_drv2 = NULL;
+#if (__FreeBSD_version >= 700050)
+	destroy_dev_sched(dev);
+#else
 	destroy_dev(dev);	
+#endif
 	return res;
 }
 
@@ -1254,7 +1262,11 @@
 		ZAP_LOCK_INIT(toselwakeup_lock, "toselwakeup_lock");
 
 	        kthread_must_exit = 0;
+#if (__FreeBSD_version >= 800002)
+		if (kproc_create(selwakeup_thread_handler, (void *)toselwakeup, &kthread, 0, 0, "zt_selwakeup_thread"))
+#else
 		if (kthread_create(selwakeup_thread_handler, (void *)toselwakeup, &kthread, 0, 0, "zt_selwakeup_thread"))
+#endif
 		{
 			printf("Failed to create kthread\n");
 		}
