--- src/common/xsystemd.c.orig	2026-01-15 20:26:01 UTC
+++ src/common/xsystemd.c
@@ -45,6 +45,7 @@
 #include "src/common/read_config.h"
 #include "src/common/slurm_protocol_defs.h"
 #include "src/common/strlcpy.h"
+#include "src/common/slurm_sockaddr.h"
 #include "src/common/xmalloc.h"
 #include "src/common/xstring.h"
 
@@ -89,7 +90,6 @@ extern void xsystemd_change_mainpid(pid_t pid)
 {
 	char *notify_socket = getenv("NOTIFY_SOCKET");
 	char *payload = NULL;
-	size_t len = 0;
 	struct sockaddr_un addr = { .sun_family = AF_UNIX };
 	int fd = -1;
 
@@ -99,7 +99,8 @@ extern void xsystemd_change_mainpid(pid_t pid)
 	}
 
 	strlcpy(addr.sun_path, notify_socket, sizeof(addr.sun_path));
-	len = strlen(addr.sun_path) + 1 + sizeof(addr.sun_family);
+	socklen_t len = slurm_sockaddr_fixlen((struct sockaddr *)&addr,
+					      (socklen_t)sizeof(addr));
 
 	if ((fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
 		error("%s: socket() failed: %m", __func__);
