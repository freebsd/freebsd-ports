--- fuse/commands.c.orig	2008-03-08 16:06:25.000000000 +0000
+++ fuse/commands.c	2012-10-14 13:11:33.000000000 +0000
@@ -19,15 +19,15 @@
 #include <getopt.h>
 #include <signal.h>
 
-#include "afp.h"
-#include "dsi.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/dsi.h"
 #include "afp_server.h"
-#include "utils.h"
+#include "afpfs-ng/utils.h"
 #include "daemon.h"
-#include "uams_def.h"
-#include "codepage.h"
-#include "libafpclient.h"
-#include "map_def.h"
+#include "afpfs-ng/uams_def.h"
+#include "afpfs-ng/codepage.h"
+#include "afpfs-ng/libafpclient.h"
+#include "afpfs-ng/map_def.h"
 #include "fuse_int.h"
 #include "fuse_error.h"
 #include "fuse_internal.h"
diff -Naur afpfs-ng-0.8.1.orig/fuse/daemon.c afpfs-ng-0.8.1/fuse/daemon.c
