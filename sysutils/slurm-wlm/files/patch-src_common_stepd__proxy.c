--- src/common/stepd_proxy.c.orig	2026-01-15 20:26:01 UTC
+++ src/common/stepd_proxy.c
@@ -40,6 +40,7 @@
 #include "src/common/read_config.h"
 #include "src/common/slurm_protocol_api.h"
 #include "src/common/slurm_protocol_pack.h"
+#include "src/common/slurm_sockaddr.h"
 #include "src/common/stepd_api.h"
 #include "src/common/stepd_proxy.h"
 #include "src/common/xmalloc.h"
@@ -299,13 +300,14 @@ static int _stepd_connect_to_slurmd(void)
 static int _stepd_connect_to_slurmd(void)
 {
 	struct sockaddr_un slurmd_addr = { .sun_family = AF_UNIX };
-	size_t len;
+	socklen_t len;
 	int fd;
 
 	(void) snprintf(slurmd_addr.sun_path, sizeof(slurmd_addr.sun_path),
 			"%s/slurmd.socket", slurmd_spooldir);
 
-	len = strlen(slurmd_addr.sun_path) + 1 + sizeof(slurmd_addr.sun_family);
+	len = slurm_sockaddr_fixlen((struct sockaddr *)&slurmd_addr,
+				    (socklen_t)sizeof(slurmd_addr));
 
 	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
 		error("%s: socket() failed: %m", __func__);
