--- gnulib/lib/fdopendir.c.orig	2011-04-02 15:37:38.000000000 +0000
+++ gnulib/lib/fdopendir.c	2011-05-30 21:05:02.000000000 +0000
@@ -182,9 +182,11 @@
 
 # include <errno.h>
 # include <sys/stat.h>
+# include <dirent.h>
 
 # undef fdopendir
 
+extern DIR *fdopendir(int);
 /* Like fdopendir, but work around GNU/Hurd bug by validating FD.  */
 
 DIR *

