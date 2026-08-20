--- src/imap/imap-client-hibernate.c.orig	2026-08-05 21:51:45 UTC
+++ src/imap/imap-client-hibernate.c
@@ -62,7 +62,8 @@ static void imap_hibernate_write_cmd(struct client *cl
 	str_append_tabescaped(cmd, user->set->unexpanded_mail_log_prefix);
 	str_printfa(cmd, "\tidle_notify_interval=%u",
 		    client->set->imap_idle_notify_interval);
-	if (fstat(client->fd_in, &peer_st) == 0) {
+	if (fstat(client->fd_in, &peer_st) == 0 &&
+	    peer_st.st_dev != (dev_t)-1) {
 		str_printfa(cmd, "\tpeer_dev_major=%lu\tpeer_dev_minor=%lu\tpeer_ino=%llu",
 			    (unsigned long)major(peer_st.st_dev),
 			    (unsigned long)minor(peer_st.st_dev),
