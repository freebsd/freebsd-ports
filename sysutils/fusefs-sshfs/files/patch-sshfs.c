--- sshfs.c.orig	2017-03-17 21:07:50 UTC
+++ sshfs.c
@@ -1027,7 +1027,7 @@ static int pty_master(char **name)
 {
 	int mfd;
 
-	mfd = open("/dev/ptmx", O_RDWR | O_NOCTTY);
+	mfd = posix_openpt(O_RDWR | O_NOCTTY);
 	if (mfd == -1) {
 		perror("failed to open pty");
 		return -1;
