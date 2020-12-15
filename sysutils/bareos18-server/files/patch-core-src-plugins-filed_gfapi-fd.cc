--- core/src/plugins/filed/gfapi-fd.cc	2020-12-14 23:47:04.832213000 -0500
+++ core/src/plugins/filed/gfapi-fd.cc	2020-12-14 23:47:56.824952000 -0500
@@ -30,7 +30,7 @@
 #include "lib/path_list.h"
 #include "lib/edit.h"
 
-#include <api/glfs.h>
+#include <glusterfs/api/glfs.h>
 
 
 /* avoid missing config.h problem on Debian 8 and Ubuntu 16:
@@ -39,10 +39,10 @@
  */
 #ifndef _CONFIG_H
 #define _CONFIG_H
-#include <compat-errno.h>
+#include <glusterfs/compat-errno.h>
 #undef _CONFIG_H
 #else
-#include <compat-errno.h>
+#include <glusterfs/compat-errno.h>
 #endif
 
 namespace filedaemon {
