--- os_freebsd.c.orig	Sat Mar 13 11:32:52 2004
+++ os_freebsd.c	Thu Jul 15 23:42:06 2004
@@ -18,6 +18,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <dirent.h>
+#include <fcntl.h>
 #include <err.h>
 #include <camlib.h>
 #include <cam/scsi/scsi_message.h>
