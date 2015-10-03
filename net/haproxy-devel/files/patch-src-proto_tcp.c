--- src/proto_tcp.c.orig	2015-10-01 14:53:25.738017000 +0300
+++ src/proto_tcp.c	2015-10-01 14:54:08.222037000 +0300
@@ -1456,7 +1456,7 @@ static enum act_return tcp_exec_action_s
 	 * network and has no effect on local net.
 	 */
 #ifdef IP_TTL
-	setsockopt(conn->t.sock.fd, SOL_IP, IP_TTL, &one, sizeof(one));
+	setsockopt(conn->t.sock.fd, IPPROTO_IP, IP_TTL, &one, sizeof(one));
 #endif
  out:
 	/* kill the stream if any */
