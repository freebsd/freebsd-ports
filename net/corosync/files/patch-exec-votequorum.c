--- exec/votequorum.c.orig	2015-06-22 14:03:28 UTC
+++ exec/votequorum.c
@@ -893,7 +893,7 @@ static void update_ev_tracking_barrier(u
 		log_printf(LOGSYS_LEVEL_WARNING,
 			   "Unable to update ev_tracking_barrier on disk data!!!");
 	}
-	fdatasync(ev_tracking_fd);
+	fsync(ev_tracking_fd);
 
 	LEAVE();
 }
