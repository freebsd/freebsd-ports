
$FreeBSD$

--- zaptel/zaptel.c.orig
+++ zaptel/zaptel.c
@@ -396,7 +396,7 @@
 
 int schluffen(void *q)
 {
-	int rc = tsleep(q, PZERO | PCATCH, "schluffen", 0);
+	int rc = tsleep(q, PZERO | PCATCH, "schluffen", 10);
 	switch(rc)
 	{
 		case EINTR:
@@ -675,7 +675,11 @@
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
 
