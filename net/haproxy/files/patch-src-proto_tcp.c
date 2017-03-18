--- src/connection.c.orig	2017-03-18 18:06:14.328891000 +0300
+++ src/connection.c	2017-03-18 18:10:31.264762000 +0300
@@ -136,13 +136,17 @@ void conn_fd_handler(int fd)
 	 * have been released and the FD destroyed.
 	 */
 	if ((conn->flags & CO_FL_WAKE_DATA) &&
-	    ((conn->flags ^ flags) & CO_FL_CONN_STATE) &&
-	    conn->data->wake(conn) < 0)
+           (((conn->flags ^ flags) & CO_FL_CONN_STATE) ||
+            ((flags & CO_FL_HANDSHAKE) && !(conn->flags & CO_FL_HANDSHAKE))) &&
+           conn->data->wake(conn) < 0) {
 		return;
+       }
+
+       /* Now set the CO_FL_CONNECTED flag if the connection was just established. */
+
+       if (unlikely(!(conn->flags & (CO_FL_WAIT_L4_CONN | CO_FL_WAIT_L6_CONN | CO_FL_CONNECTED))))
+               conn->flags |= CO_FL_CONNECTED;
 
-	/* Last check, verify if the connection just established */
-	if (unlikely(!(conn->flags & (CO_FL_WAIT_L4_CONN | CO_FL_WAIT_L6_CONN | CO_FL_CONNECTED))))
-		conn->flags |= CO_FL_CONNECTED;
 
 	/* remove the events before leaving */
 	fdtab[fd].ev &= FD_POLL_STICKY;

--- include/types/connection.h
+++ include/types/connection.h
@@ -98,7 +98,7 @@ enum {
 
 	/* flags used to report connection status and errors */
 	CO_FL_ERROR         = 0x00100000,  /* a fatal error was reported     */
-	CO_FL_CONNECTED     = 0x00200000,  /* the connection is now established */
+	CO_FL_CONNECTED     = 0x00200000,  /* L4+L6 now ready ; extra handshakes may or may not exist */
 	CO_FL_WAIT_L4_CONN  = 0x00400000,  /* waiting for L4 to be connected */
 	CO_FL_WAIT_L6_CONN  = 0x00800000,  /* waiting for L6 to be connected (eg: SSL) */
 
