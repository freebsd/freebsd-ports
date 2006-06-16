--- dazuko_freebsd.c	Wed Jun 14 20:14:51 2006
+++ dazuko_freebsd.c	Wed Jun 14 20:15:36 2006
@@ -1580,7 +1580,7 @@
 	freebsd_setupid(&xp_id, uio->uio_procp);
 
 	/* return dev_major if process is not registered */
-	if (!dazuko_is_our_daemon(&xp_id, NULL))
+	if (!dazuko_is_our_daemon(&xp_id, NULL, NULL))
 		return read_dev_major(uio);
 
 	return 0;
