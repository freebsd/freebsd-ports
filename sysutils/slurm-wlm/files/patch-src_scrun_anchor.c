--- src/scrun/anchor.c.orig	2026-06-09 20:26:02 UTC
+++ src/scrun/anchor.c
@@ -63,6 +63,7 @@
 #include "src/common/pack.h"
 #include "src/common/read_config.h"
 #include "src/common/setproctitle.h"
+#include "src/common/slurm_sockaddr.h"
 #include "src/common/spank.h"
 #include "src/common/uid.h"
 #include "src/common/xassert.h"
@@ -653,6 +654,7 @@ static void _queue_send_console_socket(void)
 	struct sockaddr_un addr = {
 		.sun_family = AF_UNIX,
 	};
+	socklen_t addrlen;
 	int fd = socket(AF_UNIX, SOCK_STREAM, 0);
 
 	fd_set_nonblocking(fd);
@@ -663,13 +665,15 @@ static void _queue_send_console_socket(void)
 		fatal("console socket address too long: %s",
 		      state.console_socket);
 
-	if ((connect(fd, (struct sockaddr *) &addr, sizeof(addr))) < 0)
+	addrlen = slurm_sockaddr_fixlen((struct sockaddr *)&addr,
+					(socklen_t)sizeof(addr));
+	if ((connect(fd, (struct sockaddr *) &addr, addrlen)) < 0)
 		fatal("%s: [%s] Unable to connect() to console socket: %m",
 		      __func__, addr.sun_path);
 
 	if ((rc = conmgr_process_fd(CON_TYPE_RAW, &conmgr_timeouts_disabled, fd,
 				    fd, &events, CON_FLAG_NONE,
-				    (slurm_addr_t *) &addr, sizeof(addr), NULL,
+				    (slurm_addr_t *) &addr, addrlen, NULL,
 				    NULL)))
 		fatal("%s: [%s] unable to initialize console socket: %s",
 		      __func__, addr.sun_path, slurm_strerror(rc));
