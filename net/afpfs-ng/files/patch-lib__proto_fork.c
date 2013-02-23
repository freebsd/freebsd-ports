--- lib/proto_fork.c.orig	2008-01-30 04:37:58.000000000 +0000
+++ lib/proto_fork.c	2012-10-14 13:11:34.000000000 +0000
@@ -9,11 +9,11 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include "dsi.h"
-#include "afp.h"
-#include "utils.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/utils.h"
 #include "dsi_protocol.h"
-#include "afp_protocol.h"
+#include "afpfs-ng/afp_protocol.h"
 
 int afp_setforkparms(struct afp_volume * volume,
 	unsigned short forkid, unsigned short bitmap, unsigned long len)
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_login.c afpfs-ng-0.8.1/lib/proto_login.c
