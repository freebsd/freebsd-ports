--- lib/midlevel.c.orig	2008-03-08 16:08:18.000000000 +0000
+++ lib/midlevel.c	2012-10-14 13:11:44.000000000 +0000
@@ -10,7 +10,7 @@
 */
 
 
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 
 #include <sys/stat.h>
 #include <string.h>
@@ -28,9 +28,9 @@
 #include "users.h"
 #include "did.h"
 #include "resource.h"
-#include "utils.h"
-#include "codepage.h"
-#include "midlevel.h"
+#include "afpfs-ng/utils.h"
+#include "afpfs-ng/codepage.h"
+#include "afpfs-ng/midlevel.h"
 #include "afp_internal.h"
 #include "forklist.h"
 #include "uams.h"
@@ -713,7 +713,7 @@
 {
 
 	int ret,err=0;
-	int totalwritten = 0;
+	size_t totalwritten = 0;
 	uint64_t sizetowrite, ignored;
 	unsigned char flags = 0;
 	unsigned int max_packet_size=volume->server->tx_quantum;
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_attr.c afpfs-ng-0.8.1/lib/proto_attr.c
