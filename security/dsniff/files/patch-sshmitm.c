--- ./sshmitm.c.orig	2001-03-15 09:33:04.000000000 +0100
+++ ./sshmitm.c	2014-07-22 13:20:14.000000000 +0200
@@ -41,7 +41,7 @@
 int	 client_fd, server_fd;
 SSH_CTX	*ssh_client_ctx, *ssh_server_ctx;
 SSH	*ssh_client, *ssh_server;
-struct	 sockaddr_in csin, ssin;
+struct	 sockaddr_in ________csin, ssin;
 int	 sig_pipe[2];
 
 static void
@@ -148,7 +148,7 @@
 	
 	if (Opt_debug)
 		warnx("new connection from %s.%d",
-		      inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
+		      inet_ntoa(________csin.sin_addr), ntohs(________csin.sin_port));
 	
 	if (fcntl(client_fd, F_SETFL, 0) == -1)
 		err(1, "fcntl");
@@ -237,10 +237,10 @@
 				}
 				else {
 					pass_done = 1;
-					record(csin.sin_addr.s_addr,
+					record(________csin.sin_addr.s_addr,
 					       ssin.sin_addr.s_addr,
 					       IPPROTO_TCP,
-					       ntohs(csin.sin_port),
+					       ntohs(________csin.sin_port),
 					       ntohs(ssin.sin_port), "ssh",
 					       userpass, strlen(userpass));
 				}
@@ -326,7 +326,7 @@
 			if (errno != EINTR)
 				err(1, "select");
 		}
-		i = sizeof(csin);
+		i = sizeof(________csin);
 		
 		if (FD_ISSET(sig_pipe[0], &fds)) {
 			while (read(sig_pipe[0], buf, 1) == 1)
@@ -336,7 +336,7 @@
 		}
 		if (FD_ISSET(mitm_fd, &fds)) {
 			client_fd = accept(mitm_fd,
-					   (struct sockaddr *)&csin, &i);
+					   (struct sockaddr *)&________csin, &i);
 
 			if (client_fd >= 0) {
 				if (fork() == 0) {
@@ -389,7 +389,7 @@
 	if (argc < 1)
 		usage();
 	
-	if ((ip = libnet_name_resolve(argv[0], 1)) == -1)
+	if ((ip = libnet_name2addr4(NULL, argv[0], LIBNET_RESOLVE)) == -1)
 		usage();
 
 	if (argc == 2 && (rport = atoi(argv[1])) == 0)
