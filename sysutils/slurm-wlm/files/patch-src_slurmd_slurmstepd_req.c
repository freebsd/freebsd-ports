--- src/slurmd/slurmstepd/req.c.orig	2026-01-15 20:26:01 UTC
+++ src/slurmd/slurmstepd/req.c
@@ -58,6 +58,7 @@
 #include "src/common/proc_args.h"
 #include "src/common/slurm_protocol_defs.h"
 #include "src/common/slurm_protocol_pack.h"
+#include "src/common/slurm_sockaddr.h"
 #include "src/common/stepd_api.h"
 #include "src/common/stepd_proxy.h"
 #include "src/common/strlcpy.h"
@@ -135,7 +136,7 @@ _create_socket(const char *name)
 _create_socket(const char *name)
 {
 	int fd;
-	int len;
+	socklen_t len;
 	struct sockaddr_un addr;
 
 	/*
@@ -156,7 +157,8 @@ _create_socket(const char *name)
 	memset(&addr, 0, sizeof(addr));
 	addr.sun_family = AF_UNIX;
 	strlcpy(addr.sun_path, name, sizeof(addr.sun_path));
-	len = strlen(addr.sun_path)+1 + sizeof(addr.sun_family);
+	len = slurm_sockaddr_fixlen((struct sockaddr *)&addr,
+				    (socklen_t)sizeof(addr));
 
 	/* bind the name to the descriptor */
 	if (bind(fd, (struct sockaddr *) &addr, len) < 0) {
@@ -348,12 +350,12 @@ static int _msg_socket_accept(eio_obj_t *obj, list_t *
 {
 	int fd, *param = NULL;
 	struct sockaddr_un addr;
-	int len = sizeof(addr);
+	socklen_t len = sizeof(addr);
 
 	debug3("Called _msg_socket_accept");
 
 	while ((fd = accept4(obj->fd, (struct sockaddr *) &addr,
-			    (socklen_t *) &len, SOCK_CLOEXEC)) < 0) {
+			    &len, SOCK_CLOEXEC)) < 0) {
 		if (errno == EINTR)
 			continue;
 		if ((errno == EAGAIN) ||
