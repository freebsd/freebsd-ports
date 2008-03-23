--- ufs_copy.c.orig	2006-09-21 15:28:09.000000000 +0900
+++ ufs_copy.c	2007-12-27 23:28:55.000000000 +0900
@@ -111,9 +111,11 @@
 main(int argc, char *argv[])
 {
 	struct fstab *fs;
-	int ch, eval=0;
+	int ch, eval=0, md;
 	char *snapshot = NULL;
-	char *src, *dst;
+	char *src, *dst, *snap = NULL;
+	char mddev[256];
+	FILE *readp;
 
 #ifdef USEMMAP
 	while ((ch = getopt(argc, argv, "aBb:ceMms:v")) != -1)
@@ -174,6 +176,21 @@
 		eval = system(buf);
 		if (eval)
 			errx(eval, "mksnap_ffs failed");
+		
+		snprintf(buf, sizeof(buf),
+			 "/sbin/mdconfig -a -n -t vnode -f %s", src);
+		fprintf(stderr, "%s\n", buf);
+		readp = popen(buf, "r");
+		if (readp == NULL)
+			errx(eval, "mdconfig failed");
+		eval = fscanf(readp, "%d", &md);
+		if (eval != 1)
+			errx(eval, "mdconfig failed");
+		pclose(readp);
+		snprintf(mddev, sizeof(mddev), "/dev/md%d", md);
+		snap = src;
+		src = mddev;
+		fprintf(stderr, "attached %s as memory disk %s\n", snap, mddev);
 	}
 
 	if ((fs = getfsfile(src)) == NULL) {
@@ -188,9 +205,19 @@
 	}
 
 	if (snapshot) {
-		fprintf(stderr, "removing snapshot file %s ... ", src);
+		char buf[1024];
+
+		snprintf(buf, sizeof(buf),
+			 "/sbin/mdconfig -d -u %d", md);
+		fprintf(stderr, "%s\n", buf);
+		eval = system(buf);
+		if (eval)
+			errx(eval, "mdconfig failed");
+		fprintf(stderr, "detached memory disk %s\n", mddev);
+
+		fprintf(stderr, "removing snapshot file %s ... ", snap);
 		fflush(stderr);
-		if (unlink(src) == 0)
+		if (unlink(snap) == 0)
 			fprintf(stderr, "done\n");
 		else
 			fprintf(stderr, "failed\n");
