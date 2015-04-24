--- src/server/nsca-ng.c.orig	2013-11-06 21:44:18 UTC
+++ src/server/nsca-ng.c
@@ -300,11 +300,9 @@ close_descriptors(void)
 	int min_fd = STDERR_FILENO + 1;
 
 #if HAVE_CLOSEFROM /* BSD and Solaris. */
-	if (closefrom(min_fd) == -1)
-		die("Cannot close file descriptors >= %d: %m", min_fd);
+	(void)closefrom(min_fd);
 #elif defined(F_CLOSEM) /* AIX and IRIX. */
-	if (fcntl(min_fd, F_CLOSEM, 0) == -1)
-		die("Cannot close file descriptors >= %d: %m", min_fd);
+	(void)fcntl(min_fd, F_CLOSEM, 0);
 #else
 	int max_fd = MIN(sysconf(_SC_OPEN_MAX), /* Arbitrary limit: */ 1048576);
 	int fd;
