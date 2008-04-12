--- fuse_module/fuse_vfsops.c.orig	2008-04-11 11:34:04.000000000 +0900
+++ fuse_module/fuse_vfsops.c	2008-04-11 11:34:24.000000000 +0900
@@ -18,6 +18,7 @@
 #include <sys/namei.h>
 #include <sys/mount.h>
 #include <sys/sysctl.h>
+#include <sys/fcntl.h>
 
 #include "fuse.h"
 #include "fuse_session.h"
