# Only needed for FreeBSD < 8.1, but no harm
--- mbuffer.c.orig	2011-03-26 15:45:51.000000000 +0800
+++ mbuffer.c	2011-03-26 15:45:47.000000000 +0800
@@ -2007,7 +2007,7 @@
 	}
 
 	debugmsg("checking if we have a controlling terminal...\n");
-	err = sigignore(SIGTTIN);
+	err = sigset(SIGTTIN, SIG_IGN);
 	assert(err == 0);
 	fl = fcntl(STDERR_FILENO,F_GETFL);
 	err = fcntl(STDERR_FILENO,F_SETFL,fl | O_NONBLOCK);
