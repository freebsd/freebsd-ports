--- scgi/passfd.c.orig	Sun Dec  4 15:49:02 2005
+++ scgi/passfd.c	Sun Dec  4 15:49:28 2005
@@ -22,7 +22,7 @@
 #include <stddef.h>
 
 
-#define CONTROLLEN sizeof (struct cmsghdr) + sizeof (int)
+#define CONTROLLEN sizeof (struct cmsghdr) + sizeof (void*)
 
 static int
 recv_fd(int sockfd)
@@ -31,7 +31,7 @@
 	struct cmsghdr *cmptr = (struct cmsghdr *) tmpbuf;
 	struct iovec iov[1];
 	struct msghdr msg;
-	char buf[1];
+	void* buf[1];
 
 	iov[0].iov_base = buf;
 	iov[0].iov_len = sizeof (buf);
@@ -56,7 +56,7 @@
 	struct cmsghdr *cmptr = (struct cmsghdr *) tmpbuf;
         struct iovec iov[1];
         struct msghdr msg;
-        char buf[1];
+        void* buf[1];
 
         iov[0].iov_base = buf;
         iov[0].iov_len = 1;
