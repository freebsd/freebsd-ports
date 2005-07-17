--- gnome-keyring-daemon-io.c.orig	Wed May  4 03:17:18 2005
+++ gnome-keyring-daemon-io.c	Sat Jul 16 21:46:13 2005
@@ -100,14 +100,17 @@ read_unix_socket_credentials (int fd,
 	char buf;
 	
 #ifdef HAVE_CMSGCRED 
-	char cmsgmem[CMSG_SPACE (sizeof (struct cmsgcred))];
-	struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
+	struct cmsgcred *cred;
+	union {
+		struct cmsghdr hdr;
+		char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
+	} cmsg;
 #endif
 	
 	*pid = 0;
 	*uid = 0;
 	
-#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED)
+#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED) && !defined(__FreeBSD__)
 	/* Set the socket to receive credentials on the next message */
 	{
 		int on = 1;
@@ -126,9 +129,9 @@ read_unix_socket_credentials (int fd,
 	msg.msg_iovlen = 1;
 	
 #ifdef HAVE_CMSGCRED
-	memset (cmsgmem, 0, sizeof (cmsgmem));
-	msg.msg_control = cmsgmem;
-	msg.msg_controllen = sizeof (cmsgmem);
+	memset (&cmsg, 0, sizeof (cmsg));
+	msg.msg_control = (caddr_t) &cmsg;
+	msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 #endif
 
  again:
@@ -147,7 +150,8 @@ read_unix_socket_credentials (int fd,
 	}
 
 #ifdef HAVE_CMSGCRED
-	if (cmsg->cmsg_len < sizeof (cmsgmem) || cmsg->cmsg_type != SCM_CREDS) {
+	if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred)) ||
+	    cmsg.hdr.cmsg_type != SCM_CREDS) {
 		g_warning ("Message from recvmsg() was not SCM_CREDS\n");
 		return FALSE;
 	}
@@ -168,10 +172,7 @@ read_unix_socket_credentials (int fd,
 			return FALSE;
 		}
 #elif defined(HAVE_CMSGCRED)
-		struct cmsgcred *cred;
-		
-		cred = (struct cmsgcred *) CMSG_DATA (cmsg);
-		
+		cred = (struct cmsgcred *) CMSG_DATA (&cmsg);
 		*pid = cred->cmcred_pid;
 		*uid = cred->cmcred_euid;
 #else /* !SO_PEERCRED && !HAVE_CMSGCRED */
