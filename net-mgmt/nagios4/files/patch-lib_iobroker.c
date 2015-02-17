--- lib/iobroker.c.orig	2014-08-12 15:00:01 UTC
+++ lib/iobroker.c
@@ -415,11 +415,11 @@ int iobroker_poll(iobroker_set *iobs, in
 			iobs->pfd[p].events = POLLIN;
 			p++;
 		}
-		nfds = poll(iobs->pfd, iobs->num_fds, timeout);
+		nfds = poll(iobs->pfd, p, timeout);
 		if (nfds < 0) {
 			return IOBROKER_ELIB;
 		}
-		for (i = 0; i < iobs->num_fds; i++) {
+		for (i = 0; i < p; i++) {
 			iobroker_fd *s;
 			if ((iobs->pfd[i].revents & POLLIN) != POLLIN) {
 				continue;
