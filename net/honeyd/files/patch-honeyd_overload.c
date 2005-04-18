--- honeyd_overload.c.orig	Thu Apr 14 16:07:26 2005
+++ honeyd_overload.c	Thu Apr 14 15:32:19 2005
@@ -127,7 +127,6 @@
 DECLARE(setsockopt, int, (int, int, int, const void *, socklen_t));
 DECLARE(getsockname, int, (int, struct sockaddr *, socklen_t *));
 
-DECLARE(recv, ssize_t, (int, void *, size_t, int));
 DECLARE(recvfrom, ssize_t, (int, void *, size_t, int, struct sockaddr *,
 	    socklen_t *));
 
