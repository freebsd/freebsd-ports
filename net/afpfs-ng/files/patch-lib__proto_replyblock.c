--- lib/proto_replyblock.c.orig	2008-02-18 03:46:19.000000000 +0000
+++ lib/proto_replyblock.c	2012-10-14 13:11:34.000000000 +0000
@@ -6,9 +6,9 @@
  */
 
 #include <string.h>
-#include "dsi.h"
-#include "afp.h"
-#include "utils.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/utils.h"
 #include "afp_internal.h"
 
 
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_server.c afpfs-ng-0.8.1/lib/proto_server.c
