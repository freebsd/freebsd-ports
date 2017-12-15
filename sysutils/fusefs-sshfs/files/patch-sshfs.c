--- sshfs.c.orig	2017-09-20 17:08:27 UTC
+++ sshfs.c
@@ -965,7 +965,7 @@ static int pty_master(char **name)
 {
 	int mfd;
 
-	mfd = open("/dev/ptmx", O_RDWR | O_NOCTTY);
+	mfd = posix_openpt(O_RDWR | O_NOCTTY);
 	if (mfd == -1) {
 		perror("failed to open pty");
 		return -1;
