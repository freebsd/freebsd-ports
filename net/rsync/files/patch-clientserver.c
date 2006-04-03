--- clientserver.c	24 Feb 2006 01:56:26 -0000	1.177
+++ clientserver.c	31 Mar 2006 17:36:26 -0000
@@ -733,8 +733,6 @@ int start_daemon(int f_in, int f_out)
 	char *host = client_name(f_in);
 	int i;
 
-	rprintf(FLOG, "connect from %s (%s)\n", host, addr);
-
 	io_set_sock_fds(f_in, f_out);
 
 	if (!lp_load(config_file, 0))
@@ -742,6 +740,8 @@ int start_daemon(int f_in, int f_out)
 
 	log_init();
 
+	rprintf(FLOG, "connect from %s (%s)\n", host, addr);
+
 	if (!am_server) {
 		set_socket_options(f_in, "SO_KEEPALIVE");
 		if (sockopts)
