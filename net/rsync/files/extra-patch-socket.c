Index: socket.c
diff -u socket.c.orig socket.c
--- socket.c.orig	Mon Jan 27 12:35:09 2003
+++ socket.c	Sat Feb  8 00:06:59 2003
@@ -292,11 +292,11 @@
  * @param bind_address Local address to bind, or NULL to allow it to
  * default.
  **/
-static int open_socket_in(int type, int port, const char *bind_address,
-			  int af_hint)
+static int *open_socket_in(int type, int port, const char *bind_address,
+			   int af_hint)
 {
 	int one=1;
-	int s;
+	int *s, *socks, maxs;
 	struct addrinfo hints, *all_ai, *resp;
 	char portbuf[10];
 	int error;
@@ -310,41 +310,65 @@
 	if (error) {
 		rprintf(FERROR, RSYNC_NAME ": getaddrinfo: bind address %s: %s\n",
 			bind_address, gai_strerror(error));
-		return -1;
+		return NULL;
+	}
+
+	/* Count max number of sockets we may open */
+	for (maxs = 0, resp = all_ai; resp; resp = resp->ai_next, maxs++)
+		;
+	socks = malloc((maxs + 1) * sizeof(int));
+	if (!socks) {
+		rprintf(FERROR,
+			RSYNC_NAME "couldn't allocate memory for sockets");
+		return NULL;
 	}
 
 	/* We may not be able to create the socket, if for example the
 	 * machine knows about IPv6 in the C library, but not in the
 	 * kernel. */
+	*socks = 0;   /* num of sockets counter at start of array */
+	s = socks + 1;
 	for (resp = all_ai; resp; resp = resp->ai_next) {
-		s = socket(resp->ai_family, resp->ai_socktype,
+		*s = socket(resp->ai_family, resp->ai_socktype,
 			   resp->ai_protocol);
 
-		if (s == -1) 
+		if (*s == -1) 
 			/* See if there's another address that will work... */
 			continue;
 		
-		setsockopt(s, SOL_SOCKET, SO_REUSEADDR,
+		setsockopt(*s, SOL_SOCKET, SO_REUSEADDR,
 			   (char *)&one, sizeof one);
 		
+#ifdef IPV6_V6ONLY
+		if (resp->ai_family == AF_INET6)
+			setsockopt(*s, IPPROTO_IPV6, IPV6_V6ONLY,
+				   (char *)&one, sizeof one);
+#endif
+
 		/* now we've got a socket - we need to bind it */
-		if (bind(s, all_ai->ai_addr, all_ai->ai_addrlen) < 0) {
+		if (bind(*s, resp->ai_addr, resp->ai_addrlen) < 0) {
 			/* Nope, try another */
-			close(s);
+			close(*s);
 			continue;
 		}
 
-		freeaddrinfo(all_ai);
-		return s;
+		(*socks)++;
+		s++;
 	}
 
-	rprintf(FERROR, RSYNC_NAME ": open inbound socket on port %d failed: "
-		"%s\n",
-		port, 
-		strerror(errno));
+	if (all_ai)
+		freeaddrinfo(all_ai);
 
-	freeaddrinfo(all_ai);
-	return -1; 
+	if (*socks == 0) {
+		rprintf(FERROR,
+			RSYNC_NAME ": open inbound socket on port %d failed: "
+			"%s\n",
+			port, 
+			strerror(errno));
+		free(socks);
+		return NULL;
+	}
+	return socks;
 }
 
 
@@ -376,19 +400,29 @@
 
 void start_accept_loop(int port, int (*fn)(int, int))
 {
-	int s;
+	fd_set deffds;
+	int *s, maxfd, i, j;
 	extern char *bind_address;
 	extern int default_af_hint;
 
 	/* open an incoming socket */
 	s = open_socket_in(SOCK_STREAM, port, bind_address, default_af_hint);
-	if (s == -1)
+	if (s == NULL)
 		exit_cleanup(RERR_SOCKETIO);
 
 	/* ready to listen */
-	if (listen(s, 5) == -1) {
-		close(s);
-		exit_cleanup(RERR_SOCKETIO);
+	FD_ZERO(&deffds);
+	maxfd = -1;
+	for (i = 1; i <= *s; i++) {
+		if (listen(s[i], 5) == -1) {
+			for (j = 1; j <= i; j++)
+				close(s[j]);
+			free(s);
+			exit_cleanup(RERR_SOCKETIO);
+		}
+		FD_SET(s[i], &deffds);
+		if (maxfd < s[i])
+			maxfd = s[i];
 	}
 
 
@@ -406,16 +440,20 @@
 		   forever */
 		log_close();
 
-		FD_ZERO(&fds);
-		FD_SET(s, &fds);
+		FD_COPY(&deffds, &fds);
 
-		if (select(s+1, &fds, NULL, NULL, NULL) != 1) {
+		if (select(maxfd + 1, &fds, NULL, NULL, NULL) != 1) {
 			continue;
 		}
 
-		if(!FD_ISSET(s, &fds)) continue;
-
-		fd = accept(s,(struct sockaddr *)&addr,&addrlen);
+		fd = -1;
+		for (i = 1; i <= *s; i++) {
+			if (FD_ISSET(s[i], &fds)) {
+				fd = accept(s[i], (struct sockaddr *)&addr,
+					    &addrlen);
+				break;
+			}
+		}
 
 		if (fd == -1) continue;
 
@@ -430,7 +468,7 @@
 
 		if ((pid = fork()) == 0) {
 			int ret;
-			close(s);
+			close(s[i]);
 			/* open log file in child before possibly giving
 			   up privileges  */
 			log_open();
@@ -452,6 +490,7 @@
 			close(fd);
 		}
 	}
+	free(s);
 }
 
 
