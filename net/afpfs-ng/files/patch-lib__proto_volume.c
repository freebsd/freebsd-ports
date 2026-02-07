--- lib/proto_volume.c.orig	2008-02-18 03:47:48.000000000 +0000
+++ lib/proto_volume.c	2012-10-14 13:11:34.000000000 +0000
@@ -8,13 +8,13 @@
 
 #include <string.h>
 #include <stdlib.h>
-#include "dsi.h"
-#include "afp.h"
-#include "utils.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/utils.h"
 #include "dsi_protocol.h"
-#include "afp_protocol.h"
+#include "afpfs-ng/afp_protocol.h"
 #include "afp_internal.h"
-#include "codepage.h"
+#include "afpfs-ng/codepage.h"
 
 static int parse_volbitmap_reply(struct afp_server * server, 
 		struct afp_volume * tmpvol, 
diff -Naur afpfs-ng-0.8.1.orig/lib/resource.c afpfs-ng-0.8.1/lib/resource.c
