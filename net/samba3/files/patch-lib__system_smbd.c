--- lib/system_smbd.c.orig	Sun Sep 16 04:29:55 2007
+++ lib/system_smbd.c	Sun Sep 16 04:31:21 2007
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
