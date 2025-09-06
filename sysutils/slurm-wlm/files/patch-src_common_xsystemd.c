--- src/common/xsystemd.c.orig	2024-05-21 17:19:51 UTC
+++ src/common/xsystemd.c
@@ -36,6 +36,9 @@
 
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <string.h>
+#include <stdlib.h>
+#include <stddef.h>
 
 #include "src/common/log.h"
 #include "src/common/slurm_protocol_defs.h"
@@ -57,7 +60,12 @@ extern void xsystemd_change_mainpid(pid_t pid)
 	}
 
 	strlcpy(addr.sun_path, notify_socket, sizeof(addr.sun_path));
+#if defined(__FreeBSD__)
+	len = (socklen_t)SUN_LEN(&addr);
+	addr.sun_len = (uint8_t)len;
+#else
 	len = strlen(addr.sun_path) + 1 + sizeof(addr.sun_family);
+#endif
 
 	if ((fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
 		error("%s: socket() failed: %m", __func__);
