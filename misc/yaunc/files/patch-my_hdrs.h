
$FreeBSD$

--- my_hdrs.h.orig	Thu Mar 23 03:32:02 2000
+++ my_hdrs.h	Sun Dec 22 16:33:44 2002
@@ -34,8 +34,6 @@
 ssize_t Recvfrom(int, void *, size_t, int, struct sockaddr *, socklen_t *);
 
 /* other networking function */
-int inet_pton(int, const char *, void *);
-const char * inet_ntop(int, const void *, char *, size_t);
 void Inet_pton(int, const char *, void *);
 
 /* non-networking stuff */
