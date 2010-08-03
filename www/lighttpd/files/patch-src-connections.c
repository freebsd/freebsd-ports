--- src/connections.c.orig
+++ src/connections.c
@@ -310,6 +310,8 @@ static int connection_handle_read_ssl(server *srv, connection *con) {
 		/* the other end close the connection -> KEEP-ALIVE */
 
 		return -2;
+	} else {
+		joblist_append(srv, con);
 	}
 
 	return 0;
@@ -320,6 +322,7 @@ static int connection_handle_read_ssl(server *srv, connection *con) {
 #endif
 }
 
+/* 0: everything ok, -1: error, -2: con closed */
 static int connection_handle_read(server *srv, connection *con) {
 	int len;
 	buffer *b;
@@ -1180,15 +1183,20 @@ static handler_t connection_handle_fdevent(void *s, void *context, int revents)
 
 	joblist_append(srv, con);
 
-	if (revents & FDEVENT_IN) {
-		con->is_readable = 1;
-#if 0
-		log_error_write(srv, __FILE__, __LINE__, "sd", "read-wait - done", con->fd);
-#endif
-	}
-	if (revents & FDEVENT_OUT) {
-		con->is_writable = 1;
-		/* we don't need the event twice */
+	if (con->conf.is_ssl) {
+		/* ssl may read and write for both reads and writes */
+		if (revents & (FDEVENT_IN | FDEVENT_OUT)) {
+			con->is_readable = 1;
+			con->is_writable = 1;
+		}
+	} else {
+		if (revents & FDEVENT_IN) {
+			con->is_readable = 1;
+		}
+		if (revents & FDEVENT_OUT) {
+			con->is_writable = 1;
+			/* we don't need the event twice */
+		}
 	}
