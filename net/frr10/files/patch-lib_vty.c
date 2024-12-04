--- lib/vty.c.orig	2024-11-12 16:20:46 UTC
+++ lib/vty.c
@@ -43,6 +43,7 @@
 #include "northbound_cli.h"
 #include "printfrr.h"
 #include "json.h"
+#include "sockopt.h"
 
 #include <arpa/telnet.h>
 #include <termios.h>
@@ -352,7 +353,7 @@ int vty_out(struct vty *vty, const char *format, ...)
 		 * put the data of collective vty->obuf Linked List items on the
 		 * socket and free the vty->obuf data.
 		 */
-		if (vty->vty_buf_size_accumulated >= VTY_MAX_INTERMEDIATE_FLUSH) {
+		if (vty->vty_buf_size_accumulated >= vty->buf_size_intermediate) {
 			vty->vty_buf_size_accumulated = 0;
 			vtysh_flush(vty);
 		}
@@ -2157,15 +2158,15 @@ static void vtysh_accept(struct event *thread)
 	 * Increasing the SEND socket buffer size so that the socket can hold
 	 * before sending it to VTY shell.
 	 */
-	ret = setsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char *)&sndbufsize,
-			 sizeof(sndbufsize));
-	if (ret < 0) {
+	ret = setsockopt_so_sendbuf(sock, sndbufsize);
+	if (ret <= 0) {
 		flog_err(EC_LIB_SOCKET,
 			 "Cannot set socket %d send buffer size, %s", sock,
 			 safe_strerror(errno));
 		close(sock);
 		return;
 	}
+
 	set_cloexec(sock);
 
 #ifdef VTYSH_DEBUG
@@ -2173,6 +2174,13 @@ static void vtysh_accept(struct event *thread)
 #endif /* VTYSH_DEBUG */
 
 	vty = vty_new();
+
+	vty->buf_size_set = ret;
+	if (vty->buf_size_set < VTY_MAX_INTERMEDIATE_FLUSH)
+		vty->buf_size_intermediate = vty->buf_size_set / 2;
+	else
+		vty->buf_size_intermediate = VTY_MAX_INTERMEDIATE_FLUSH;
+
 	vty->fd = sock;
 	vty->wfd = sock;
 	vty->type = VTY_SHELL_SERV;
