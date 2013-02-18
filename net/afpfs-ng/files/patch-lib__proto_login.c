--- lib/proto_login.c.orig	2008-01-30 04:37:59.000000000 +0000
+++ lib/proto_login.c	2012-10-14 13:11:34.000000000 +0000
@@ -10,10 +10,10 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include "dsi.h"
+#include "afpfs-ng/dsi.h"
 #include "dsi_protocol.h"
-#include "afp.h"
-#include "utils.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/utils.h"
 #include "afp_internal.h"
 
 
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_map.c afpfs-ng-0.8.1/lib/proto_map.c
