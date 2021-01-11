--- gl/lib/fdopendir.c.orig	2021-01-01 18:54:11 UTC
+++ gl/lib/fdopendir.c
@@ -227,9 +227,11 @@ fd_clone_opendir (int fd, struct saved_cwd const *cwd)
 
 # include <errno.h>
 # include <sys/stat.h>
+# include <dirent.h>
 
 # undef fdopendir
 
+extern DIR *fdopendir(int);
 /* Like fdopendir, but work around GNU/Hurd bug by validating FD.  */
 
 DIR *
