--- tunip.c.orig	2019-10-03 14:52:47 UTC
+++ tunip.c
@@ -1058,6 +1058,7 @@ void vpnc_doit(struct sa_block *s)
 	} else {
 		printf("VPNC started in foreground...\n");
 	}
+	tun_claim(s->tun_fd);
 	openlog("vpnc", LOG_PID | LOG_PERROR, LOG_DAEMON);
 	write_pidfile(pidfile);
 	
