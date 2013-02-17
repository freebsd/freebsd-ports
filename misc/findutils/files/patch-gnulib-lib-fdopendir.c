--- gl/lib/fdopendir.c.orig	2012-12-15 14:42:45.000000000 +0100
+++ gl/lib/fdopendir.c	2013-02-02 17:11:52.000000000 +0100
@@ -182,9 +182,11 @@
 
 # include <errno.h>
 # include <sys/stat.h>
+# include <dirent.h>
 
 # undef fdopendir
 
+extern DIR *fdopendir(int);
 /* Like fdopendir, but work around GNU/Hurd bug by validating FD.  */
 
 DIR *
