--- src/lib-auth/auth-server-connection.h.orig	2017-10-05 17:10:44 UTC
+++ src/lib-auth/auth-server-connection.h
@@ -38,4 +38,6 @@ void auth_server_connection_disconnect(struct auth_ser
 unsigned int
 auth_server_connection_add_request(struct auth_server_connection *conn,
 				   struct auth_client_request *request);
+void auth_server_connection_remove_request(struct auth_server_connection *conn,
+					   unsigned int id);
 #endif
