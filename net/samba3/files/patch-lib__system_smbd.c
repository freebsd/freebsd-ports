--- ./lib/system_smbd.c.orig	2009-01-19 10:40:09.000000000 +0000
+++ ./lib/system_smbd.c	2009-01-20 15:50:59.000000000 +0000
@@ -104,12 +104,10 @@
 
 	restore_re_gid();
 
-	if (sys_setgroups(ngrp_saved, gids_saved) != 0) {
+	if (sys_setgroups(gid, ngrp_saved, gids_saved) != 0) {
 		/* yikes! */
 		DEBUG(0,("ERROR: getgrouplist: failed to reset group list!\n"));
-		smb_panic("getgrouplist: failed to reset group list!\n");
-		free(gids_saved);
-		return -1;
+		smb_panic("getgrouplist: failed to reset group list!");
 	}
 
 	free(gids_saved);
