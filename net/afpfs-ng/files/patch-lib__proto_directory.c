--- lib/proto_directory.c.orig	2008-02-19 02:39:29.000000000 +0000
+++ lib/proto_directory.c	2012-10-14 13:11:44.000000000 +0000
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
 #include "afp_replies.h"
 
@@ -248,6 +248,7 @@
 
 	return 0;
 }
+
 int afp_enumerateext2_reply(struct afp_server *server, char * buf, unsigned int size, void * other) 
 {
 
@@ -266,8 +267,7 @@
 	char * p = buf + sizeof(*reply);
 	int i;
 	char  *max=buf+size;
-	struct afp_file_info * filebase = NULL, *filecur=NULL, *new_file=NULL;
-	void ** x = other;
+	struct afp_file_info * filebase = NULL, *filecur = NULL, *new_file = NULL, **x = (struct afp_file_info **) other;
 
 	if (reply->dsi_header.return_code.error_code) {
 		return reply->dsi_header.return_code.error_code;
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_files.c afpfs-ng-0.8.1/lib/proto_files.c
