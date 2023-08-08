--- expand.c.orig	2023-02-14 21:23:14.429816000 -0800
+++ expand.c	2023-02-14 21:25:25.393203000 -0800
@@ -179,7 +179,7 @@
 			savec = *tail;
 			*tail = '\0';
 		}
-		tp = lookup(cp, NULL, 0);
+		tp = lookup(cp, 0, 0);
 		if (savec != '\0')
 			*tail = savec;
 		if (tp != NULL) {
@@ -309,7 +309,7 @@
 			return;
 		goto patherr2;
 	}
-	if (fstat(dirp->dd_fd, &stb) < 0)
+	if (fstat(dirfd(dirp), &stb) < 0)
 		goto patherr1;
 	if (!ISDIR(stb.st_mode)) {
 		errno = ENOTDIR;
