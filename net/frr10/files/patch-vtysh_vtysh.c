--- vtysh/vtysh.c.orig	2024-11-12 16:20:46 UTC
+++ vtysh/vtysh.c
@@ -39,6 +39,7 @@
 #include "frrstr.h"
 #include "json.h"
 #include "ferr.h"
+#include "sockopt.h"
 
 DEFINE_MTYPE_STATIC(MVTYSH, VTYSH_CMD, "Vtysh cmd copy");
 
@@ -4694,9 +4695,8 @@ static int vtysh_connect(struct vtysh_client *vclient)
 	 * Increasing the RECEIVE socket buffer size so that the socket can hold
 	 * after receving from other process.
 	 */
-	ret = setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char *)&rcvbufsize,
-			 sizeof(rcvbufsize));
-	if (ret < 0) {
+	ret = setsockopt_so_recvbuf(sock, rcvbufsize);
+	if (ret <= 0) {
 #ifdef DEBUG
 		fprintf(stderr, "Cannot set socket %d rcv buffer size, %s\n",
 			sock, safe_strerror(errno));
