--- lib/meta.c.orig	2008-01-04 03:52:44.000000000 +0000
+++ lib/meta.c	2012-10-14 13:11:34.000000000 +0000
@@ -17,10 +17,10 @@
 #include <unistd.h>
 #include <sys/time.h>
 
-#include "afp.h"
-#include "dsi.h"
-#include "afp_protocol.h"
-#include "utils.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp_protocol.h"
+#include "afpfs-ng/utils.h"
 
 
 int afp_meta_getattr(const char *path, struct stat *stbuf)
diff -Naur afpfs-ng-0.8.1.orig/lib/midlevel.c afpfs-ng-0.8.1/lib/midlevel.c
