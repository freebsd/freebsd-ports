--- src/conmgr/con.c.orig	2026-01-15 20:26:01 UTC
+++ src/conmgr/con.c
@@ -59,6 +59,7 @@
 #include "src/common/slurm_protocol_api.h"
 #include "src/common/slurm_protocol_defs.h"
 #include "src/common/slurm_protocol_socket.h"
+#include "src/common/slurm_sockaddr.h"
 #include "src/common/slurm_time.h"
 #include "src/common/util-net.h"
 #include "src/common/xmalloc.h"
@@ -1029,6 +1030,7 @@ static int _add_unix_listener(conmgr_con_type_t type, 
 	slurm_addr_t addr = { 0 };
 	int fd = socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
 	int rc = EINVAL;
+	socklen_t bind_len = 0;
 
 	if (fd < 0)
 		fatal("%s: socket() failed: %m", __func__);
@@ -1045,9 +1047,11 @@ static int _add_unix_listener(conmgr_con_type_t type, 
 	if (unlink(unixsock) && (errno != ENOENT))
 		error("Error unlink(%s): %m", unixsock);
 
-	/* bind() will EINVAL if socklen=sizeof(addr) */
-	if ((rc = bind(fd, (const struct sockaddr *) &addr,
-		       sizeof(struct sockaddr_un))))
+	/* Ensure correct sockaddr length (and sun_len/sa_len where applicable) */
+	bind_len = slurm_sockaddr_fixlen((struct sockaddr *)&addr,
+					 (socklen_t)sizeof(addr));
+
+	if ((rc = bind(fd, (const struct sockaddr *)&addr, bind_len)))
 		fatal("%s: [%s] Unable to bind UNIX socket: %m",
 		      __func__, listen_on);
 
@@ -1059,7 +1063,7 @@ static int _add_unix_listener(conmgr_con_type_t type, 
 		      __func__, listen_on);
 
 	return add_connection(type, NULL, fd, -1, events, flags, &addr,
-			      sizeof(addr), true, unixsock, NULL, arg);
+			      bind_len, true, unixsock, NULL, arg);
 }
 
 static int _add_socket_listener(conmgr_con_type_t type,
@@ -1207,16 +1211,14 @@ extern int conmgr_create_connect_socket(conmgr_con_typ
 					void *arg)
 {
 	int fd = -1, rc = SLURM_ERROR;
-	//socklen_t bindlen = 0;
+	socklen_t connect_len = 0;
 
 	if (addr->ss_family == AF_UNIX) {
 		fd = socket(addr->ss_family, (SOCK_STREAM | SOCK_CLOEXEC), 0);
-		//bindlen = sizeof(struct sockaddr_un);
 	} else if ((addr->ss_family == AF_INET) ||
 		   (addr->ss_family == AF_INET6)) {
 		fd = socket(addr->ss_family, (SOCK_STREAM | SOCK_CLOEXEC),
 			    IPPROTO_TCP);
-		//bindlen = addrlen;
 	} else {
 		return EAFNOSUPPORT;
 	}
@@ -1233,9 +1235,12 @@ extern int conmgr_create_connect_socket(conmgr_con_typ
 
 	log_flag(CONMGR, "%s: [%pA(fd:%d)] attempting to connect() new socket",
 		 __func__, addr, fd);
+	/* Ensure correct sockaddr length (and sa_len/sin_len/sin6_len where applicable) */
+	connect_len = slurm_sockaddr_fixlen((struct sockaddr *)addr, addrlen);
 
+
 again:
-	if ((rc = connect(fd, (const struct sockaddr *) addr, addrlen))) {
+	if ((rc = connect(fd, (const struct sockaddr *) addr, connect_len))) {
 		rc = errno;
 
 		if (rc == EINTR) {
