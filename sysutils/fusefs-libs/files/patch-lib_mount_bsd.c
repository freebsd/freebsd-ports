--- lib/mount_bsd.c.orig	2008-07-07 08:01:09.000000000 +0200
+++ lib/mount_bsd.c	2008-07-07 08:01:59.000000000 +0200
@@ -10,6 +10,7 @@
 #include "fuse_misc.h"
 #include "fuse_opt.h"
 
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <sys/sysctl.h>
