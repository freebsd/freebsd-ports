--- gnome-keyring.c.orig	Mon Apr 24 06:21:29 2006
+++ gnome-keyring.c	Mon Jun 12 14:24:47 2006
@@ -275,9 +275,9 @@ write_credentials_byte_sync (int socket)
   msg.msg_control = (caddr_t) &cmsg;
   msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
   memset (&cmsg, 0, sizeof (cmsg));
-  cmsg->cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
-  cmsg->cmsg_level = SOL_SOCKET;
-  cmsg->cmsg_type = SCM_CREDS;
+  cmsg.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
 #endif
 
  again:
@@ -324,10 +324,10 @@ write_credentials_byte (GnomeKeyringOper
 
   msg.msg_control = (caddr_t) &cmsg;
   msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
-  memset (cmsg, 0, sizeof (cmsg));
-  cmsg->cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
-  cmsg->cmsg_level = SOL_SOCKET;
-  cmsg->cmsg_type = SCM_CREDS;
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
 #endif
 
  again:
