--- lib/event.c.orig	2024-09-12 07:46:05 UTC
+++ lib/event.c
@@ -571,8 +571,9 @@ struct event_loop *event_master_create(const char *nam
 	}
 
 	if (rv->fd_limit > STUPIDLY_LARGE_FD_SIZE) {
-		zlog_warn("FD Limit set: %u is stupidly large.  Is this what you intended?  Consider using --limit-fds also limiting size to %u",
-			  rv->fd_limit, STUPIDLY_LARGE_FD_SIZE);
+		if (frr_is_daemon())
+			zlog_warn("FD Limit set: %u is stupidly large.  Is this what you intended?  Consider using --limit-fds also limiting size to %u",
+				  rv->fd_limit, STUPIDLY_LARGE_FD_SIZE);
 
 		rv->fd_limit = STUPIDLY_LARGE_FD_SIZE;
 	}
