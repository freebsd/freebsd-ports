--- ssh.c.orig	Tue Apr 17 14:55:04 2001
+++ ssh.c	Sat May 26 15:05:28 2001
@@ -199,6 +199,9 @@
 	log("Using rsh.  WARNING: Connection will not be encrypted.");
 	/* Build argument list for rsh. */
 	i = 0;
+#ifndef	_PATH_RSH
+#define	_PATH_RSH	"/usr/bin/rsh"
+#endif
 	args[i++] = _PATH_RSH;
 	/* host may have to come after user on some systems */
 	args[i++] = host;
