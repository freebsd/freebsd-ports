--- gnome-keyring-daemon-io.c.orig	Tue May 11 15:31:33 2004
+++ gnome-keyring-daemon-io.c	Tue May 11 16:27:21 2004
@@ -99,7 +99,7 @@
 	struct iovec iov;
 	char buf;
 	
-#ifdef HAVE_CMSGCRED 
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
 	char cmsgmem[CMSG_SPACE (sizeof (struct cmsgcred))];
 	struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
 #endif
@@ -118,18 +118,17 @@
 	}
 #endif
 	
-	iov.iov_base = &buf;
-	iov.iov_len = 1;
-	
 	memset (&msg, 0, sizeof (msg));
 	msg.msg_iov = &iov;
 	msg.msg_iovlen = 1;
 	
-#ifdef HAVE_CMSGCRED
-	memset (cmsgmem, 0, sizeof (cmsgmem));
-	msg.msg_control = cmsgmem;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+	msg.msg_control = (char *) cmsg;
 	msg.msg_controllen = sizeof (cmsgmem);
+	memset (cmsg, 0, sizeof (cmsgmem));
 #endif
+	iov.iov_base = &buf;
+	iov.iov_len = 1;
 
  again:
 	if (recvmsg (fd, &msg, 0) < 0) {
