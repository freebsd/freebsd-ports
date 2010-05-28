--- relayd/check_icmp.c.orig	2009-08-07 13:32:54.000000000 +0200
+++ relayd/check_icmp.c	2010-05-27 11:22:12.631744485 +0200
@@ -150,7 +150,7 @@
 			if (((struct sockaddr *)&host->conf.ss)->sa_family !=
 			    cie->af)
 				continue;
-			if (!(host->flags & F_CHECK_DONE)) {
+			if (!(host->flags & (F_CHECK_DONE|F_DISABLE))) {
 				host->up = HOST_DOWN;
 				hce_notify_done(host, he);
 			}
