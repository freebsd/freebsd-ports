--- isakmpd.c	25 Jun 2004 20:25:34 -0000	1.67
+++ isakmpd.c	7 Dec 2004 19:41:01 -0000
@@ -386,7 +386,7 @@
 		if (fcntl(n, F_GETFL, 0) == -1 && errno == EBADF)
 			(void) open("/dev/null", n ? O_WRONLY : O_RDONLY, 0);
 
-	for (n = 1; n < _NSIG; n++)
+	for (n = 1; n < NSIG; n++)
 		signal(n, SIG_DFL);
 
 	/* Log cmd line parsing and initialization errors to stderr.  */
