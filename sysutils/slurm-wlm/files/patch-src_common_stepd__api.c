--- src/common/stepd_api.c.orig	2024-05-21 17:19:51 UTC
+++ src/common/stepd_api.c
@@ -48,6 +48,7 @@
 #include <signal.h>
 #include <stdlib.h>
 #include <string.h>
+#include <stddef.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/time.h>
@@ -146,7 +147,7 @@ _step_connect(const char *directory, const char *noden
 	      slurm_step_id_t *step_id)
 {
 	int fd;
-	int len;
+	socklen_t len;
 	struct sockaddr_un addr;
 	char *name = NULL, *pos = NULL;
 	uint32_t stepid = step_id->step_id;
@@ -177,7 +178,15 @@ _step_connect(const char *directory, const char *noden
 	memset(&addr, 0, sizeof(addr));
 	addr.sun_family = AF_UNIX;
 	strlcpy(addr.sun_path, name, sizeof(addr.sun_path));
-	len = strlen(addr.sun_path) + 1 + sizeof(addr.sun_family);
+
+#if defined(__FreeBSD__)
+	/* Compute exact namelen from the populated path */
+	len = (socklen_t)SUN_LEN(&addr);
+	/* FreeBSD requires sun_len to match the exact length */
+	addr.sun_len = (uint8_t)len;
+#else
+	len = (socklen_t)(strlen(addr.sun_path) + 1 + sizeof(addr.sun_family));
+#endif
 
 	if (connect(fd, (struct sockaddr *) &addr, len) < 0) {
 		/* Can indicate race condition at step termination */
