--- lib/client.c.orig	2008-02-18 03:36:30.000000000 +0000
+++ lib/client.c	2012-10-14 13:11:34.000000000 +0000
@@ -1,5 +1,5 @@
-#include <afp.h>
-#include <libafpclient.h>
+#include <afpfs-ng/afp.h>
+#include <afpfs-ng/libafpclient.h>
 
 
 struct libafpclient * libafpclient = NULL;
diff -Naur afpfs-ng-0.8.1.orig/lib/codepage.c afpfs-ng-0.8.1/lib/codepage.c
