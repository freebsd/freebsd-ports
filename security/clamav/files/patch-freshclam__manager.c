--- freshclam/manager.c.orig	2010-11-23 12:41:18.000000000 +0100
+++ freshclam/manager.c	2010-12-16 15:40:54.000000000 +0100
@@ -1476,7 +1476,7 @@
     char lastline[256];
     int pipefd[2];
     pid_t pid;
-    int status = 0;
+    int status = 0, ret;
     FILE *f;
 
     if (pipe(pipefd) == -1) {
@@ -1513,7 +1513,8 @@
 	    }
 	    fclose(f);
 
-	    if (waitpid(pid, &status, 0) == -1 && errno != ECHILD)
+	    while ((ret = waitpid(pid, &status, 0)) == -1 && errno == EINTR);
+	    if (ret == -1 && errno != ECHILD)
 		logg("^waitpid() failed: %s\n", strerror(errno));
 	    cli_chomp(firstline);
 	    cli_chomp(lastline);
@@ -1523,7 +1524,7 @@
 		     lastline);
 	    }
 	    if (WIFEXITED(status)) {
-		int ret = WEXITSTATUS(status);
+		ret = WEXITSTATUS(status);
 		if (ret) {
 		    logg("^Database load exited with status %d\n", ret);
 		    return ret;
