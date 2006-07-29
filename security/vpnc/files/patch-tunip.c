Index: tunip.c
===================================================================
--- tunip.c	(revision 67)
+++ tunip.c	(working copy)
@@ -3,6 +3,7 @@
    Copyright (C) 2002      Geoffrey Keating
    Copyright (C) 2003-2005 Maurice Massar
    Copyright (C) 2004      Tomas Mraz
+   Copyright (C) 2006      Daniel Roethlisberger
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -776,7 +777,16 @@
 {
 	int sock;
 	struct pollfd pollfds[2];
+	int enable_keepalives;
+	int poll_timeout;
 
+	/* non-esp marker, nat keepalive payload (0xFF) */
+	char keepalive[5] = { 0x00, 0x00, 0x00, 0x00, 0xFF };
+
+	/* send keepalives if UDP encapsulation is enabled */
+	enable_keepalives = !strcmp(meth->name, "udpesp");
+	poll_timeout = enable_keepalives ? 20000 : -1;
+
 	pollfds[0].fd = tun_fd;
 	pollfds[0].events = POLLIN;
 	pollfds[1].fd = encap_get_fd(meth);
@@ -786,8 +796,16 @@
 		int presult;
 
 		do {
-			presult = poll(pollfds, sizeof(pollfds) / sizeof(pollfds[0]), -1);
-		} while (presult == -1 && errno == EINTR && !do_kill);
+			presult = poll(pollfds, sizeof(pollfds) / sizeof(pollfds[0]), poll_timeout);
+			if (presult == 0 && enable_keepalives) {
+				/* send nat keepalive packet */
+				if(sendto(meth->fd, keepalive, sizeof(keepalive), 0,
+					(struct sockaddr*)&peer->remote_sa->dest,
+					sizeof(peer->remote_sa->dest)) == -1) {
+					syslog(LOG_ERR, "sendto: %m");
+				}
+			}
+		} while ((presult == 0 || (presult == -1 && errno == EINTR)) && !do_kill);
 		if (presult == -1) {
 			syslog(LOG_ERR, "poll: %m");
 			continue;
