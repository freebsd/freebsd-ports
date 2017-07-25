--- xe.c.orig	2017-07-17 14:20:26 UTC
+++ xe.c
@@ -13,6 +13,7 @@
 
 #include <limits.h>
 #include <errno.h>
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -114,7 +115,7 @@ my_child:
 		} else if (WEXITSTATUS(status) > 125) {
 			exit(WEXITSTATUS(status));
 		}
-	} else if (WIFSIGNALED(status)) {
+	} else if (WIFSIGNALED(status) && !(fflag && WTERMSIG(status) == SIGPIPE)) {
 		fprintf(stderr, "xe: job %ld [pid %ld] terminated by signal %d\n",
 		    children[i].iter, (long)pid, WTERMSIG(status));
 		exit(125);
@@ -472,6 +473,7 @@ main(int argc, char *argv[], char *envp[])
 			pusharg("/bin/sh");
 			pusharg("-c");
 			pusharg(sflag);
+			pusharg("--");
 			pusharg("-");
 		} else if (optind >= cmdend) {
 			pusharg("printf");
