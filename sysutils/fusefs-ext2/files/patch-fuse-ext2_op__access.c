--- fuse-ext2/op_access.c.orig	2015-03-30 23:42:20 UTC
+++ fuse-ext2/op_access.c
@@ -19,6 +19,7 @@
  */
 
 #include "fuse-ext2.h"
+#include <unistd.h>
 
 int op_access (const char *path, int mask)
 {
