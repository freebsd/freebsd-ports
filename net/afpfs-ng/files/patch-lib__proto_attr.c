--- lib/proto_attr.c.orig	2008-01-30 04:37:58.000000000 +0000
+++ lib/proto_attr.c	2012-10-14 13:11:44.000000000 +0000
@@ -7,10 +7,10 @@
 
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
 
 /* This is a new command, function 76.  There are currently no docs, so this 
@@ -166,7 +166,7 @@
 	copy_path(server,p,pathname,strlen(pathname));
 	unixpath_to_afppath(server,p);
 	p2=p+sizeof_path_header(server)+strlen(pathname);
-	if (((unsigned int ) p2) & 0x1) p2++;
+	if (((unsigned long) p2) & 0x1) p2++;
 	req2=(void *) p2;
 
 	req2->len=htons(namelen);
diff -Naur afpfs-ng-0.8.1.orig/lib/proto_desktop.c afpfs-ng-0.8.1/lib/proto_desktop.c
