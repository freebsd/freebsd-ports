--- lib/gibber/gibber-unix-transport.c.orig	2009-06-02 23:56:27.000000000 -0400
+++ lib/gibber/gibber-unix-transport.c	2009-06-03 00:13:18.000000000 -0400
@@ -200,11 +200,12 @@ gibber_unix_transport_send_credentials (
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
+  } cmsg;
 
   DEBUG ("send credentials");
   fd = GIBBER_FD_TRANSPORT (transport)->fd;
@@ -217,19 +218,12 @@ gibber_unix_transport_send_credentials (
   memset (&msg, 0, sizeof msg);
   msg.msg_iov = &iov;
   msg.msg_iovlen = 1;
-  msg.msg_control = buffer;
-  msg.msg_controllen = sizeof (buffer);
-
-  /* Set the credentials */
-  ch = CMSG_FIRSTHDR (&msg);
-  ch->cmsg_len = CMSG_LEN (sizeof (struct ucred));
-  ch->cmsg_level = SOL_SOCKET;
-  ch->cmsg_type = SCM_CREDENTIALS;
-
-  cred = (struct ucred *) CMSG_DATA (ch);
-  cred->pid = getpid ();
-  cred->uid = getuid ();
-  cred->gid = getgid ();
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
 
   ret = sendmsg (fd, &msg, 0);
   if (ret == -1)
@@ -256,9 +250,11 @@ gibber_unix_transport_read (GibberFdTran
   GibberBuffer buf;
   struct iovec iov;
   struct msghdr msg;
-  char control[CMSG_SPACE (sizeof (struct ucred))];
-  struct cmsghdr *ch;
-  struct ucred *cred;
+  struct cmsgcred *cred;
+  union {
+	  struct cmsghdr hdr;
+	  char cred[CMSG_SPACE (sizeof *cred)];
+  } cmsg;
   int opt;
 
   if (priv->recv_creds_cb == NULL)
@@ -268,8 +264,10 @@ gibber_unix_transport_read (GibberFdTran
   fd = transport->fd;
 
   /* set SO_PASSCRED flag */
+#ifdef SO_PASSCRED
   opt = 1;
   setsockopt (fd, SOL_SOCKET, SO_PASSCRED, &opt, sizeof (opt));
+#endif
 
   memset (buffer, 0, sizeof (buffer));
   memset (&iov, 0, sizeof (iov));
@@ -279,8 +277,8 @@ gibber_unix_transport_read (GibberFdTran
   memset (&msg, 0, sizeof (msg));
   msg.msg_iov = &iov;
   msg.msg_iovlen = 1;
-  msg.msg_control = control;
-  msg.msg_controllen = sizeof (control);
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof *cred);
 
   bytes_read = recvmsg (fd, &msg, 0);
 
@@ -300,15 +298,17 @@ gibber_unix_transport_read (GibberFdTran
     }
 
   /* unset SO_PASSCRED flag */
+#ifdef SO_PASSCRED
   opt = 0;
   setsockopt (fd, SOL_SOCKET, SO_PASSCRED, &opt, sizeof (opt));
+#endif
 
   buf.data = buffer;
   buf.length = bytes_read;
 
   /* extract the credentials */
-  ch = CMSG_FIRSTHDR (&msg);
-  if (ch == NULL)
+  if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof *cred) ||
+      cmsg.hdr.cmsg_type != SCM_CREDS)
     {
       GError *err = NULL;
 
@@ -325,10 +325,10 @@ gibber_unix_transport_read (GibberFdTran
     {
       GibberCredentials credentials;
 
-      cred = (struct ucred *) CMSG_DATA (ch);
-      credentials.pid = cred->pid;
-      credentials.uid = cred->uid;
-      credentials.gid = cred->gid;
+      cred = (struct cmsgcred *) CMSG_DATA (&cmsg.hdr);
+      credentials.pid = cred->cmcred_pid;
+      credentials.uid = cred->cmcred_uid;
+      credentials.gid = cred->cmcred_gid;
 
       priv->recv_creds_cb (self, &buf, &credentials, NULL,
           priv->recv_creds_data);
