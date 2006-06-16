--- dazuko_freebsd5.c	Wed Jun 14 20:10:08 2006
+++ dazuko_freebsd5.c	Wed Jun 14 20:11:55 2006
@@ -1643,7 +1643,7 @@
 	freebsd5_setupid(&xp_id, uio->uio_td);
 
 	/* return dev_major if process is not registered */
-	if (!dazuko_is_our_daemon(&xp_id, NULL))
+	if (!dazuko_is_our_daemon(&xp_id, NULL, NULL))
 		return read_dev_major(uio);
 
 	return 0;
