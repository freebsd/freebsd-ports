--- src/proto_tcp.c.orig	2017-02-28 11:59:23.000000000 +0300
+++ src/proto_tcp.c	2017-03-12 11:55:08.528932000 +0300
@@ -474,16 +474,10 @@ int tcp_connect_server(struct connection
 	if (global.tune.server_rcvbuf)
                 setsockopt(fd, SOL_SOCKET, SO_RCVBUF, &global.tune.server_rcvbuf, sizeof(global.tune.server_rcvbuf));
 
-	if (connect(fd, (struct sockaddr *)&conn->addr.to, get_addr_len(&conn->addr.to)) == -1) {
-		if (errno == EINPROGRESS || errno == EALREADY) {
-			/* common case, let's wait for connect status */
-			conn->flags |= CO_FL_WAIT_L4_CONN;
-		}
-		else if (errno == EISCONN) {
-			/* should normally not happen but if so, indicates that it's OK */
-			conn->flags &= ~CO_FL_WAIT_L4_CONN;
-		}
-		else if (errno == EAGAIN || errno == EADDRINUSE || errno == EADDRNOTAVAIL) {
+	if ((connect(fd, (struct sockaddr *)&conn->addr.to, get_addr_len(&conn->addr.to)) == -1) &&
+	    (errno != EINPROGRESS) && (errno != EALREADY) && (errno != EISCONN)) {
+
+		if (errno == EAGAIN || errno == EADDRINUSE || errno == EADDRNOTAVAIL) {
 			char *msg;
 			if (errno == EAGAIN || errno == EADDRNOTAVAIL) {
 				msg = "no free ports";
@@ -520,10 +514,6 @@ int tcp_connect_server(struct connection
 			return SF_ERR_SRVCL;
 		}
 	}
-	else {
-		/* connect() == 0, this is great! */
-		conn->flags &= ~CO_FL_WAIT_L4_CONN;
-	}
 
 	conn->flags |= CO_FL_ADDR_TO_SET;
 
@@ -533,6 +523,7 @@ int tcp_connect_server(struct connection
 
 	conn_ctrl_init(conn);       /* registers the FD */
 	fdtab[fd].linger_risk = 1;  /* close hard if needed */
+	conn_sock_want_send(conn);  /* for connect status */
 
 	if (conn_xprt_init(conn) < 0) {
 		conn_force_close(conn);
@@ -540,17 +531,6 @@ int tcp_connect_server(struct connection
 		return SF_ERR_RESOURCE;
 	}
 
-	if (conn->flags & (CO_FL_HANDSHAKE | CO_FL_WAIT_L4_CONN)) {
-		conn_sock_want_send(conn);  /* for connect status, proxy protocol or SSL */
-	}
-	else {
-		/* If there's no more handshake, we need to notify the data
-		 * layer when the connection is already OK otherwise we'll have
-		 * no other opportunity to do it later (eg: health checks).
-		 */
-		data = 1;
-	}
-
 	if (data)
 		conn_data_want_send(conn);  /* prepare to send data if any */
 
