
$FreeBSD$

--- src/treestore.h	2001/12/14 08:39:52	1.1
+++ src/treestore.h	2001/12/14 08:40:21
@@ -1,6 +1,8 @@
 #ifndef __TREE_STORE_H
 #define __TREE_STORE_H
 
+#include <glib.h>
+
 /* Default filenames for the tree */
 
 #ifdef OS2_NT
