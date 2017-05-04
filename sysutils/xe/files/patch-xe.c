--- xe.c.orig	2017-04-13 15:28:38 UTC
+++ xe.c
@@ -12,6 +12,7 @@
 
 #include <limits.h>
 #include <errno.h>
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -99,7 +100,7 @@ mywait()
 		} else if (WEXITSTATUS(status) > 125) {
 			exit(WEXITSTATUS(status));
 		}
-	} else if (WIFSIGNALED(status)) {
+	} else if (WIFSIGNALED(status) && !(fflag && WTERMSIG(status) == SIGPIPE)) {
 		fprintf(stderr, "xe: pid %d terminated by signal %d\n",
 		    pid, WTERMSIG(status));
 		exit(125);
@@ -358,6 +359,7 @@ main(int argc, char *argv[], char *envp[
 			pusharg("/bin/sh");
 			pusharg("-c");
 			pusharg(sflag);
+			pusharg("--");
 			pusharg("-");
 		} else if (optind >= cmdend) {
 			pusharg("printf");
