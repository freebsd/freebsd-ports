--- stun/tools/stund.c.orig	2008-11-27 14:04:54.000000000 -0500
+++ stun/tools/stund.c	2009-02-27 23:15:29.000000000 -0500
@@ -163,6 +163,8 @@ static int recv_err (int fd)
   struct msghdr hdr;
   memset (&hdr, 0, sizeof (hdr));
   return recvmsg (fd, &hdr, MSG_ERRQUEUE) >= 0;
+#else
+  return -1;
 #endif
 }
 
