--- gnome-keyring.c.orig	Tue Sep  7 00:05:37 2004
+++ gnome-keyring.c	Fri Dec 17 10:06:11 2004
@@ -36,6 +36,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/uio.h>
 #include <sys/un.h>
 #include <stdarg.h>
 
@@ -253,11 +254,39 @@
 {
   char buf;
   int bytes_written;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  struct {
+	  struct cmsghdr hdr;
+	  struct cmsgcred cred;
+  } cmsg;
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
+  msg.msg_control = &cmsg;
+  msg.msg_controllen = sizeof (cmsg);
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = sizeof (cmsg);
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
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
@@ -275,11 +304,39 @@
 {
   char buf;
   int bytes_written;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  struct {
+	  struct cmsghdr hdr;
+	  struct cmsgcred cred;
+  } cmsg;
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
+  msg.msg_control = &cmsg;
+  msg.msg_controllen = sizeof (cmsg);
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = sizeof (cmsg);
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
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
