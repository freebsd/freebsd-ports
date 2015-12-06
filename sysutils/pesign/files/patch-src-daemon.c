--- src/daemon.c.orig	2014-10-24 21:51:06.000000000 +0200
+++ src/daemon.c	2015-01-16 09:57:05.000000000 +0100
@@ -25,7 +25,6 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
-#include <sys/prctl.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
@@ -839,7 +838,7 @@ shutdown:
 			do_shutdown(ctx, nsockets, pollfds);
 			return 0;
 		}
-		rc = ppoll(pollfds, nsockets, NULL, NULL);
+		rc = poll(pollfds, nsockets, INFTIM);
 		if (should_exit != 0)
 			goto shutdown;
 		if (rc < 0) {
@@ -864,8 +863,8 @@ shutdown:
 
 			struct sockaddr_un remote;
 			socklen_t len = sizeof(remote);
-			pollfds[nsockets-1].fd = accept(pollfds[0].fd, &remote,
-							&len);
+			pollfds[nsockets-1].fd = accept(pollfds[0].fd,
+							(struct sockaddr *)&remote, &len);
 			pollfds[nsockets-1].events = POLLIN|POLLPRI|POLLHUP;
 			pollfds[nsockets-1].revents = pollfds[0].revents;
 		}
@@ -942,7 +941,7 @@ set_up_socket(context *ctx)
 		.sun_path = SOCKPATH,
 	};
 
-	int rc = bind(sd, &addr_un, sizeof(addr_un));
+	int rc = bind(sd, (struct sockaddr *)&addr_un, sizeof(addr_un));
 	if (rc < 0) {
 		ctx->backup_cms->log(ctx->backup_cms, ctx->priority|LOG_ERR,
 			"unable to bind to \"%s\": %m",
@@ -998,7 +997,7 @@ check_socket(context *ctx)
 
 		struct sockaddr_un remote;
 		socklen_t size = sizeof(remote);
-		rc = getpeername(sd, &remote, &size);
+		rc = getpeername(sd, (struct sockaddr *)&remote, &size);
 		if (rc < 0) {
 			close(sd);
 			return;
@@ -1159,8 +1158,6 @@ daemonize(cms_context *cms_ctx, char *ce
 		close(fd);
 	}
 
-	prctl(PR_SET_NAME, "pesignd", 0, 0, 0);
-
 	setsid();
 
 	if (do_fork) {
