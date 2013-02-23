--- lib/lowlevel.c.orig	2008-02-20 01:33:17.000000000 +0000
+++ lib/lowlevel.c	2012-10-14 13:11:44.000000000 +0000
@@ -19,10 +19,10 @@
 #else
 #include <fcntl.h>
 #endif
-#include "afp.h"
-#include "afp_protocol.h"
-#include "codepage.h"
-#include "utils.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/afp_protocol.h"
+#include "afpfs-ng/codepage.h"
+#include "afpfs-ng/utils.h"
 #include "did.h"
 #include "users.h"
 
@@ -582,7 +582,7 @@
 	if (volume->server->using_version->av_number>=30)
 		stbuf->st_mode |= fp.unixprivs.permissions;
 	else
-		set_nonunix_perms(stbuf,&fp);
+		set_nonunix_perms(&stbuf->st_mode,&fp);
 
 	stbuf->st_uid=fp.unixprivs.uid;
 	stbuf->st_gid=fp.unixprivs.gid;
diff -Naur afpfs-ng-0.8.1.orig/lib/map_def.c afpfs-ng-0.8.1/lib/map_def.c
