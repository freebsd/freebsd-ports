--- gnome-keyring.c.orig	Tue May 11 15:45:22 2004
+++ gnome-keyring.c	Tue May 11 16:22:21 2004
@@ -248,11 +248,37 @@
 {
   char buf;
   int bytes_written;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  char cmsgmem[CMSG_SPACE (sizeof (struct cmsgcred))];
+  struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
+  struct iovec iov;
+  struct msghdr msg;
+#endif
+
+  buf = 0;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  iov.iov_base = &buf;
+  iov.iov_len = 1;
+
+  memset (&msg, 0, sizeof (msg));
+  msg.msg_iov = &iov;
+  msg.msg_iovlen = 1;
+
+  msg.msg_control = cmsg;
+  msg.msg_controllen = sizeof (cmsgmem);
+  memset (cmsg, 0, sizeof (cmsgmem));
+  cmsg->cmsg_len = sizeof (cmsgmem);
+  cmsg->cmsg_level = SOL_SOCKET;
+  cmsg->cmsg_type = SCM_CREDS;
+#endif
 
  again:
 
-  buf = 0;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  bytes_written = sendmsg (socket, &msg, 0);
+#else
   bytes_written = write (socket, &buf, 1);
+#endif
 
   if (bytes_written < 0 && errno == EINTR)
     goto again;
@@ -270,11 +296,37 @@
 {
   char buf;
   int bytes_written;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  char cmsgmem[CMSG_SPACE (sizeof (struct cmsgcred))];
+  struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
+  struct iovec iov;
+  struct msghdr msg;
+#endif
+
+  buf = 0;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  iov.iov_base = &buf;
+  iov.iov_len = 1;
+
+  memset (&msg, 0, sizeof (msg));
+  msg.msg_iov = &iov;
+  msg.msg_iovlen = 1;
+
+  msg.msg_control = cmsg;
+  msg.msg_controllen = sizeof (cmsgmem);
+  memset (cmsg, 0, sizeof (cmsgmem));
+  cmsg->cmsg_len = sizeof (cmsgmem);
+  cmsg->cmsg_level = SOL_SOCKET;
+  cmsg->cmsg_type = SCM_CREDS;
+#endif
 
  again:
 
-  buf = 0;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  bytes_written = sendmsg (op->socket, &msg, 0);
+#else
   bytes_written = write (op->socket, &buf, 1);
+#endif
 
   if (bytes_written < 0 && errno == EINTR)
     goto again;
