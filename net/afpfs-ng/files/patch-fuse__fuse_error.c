--- fuse/fuse_error.c.orig	2008-01-18 04:40:10.000000000 +0000
+++ fuse/fuse_error.c	2012-10-14 13:11:33.000000000 +0000
@@ -4,7 +4,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <stdio.h>
-#include "libafpclient.h"
+#include "afpfs-ng/libafpclient.h"
 #include "fuse_internal.h"
 
 #define TMP_FILE "/tmp/fuse_stderr"
diff -Naur afpfs-ng-0.8.1.orig/fuse/fuse_int.c afpfs-ng-0.8.1/fuse/fuse_int.c
