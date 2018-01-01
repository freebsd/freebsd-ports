--- uwac/libuwac/uwac-os.c.orig	2017-11-27 16:54:50 UTC
+++ uwac/libuwac/uwac-os.c
@@ -31,6 +31,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/mman.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
@@ -153,17 +154,7 @@ static int create_tmpfile_cloexec(char *tmpname)
 {
 	int fd;
 
-#ifdef HAVE_MKOSTEMP
-	fd = mkostemp(tmpname, O_CLOEXEC);
-	if (fd >= 0)
-		unlink(tmpname);
-#else
-	fd = mkstemp(tmpname);
-	if (fd >= 0) {
-		fd = set_cloexec_or_close(fd);
-		unlink(tmpname);
-	}
-#endif
+	fd = shm_open(SHM_ANON, O_CREAT | O_RDWR, 0600);
 
 	return fd;
 }
