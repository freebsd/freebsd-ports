--- src/connection.c
+++ src/connection.c
@@ -131,6 +131,13 @@ void conn_fd_handler(int fd)
 	}
 
  leave:
+	/* Verify if the connection just established. The CO_FL_CONNECTED flag
+	 * being included in CO_FL_CONN_STATE, its change will be noticed by
+	 * the next block and be used to wake up the data layer.
+	 */
+	if (unlikely(!(conn->flags & (CO_FL_WAIT_L4_CONN | CO_FL_WAIT_L6_CONN | CO_FL_CONNECTED))))
+		conn->flags |= CO_FL_CONNECTED;
+
 	/* The wake callback may be used to process a critical error and abort the
 	 * connection. If so, we don't want to go further as the connection will
 	 * have been released and the FD destroyed.
@@ -140,10 +147,6 @@ void conn_fd_handler(int fd)
 	    conn->data->wake(conn) < 0)
 		return;
 
-	/* Last check, verify if the connection just established */
-	if (unlikely(!(conn->flags & (CO_FL_WAIT_L4_CONN | CO_FL_WAIT_L6_CONN | CO_FL_CONNECTED))))
-		conn->flags |= CO_FL_CONNECTED;
-
 	/* remove the events before leaving */
 	fdtab[fd].ev &= FD_POLL_STICKY;
 
--- src/stream_interface.c
+++ src/stream_interface.c
@@ -563,7 +563,8 @@ static int si_conn_wake_cb(struct connection *conn)
 	if (conn->flags & CO_FL_ERROR)
 		si->flags |= SI_FL_ERR;
 
-	if (unlikely(!(conn->flags & (CO_FL_WAIT_L4_CONN | CO_FL_WAIT_L6_CONN | CO_FL_CONNECTED)))) {
+	if ((si->state < SI_ST_EST) &&
+	    (conn->flags & (CO_FL_CONNECTED | CO_FL_HANDSHAKE)) == CO_FL_CONNECTED) {
 		si->exp = TICK_ETERNITY;
 		oc->flags |= CF_WRITE_NULL;
 	}
--- include/types/connection.h
+++ include/types/connection.h
@@ -95,15 +95,15 @@ enum {
 	CO_FL_SOCK_RD_SH    = 0x00040000,  /* SOCK layer was notified about shutr/read0 */
 	CO_FL_SOCK_WR_SH    = 0x00080000,  /* SOCK layer asked for shutw */
 
-	/* flags used to report connection status and errors */
+	/* flags used to report connection errors or other closing conditions */
 	CO_FL_ERROR         = 0x00100000,  /* a fatal error was reported     */
-	CO_FL_CONNECTED     = 0x00200000,  /* the connection is now established */
+	CO_FL_NOTIFY_DATA   = 0x001F0000,  /* any shut/error flags above needs to be reported */
+
+	/* flags used to report connection status updates */
+	CO_FL_CONNECTED     = 0x00200000,  /* L4+L6 now ready ; extra handshakes may or may not exist */
 	CO_FL_WAIT_L4_CONN  = 0x00400000,  /* waiting for L4 to be connected */
 	CO_FL_WAIT_L6_CONN  = 0x00800000,  /* waiting for L6 to be connected (eg: SSL) */
 
-	/* synthesis of the flags above */
-	CO_FL_CONN_STATE    = 0x00FF0000,  /* all shut/connected flags */
-
 	/*** All the flags below are used for connection handshakes. Any new
 	 * handshake should be added after this point, and CO_FL_HANDSHAKE
 	 * should be updated.
diff --git a/src/connection.c b/src/connection.c
index 1e4c9aa..3629094 100644
--- src/connection.c
+++ src/connection.c
@@ -99,19 +99,21 @@ void conn_fd_handler(int fd)
 	 */
 	if (conn->xprt && fd_recv_ready(fd) &&
 	    ((conn->flags & (CO_FL_DATA_RD_ENA|CO_FL_WAIT_ROOM|CO_FL_ERROR|CO_FL_HANDSHAKE)) == CO_FL_DATA_RD_ENA)) {
-		/* force detection of a flag change : it's impossible to have both
-		 * CONNECTED and WAIT_CONN so we're certain to trigger a change.
+		/* force reporting of activity by clearing the previous flags :
+		 * we'll have at least ERROR or CONNECTED at the end of an I/O,
+		 * both of which will be detected below.
 		 */
-		flags = CO_FL_WAIT_L4_CONN | CO_FL_CONNECTED;
+		flags = 0;
 		conn->data->recv(conn);
 	}
 
 	if (conn->xprt && fd_send_ready(fd) &&
 	    ((conn->flags & (CO_FL_DATA_WR_ENA|CO_FL_WAIT_DATA|CO_FL_ERROR|CO_FL_HANDSHAKE)) == CO_FL_DATA_WR_ENA)) {
-		/* force detection of a flag change : it's impossible to have both
-		 * CONNECTED and WAIT_CONN so we're certain to trigger a change.
+		/* force reporting of activity by clearing the previous flags :
+		 * we'll have at least ERROR or CONNECTED at the end of an I/O,
+		 * both of which will be detected below.
 		 */
-		flags = CO_FL_WAIT_L4_CONN | CO_FL_CONNECTED;
+		flags = 0;
 		conn->data->send(conn);
 	}
 
@@ -129,21 +131,30 @@ void conn_fd_handler(int fd)
 		if (!tcp_connect_probe(conn))
 			goto leave;
 	}
-
  leave:
-	/* Verify if the connection just established. The CO_FL_CONNECTED flag
-	 * being included in CO_FL_CONN_STATE, its change will be noticed by
-	 * the next block and be used to wake up the data layer.
-	 */
+	/* Verify if the connection just established. */
 	if (unlikely(!(conn->flags & (CO_FL_WAIT_L4_CONN | CO_FL_WAIT_L6_CONN | CO_FL_CONNECTED))))
 		conn->flags |= CO_FL_CONNECTED;
 
-	/* The wake callback may be used to process a critical error and abort the
-	 * connection. If so, we don't want to go further as the connection will
-	 * have been released and the FD destroyed.
+	/* The wake callback is normally used to notify the data layer about
+	 * data layer activity (successful send/recv), connection establishment,
+	 * shutdown and fatal errors. We need to consider the following
+	 * situations to wake up the data layer :
+	 *  - change among the CO_FL_NOTIFY_DATA flags :
+	 *      {DATA,SOCK}_{RD,WR}_SH, ERROR,
+	 *  - absence of any of {L4,L6}_CONN and CONNECTED, indicating the
+	 *    end of handshake and transition to CONNECTED
+	 *  - raise of CONNECTED with HANDSHAKE down
+	 *  - end of HANDSHAKE with CONNECTED set
+	 *  - regular data layer activity
+	 *
+	 * Note that the wake callback is allowed to release the connection and
+	 * the fd (and return < 0 in this case).
 	 */
 	if ((conn->flags & CO_FL_WAKE_DATA) &&
-	    ((conn->flags ^ flags) & CO_FL_CONN_STATE) &&
+	    (((conn->flags ^ flags) & CO_FL_NOTIFY_DATA) ||
+	     ((flags & (CO_FL_CONNECTED|CO_FL_HANDSHAKE)) != CO_FL_CONNECTED &&
+	      (conn->flags & (CO_FL_CONNECTED|CO_FL_HANDSHAKE)) == CO_FL_CONNECTED)) &&
 	    conn->data->wake(conn) < 0)
 		return;
 
