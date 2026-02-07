--- lib/gibber/gibber-unix-transport.c.orig	2013-10-04 15:51:47 UTC
+++ lib/gibber/gibber-unix-transport.c
@@ -374,6 +374,167 @@ gibber_unix_transport_recv_credentials (GibberUnixTran
   return TRUE;
 }
 
+/* End Linux part */
+#elif defined(__FreeBSD__)
+
+gboolean
+gibber_unix_transport_send_credentials (GibberUnixTransport *transport,
+    const guint8 *data,
+    gsize size)
+{
+  int fd, ret;
+  struct msghdr msg;
+  struct iovec iov;
+  union {
+    struct cmsghdr hdr;
+    char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
+  } cmsg;
+
+  DEBUG ("send credentials");
+  fd = GIBBER_FD_TRANSPORT (transport)->fd;
+
+  /* Set the message payload */
+  memset (&iov, 0, sizeof (iov));
+  iov.iov_base = (void *) data;
+  iov.iov_len = size;
+
+  memset (&msg, 0, sizeof (msg));
+  msg.msg_iov = &iov;
+  msg.msg_iovlen = 1;
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
+
+  ret = sendmsg (fd, &msg, 0);
+  if (ret == -1)
+    {
+      DEBUG ("sendmsg failed: %s", g_strerror (errno));
+      return FALSE;
+    }
+
+  return TRUE;
+}
+
+gboolean
+gibber_unix_transport_recv_credentials (GibberUnixTransport *self,
+    GibberUnixTransportRecvCredentialsCb callback,
+    gpointer user_data)
+{
+  GibberUnixTransportPrivate *priv = GIBBER_UNIX_TRANSPORT_GET_PRIVATE (self);
+
+  if (priv->recv_creds_cb != NULL)
+    {
+      DEBUG ("already waiting for credentials");
+      return FALSE;
+    }
+
+  priv->recv_creds_cb = callback;
+  priv->recv_creds_data = user_data;
+  return TRUE;
+}
+
+gboolean
+gibber_unix_transport_supports_credentials (void)
+{
+  return TRUE;
+}
+
+#define BUFSIZE 1024
+
+static GibberFdIOResult
+gibber_unix_transport_read (GibberFdTransport *transport,
+    GIOChannel *channel,
+    GError **error)
+{
+  GibberUnixTransport *self = GIBBER_UNIX_TRANSPORT (transport);
+  GibberUnixTransportPrivate *priv = GIBBER_UNIX_TRANSPORT_GET_PRIVATE (self);
+  int fd;
+  guint8 buffer[BUFSIZE];
+  ssize_t bytes_read;
+  GibberBuffer buf;
+  struct iovec iov;
+  struct msghdr msg;
+  struct cmsgcred *cred;
+  union {
+    struct cmsghdr hdr;
+    char cred[CMSG_SPACE (sizeof *cred)];
+  } cmsg;
+  int opt;
+
+  if (priv->recv_creds_cb == NULL)
+    return gibber_fd_transport_read (transport, channel, error);
+
+  /* We are waiting for credentials */
+  fd = transport->fd;
+
+  memset (buffer, 0, sizeof (buffer));
+  memset (&iov, 0, sizeof (iov));
+  iov.iov_base = buffer;
+  iov.iov_len = sizeof (buffer);
+
+  memset (&msg, 0, sizeof (msg));
+  msg.msg_iov = &iov;
+  msg.msg_iovlen = 1;
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof *cred);
+
+  bytes_read = recvmsg (fd, &msg, 0);
+
+  if (bytes_read == -1)
+    {
+      GError *err = NULL;
+
+      g_set_error_literal (&err, G_IO_CHANNEL_ERROR,
+          g_io_channel_error_from_errno (errno), "recvmsg failed");
+
+      priv->recv_creds_cb (self, NULL, NULL, err, priv->recv_creds_data);
+      g_propagate_error (error, err);
+
+      priv->recv_creds_cb = NULL;
+      priv->recv_creds_data = NULL;
+      return GIBBER_FD_IO_RESULT_ERROR;
+    }
+
+  buf.data = buffer;
+  buf.length = bytes_read;
+
+  /* extract the credentials */
+  if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof *cred) ||
+      cmsg.hdr.cmsg_type != SCM_CREDS)
+    {
+      GError *err = NULL;
+
+      DEBUG ("Message doesn't contain credentials");
+
+      g_set_error_literal (&err, GIBBER_UNIX_TRANSPORT_ERROR,
+          GIBBER_UNIX_TRANSPORT_ERROR_NO_CREDENTIALS,
+          "no credentials received");
+
+      priv->recv_creds_cb (self, &buf, NULL, err, priv->recv_creds_data);
+      g_error_free (err);
+    }
+  else
+    {
+      GibberCredentials credentials;
+
+      cred = (struct cmsgcred *) CMSG_DATA (&cmsg.hdr);
+      credentials.pid = cred->cmcred_pid;
+      credentials.uid = cred->cmcred_uid;
+      credentials.gid = cred->cmcred_gid;
+
+      priv->recv_creds_cb (self, &buf, &credentials, NULL,
+          priv->recv_creds_data);
+    }
+
+  priv->recv_creds_cb = NULL;
+  priv->recv_creds_data = NULL;
+  return GIBBER_FD_IO_RESULT_SUCCESS;
+}
+
+/* End FreeBSD part */
 #else /* OSs where we have no implementation */
 
 gboolean
@@ -392,9 +553,7 @@ gibber_unix_transport_recv_credentials (GibberUnixTran
 }
 
 gboolean
-gibber_unix_transport_send_credentials (GibberUnixTransport *transport,
-    const guint8 *data,
-    gsize size)
+gibber_unix_transport_send_credentials (void)
 {
   DEBUG ("stub implementation, failing");
   return FALSE;
