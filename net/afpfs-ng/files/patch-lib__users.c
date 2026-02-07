--- lib/users.c.orig	2008-02-18 03:48:56.000000000 +0000
+++ lib/users.c	2012-10-14 13:11:34.000000000 +0000
@@ -3,8 +3,8 @@
 #include <grp.h>
 #include <string.h>
 
-#include "afp.h"
-#include "map_def.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/map_def.h"
 
 /* How mapping works
  *
diff -Naur afpfs-ng-0.8.1.orig/lib/utils.c afpfs-ng-0.8.1/lib/utils.c
