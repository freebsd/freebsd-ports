--- lib/wrapsock_r.c.orig	2016-06-17 22:39:47 UTC
+++ lib/wrapsock_r.c
@@ -97,19 +97,6 @@ Listen(int fd, int backlog)
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
