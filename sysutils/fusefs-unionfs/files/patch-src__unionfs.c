--- src/unionfs.c.orig	2015-01-14 10:08:20 UTC
+++ src/unionfs.c
@@ -65,6 +65,13 @@
 #include "conf.h"
 #include "uioctl.h"
 
+// Patch pushed upstream: 
+// https://github.com/rpodgorny/unionfs-fuse/pull/40
+// Remove this as soon as pushed into a release.
+#ifdef IOCPARM_LEN
+#define _IOC_SIZE(nr) IOCPARM_LEN(nr)
+#endif
+
 static struct fuse_opt unionfs_opts[] = {
 	FUSE_OPT_KEY("chroot=%s,", KEY_CHROOT),
 	FUSE_OPT_KEY("cow", KEY_COW),
@@ -92,7 +99,12 @@ static int unionfs_chmod(const char *pat
 	char p[PATHLEN_MAX];
 	if (BUILD_PATH(p, uopt.branches[i].path, path)) RETURN(-ENAMETOOLONG);
 
+// Unsure of origin. Patch needs review.
+#if __FreeBSD__
+	int res = lchmod(p, mode);
+#else
 	int res = chmod(p, mode);
+#endif
 	if (res == -1) RETURN(-errno);
 
 	RETURN(0);
@@ -671,6 +683,9 @@ static int unionfs_truncate(const char *
 	RETURN(0);
 }
 
+// Patch pushed upstream: 
+// https://github.com/rpodgorny/unionfs-fuse/pull/39
+// Remove this as soon as pushed into a release.
 static int unionfs_utimens(const char *path, const struct timespec ts[2]) {
 	DBG("%s\n", path);
 
@@ -685,9 +700,9 @@ static int unionfs_utimens(const char *p
 #else
 	struct timeval tv[2];
 	tv[0].tv_sec = ts[0].tv_sec;
-	tv[0].tv_usec = ts[0].tv_nsec * 1000;
+	tv[0].tv_usec = ts[0].tv_nsec / 1000;
 	tv[1].tv_sec = ts[1].tv_sec;
-	tv[1].tv_usec = ts[1].tv_nsec * 1000;
+	tv[1].tv_usec = ts[1].tv_nsec / 1000;
 	int res = utimes(p, tv);
 #endif
 
