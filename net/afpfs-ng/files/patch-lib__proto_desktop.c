--- lib/proto_desktop.c.orig	2008-02-18 03:44:11.000000000 +0000
+++ lib/proto_desktop.c	2012-10-14 13:11:44.000000000 +0000
@@ -9,10 +9,10 @@
 #include <string.h>
 #include <stdlib.h>
 
-#include "dsi.h"
-#include "afp.h"
-#include "utils.h"
-#include "afp_protocol.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/utils.h"
+#include "afpfs-ng/afp_protocol.h"
 #include "dsi_protocol.h"
 
 /* closedt, addicon, geticoninfo, addappl, removeappl */
@@ -168,7 +168,7 @@
 	return 0;
 }
 
-int afp_closedt(struct afp_server * server, unsigned short * refnum) 
+int afp_closedt(struct afp_server * server, unsigned short refnum) 
 {
 	struct {
 		struct dsi_header dsi_header __attribute__((__packed__));
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_directory.c afpfs-ng-0.8.1/lib/proto_directory.c
