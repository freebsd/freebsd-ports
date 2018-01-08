--- sshfs.c.orig	2018-01-08 21:05:08 UTC
+++ sshfs.c
@@ -971,7 +971,7 @@ static int pty_master(char **name)
 {
 	int mfd;
 
-	mfd = open("/dev/ptmx", O_RDWR | O_NOCTTY);
+	mfd = posix_openpt(O_RDWR | O_NOCTTY);
 	if (mfd == -1) {
 		perror("failed to open pty");
 		return -1;
