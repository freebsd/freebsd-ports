--- src/doveadm/client-connection-tcp.c.orig	2018-03-20 10:15:40 UTC
+++ src/doveadm/client-connection-tcp.c
@@ -334,6 +334,9 @@ static int doveadm_cmd_handle(struct client_connection
 	   running one and we can't call the original one recursively, so
 	   create a new ioloop. */
 	conn->ioloop = io_loop_create();
+	o_stream_switch_ioloop(conn->output);
+	if (conn->log_out != NULL)
+		o_stream_switch_ioloop(conn->log_out);
 
 	if (cmd_ver2 != NULL)
 		doveadm_cmd_server_run_ver2(conn, argc, argv, cctx);
