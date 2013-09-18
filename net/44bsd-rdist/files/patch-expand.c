--- expand.c.orig	2013-09-17 23:46:26.681322944 -0700
+++ expand.c	2013-09-18 00:29:13.792410201 -0700
@@ -309,7 +309,7 @@
 			return;
 		goto patherr2;
 	}
-	if (fstat(dirp->dd_fd, &stb) < 0)
+	if (fstat(dirfd(dirp), &stb) < 0)
 		goto patherr1;
 	if (!ISDIR(stb.st_mode)) {
 		errno = ENOTDIR;
