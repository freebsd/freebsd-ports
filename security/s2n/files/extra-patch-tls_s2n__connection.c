--- tls/s2n_connection.c.orig	2015-10-22 22:11:14 UTC
+++ tls/s2n_connection.c
@@ -192,8 +192,8 @@ int s2n_connection_wipe(struct s2n_conne
 
     /* Clone the stuffers */
     /* ignore gcc 4.7 address warnings because dest is allocated on the stack */
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Waddress"
+//#pragma GCC diagnostic push
+//#pragma GCC diagnostic ignored "-Waddress"
     memcpy_check(&alert_in, &conn->alert_in, sizeof(struct s2n_stuffer));
     memcpy_check(&reader_alert_out, &conn->reader_alert_out, sizeof(struct s2n_stuffer));
     memcpy_check(&writer_alert_out, &conn->writer_alert_out, sizeof(struct s2n_stuffer));
@@ -201,7 +201,7 @@ int s2n_connection_wipe(struct s2n_conne
     memcpy_check(&header_in, &conn->header_in, sizeof(struct s2n_stuffer));
     memcpy_check(&in, &conn->in, sizeof(struct s2n_stuffer));
     memcpy_check(&out, &conn->out, sizeof(struct s2n_stuffer));
-#pragma GCC diagnostic pop
+//#pragma GCC diagnostic pop
 
     /* Zero the whole connection structure */
     memset_check(conn, 0, sizeof(struct s2n_connection));
