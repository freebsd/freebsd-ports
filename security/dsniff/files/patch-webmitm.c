--- ./webmitm.c.orig	2001-03-17 09:35:05.000000000 +0100
+++ ./webmitm.c	2014-07-22 13:20:14.000000000 +0200
@@ -43,7 +43,7 @@
 int	 client_fd, server_fd;
 SSL_CTX	*ssl_client_ctx, *ssl_server_ctx;
 SSL	*ssl_client, *ssl_server;
-struct	 sockaddr_in csin, ssin;
+struct	 sockaddr_in ________csin, ssin;
 int	 do_ssl, sig_pipe[2];
 in_addr_t	static_host = 0;
 
@@ -101,8 +101,8 @@
 	char obuf[1024];
 	
 	if ((len = decode_http(buf, len, obuf, sizeof(obuf))) > 0) {
-		record(csin.sin_addr.s_addr, ssin.sin_addr.s_addr,
-		       IPPROTO_TCP, ntohs(csin.sin_port), ntohs(ssin.sin_port),
+		record(________csin.sin_addr.s_addr, ssin.sin_addr.s_addr,
+		       IPPROTO_TCP, ntohs(________csin.sin_port), ntohs(ssin.sin_port),
 		       "http", obuf, len);
 	}
 }
@@ -242,7 +242,7 @@
 			word = buf_tok(&msg, "/", 1);
 			vhost = buf_strdup(word);
 		}
-		ssin.sin_addr.s_addr = libnet_name_resolve(vhost, 1);
+		ssin.sin_addr.s_addr = libnet_name2addr4(NULL, vhost, 1);
 		free(vhost);
 		
 		if (ssin.sin_addr.s_addr == ntohl(INADDR_LOOPBACK) ||
@@ -355,7 +355,7 @@
 	
 	if (Opt_debug)
 		warnx("new connection from %s.%d",
-		      inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
+		      inet_ntoa(________csin.sin_addr), ntohs(________csin.sin_port));
 
 	client_init();
 	
@@ -363,7 +363,7 @@
 		err(1, "client_request");
 
 	if (Opt_debug)
-		warnx("%d bytes from %s", i, inet_ntoa(csin.sin_addr));
+		warnx("%d bytes from %s", i, inet_ntoa(________csin.sin_addr));
 	
 	if (Opt_debug > 1)
 		write(STDERR_FILENO, buf, i);
@@ -393,7 +393,7 @@
 			
 			if (Opt_debug)
 				warnx("%d bytes from %s",
-				      i, inet_ntoa(csin.sin_addr));
+				      i, inet_ntoa(________csin.sin_addr));
 
 			if (Opt_debug > 1)
 				write(STDERR_FILENO, buf, i);
@@ -456,7 +456,7 @@
 			if (errno != EINTR)
 				err(1, "select");
 		}
-		i = sizeof(csin);
+		i = sizeof(________csin);
 		
 		if (FD_ISSET(sig_pipe[0], &fds)) {
 			while (read(sig_pipe[0], &i, 1) == 1)
@@ -466,11 +466,11 @@
 			continue;
 		}
 		if (FD_ISSET(http_fd, &fds)) {
-			client_fd = accept(http_fd, (struct sockaddr *)&csin, &i);
+			client_fd = accept(http_fd, (struct sockaddr *)&________csin, &i);
 			do_ssl = 0;
 		}
 		else if (FD_ISSET(https_fd, &fds)) {
-			client_fd = accept(https_fd, (struct sockaddr *)&csin, &i);
+			client_fd = accept(https_fd, (struct sockaddr *)&________csin, &i);
 			do_ssl = 1;
 		}
 		else errx(1, "select failure");
@@ -510,7 +510,7 @@
 	argv += optind;
 
 	if (argc == 1) {
-		if ((static_host = libnet_name_resolve(argv[0], 1)) == -1)
+		if ((static_host = libnet_name2addr4(NULL, argv[0], 1)) == -1)
 			usage();
 	}
 	else if (argc != 0) usage();
