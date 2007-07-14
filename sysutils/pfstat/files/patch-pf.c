--- pf.c.orig	Thu May 11 23:41:07 2006
+++ pf.c	Mon Dec 11 21:08:31 2006
@@ -67,10 +67,8 @@
 
 	/* first, find out how many queues there are */
 	memset(&pa, 0, sizeof(pa));
-	if (ioctl(fd, DIOCGETALTQS, &pa)) {
-		fprintf(stderr, "ioctl: DIOCGETALTQS: %s\n", strerror(errno));
-		return (1);
-	}
+	if (ioctl(fd, DIOCGETALTQS, &pa))
+		return (0);
 	mnr = pa.nr;
 
 	/* fetch each of those queues */
