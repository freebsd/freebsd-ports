--- lib/server.c.orig	2008-02-19 01:56:21.000000000 +0000
+++ lib/server.c	2012-10-14 13:11:34.000000000 +0000
@@ -8,15 +8,15 @@
 #include <string.h>
 #include <time.h>
 
-#include "afp.h"
-#include "dsi.h"
-#include "utils.h"
-#include "uams_def.h"
-#include "codepage.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/utils.h"
+#include "afpfs-ng/uams_def.h"
+#include "afpfs-ng/codepage.h"
 #include "users.h"
-#include "libafpclient.h"
+#include "afpfs-ng/libafpclient.h"
 #include "afp_internal.h"
-#include "dsi.h"
+#include "afpfs-ng/dsi.h"
 
 
 struct afp_server * afp_server_complete_connection(
diff -Naur afpfs-ng-0.8.1.orig/lib/status.c afpfs-ng-0.8.1/lib/status.c
