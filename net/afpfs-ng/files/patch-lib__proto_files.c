--- lib/proto_files.c.orig	2008-02-18 03:46:18.000000000 +0000
+++ lib/proto_files.c	2012-10-14 13:11:34.000000000 +0000
@@ -8,11 +8,11 @@
 
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
 #include "afp_internal.h"
 
 /* afp_setfileparms, afp_setdirparms and afpsetfiledirparms are all remarkably
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_fork.c afpfs-ng-0.8.1/lib/proto_fork.c
