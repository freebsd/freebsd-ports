--- lib/wrapsock_r.c.orig	Thu Sep 30 12:04:02 1999
+++ lib/wrapsock_r.c	Thu Sep 30 12:04:10 1999
@@ -97,19 +97,6 @@
 }
 /* end Listen */
 
-#ifdef	HAVE_POLL
-int
-Poll(struct pollfd *fdarray, unsigned long nfds, int timeout)
-{
-	int		n;
-
-	if ( (n = poll(fdarray, nfds, timeout)) < 0)
-		err_sys("poll error");
-
-	return(n);
-}
-#endif
-
 ssize_t
 Recv(int fd, void *ptr, size_t nbytes, int flags)
 {
