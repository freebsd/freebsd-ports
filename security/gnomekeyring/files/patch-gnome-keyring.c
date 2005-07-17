--- gnome-keyring.c.orig	Fri May 27 03:54:22 2005
+++ gnome-keyring.c	Sat Jul 16 21:49:24 2005
@@ -36,6 +36,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/uio.h>
 #include <sys/un.h>
 #include <stdarg.h>
 
@@ -253,11 +254,39 @@ write_credentials_byte_sync (int socket)
 {
   char buf;
   int bytes_written;
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  union {
+	  struct cmsghdr hdr;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
+  } cmsg;
+  struct iovec iov;
+  struct msghdr msg;
+#endif
+
+  buf = 0;
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  iov.iov_base = &buf;
+  iov.iov_len = 1;
+
+  memset (&msg, 0, sizeof (msg));
+  msg.msg_iov = &iov;
+  msg.msg_iovlen = 1;
+
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
+#endif
 
  again:
 
-  buf = 0;
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  bytes_written = sendmsg (socket, &msg, 0);
+#else
   bytes_written = write (socket, &buf, 1);
+#endif
 
   if (bytes_written < 0 && errno == EINTR)
     goto again;
@@ -275,11 +304,39 @@ write_credentials_byte (GnomeKeyringOper
 {
   char buf;
   int bytes_written;
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  union {
+	  struct cmsghdr hdr;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
+  } cmsg;
+  struct iovec iov;
+  struct msghdr msg;
+#endif
+
+  buf = 0;
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  iov.iov_base = &buf;
+  iov.iov_len = 1;
+
+  memset (&msg, 0, sizeof (msg));
+  msg.msg_iov = &iov;
+  msg.msg_iovlen = 1;
+
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
+#endif
 
  again:
 
-  buf = 0;
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  bytes_written = sendmsg (op->socket, &msg, 0);
+#else
   bytes_written = write (op->socket, &buf, 1);
+#endif
 
   if (bytes_written < 0 && errno == EINTR)
     goto again;
