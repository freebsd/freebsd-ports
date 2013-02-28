--- io/fadvise.c.orig	2013-02-18 10:17:09.000000000 +0100
+++ io/fadvise.c	2013-02-18 10:17:20.000000000 +0100
@@ -105,7 +105,7 @@
 		return command_usage(&fadvise_cmd);
 	}
 
-	if (posix_fadvise64(file->fd, offset, length, advise) < 0) {
+	if (posix_fadvise(file->fd, offset, length, advise) < 0) {
 		perror("fadvise");
 		return 0;
 	}
