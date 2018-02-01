--- src/lib-auth/auth-server-connection.c.orig	2017-10-05 17:10:44 UTC
+++ src/lib-auth/auth-server-connection.c
@@ -481,3 +481,10 @@ auth_server_connection_add_request(struct auth_server_
 	hash_table_insert(conn->requests, POINTER_CAST(id), request);
 	return id;
 }
+
+void auth_server_connection_remove_request(struct auth_server_connection *conn,
+					   unsigned int id)
+{
+	i_assert(conn->handshake_received);
+	hash_table_remove(conn->requests, POINTER_CAST(id));
+}
