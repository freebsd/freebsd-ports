--- src/common/sack_api.c.orig	2026-01-15 20:26:01 UTC
+++ src/common/sack_api.c
@@ -43,6 +43,7 @@
 #include "src/common/pack.h"
 #include "src/common/sack_api.h"
 #include "src/common/slurm_protocol_api.h"
+#include "src/common/slurm_sockaddr.h"
 #include "src/common/xmalloc.h"
 
 #define SACK_CLUSTER_PATTERN "/run/slurm-%s/sack.socket"
@@ -64,14 +65,14 @@ static int _sack_try_connection(struct sockaddr_un *ad
 static int _sack_try_connection(struct sockaddr_un *addr)
 {
 	int fd;
-	size_t len = strlen(addr->sun_path) + 1 + sizeof(addr->sun_family);
+	socklen_t len = slurm_sockaddr_fixlen((struct sockaddr *)addr, (socklen_t)sizeof(*addr));
 
 	if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
 		debug3("%s: socket() failed: %m", __func__);
 		return -1;
 	}
 
-	if (connect(fd, (struct sockaddr *) addr, len) < 0) {
+	if (connect(fd, (struct sockaddr *)addr, len) < 0) {
 		debug3("%s: connect() failed for %s: %m",
 		      __func__, addr->sun_path);
 		close(fd);
