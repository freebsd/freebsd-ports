--- ./src/unionfs.c.orig	2012-09-11 00:06:32.000000000 +0200
+++ ./src/unionfs.c	2013-07-24 16:54:01.555073796 +0200
@@ -83,7 +83,11 @@
 	char p[PATHLEN_MAX];
 	if (BUILD_PATH(p, uopt.branches[i].path, path)) RETURN(-ENAMETOOLONG);
 
+#if __FreeBSD__
+	int res = lchmod(p, mode);
+#else
 	int res = chmod(p, mode);
+#endif
 	if (res == -1) RETURN(-errno);
 
 	RETURN(0);
@@ -190,7 +194,7 @@
 	DBG("%s\n", path);
 
 	if (uopt.stats_enabled && strcmp(path, STATS_FILENAME) == 0) {
-		memset(stbuf, 0, sizeof(stbuf));
+		memset(stbuf, 0, sizeof(*stbuf));
 		stbuf->st_mode = S_IFREG | 0444;
 		stbuf->st_nlink = 1;
 		stbuf->st_size = STATS_SIZE;
@@ -663,7 +667,16 @@
 	char p[PATHLEN_MAX];
 	if (BUILD_PATH(p, uopt.branches[i].path, path)) RETURN(-ENAMETOOLONG);
 
+#ifdef __FreeBSD__
+	struct timeval tv[2];
+	tv[0].tv_sec = ts[0].tv_sec;
+	tv[0].tv_usec = ts[0].tv_nsec / 1000;
+	tv[1].tv_sec = ts[0].tv_sec;
+	tv[1].tv_usec = ts[0].tv_nsec / 1000;
+	int res = lutimes(p, tv);
+#else
 	int res = utimensat(0, p, ts, AT_SYMLINK_NOFOLLOW);
+#endif
 
 	if (res == -1) RETURN(-errno);
 
