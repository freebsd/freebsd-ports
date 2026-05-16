--- src/dpipe.c.orig	2026-03-23 08:45:44 UTC
+++ src/dpipe.c
@@ -201,7 +201,11 @@ int main(int argc, char *argv[]) 
 
 	if (daemonize != 0)
 		daemon(0,0);
+#ifdef VDE_FREEBSD
+	else if (setpgrp(0,getpid()) == -1) {
+#else
 	else if (setpgrp() == -1) {
+#endif
 		fprintf(stderr,"Err: cannot create pgrp\n");
 		perror("setpgrp");
 		exit(1);
