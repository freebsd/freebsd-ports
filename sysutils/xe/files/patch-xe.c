--- xe.c.orig	2016-05-20 18:14:18 UTC
+++ xe.c
@@ -13,6 +13,7 @@
 
 #include <limits.h>
 #include <errno.h>
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -100,7 +101,7 @@ mywait()
 		} else if (WEXITSTATUS(status) > 125) {
 			exit(WEXITSTATUS(status));
 		}
-	} else if (WIFSIGNALED(status)) {
+	} else if (WIFSIGNALED(status) && !(fflag && WTERMSIG(status) == SIGPIPE)) {
 		fprintf(stderr, "xe: pid %d terminated by signal %d\n",
 		    pid, WTERMSIG(status));
 		exit(125);
@@ -353,6 +354,7 @@ main(int argc, char *argv[], char *envp[
 			pusharg("/bin/sh");
 			pusharg("-c");
 			pusharg(sflag);
+			pusharg("--");
 			pusharg("-");
 		} else if (optind >= cmdend) {
 			pusharg("printf");
