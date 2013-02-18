--- lib/forklist.c.orig	2008-01-17 04:49:16.000000000 +0000
+++ lib/forklist.c	2012-10-14 13:11:34.000000000 +0000
@@ -10,7 +10,7 @@
 */
 
 
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 
 #include <stdlib.h>
 #include <pthread.h>
diff -Naur afpfs-ng-0.8.1.orig/lib/identify.c afpfs-ng-0.8.1/lib/identify.c
