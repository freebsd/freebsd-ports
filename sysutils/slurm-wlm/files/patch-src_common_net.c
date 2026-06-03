--- src/common/net.c.orig	2026-01-15 20:26:01 UTC
+++ src/common/net.c
@@ -81,6 +81,7 @@
 #include "src/common/log.h"
 #include "src/common/macros.h"
 #include "src/common/net.h"
+#include "src/common/slurm_sockaddr.h"
 #include "src/common/slurm_protocol_api.h"
 #include "src/common/util-net.h"
 #include "src/common/xmalloc.h"
@@ -108,6 +109,8 @@ int net_stream_listen(int *fd, uint16_t *port)
 	/* bind ephemeral port */
 	slurm_setup_addr(&sin, 0);
 
+	len = slurm_sockaddr_fixlen((struct sockaddr *)&sin, len);
+
 	if ((*fd = socket(sin.ss_family, SOCK_STREAM, IPPROTO_TCP)) < 0)
 		return -1;
 
@@ -259,7 +262,8 @@ static bool _is_port_ok(int s, uint16_t port, bool loc
 		return false;
 	}
 
-	if (bind(s, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
+	socklen_t alen = slurm_sockaddr_fixlen((struct sockaddr *)&addr, sizeof(addr));
+	if (bind(s, (struct sockaddr *) &addr, alen) < 0) {
 		log_flag(NET, "%s: bind() failed on port:%d fd:%d: %m",
 			 __func__, port, s);
 		return false;
