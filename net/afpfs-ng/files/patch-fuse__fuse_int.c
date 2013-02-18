--- fuse/fuse_int.c.orig	2008-03-02 05:06:24.000000000 +0000
+++ fuse/fuse_int.c	2012-10-14 13:11:44.000000000 +0000
@@ -18,7 +18,7 @@
 #define FUSE_USE_VERSION 25
 
 
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 
 #include <fuse.h>
 #include <stdio.h>
@@ -39,10 +39,10 @@
 #include <pwd.h>
 #include <stdarg.h>
 
-#include "dsi.h"
-#include "afp_protocol.h"
-#include "codepage.h"
-#include "midlevel.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp_protocol.h"
+#include "afpfs-ng/codepage.h"
+#include "afpfs-ng/midlevel.h"
 #include "fuse_error.h"
 
 /* Uncomment the following line to enable full debugging: */
@@ -197,7 +197,7 @@
 	ret = ml_open(volume,path,flags,&fp);
 
 	if (ret==0) 
-		fi->fh=(void *) fp;
+		fi->fh=(unsigned long) fp;
 
 	return ret;
 }
diff -Naur afpfs-ng-0.8.1.orig/include/Makefile.am afpfs-ng-0.8.1/include/Makefile.am
