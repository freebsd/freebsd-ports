--- lib/status.c.orig	2008-03-08 16:08:38.000000000 +0000
+++ lib/status.c	2012-10-14 13:11:34.000000000 +0000
@@ -1,8 +1,8 @@
 #include <string.h>
 #include <stdio.h>
-#include "map_def.h"
-#include "dsi.h"
-#include "afp.h"
+#include "afpfs-ng/map_def.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp.h"
 
 int afp_status_header(char * text, int * len) 
 {
diff -Naur afpfs-ng-0.8.1.orig/lib/uams.c afpfs-ng-0.8.1/lib/uams.c
