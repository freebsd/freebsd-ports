--- lib/map_def.c.orig	2007-09-07 13:10:59.000000000 +0000
+++ lib/map_def.c	2012-10-14 13:11:34.000000000 +0000
@@ -1,6 +1,6 @@
 #include <string.h>
-#include "afp.h"
-#include "map_def.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/map_def.h"
 
 static char *afp_map_strings[] = {
 	"Unknown",
diff -Naur afpfs-ng-0.8.1.orig/lib/meta.c afpfs-ng-0.8.1/lib/meta.c
