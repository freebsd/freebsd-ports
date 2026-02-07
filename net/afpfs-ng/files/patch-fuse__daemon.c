--- fuse/daemon.c.orig	2008-03-04 17:26:05.000000000 +0000
+++ fuse/daemon.c	2012-10-14 13:11:33.000000000 +0000
@@ -23,11 +23,11 @@
 #include <signal.h>
 #include <sys/socket.h>
 
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 
-#include "dsi.h"
+#include "afpfs-ng/dsi.h"
 #include "afp_server.h"
-#include "utils.h"
+#include "afpfs-ng/utils.h"
 #include "daemon.h"
 #include "commands.h"
 
diff -Naur afpfs-ng-0.8.1.orig/fuse/fuse_error.c afpfs-ng-0.8.1/fuse/fuse_error.c
