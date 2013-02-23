--- lib/proto_server.c.orig	2008-02-19 01:56:21.000000000 +0000
+++ lib/proto_server.c	2012-10-14 13:11:34.000000000 +0000
@@ -7,12 +7,12 @@
  */
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
-#include "codepage.h"
+#include "afpfs-ng/afp_protocol.h"
+#include "afpfs-ng/codepage.h"
 #include "afp_internal.h"
 
 int afp_getsrvrparms(struct afp_server *server)
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_session.c afpfs-ng-0.8.1/lib/proto_session.c
