--- server.c.orig	2010-01-20 18:36:52.000000000 -0800
+++ server.c	2012-09-22 02:39:04.991117023 -0700
@@ -101,7 +101,9 @@
 
 static void dispatch_pages(FILE *fh)
 {
+#ifdef __Linux__
 	dump_page_errors(fh);
+#endif
 	fprintf(fh, "done\n");
 }
 
@@ -137,6 +139,7 @@
 		Enomem();
 }
 
+#ifdef __Linux__
 /* check if client is allowed to access */
 static int access_check(int fd, struct msghdr *msg)
 {
@@ -162,6 +165,35 @@
 	sendstring(fd, "permission denied\n");
 	return -1;
 }
+#endif
+
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
 
 /* retrieve commands from client */
 static int client_input(int fd, struct clientcon *cc)
@@ -242,18 +274,22 @@
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
@@ -300,7 +336,12 @@
 	sigaction(SIGALRM, &sa, &oldsa);	
 	if (sigsetjmp(ping_timeout_ctx, 1) == 0) {
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
