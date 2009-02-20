--- clients/upssched.c.orig	2009-02-19 20:01:40.000000000 +0100
+++ clients/upssched.c	2009-02-19 20:02:00.000000000 +0100
@@ -595,7 +595,7 @@
 	int	pipefd, ret;
 	struct	sockaddr_un saddr;
 
-	memset(&sa, '\0', sizeof(saddr));
+	memset(&saddr, '\0', sizeof(saddr));
 	saddr.sun_family = AF_UNIX;
 	snprintf(saddr.sun_path, sizeof(saddr.sun_path), "%s", pipefn);
 
