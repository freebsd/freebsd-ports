--- gnome-keyring-daemon-io.c.orig	Tue Jan 13 05:29:02 2004
+++ gnome-keyring-daemon-io.c	Fri Dec 17 00:44:55 2004
@@ -100,8 +100,10 @@
 	char buf;
 	
 #ifdef HAVE_CMSGCRED 
-	char cmsgmem[CMSG_SPACE (sizeof (struct cmsgcred))];
-	struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
+	struct {
+		struct cmsghdr hdr;
+		struct cmsgcred cred;
+	} cmsg;
 #endif
 	
 	*pid = 0;
@@ -126,9 +128,9 @@
 	msg.msg_iovlen = 1;
 	
 #ifdef HAVE_CMSGCRED
-	memset (cmsgmem, 0, sizeof (cmsgmem));
-	msg.msg_control = cmsgmem;
-	msg.msg_controllen = sizeof (cmsgmem);
+	memset (&cmsg, 0, sizeof (cmsg));
+	msg.msg_control = &cmsg;
+	msg.msg_controllen = sizeof (cmsg);
 #endif
 
  again:
@@ -147,7 +149,8 @@
 	}
 
 #ifdef HAVE_CMSGCRED
-	if (cmsg->cmsg_len < sizeof (cmsgmem) || cmsg->cmsg_type != SCM_CREDS) {
+	if (cmsg.hdr.cmsg_len < sizeof (cmsg) ||
+	    cmsg.hdr.cmsg_type != SCM_CREDS) {
 		g_warning ("Message from recvmsg() was not SCM_CREDS\n");
 		return FALSE;
 	}
@@ -168,12 +171,8 @@
 			return FALSE;
 		}
 #elif defined(HAVE_CMSGCRED)
-		struct cmsgcred *cred;
-		
-		cred = (struct cmsgcred *) CMSG_DATA (cmsg);
-		
-		*pid = cred->cmcred_pid;
-		*uid = cred->cmcred_euid;
+		*pid = cmsg.cred.cmcred_pid;
+		*uid = cmsg.cred.cmcred_euid;
 #else /* !SO_PEERCRED && !HAVE_CMSGCRED */
 		g_warning ("Socket credentials not supported on this OS\n");
 		return FALSE;
