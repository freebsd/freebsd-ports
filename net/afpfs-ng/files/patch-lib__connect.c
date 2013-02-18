--- lib/connect.c.orig	2008-02-18 03:38:59.000000000 +0000
+++ lib/connect.c	2012-10-14 13:11:34.000000000 +0000
@@ -10,13 +10,13 @@
 #include <string.h>
 #include <sys/socket.h>
 
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
 #include "server.h"
 
 
diff -Naur afpfs-ng-0.8.1.orig/lib/did.c afpfs-ng-0.8.1/lib/did.c
