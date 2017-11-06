--- server.c.orig	2017-06-11 18:52:26 UTC
+++ server.c
@@ -101,7 +101,9 @@ static void dispatch_dump(FILE *fh, char *s)
 
 static void dispatch_pages(FILE *fh)
 {
+#ifdef __Linux__
 	dump_page_errors(fh);
+#endif
 	fprintf(fh, "done\n");
 }
 
@@ -137,6 +139,7 @@ static void process_cmd(struct clientcon *cc)
 		Enomem();
 }
 
+#ifdef __Linux__
 /* check if client is allowed to access */
 static int access_check(int fd, struct msghdr *msg)
 {
@@ -162,11 +165,44 @@ static int access_check(int fd, struct msghdr *msg)
 	sendstring(fd, "permission denied\n");
 	return -1;
 }
+#endif
 
+#ifdef __FreeBSD__
+/* check if client is allowed to access */
+static int access_check(int fd, struct msghdr *msg)
+{
+	struct cmsghdr *cmsg;
+	struct cmsgcred *cr;
+
+	/* check credentials */
+	cmsg = CMSG_FIRSTHDR(msg);
+	if (cmsg == NULL || 
+		cmsg->cmsg_level != SOL_SOCKET ||
+		cmsg->cmsg_type != SCM_CREDS) { 
+		Eprintf("Did not receive credentials over client unix socket %p\n",
+			cmsg);
+		return -1;
+	}
+	cr = (struct cmsgcred *)CMSG_DATA(cmsg);
+	if (cr->cmcred_uid == 0 || 
+		(acc.uid != -1U && cr->cmcred_uid == acc.uid) ||
+		(acc.gid != -1U && cr->cmcred_gid == acc.gid))
+		return 0;
+	Eprintf("rejected client access from pid:%u uid:%u gid:%u\n",
+		cr->cmcred_pid, cr->cmcred_uid, cr->cmcred_gid);
+	sendstring(fd, "permission denied\n");
+	return -1;
+}
+#endif
+
 /* retrieve commands from client */
 static int client_input(int fd, struct clientcon *cc)
 {
+#ifdef __Linux__
 	char ctlbuf[CMSG_SPACE(sizeof(struct ucred))];
+#else
+	char ctlbuf[CMSG_SPACE(sizeof(struct cmsgcred))];
+#endif
 	struct iovec miov;
 	struct msghdr msg = {
 		.msg_iov = &miov,
@@ -242,18 +278,22 @@ static void client_accept(struct pollfd *pfd, void *da
 {
 	struct clientcon *cc = NULL;
 	int nfd = accept(pfd->fd, NULL, 0);	
+#ifdef __Linux__
 	int on;
+#endif
 
 	if (nfd < 0) {
 		SYSERRprintf("accept failed on client socket");
 		return;
 	}
 
+#ifdef __Linux__
 	on = 1;
 	if (setsockopt(nfd, SOL_SOCKET, SO_PASSCRED, &on, sizeof(on)) < 0) {
 		SYSERRprintf("Cannot enable credentials passing on client socket");
 		goto cleanup;
 	}
+#endif
 
 	cc = xalloc(sizeof(struct clientcon));
 	if (register_pollcb(nfd, POLLIN, client_event, cc) < 0) {
@@ -301,7 +341,12 @@ static int server_ping(struct sockaddr_un *un)
 	if (sigsetjmp(ping_timeout_ctx, 1) == 0) {
 		ret = -1;
 		alarm(initial_ping_timeout);
+#ifdef __Linux__
 		if (connect(fd, un, sizeof(struct sockaddr_un)) < 0)
+#endif
+#ifdef __FreeBSD__
+		if (connect(fd, (struct sockaddr *) un, sizeof(struct sockaddr_un)) < 0)
+#endif
 			goto cleanup;
 		if (write(fd, PAIR("ping\n")) < 0)
 			goto cleanup;
@@ -322,7 +367,9 @@ void server_setup(void)
 {
 	int fd;
 	struct sockaddr_un adr; 
+#ifdef __Linux__
 	int on;
+#endif
 
 	server_config();
 
@@ -363,9 +410,11 @@ void server_setup(void)
 	listen(fd, 10);
 	/* Set SO_PASSCRED to avoid race with client connecting too fast */
 	/* Ignore error for old kernels */
+#ifdef __Linux__
 	on = 1;
 	setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &on, sizeof(on));
 
+#endif
 	register_pollcb(fd, POLLIN, client_accept, NULL);
 	return;
 
