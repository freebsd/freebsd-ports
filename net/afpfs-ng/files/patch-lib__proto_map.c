--- lib/proto_map.c.orig	2008-01-30 04:37:59.000000000 +0000
+++ lib/proto_map.c	2012-10-14 13:11:44.000000000 +0000
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
 
 /* This is used to pass the return values back from afp_getuserinfo_reply() */
 struct uidgid {
@@ -122,7 +122,7 @@
 
 	if (reply->header.return_code.error_code!=kFPNoErr) return -1;
 
-	copy_from_pascal_two(name,&reply->name,255);
+	copy_from_pascal_two(name,reply->name,255);
 
 	return 0;
 }
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_replyblock.c afpfs-ng-0.8.1/lib/proto_replyblock.c
