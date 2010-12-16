--- clamd/others.c.orig	2010-11-05 10:48:02.000000000 +0100
+++ clamd/others.c	2010-12-16 15:41:59.000000000 +0100
@@ -146,7 +146,7 @@
 	    exit(execle("/bin/sh", "sh", "-c", buffer_cmd, NULL, env));
 	} else if(pid > 0) { /* parent */
 	    pthread_mutex_unlock(&virusaction_lock);
-	    waitpid(pid, NULL, 0);
+	    while(waitpid(pid, NULL, 0) == -1 && errno == EINTR);
 	} else {
 	    logg("!VirusEvent: fork failed.\n");
 	}
