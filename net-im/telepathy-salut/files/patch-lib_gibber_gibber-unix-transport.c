--- lib/gibber/gibber-unix-transport.c.orig	2010-10-22 15:15:56 UTC
+++ lib/gibber/gibber-unix-transport.c
@@ -217,11 +217,12 @@ gibber_unix_transport_send_credentials (GibberUnixTran
     gsize size)
 {
   int fd, ret;
-  struct ucred *cred;
   struct msghdr msg;
-  struct cmsghdr *ch;
   struct iovec iov;
-  char buffer[CMSG_SPACE (sizeof (struct ucred))];
+  union {
+	  struct cmsghdr hdr;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
+  } buffer;
 
   DEBUG ("send credentials");
   fd = GIBBER_FD_TRANSPORT (transport)->fd;
@@ -234,21 +235,15 @@ gibber_unix_transport_send_credentials (GibberUnixTran
   memset (&msg, 0, sizeof (msg));
   msg.msg_iov = &iov;
   msg.msg_iovlen = 1;
-  msg.msg_control = buffer;
-  msg.msg_controllen = sizeof (buffer);
+  msg.msg_control = (caddr_t) &buffer;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
   memset (buffer, 0, sizeof (buffer));
 
   /* Set the credentials */
-  ch = CMSG_FIRSTHDR (&msg);
-  ch->cmsg_len = CMSG_LEN (sizeof (struct ucred));
-  ch->cmsg_level = SOL_SOCKET;
-  ch->cmsg_type = SCM_CREDENTIALS;
+  buffer.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
+  buffer.hdr.cmsg_level = SOL_SOCKET;
+  buffer.hdr.cmsg_type = SCM_CREDS;
 
-  cred = (struct ucred *) CMSG_DATA (ch);
-  cred->pid = getpid ();
-  cred->uid = getuid ();
-  cred->gid = getgid ();
-
   ret = sendmsg (fd, &msg, 0);
   if (ret == -1)
     {
@@ -274,10 +269,10 @@ gibber_unix_transport_read (GibberFdTransport *transpo
   GibberBuffer buf;
   struct iovec iov;
   struct msghdr msg;
-  char control[CMSG_SPACE (sizeof (struct ucred))];
-  struct cmsghdr *ch;
-  struct ucred *cred;
-  int opt;
+  union {
+	  struct cmsghdr hdr;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
+  } control;
 
   if (priv->recv_creds_cb == NULL)
     return gibber_fd_transport_read (transport, channel, error);
@@ -285,10 +280,6 @@ gibber_unix_transport_read (GibberFdTransport *transpo
   /* We are waiting for credentials */
   fd = transport->fd;
 
-  /* set SO_PASSCRED flag */
-  opt = 1;
-  setsockopt (fd, SOL_SOCKET, SO_PASSCRED, &opt, sizeof (opt));
-
   memset (buffer, 0, sizeof (buffer));
   memset (&iov, 0, sizeof (iov));
   iov.iov_base = buffer;
@@ -297,8 +288,9 @@ gibber_unix_transport_read (GibberFdTransport *transpo
   memset (&msg, 0, sizeof (msg));
   msg.msg_iov = &iov;
   msg.msg_iovlen = 1;
-  msg.msg_control = control;
-  msg.msg_controllen = sizeof (control);
+  memset (&control, 0, sizeof (control));
+  msg.msg_control = (caddr_t) &control;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 
   bytes_read = recvmsg (fd, &msg, 0);
 
@@ -317,16 +309,11 @@ gibber_unix_transport_read (GibberFdTransport *transpo
       return GIBBER_FD_IO_RESULT_ERROR;
     }
 
-  /* unset SO_PASSCRED flag */
-  opt = 0;
-  setsockopt (fd, SOL_SOCKET, SO_PASSCRED, &opt, sizeof (opt));
-
   buf.data = buffer;
   buf.length = bytes_read;
 
   /* extract the credentials */
-  ch = CMSG_FIRSTHDR (&msg);
-  if (ch == NULL)
+  if (control.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred)) || control.hdr.cmsg_type != SCM_CREDS)
     {
       GError *err = NULL;
 
@@ -342,11 +329,12 @@ gibber_unix_transport_read (GibberFdTransport *transpo
   else
     {
       GibberCredentials credentials;
+      struct cmsgcred *cred;
 
-      cred = (struct ucred *) CMSG_DATA (ch);
-      credentials.pid = cred->pid;
-      credentials.uid = cred->uid;
-      credentials.gid = cred->gid;
+      cred = (struct cmsgcred *) CMSG_DATA (&control);
+      credentials.pid = cred->cmcred_pid;
+      credentials.uid = cred->cmcred_uid;
+      credentials.gid = cred->cmcred_gid;
 
       priv->recv_creds_cb (self, &buf, &credentials, NULL,
           priv->recv_creds_data);
