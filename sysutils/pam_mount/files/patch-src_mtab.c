--- src/mtab.c.orig	2012-12-03 17:20:15.000000000 +0100
+++ src/mtab.c	2012-12-03 17:20:28.000000000 +0100
@@ -138,7 +138,7 @@
 			l0g("HX_dirname: %s\n", strerror(errno));
 			return -errno;
 		}
-		ret = HX_mkdir(dirname);
+		ret = HX_mkdir(dirname, S_IRWXUGO);
 		free(dirname);
 		if (ret < 0) {
 			l0g("HX_mkdir: %s\n", strerror(-ret));
