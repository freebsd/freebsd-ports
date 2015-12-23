--- source3/client/dnsbrowse.c.orig	2015-07-21 09:47:49.000000000 +0000
+++ source3/client/dnsbrowse.c	2015-12-07 02:08:01.627022117 +0000
@@ -91,7 +91,7 @@
 		}
 	}
 
-	TALLOC_FREE(fdset);
+	TALLOC_FREE(ctx);
 	DNSServiceRefDeallocate(mdns_conn_sdref);
 }
 
@@ -168,7 +168,7 @@
 	for (;;)  {
 		int revents;
 
-		ret = poll_one_fd(mdnsfd, POLLIN|POLLHUP, &revents, 1000);
+		ret = poll_one_fd(mdnsfd, POLLIN|POLLHUP, 1000, &revents);
 		if (ret <= 0 && errno != EINTR) {
 			break;
 		}
